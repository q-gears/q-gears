/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-string.h
 * Purpose: libupse: string utility function header
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

#ifndef __UPSE__LIBUPSE__UPSE_STRING_H__GUARD
#define __UPSE__LIBUPSE__UPSE_STRING_H__GUARD

#include "upse.h"
#include "upse-string.h"

/*
 * fgets() wrapper - inefficient, but it will do.
 */
char *upse_io_fgets(char *s, int n, void *stream, upse_iofuncs_t * iofuncs);

#endif
