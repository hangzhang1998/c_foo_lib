#ifndef BIT_KITS_H_INCLUDED
#define BIT_KITS_H_INCLUDED


/**
 * MASK_BIT_POS_XX -- XX position is 1, other is 0
 */
#define MASK_BIT_POS_1  0x1
#define MASK_BIT_POS_2  0x2
#define MASK_BIT_POS_3  0x4
#define MASK_BIT_POS_4  0x8
#define MASK_BIT_POS_5  0x10
#define MASK_BIT_POS_6  0x20
#define MASK_BIT_POS_7  0x40
#define MASK_BIT_POS_8  0x80
#define MASK_BIT_POS_9  0x100
#define MASK_BIT_POS_10 0x200
#define MASK_BIT_POS_11 0x400
#define MASK_BIT_POS_12 0x800
#define MASK_BIT_POS_13 0x1000
#define MASK_BIT_POS_14 0x2000
#define MASK_BIT_POS_15 0x4000
#define MASK_BIT_POS_16 0x8000
#define MASK_BIT_POS_17 0x10000
#define MASK_BIT_POS_18 0x20000
#define MASK_BIT_POS_19 0x40000
#define MASK_BIT_POS_20 0x80000
#define MASK_BIT_POS_21 0x100000
#define MASK_BIT_POS_22 0x200000
#define MASK_BIT_POS_23 0x400000
#define MASK_BIT_POS_24 0x800000
#define MASK_BIT_POS_25 0x1000000
#define MASK_BIT_POS_26 0x2000000
#define MASK_BIT_POS_27 0x4000000
#define MASK_BIT_POS_28 0x8000000
#define MASK_BIT_POS_29 0x10000000
#define MASK_BIT_POS_30 0x20000000
#define MASK_BIT_POS_31 0x40000000
#define MASK_BIT_POS_32 0x80000000



/**
 * MASK_BITS_ALL_XX   ---   Specify Mask Code Value
 */
#define MASK_BITS_ALL_4  0xf
#define MASK_BITS_ALL_8  0xff
#define MASK_BITS_ALL_12 0xfff
#define MASK_BITS_ALL_16 0xffff
#define MASK_BITS_ALL_20 0xfffff
#define MASK_BITS_ALL_24 0xffffff
#define MASK_BITS_ALL_28 0xfffffff
#define MASK_BITS_ALL_32 0xffffffff
#define MASK_BITS_ALL_36 0xfffffffff
#define MASK_BITS_ALL_40 0xffffffffff
#define MASK_BITS_ALL_44 0xfffffffffff
#define MASK_BITS_ALL_48 0xffffffffffff
#define MASK_BITS_ALL_52 0xfffffffffffff
#define MASK_BITS_ALL_56 0xffffffffffffff
#define MASK_BITS_ALL_60 0xfffffffffffffff
#define MASK_BITS_ALL_64 0xffffffffffffffff



/**
 * MASK_BITS_XXXXX(TYPES)   ---   Specify Mask Code Value
 */
#define MASK_BITS_UCHAR   MASK_BITS_ALL_8
#define MASK_BITS_USHORT  MASK_BITS_ALL_16
#define MASK_BITS_UINT32  MASK_BITS_ALL_32
#define MASK_BITS_ULONG32 MASK_BITS_ALL_32
#define MASK_BITS_ULONG64 MASK_BITS_ALL_64




/**
 * __get_bit_mask_from_pos__   -   get the specify bit mask by position
 * @pos: position, where you want to set 1 from bits
 *
 * 获得特定位的掩码
 */
#define __get_bit_mask_from_pos__(pos) \
    ((0x1) << ((pos) - 1))




/**
 * __get_bit_from_pos__   -   get the bit value by position
 * @op_number: operating number
 * @pos: position, like MASK_BIT_POS_1
 *
 * 获取一个操作数的特定位的比特值
 */
#define __get_bit_from_pos__(op_number, pos) \
    (((op_number) & (pos)) ? 1 : 0)



/**
 * __set_bit_from_pos__   --   set the bit value to 1 by position
 * @op_number: operating number
 * @pos: position, like MASK_BIT_POS_1
 *
 * 将一个操作数的特定位置为 1
 */
#define __set_bit_from_pos__(op_number, pos) \
    ((op_number) | (pos))


/**
 * __clr_bit_from_pos__   --   clear the bit value to 0 by position
 * @op_number: operating number
 * @pos: position, like MASK_BIT_POS_1
 *
 * 将一个操作数的特定位置为 0
 */
#define __clr_bit_from_pos__(op_number, pos) \
    ((op_number) & (~(pos)))




#endif // BIT_KITS_H_INCLUDED
