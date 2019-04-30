#ifndef ALLOC_KITS_H_INCLUDED
#define ALLOC_KITS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>



#define __malloc__(ptr, type, __label_end__) do {                   \
    if ((ptr = (type) malloc(sizeof(*ptr))) == NULL) {              \
            perror("__malloc__ ERROR:");                            \
            goto __label_end__;                                     \
    }                                                               \
} while(0)



#define __free__(ptr) do {          \
    if (ptr) {                      \
        free(ptr);                  \
    }                               \
} while(0)


#endif // ALLOC_KITS_H_INCLUDED
