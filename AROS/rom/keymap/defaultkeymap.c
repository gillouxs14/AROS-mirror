#include <devices/keymap.h>


#undef N
#undef S
#undef A
#undef C
#undef D
#undef V
#undef ST

#define N KC_NOQUAL
#define S KCF_SHIFT
#define A KCF_ALT
#define C KCF_CONTROL
#define D KCF_DEAD
#define V KC_VANILLA
#define ST KCF_STRING

static UBYTE lokeymaptypes[] =
{
    N, 		/* 00 */
    S|A, 	/* 01 */
    S|A,	/* 02 */
    S|A,	/* 03 */
    S|A,	/* 04 */
    S|A,	/* 05 */
    S|A,	/* 06 */
    S|A,	/* 07 */
    S|A,	/* 08 */
    S|A,	/* 09 */
    S|A,	/* 0A */
    N, 		/* 0B */
    N, 		/* 0C */
    N, 		/* 0D */
    N, 		/* 0E */
    S|A, 	/* 0F */
    S|A, 	/* 10 */
    S|A, 	/* 11 */
    S|A, 	/* 12 */
    S|A, 	/* 13 */
    S|A, 	/* 14 */
    S|A, 	/* 15 */
    S|A, 	/* 16 */
    S|A, 	/* 17 */
    S|A, 	/* 18 */
    S|A, 	/* 19 */
    N, 		/* 1A */
    N, 		/* 1B */
    N, 		/* 1C */
    N, 		/* 1D */
    N, 		/* 1E */
    N, 		/* 1F */
    S|A, 	/* 20 */
    S|A, 	/* 21 */
    S|A, 	/* 22 */
    S|A, 	/* 23 */
    S|A, 	/* 24 */
    S|A, 	/* 25 */
    S|A, 	/* 26 */
    S|A, 	/* 27 */
    S|A, 	/* 28 */
    N, 		/* 29 */
    N, 		/* 2A */
    N, 		/* 2B */
    N, 		/* 2C */
    N, 		/* 2D */
    N, 		/* 2E */
    N, 		/* 2F */
    N, 		/* 30 */
    S|A, 	/* 31 */
    S|A, 	/* 32 */
    S|A, 	/* 33 */
    S|A, 	/* 34 */
    S|A, 	/* 35 */
    S|A, 	/* 36 */
    S|A, 	/* 37 */
    N, 		/* 38 */
    N, 		/* 39 */
    N, 		/* 3A */
    N, 		/* 3B */
    N, 		/* 3C */
    N, 		/* 3D */
    N, 		/* 3E */
    N, 		/* 3F */
    
};

static UBYTE hikeymaptypes[] =
{
    N, 		/* 40 */
    V, 	/* 41 */
    V,	/* 42 */
    V,	/* 43 */
    V,	/* 44 */
    V,	/* 45 */
    V,	/* 46 */
    V,	/* 47 */
    V,	/* 48 */
    V,	/* 49 */
    V,	/* 4A */
    V, 	/* 4B */
    S, 		/* 4C */
    S, 		/* 4D */
    S, 		/* 4E */
    S, 		/* 4F */
    S, 		/* 50 */
    S, 		/* 51 */
    S, 		/* 52 */
    S, 		/* 53 */
    S, 		/* 54 */
    S, 		/* 55 */
    S, 		/* 56 */
    S, 		/* 57 */
    S, 		/* 58 */
    S, 		/* 59 */
    S, 		/* 5A */
    S, 		/* 5B */
    S, 		/* 5C */
    S, 		/* 5D */
    S, 		/* 5E */
    S, 		/* 5F */
    S, 		/* 60 */
    S, 		/* 61 */
    S, 		/* 62 */
    S, 		/* 63 */
    S, 		/* 64 */
    S, 		/* 65 */
    S, 		/* 66 */
    S, 		/* 67 */
    S, 		/* 68 */
    S, 		/* 69 */
    S, 		/* 6A */
    S, 		/* 6B */
    S, 		/* 6C */
    S, 		/* 6D */
    S, 		/* 6E */
    S, 		/* 6F */
    S, 		/* 70 */
    S, 		/* 71 */
    S, 		/* 72 */
    S, 		/* 73 */
    S, 		/* 74 */
    S, 		/* 75 */
    S, 		/* 76 */
    S, 		/* 77 */
    S, 		/* 78 */
    S, 		/* 79 */
    S, 		/* 7A */
    S, 		/* 7B */
    S, 		/* 7C */
    S, 		/* 7D */
    S, 		/* 7E */
    S, 		/* 7F */
    
};

