/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$

    Desc: Scan a stream and write the result in the parameters
    Lang: english
*/
/* Original source from libnix */
#define AROS_ALMOST_COMPATIBLE

/*****************************************************************************

    NAME */
#include <stdio.h>
#include <stdarg.h>

	int vfscanf (

/*  SYNOPSIS */
	FILE	   * stream,
	const char * format,
	va_list      args)

/*  FUNCTION
	Read the scream, scan it as the format specified and write the
	result of the conversion into the specified arguments.

    INPUTS
	stream - A stream to read from
	format - A scanf() format string.
	args - A list of arguments for the results.

    RESULT
	The number of converted arguments.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY
	28.01.1997 digulla created

******************************************************************************/
{
    return __vcscan (stream, (void *)fgetc, (void *)ungetc, format, args);
} /* vfscanf */
