#ifndef FILE_OPERATOR_H_INCLUDED
#define FILE_OPERATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "memctl/alloc_kits.h"


#include "list.h"

extern struct lines* init_lines(void);
extern void lines_delete_all(struct lines *lnsptr);
extern void lines_show_all(struct lines * lnsptr);
extern void readlines(FILE *fptr, struct lines* lnsptr);


/**
 * __get_file__   -   open a file with path
 * @fptr: FILE* pointer
 * @path: string type, Path where file exist
 * @mode: File is opened mode
 * @__label_to_jump: if opening fall, jump to the label
 */
#define __get_file__(fptr, path, mode, __label_to_jmp) do {   \
    if ((fptr = fopen(path, mode)) == NULL) {               \
        perror("File open Error: __fopen__()\n");           \
        goto __label_to_jmp;                                \
    }                                                       \
} while(0)


/**
 * __put_file__   -   free FILE* pointer
 * @fptr: FILE* pointer
 */
#define __put_file__(fptr) do {                               \
    if (fptr) {                                             \
        fclose(fptr);                                       \
    }                                                       \
} while(0)



/**
 __STRUCT_LINE_CHAR_MAX__   ---   define the length of line->line
 */
#define __STRUCT_LINE_CHAR_MAX__ 1024



typedef struct line{
    char line[__STRUCT_LINE_CHAR_MAX__];
    struct list_head next;
} file_line;



struct lines_struct_op{
    void (*show)(struct lines * lnsptr);

};


struct lines{
    unsigned long number;

    unsigned char dirty;    // If text changed, dirty will be set
//    struct lines_struct_op * op;
    struct list_head next;
} file_lines;


struct lines* init_lines(void) {
    struct lines * lines_struct = NULL;

    __malloc__(lines_struct, struct lines *, __func_init_lines_END__);

    lines_struct->number = 0;
    lines_struct->dirty = 0;

__func_init_lines_END__:

    return lines_struct;

}

/**
 * line_delete_all	-	delete all line in lines list
 * @lnsptr:	the lines's list head pointer
 */
void lines_delete_all(struct lines *lnsptr)
{
    struct line * tmp_line = NULL;              // temp_pointer for load line struct

    struct list_head * tmp_list = NULL;         // main pointer for list_for_each_safe
    struct list_head * tmp_list_q = NULL;       // temp_pointer for list_for_each_safe

    list_for_each_safe(tmp_list, tmp_list_q, &lnsptr->next)
    {
        tmp_line = list_entry(tmp_list, struct line, next);
        list_del(&tmp_line->next);          // delete from lines list
        lnsptr->number--;                   // decrease line's counter in lines list
        __free__(tmp_line);                 // free line
    }

    return;
}


void lines_show_all(struct lines * lnsptr)
{
    struct list_head * tmp = NULL;
    struct line * line_tmp = NULL;
    unsigned long cnt = 0;
    list_for_each(tmp, &lnsptr->next) {
        line_tmp = list_entry(tmp, struct line, next);
        cnt++;
        fprintf(stdout, "----------------->> %lu \n"
                "%s\n", cnt, line_tmp->line);
    }

    return;
}

void readlines(FILE *fptr, struct lines* lnsptr)
{
    struct line *tmp = NULL;
    __malloc__(tmp, struct line *, __func_readlines_END__);


    while (!feof(fptr)) {
        fgets(tmp->line, __STRUCT_LINE_CHAR_MAX__, fptr);
        list_add_tail(&tmp->next, &lnsptr->next);       // add this line to lines list
        lnsptr->number++;                               // lines number plus one
        __malloc__(tmp, struct line *, __func_readlines_END__);         // allocate a new line node
    }

    __free__(tmp);

__func_readlines_END__:

    return;
}






/**

***************                     MACRO                         *****************


***************                     MACRO                         *****************

*/





/**
 * line_delete_all	-	delete all line in lines list
 * @lnsptr:	the lines's list head pointer
 *
 * not free the struct lines ( *linesptr),
 * (*linesptr) need to free manually.
 */
#define __lines_del_all(linesptr) do {                              \
    struct line * __tmp_line = NULL;                                \
    struct list_head * __tmp_list = NULL;                           \
    struct list_head * __tmp_list_q = NULL;                         \
                                                                    \
    list_for_each_safe(__tmp_list, __tmp_list_q, &linesptr->next) { \
        __tmp_line = list_entry(__tmp_list, struct line, next);     \
        list_del(&__tmp_line->next);                                \
        linesptr->number--;                                         \
        __free__(__tmp_line);                                       \
    }                                                               \
} while(0)



/**
 * lines_load   -   load file by line
 * @fptr: the NULL file pointer
 * @linesptr: the NULL struct lines's pointer
 * @path: loaded file path
 * @mode: loaded file mode
 * @__label_to_jmp__: if error encounter, goto __label_to_jmp__ code line
 */

#define lines_load(fptr, linesptr, path, mode, __label_to_jmp__) do {       \
    __get_file__(fptr, path, mode, __label_to_jmp__);                         \
    linesptr = init_lines();                                                \
    INIT_LIST_HEAD(&linesptr->next);                                        \
    readlines(fptr, linesptr);                                              \
    __put_file__(fptr);                                                       \
} while (0)



/**
 * lines_get_counters   ---   get lines number
 * @linesptr: lines* pointer
 */
#define lines_get_counters(linesptr) \
    ((linesptr) ? (linesptr)->number : -1)




/**

Example Code:

int main(void) {

    FILE *f = NULL;
    struct lines * fs = NULL;

    lines_load(f, fs, "test.txt", "r+", __func_main_end);

    lines_show_all(fs);

__func_main_end:

    __lines_del_all(fs);
    __put_file__(f);
    printf("------ >>>>>>>>   NUMBER :  %lu %d\n", lines_get_counters(fs), 0xA);

    __free__(fs);
    __window_keep__();
    return 0;
}



**/



#endif // FILE_OPERATOR_H_INCLUDED