#undef N
#undef S
#undef A
#undef C
#undef D
#undef V
#undef ST

#undef STRING
#undef DEAD
#undef BYTES

#define STRING(x) (IPTR)x
#define DEAD(x)	  (IPTR)x
#define BYTES(b0, b1, b2, b3) \
	(b0<<24)|(b1<<16)|(b1<<8)|(b1<<0)

static IPTR lokeymap[] =
{
    BYTES(0, 0, 0, 0x7C), 		/* 00 */
    BYTES(0xB9, 0xA1, '!', '1'), 	/* 01 */
    BYTES(0xB2, '@', '"', '2'), 	/* 02 */
    BYTES(0xB3, 0xA3, '#', '3'), 	/* 03 */
    BYTES(0xBC, 0xA4, '$', '4'), 	/* 04 */
    BYTES(0xBD, 0xBD, '%', '5'), 	/* 05 */
    BYTES(0xBE, 0xBE, '&', '6'), 	/* 06 */
    BYTES(0xF7, '{', '/', '7'), 	/* 07 */
    BYTES('[', '[', '(', '8'), 		/* 08 */
    BYTES(']', ']', ')', '9'),		/* 09 */
    BYTES('}', '}', '=', '0'),		/* 0A */
    BYTES(0, 0, 0, 0),	/* 0B */
    BYTES(0, 0, 0, 0),	/* 0C */
    BYTES(0, 0, 0, 0),	/* 0D */
    BYTES(0, 0, 0, 0),	/* 0E */
    BYTES('0', '0', '0', '0'), 		/* 0F */
    BYTES('Q', 'q', 'Q', 'q'), 		/* 10 */
    BYTES('W', 'w', 'W', 'w'),		/* 11 */
    BYTES('E', 'e', 'E', 'e'), 		/* 12 */
    BYTES('R', 'r', 'R', 'r'), 		/* 13 */
    BYTES('T', 't', 'T', 't'),		/* 14 */
    BYTES('Y', 'y', 'Y', 'y'),		/* 15 */
    BYTES('U', 'u', 'U', 'u'), 		/* 16 */
    BYTES('I', 'i', 'I', 'i'), 		/* 17 */
    BYTES('O', 'o', 'O', 'o'), 		/* 18 */
    BYTES('P', 'p', 'P', 'p'), 		/* 19 */
    
    BYTES(0, 0, 0, 0),	/* 1A */
    BYTES(0, 0, 0, 0),	/* 1B */
    BYTES(0, 0, 0, 0),	/* 1C */
    BYTES(0, 0, 0, 0),	/* 1D */
    BYTES(0, 0, 0, 0),	/* 1E */
    BYTES(0, 0, 0, 0),	/* 1F */
    
    BYTES('A', 'a', 'A', 'a'),		/* 20 */
    BYTES('S', 's', 'S', 's'),		/* 21 */
    BYTES('D', 'd', 'D', 'd'),		/* 22 */
    BYTES('F', 'f', 'F', 'f'), 		/* 23 */
    BYTES('G', 'g', 'G', 'g'), 		/* 24 */
    BYTES('H', 'h', 'H', 'h'), 		/* 25 */
    BYTES('J', 'j', 'J', 'j'), 		/* 26 */
    BYTES('K', 'k', 'K', 'k'), 		/* 27 */
    BYTES('L', 'l', 'L', 'l'), 		/* 28 */
    
    BYTES(0, 0, 0, 0), /* 29 */
    BYTES(0, 0, 0, 0), /* 2A */
    BYTES(0, 0, 0, 0), /* 2B */
    BYTES(0, 0, 0, 0), /* 2C */
    BYTES(0, 0, 0, 0), /* 2D */
    BYTES(0, 0, 0, 0), /* 2E */
    BYTES(0, 0, 0, 0), /* 2F */
    BYTES(0, 0, 0, 0), /* 30 */
    
    BYTES('Z', 'z', 'Z', 'z'),		/* 31 */
    BYTES('X', 'x', 'X', 'x'),		/* 32 */
    BYTES('C', 'c', 'C', 'c'),		/* 33 */
    BYTES('V', 'v', 'V', 'v'),		/* 34 */
    BYTES('B', 'b', 'B', 'b'),		/* 35 */
    BYTES('N', 'n', 'N', 'n'),		/* 36 */
    BYTES('M', 'm', 'M', 'm'),		/* 37 */
    
    BYTES(0, 0, 0, 0),	/* 38 */
    BYTES(0, 0, 0, 0),	/* 39 */
    BYTES(0, 0, 0, 0),	/* 3A */
    BYTES(0, 0, 0, 0),	/* 3B */
    BYTES(0, 0, 0, 0),	/* 3C */
    BYTES(0, 0, 0, 0),	/* 3D */
    BYTES(0, 0, 0, 0),	/* 3E */
    BYTES(0, 0, 0, 0),	/* 3F */
};

