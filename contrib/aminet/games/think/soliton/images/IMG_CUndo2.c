#ifdef USE_IMG_CUNDO2_COLORS
const ULONG IMG_CUndo2_colors[96] =
{
  0x00000000,0xffffffff,0x00000000,
  0xf7f7f7f7,0xf7f7f7f7,0xf7f7f7f7,
  0xebebebeb,0xe7e7e7e7,0xe7e7e7e7,
  0xe3e3e3e3,0xe3e3e3e3,0xe3e3e3e3,
  0x75757575,0x71717171,0x71717171,
  0xd6d6d6d6,0xd6d6d6d6,0xd6d6d6d6,
  0xcacacaca,0xcececece,0xd6d6d6d6,
  0xbebebebe,0xbebebebe,0xbebebebe,
  0xb6b6b6b6,0xb6b6b6b6,0xb2b2b2b2,
  0xaaaaaaaa,0xaaaaaaaa,0xaeaeaeae,
  0xa2a2a2a2,0xa2a2a2a2,0xa2a2a2a2,
  0x96969696,0x96969696,0x96969696,
  0x86868686,0x8a8a8a8a,0x8a8a8a8a,
  0x79797979,0x7d7d7d7d,0x7d7d7d7d,
  0x69696969,0x69696969,0x69696969,
  0x55555555,0x55555555,0x69696969,
  0xffffffff,0xffffffff,0xffffffff,
  0xcacacaca,0x65656565,0x45454545,
  0xc6c6c6c6,0x39393939,0x49494949,
  0xe7e7e7e7,0x5d5d5d5d,0x69696969,
  0x9a9a9a9a,0x00000000,0xffffffff,
  0x65656565,0x00000000,0xcacacaca,
  0xbabababa,0x75757575,0x00000000,
  0x9a9a9a9a,0x55555555,0x00000000,
  0xffffffff,0xaaaaaaaa,0x55555555,
  0xdfdfdfdf,0x8a8a8a8a,0x45454545,
  0xffffffff,0xffffffff,0x00000000,
  0x65656565,0x8a8a8a8a,0x65656565,
  0x45454545,0xaaaaaaaa,0x75757575,
  0x10101010,0x75757575,0x55555555,
  0x35353535,0x35353535,0x35353535,
  0xefefefef,0xefefefef,0xefefefef,
};
#endif

//Width 35 Height 35 Depth 5 - converting...
#define IMG_CUNDO2_WIDTH        35
#define IMG_CUNDO2_HEIGHT       35
#define IMG_CUNDO2_DEPTH         5
#define IMG_CUNDO2_COMPRESSION   0
#define IMG_CUNDO2_MASKING       2

#ifdef USE_IMG_CUNDO2_HEADER
const struct BitMapHeader IMG_CUndo2_header =
{ 35,35,192,255,5,2,0,0,0,22,22,1024,768 };
#endif

