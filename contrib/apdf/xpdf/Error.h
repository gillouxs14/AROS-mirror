//========================================================================
//
// Error.h
//
// Copyright 1996-2003 Glyph & Cog, LLC
//
//========================================================================

#ifndef ERROR_H
#define ERROR_H

#include <aconf.h>

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include <stdio.h>
#include "config.h"

// EL: extern "C" added, since I want to use this function
// for errors in T1lib and FreeType too.
extern "C" void CDECL error(int pos, char *msg, ...);

#endif