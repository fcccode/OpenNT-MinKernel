/***
*fsetpos.c - Contains fsetpos runtime
*
*       Copyright (c) 1987-1995, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Fsetpos sets the file position using an internal value returned by an
*       earlier fgetpos call.
*
*Revision History:
*       01-16-87  JCR   Module created
*       04-13-87  JCR   Added const to declaration
*       12-11-87  JCR   Added "_LOAD_DS" to declaration
*       02-15-90  GJF   Fixed copyright and indents
*       03-19-90  GJF   Replaced _LOAD_DS with _CALLTYPE1 and added #include
*                       <cruntime.h>.
*       10-02-90  GJF   New-style function declarators.
*       04-06-93  SKS   Replace _CRTAPI* with __cdecl
*       12-23-94  GJF   Use 64-bit file position (_fseeki64) for non-_MAC_.
*       01-05-94  GJF   Temporarily commented out above change due to MFC/IDE
*                       bugs.
*       01-24-95  GJF   Restored 64-bit fpos_t support.
*
*******************************************************************************/

#include <cruntime.h>
#include <stdio.h>
#include <internal.h>

/***
*int fsetpos(stream,pos) - Set file positioning
*
*Purpose:
*       Fsetpos sets the file position for the file indicated by [stream] to
*       the position indicated by [pos].  The [pos] value is defined to be in
*       an internal format (not to be interpreted by the user) and has been
*       generated by an earlier fgetpos call.
*
*Entry:
*       FILE *stream = pointer to a file stream value
*       fpos_t *pos = pointer to a file positioning value
*
*Exit:
*       Successful call returns 0.
*       Unsuccessful call returns non-zero (!0).
*
*Exceptions:
*       None.
*******************************************************************************/

int __cdecl fsetpos (
        FILE *stream,
        const fpos_t *pos
        )
{
#if     defined(_M_M68K) || defined(_M_MPPC) || defined(_POSIX_)
        return( fseek(stream, *pos, SEEK_SET) );
#else   /* !defined(_M_M68K) && !defined(_M_MPPC) */
        return( _fseeki64(stream, *pos, SEEK_SET) );
#endif  /* defined(_M_M68K) || defined(_M_MPPC) */
}