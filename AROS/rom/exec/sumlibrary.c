/*
    $Id$
    $Log$
    Revision 1.1  1996/07/28 16:37:24  digulla
    Initial revision

    Desc:
    Lang: english
*/
#include <exec/execbase.h>
#include <exec/alerts.h>
#include <aros/libcall.h>

/*****************************************************************************

    NAME */
	#include <clib/exec_protos.h>

	__AROS_LH1(void, SumLibrary,

/*  SYNOPSIS */
	__AROS_LA(struct Library *, library,A1),

/*  LOCATION */
	struct ExecBase *, SysBase, 71, Exec)

/*  FUNCTION
	Builds the checksum over a given library's jumptable and either puts
	it into the library->lib_Sum field (if the library is marked as changed)
	or compares it with this field and Alert()s at mismatch.

    INPUTS
	library - Pointer to library structure.

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	AddLibrary(), RemLibrary(), MakeLibrary(), MakeFunctions(), InitStruct().

    INTERNALS

    HISTORY

******************************************************************************/
{
    __AROS_FUNC_INIT

    UBYTE oldflags;
    ULONG sum;

    /* Arbitrate for library base */
    Forbid();

    /*
	If the library checksumming is already in progress or if the
	checksum is unused skip this part
    */
    if(library->lib_Flags&LIBF_SUMUSED&&!(library->lib_Flags&LIBF_SUMMING))
    {
	/* As long as the library is marked as changed */
	do
	{
	    ULONG *lp;

	    /* Memorize library flags */
	    oldflags=library->lib_Flags;

	    /* Tell other tasks: Summing in progress */
	    library->lib_Flags|=LIBF_SUMMING;
	    library->lib_Flags&=~LIBF_CHANGED;

	    /* As long as the summing goes multitasking may be permitted. */
	    Permit();

	    /* Build checksum. Note: library bases are LONG aligned */
	    sum=0;
	    /* Get start of jumptable */
	    lp=(ULONG *)((UBYTE *)library+library->lib_NegSize);
	    /* And sum it up */
	    while(lp<(ULONG *)library)
		sum+=*lp++;

	    /* Summing complete. Arbitrate again. */
	    Forbid();

	    /* Remove summing flag */
	    library->lib_Flags&=~LIBF_SUMMING;

	    /* Do it again if the library changed while summing. */
	}while(library->lib_Flags&LIBF_CHANGED);

	/*
	    Alert() if the library wasn't marked as changed and if the
	    checksum mismatches.
	*/
	if(!(oldflags&LIBF_CHANGED)&&library->lib_Sum!=sum)
	    Alert(AT_DeadEnd|AN_LibChkSum);

	/* Set new checksum */
	library->lib_Sum=sum;
    }

    /* All done. */
    Permit();
    __AROS_FUNC_EXIT
} /* SumLibrary */

