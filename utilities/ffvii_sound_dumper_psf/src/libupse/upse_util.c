/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_util.c
 * Purpose: libupse: utility functions
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "upse-internal.h"
#include "upse.h"
#include "upse-string.h"

void upse_execute(void)
{
    _ENTER;

    upse_r3000_cpu_execute();

    _LEAVE;
}
