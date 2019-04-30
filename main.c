#include <stdio.h>
#include "include/win_kit.h"
#include "include/bit_kits.h"

int main(void)
{
    printf("%d\n", __get_bit_from_pos__(0xf, (MASK_BIT_POS_2|MASK_BIT_POS_1)));

    printf("%d\n", __set_bit_from_pos__(0x3, MASK_BIT_POS_4|MASK_BIT_POS_3));

    printf("%d\n", __clr_bit_from_pos__(0xf, (MASK_BIT_POS_1 | MASK_BIT_POS_4)));

    printf("%u === %u\n", __get_bit_mask_from_pos__(32), MASK_BIT_POS_32);

__func_main__END__:


    __window_keep__();

    return 0;
}
