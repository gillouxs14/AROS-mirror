/*
    (C) 2000 AROS - The Amiga Research OS
    $Id$

    Desc: Graphics function MrgCop()
    Lang: english
*/
#include <graphics/view.h>

/*****************************************************************************

    NAME */
#include <proto/graphics.h>

        AROS_LH1(ULONG, MrgCop,

/*  SYNOPSIS */
        AROS_LHA(struct View *, view, A1),

/*  LOCATION */
        struct GfxBase *, GfxBase, 35, Graphics)

/*  FUNCTION

    INPUTS
        view -

    RESULT
        error -

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY


******************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct GfxBase *,GfxBase)

#warning TODO: Write graphics/MrgCop()
    aros_print_not_implemented ("MrgCop");

    return MCOP_NO_MEM;

    AROS_LIBFUNC_EXIT
} /* MrgCop */