//ifdef USE_IMG_CUNDO2_BODY
const UBYTE IMG_CUndo2_body[1050] = {
0x00,0x02,0x14,0x00,0x00,0x00,0x00,0x00,0x84,0x00,0x00,0x00,0x00,0x07,0xf8,
0x00,0x00,0x00,0x00,0x06,0x9c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x24,0x0c,0x00,0x00,0x00,0x00,0x1f,0x00,0x80,0x00,0x00,0x00,0x3f,0xff,
0x00,0x00,0x00,0x00,0x3f,0x0f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xe0,0x18,0x40,0x00,0x00,0x00,0x7f,0x00,0x60,0x00,0x00,0x00,0xff,0xff,
0x80,0x00,0x00,0x00,0xff,0x1f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xc0,0xe1,0x60,0x00,0x00,0x01,0xfe,0x01,0x70,0x00,0x00,0x01,0xff,0xfe,
0x80,0x00,0x00,0x01,0xfe,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x80,0xe3,0x80,0x00,0x00,0x03,0xfe,0x03,0xf8,0x00,0x00,0x03,0xff,0xfc,
0x00,0x00,0x00,0x03,0xfe,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x06,0x08,0xe9,0x04,0x00,0x00,0x07,0xf2,0xe7,0xf8,0x00,0x00,0x07,0xfc,0xe0,
0x00,0x00,0x00,0x07,0xff,0x1f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0d,0x1f,0xfe,0x3c,0x00,0x00,0x0f,0xdf,0xfe,0xc0,0x00,0x00,0x0f,0xef,0xfe,
0x00,0x00,0x00,0x0f,0xd0,0x01,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0c,0x5f,0xff,0x81,0x00,0x00,0x1f,0x9f,0xff,0x81,0x00,0x00,0x1f,0xdf,0xff,
0x81,0x00,0x00,0x1f,0xe0,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x38,0xff,0xff,0xff,0x80,0x00,0x1f,0x7f,0xff,0xff,0x80,0x00,0x3f,0xff,0xff,
0xff,0x80,0x00,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x20,0xff,0xff,0xfd,0x80,0x00,0x3e,0xff,0x8f,0xff,0x80,0x00,0x3f,0xff,0xff,
0xff,0x80,0x00,0x3e,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
0x60,0xff,0xff,0xfd,0xc0,0x00,0x3e,0xff,0x07,0xff,0xc0,0x00,0x7e,0xff,0xff,
0xff,0xc0,0x00,0x7f,0x00,0xf8,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,0x00,0x00,
0x03,0xff,0xff,0xfc,0x80,0x00,0x7f,0xfa,0x03,0xff,0xc0,0x00,0x7d,0xff,0xff,
0xff,0xc0,0x00,0x7e,0x05,0xfc,0x00,0x00,0x00,0x00,0x05,0xfc,0x00,0x00,0x00,
0x43,0xff,0xff,0xfb,0xc0,0x00,0x73,0xf8,0x01,0xfe,0x00,0x00,0x7f,0xff,0xff,
0xff,0xc0,0x00,0x70,0x07,0xfe,0x00,0x00,0x00,0x00,0x07,0xfe,0x00,0x00,0x00,
0x03,0xff,0xff,0xf8,0xc0,0x00,0x7b,0xf8,0x20,0xff,0x20,0x00,0xff,0xff,0xff,
0xff,0xe0,0x00,0xfc,0x07,0xdf,0x00,0x00,0x00,0x00,0x07,0xdf,0x00,0x00,0x00,
0x03,0xff,0xff,0xfd,0xe0,0x00,0x7f,0xf8,0x73,0xfe,0x00,0x00,0xfb,0xff,0xff,
0xff,0xe0,0x00,0x7c,0x07,0x8c,0x00,0x00,0x00,0x00,0x07,0x8c,0x00,0x00,0x00,
0x03,0xff,0xff,0xff,0xe0,0x00,0x6b,0xf8,0x3f,0xfc,0xe0,0x00,0xfb,0xff,0xff,
0xff,0x00,0x00,0x6c,0x07,0xc0,0x00,0x00,0x00,0x00,0x07,0xc0,0x00,0x00,0x00,
0x07,0xff,0xfc,0x1f,0xe0,0x00,0x8f,0xff,0xfc,0x1d,0xe0,0x00,0xff,0xff,0xff,
0xfe,0x00,0x00,0x88,0x00,0x03,0xe0,0x00,0x00,0x00,0x00,0x03,0xe0,0x00,0x00,
0x67,0xff,0xfc,0x3f,0xe0,0x00,0x07,0xff,0xfc,0x3d,0xe0,0x00,0xff,0xe7,0xff,
0xfe,0x00,0x00,0x60,0x18,0x03,0xc0,0x00,0x00,0x00,0x18,0x03,0xc0,0x00,0x00,
0x67,0xff,0xfc,0x1f,0xe0,0x00,0x07,0xff,0xfc,0x1d,0xe0,0x00,0xff,0xc3,0xff,
0xfe,0x00,0x00,0x60,0x3c,0x03,0xe0,0x00,0x00,0x00,0x3c,0x03,0xe0,0x00,0x00,
0xf3,0xff,0xfc,0x1f,0xe0,0x00,0x03,0xff,0xfc,0x1d,0xe0,0x00,0xfb,0xc3,0xff,
0xfe,0x00,0x00,0xf4,0x3c,0x03,0xe0,0x00,0x00,0x00,0x3c,0x03,0xe0,0x00,0x00,
0x5f,0xff,0xfd,0x0f,0xa0,0x00,0x03,0xff,0xfd,0x09,0xe0,0x00,0xfb,0x87,0xff,
0xfe,0x00,0x00,0xfc,0x78,0x02,0xf0,0x00,0x00,0x00,0x78,0x02,0xf0,0x00,0x00,
0xdb,0xff,0xff,0x8f,0x20,0x00,0x87,0xff,0xff,0x8f,0xe0,0x00,0x7b,0x86,0xff,
0xf8,0x00,0x00,0xfc,0x79,0x00,0x70,0x00,0x00,0x00,0x79,0x00,0x70,0x00,0x00,
0x53,0xff,0xf0,0x0f,0x40,0x00,0x03,0xff,0xf0,0x0f,0x80,0x00,0x7f,0x80,0x7f,
0xf8,0x00,0x00,0x7c,0x7f,0x8f,0xf0,0x00,0x00,0x00,0x7f,0x8f,0xf0,0x00,0x00,
0x0b,0xff,0xf0,0x0f,0xc0,0x00,0x01,0xff,0xf0,0x0f,0x00,0x00,0x7d,0x80,0x3f,
0xf0,0x00,0x00,0x7e,0x7f,0xcf,0xf0,0x00,0x00,0x00,0x7f,0xcf,0xf0,0x00,0x00,
0x41,0xff,0xf0,0x0e,0xc0,0x00,0x43,0xff,0xf0,0x1f,0x40,0x00,0x3d,0xc0,0x7f,
0xf0,0x00,0x00,0x7e,0x3f,0x8f,0xe0,0x00,0x00,0x00,0x3f,0x8f,0xe0,0x00,0x00,
0x03,0xff,0xff,0xfd,0x00,0x00,0x02,0xff,0xff,0xfe,0x00,0x00,0x3c,0xfe,0xff,
0xe0,0x00,0x00,0x3f,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x80,0x00,
0x18,0x7f,0xff,0xfa,0x80,0x00,0x3b,0x7f,0xff,0xfc,0x80,0x00,0x04,0x7f,0xff,
0xc0,0x00,0x00,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,
0x04,0xbf,0xff,0x75,0x00,0x00,0x1f,0x3f,0xff,0xf8,0x00,0x00,0x00,0x3f,0xff,
0x80,0x00,0x00,0x1f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,
0x00,0x5f,0xff,0xe8,0x00,0x00,0x0f,0x9f,0xfe,0xf0,0x00,0x00,0x00,0x1f,0xff,
0x00,0x00,0x00,0x0f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,
0x02,0x3f,0xf7,0xd0,0x00,0x00,0x05,0xcf,0xfa,0xe0,0x00,0x00,0x00,0x0f,0xfd,
0x00,0x00,0x00,0x07,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,
0x02,0xe6,0x0f,0xb0,0x00,0x00,0x00,0x07,0xf1,0xc0,0x00,0x00,0x00,0x07,0xfe,
0x00,0x00,0x00,0x03,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,
0x00,0xdf,0x9f,0x70,0x00,0x00,0x00,0xdf,0xe7,0x80,0x00,0x00,0x00,0xdf,0xf8,
0x00,0x00,0x00,0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xf1,0xfc,0xe0,0x00,0x00,0x00,0xfe,0x0f,0x20,0x00,0x00,0x00,0xff,0xf0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x2f,0xfa,0x80,0x00,0x00,0x00,0x38,0xfd,0x80,0x00,0x00,0x00,0x3f,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xfc,0x00,0x00,0x00,0x00,0x04,0xfc,0x00,0x00,0x00,0x00,0x07,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 };
//endif