static IPTR hikeymap[] =
{
    BYTES(0, 0, 0, 0),	/* 40 */
    BYTES(0, 0, 0, 0),	/* 41 */
    BYTES(0, 0, 0, 0),	/* 42 */
    BYTES(0, 0, 0, 0),	/* 43 */
    BYTES(0, 0, 0, 0),	/* 44 */
    BYTES(0, 0, 0, 0),	/* 45 */
    BYTES(0, 0, 0, 0),	/* 46 */
    BYTES(0, 0, 0, 0),	/* 47 */
    BYTES(0, 0, 0, 0),	/* 48 */
    BYTES(0, 0, 0, 0),	/* 49 */
    BYTES(0, 0, 0, 0),	/* 4A */
    BYTES(0, 0, 0, 0), 	/* 4B */
    BYTES(0, 0, 0, 0),	/* 4C */
    BYTES(0, 0, 0, 0),	/* 4D */
    BYTES(0, 0, 0, 0),	/* 4E */
    BYTES(0, 0, 0, 0),	/* 4F */
    BYTES(0, 0, 0, 0),	/* 50 */
    BYTES(0, 0, 0, 0),	/* 51 */
    BYTES(0, 0, 0, 0),	/* 52 */
    BYTES(0, 0, 0, 0),	/* 53 */
    BYTES(0, 0, 0, 0),	/* 54 */
    BYTES(0, 0, 0, 0),	/* 55 */
    BYTES(0, 0, 0, 0),	/* 56 */
    BYTES(0, 0, 0, 0),	/* 57 */
    BYTES(0, 0, 0, 0),	/* 58 */
    BYTES(0, 0, 0, 0),	/* 59 */
    BYTES(0, 0, 0, 0),	/* 5A */
    BYTES(0, 0, 0, 0),	/* 5B */
    BYTES(0, 0, 0, 0),	/* 5C */
    BYTES(0, 0, 0, 0),	/* 5D */
    BYTES(0, 0, 0, 0),	/* 5E */
    BYTES(0, 0, 0, 0),	/* 5F */
    BYTES(0, 0, 0, 0),	/* 60 */
    BYTES(0, 0, 0, 0),	/* 61 */
    BYTES(0, 0, 0, 0),	/* 62 */
    BYTES(0, 0, 0, 0),	/* 63 */
    BYTES(0, 0, 0, 0),	/* 64 */
    BYTES(0, 0, 0, 0),	/* 65 */
    BYTES(0, 0, 0, 0),	/* 66 */
    BYTES(0, 0, 0, 0),	/* 67 */
    BYTES(0, 0, 0, 0),	/* 68 */
    BYTES(0, 0, 0, 0),	/* 69 */
    BYTES(0, 0, 0, 0),	/* 6A */
    BYTES(0, 0, 0, 0),	/* 6B */
    BYTES(0, 0, 0, 0),	/* 6C */
    BYTES(0, 0, 0, 0),	/* 6D */
    BYTES(0, 0, 0, 0),	/* 6E */
    BYTES(0, 0, 0, 0),	/* 6F */
    BYTES(0, 0, 0, 0),	/* 70 */
    BYTES(0, 0, 0, 0),	/* 71 */
    BYTES(0, 0, 0, 0),	/* 72 */
    BYTES(0, 0, 0, 0),	/* 73 */
    BYTES(0, 0, 0, 0),	/* 74 */
    BYTES(0, 0, 0, 0),	/* 75 */
    BYTES(0, 0, 0, 0),	/* 76 */
    BYTES(0, 0, 0, 0),	/* 77 */
    BYTES(0, 0, 0, 0),	/* 78 */
    BYTES(0, 0, 0, 0),	/* 79 */
    BYTES(0, 0, 0, 0),	/* 7A */
    BYTES(0, 0, 0, 0),	/* 7B */
    BYTES(0, 0, 0, 0),	/* 7C */
    BYTES(0, 0, 0, 0),	/* 7D */
    BYTES(0, 0, 0, 0),	/* 7E */
    BYTES(0, 0, 0, 0),	/* 7F */
};

