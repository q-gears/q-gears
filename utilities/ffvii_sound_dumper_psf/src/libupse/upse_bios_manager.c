/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_bios_manager.c
 * Purpose: libupse: BIOS management functions.
 *
 * Copyright (c) 2008 William Pitcock <nenolod@sacredspiral.co.uk>
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#include "upse-internal.h"

static const char *bios_ = NULL;

int
upse_has_custom_bios(void)
{
    return bios_ != NULL;
}

const char *
upse_get_custom_bios(void)
{
    return bios_;
}

void
upse_set_custom_bios(const char *bios)
{
    bios_ = bios;
}
