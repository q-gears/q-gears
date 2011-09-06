/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_string.c
 * Purpose: libupse: string utility functions
 *
 * Copyright (c) 2007 William Pitcock <nenolod@sacredspiral.co.uk>
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#include "upse.h"
#include "upse-string.h"

/*
 * fgets() wrapper - inefficient, but it will do.
 */
char *upse_io_fgets(char *s, int n, void *stream, upse_iofuncs_t * iofuncs)
{
    int c;
    register char *p;

    if (n <= 0)
	return NULL;

    p = s;

    while (--n)
    {
	if (iofuncs->read_impl(&c, 1, 1, stream) == 0)
	{
	    break;
	}
	if ((*p++ = c) == '\n')
	{
	    break;
	}
    }
    if (p > s)
    {
	*p = 0;
	return s;
    }

    return NULL;
}
