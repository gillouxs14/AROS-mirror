/*
    (C) 1995-96 AROS - The Amiga Research OS
    $Id$

    Desc: Make a font public available
    Lang: english
*/
#include "graphics_intern.h"
#include <proto/exec.h>

/*****************************************************************************

    NAME */
#include <graphics/text.h>
#include <proto/graphics.h>

	AROS_LH1(void, AddFont,

/*  SYNOPSIS */
	AROS_LHA(struct TextFont *, textFont, A1),

/*  LOCATION */
	struct GfxBase *, GfxBase, 80, Graphics)

/*  FUNCTION
	Add a font to the list of public fonts. After that, you can
	open the font with OpenFont().

    INPUTS
	textFont - The font to add.

    RESULT
	None.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	OpenFont(), RemFont(), CloseFont(), SetFont()

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct GfxBase *,GfxBase)

    Forbid();
    AddHead (&GfxBase->TextFonts, (struct Node *)textFont);
    Permit();
    

    AROS_LIBFUNC_EXIT
} /* AddFont */