#undef SETBITS

#define SETBITS(b0, b1, b2, b3, b4, b5, b6, b7) \
	(b0<<7)|(b1<<6)|(b2<<5)|(b3<<4)|(b4<<3)|(b5<<2)|(b6<<1)|(b7<<0)
	
static UBYTE locapsable[] =
{
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 00 - 07 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 08 - 0F */
    
    SETBITS(1, 1, 1, 1, 1, 1, 1, 1),	/* 10 - 17 */
    SETBITS(1, 1, 0, 0, 0, 0, 0, 0),	/* 18 - 1F */
    
    SETBITS(1, 1, 1, 1, 1, 1, 1, 1),	/* 20 - 27 */
    SETBITS(1, 0, 0, 0, 0, 0, 0, 0),	/* 28 - 2F */
    
    SETBITS(0, 1, 1, 1, 1, 1, 1, 1),	/* 30 - 37 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0)	/* 38 - 3F */
};

static UBYTE hicapsable[] =
{
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 40 - 47 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 48 - 4F */
    
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 50 - 57 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 58 - 5F */
    
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 60 - 67 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 68 - 6F */
    
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 70 - 77 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0)	/* 78 - 7F */
};

static UBYTE lorepeatable[] =
{
    SETBITS(1, 1, 1, 1, 1, 1, 1, 1),	/* 00 - 07 */
    SETBITS(1, 1, 1, 0, 0, 0, 0, 0),	/* 08 - 0F */
    
    SETBITS(1, 1, 1, 1, 1, 1, 1, 1),	/* 10 - 17 */
    SETBITS(1, 1, 0, 0, 0, 0, 0, 0),	/* 18 - 1F */
    
    SETBITS(1, 1, 1, 1, 1, 1, 1, 1),	/* 20 - 27 */
    SETBITS(1, 0, 0, 0, 0, 0, 0, 0),	/* 28 - 2F */
    
    SETBITS(0, 1, 1, 1, 1, 1, 1, 1),	/* 30 - 37 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0)	/* 38 - 3F */
};

static UBYTE hirepeatable[] =
{
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 40 - 47 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 48 - 4F */
    
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 50 - 57 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 58 - 5F */
    
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 60 - 67 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 68 - 6F */
    
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0),	/* 70 - 77 */
    SETBITS(0, 0, 0, 0, 0, 0, 0, 0)	/* 78 - 7F */
};

struct KeyMap def_km =
{
    lokeymaptypes,
    lokeymap,
    locapsable,
    lorepeatable,
    
    hikeymaptypes,
    hikeymap,
    hicapsable,
    hirepeatable
};

/* index vertically: (keytype & KC_VANILLA)
** index horizontally: KCF_xxx qualifier combination for keypress.
** Which is used to get the index of the byte describing the keypress.
** X means invalid key.
** S means Ctrl-c alike combination (clear bits 5 and 6)
*/
#undef U /* undefined */
#define X (-1)
#define S (-2)
const BYTE keymaptype_table[8][8] =
{
    {3, X, X, X, X, X, X, X},	/* KCF_NOQUAL 			== 0 */
    {3, 2, X, X, X, X, X, X}, 	/* KCF_SHIFT  			== 1 */
    {3, X, X, X, X, X, X, X}, 	/* KCF_ALT    			== 2 */
    {3, 2, 1, 0, X, X, X, X}, 	/* KCF_SHIFT|KCF_ALT 		== 3 */
    {3, X, X, X, 2, X, X, X}, 	/* KCF_CONTROL			== 4 */
    {3, 2, X, X, 1, 0, X, X}, 	/* KCF_SHIFT|KCF_CONTROL	== 5 */
    {3, X, 2, X, 1, X, 0, X}, 	/* KCF_ALT|KCF_CONTROL		== 6 */
    {3, 2, 1, 0, S, X, X, X} 	/* KCF_SHIFT|KCF_ALT|KCF_CONTROL == KC__VANILLA == 7 */

};

#undef U
#undef S
