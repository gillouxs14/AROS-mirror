/***************************************************************************

 NListviews.mcp - New Listview MUI Custom Class Preferences
 Registered MUI class, Serial Number: 1d51 (0x9d510001 to 0x9d51001F
                                            and 0x9d510101 to 0x9d51013F)

 Copyright (C) 1996-2001 by Gilles Masson
 Copyright (C) 2001-2013 by NList Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 NList classes Support Site:  http://www.sf.net/projects/nlist-classes

 $Id$

***************************************************************************/

#if !defined(__MORPHOS__)
// uncompressed ARGB data
extern const unsigned long icon32[];
#define ICON32_WIDTH  24
#define ICON32_HEIGHT 20
#define ICON32_DEPTH  32
#else
// bzip2 compressed ARGB data
extern const unsigned char icon32[];
#endif

#ifdef USE_ICON8_COLORS
const ULONG icon8_colors[24] =
{
	0xadadadad,0xadadadad,0xadadadad,
	0x7b7b7b7b,0x7b7b7b7b,0x7b7b7b7b,
	0x3b3b3b3b,0x67676767,0xa2a2a2a2,
	0xadadadad,0xadadadad,0xadadadad,
	0xadadadad,0xadadadad,0xadadadad,
	0xadadadad,0xadadadad,0xadadadad,
	0xffffffff,0xffffffff,0xffffffff,
	0x00000000,0x00000000,0x00000000,
};
#endif

#define ICON8_WIDTH        24
#define ICON8_HEIGHT       14
#define ICON8_DEPTH         3
#define ICON8_COMPRESSION   0
#define ICON8_MASKING       2

#ifdef USE_ICON8_HEADER
const struct BitMapHeader icon8_header =
{ 23,14,0,0,3,2,0,0,0,44,44,320,256 };
#endif

#ifdef USE_ICON8_BODY
const UBYTE icon8_body[168] = {
0x00,0x00,0x44,0x00,0xff,0xff,0xb8,0x00,0xff,0xff,0xb8,0x00,0x00,0x00,0x00,
0x00,0x80,0x00,0x64,0x00,0xff,0xff,0xb8,0x00,0x3b,0xb8,0x46,0x00,0x80,0x00,
0x64,0x00,0xc4,0x47,0xfc,0x00,0x00,0x00,0x46,0x00,0x80,0x00,0x64,0x00,0xff,
0xff,0xfc,0x00,0x36,0xd8,0x46,0x00,0x80,0x00,0x64,0x00,0xc9,0x27,0xfc,0x00,
0x00,0x00,0x46,0x00,0x80,0x00,0x64,0x00,0xff,0xff,0xfc,0x00,0x3d,0xe8,0x6e,
0x00,0x80,0x00,0x5c,0x00,0xc2,0x17,0xcc,0x00,0x00,0x00,0x46,0x00,0x80,0x00,
0x78,0x00,0xff,0xff,0xf8,0x00,0x00,0x00,0x40,0x00,0x80,0x00,0x64,0x00,0xff,
0xff,0xf8,0x00,0xbf,0xff,0xee,0x00,0x7f,0xff,0xdc,0x00,0x3f,0xff,0xcc,0x00,
0x00,0x44,0x46,0x00,0xff,0xbb,0xb8,0x00,0xff,0xbb,0xb8,0x00,0x00,0x00,0x00,
0x00,0x80,0x66,0x64,0x00,0xff,0xbb,0xb8,0x00,0xbf,0xee,0xee,0x00,0x7f,0xdd,
0xdc,0x00,0x3f,0xcc,0xcc,0x00,0x3f,0xee,0xee,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00, };
#endif