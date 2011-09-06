/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-bios-base.h
 * Purpose: libupse: UPSE PS1 FakeBIOS public header
 *
 * Copyright (c) 2007 William Pitcock <nenolod@sacredspiral.co.uk>
 * Portions copyright (c) 1999-2002 Pcsx Team
 * Portions copyright (c) 2004 "Xodnizel"
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#ifndef _UPSE__LIBUPSE__UPSE_PS1_BIOS_BASE_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_BIOS_BASE_H__GUARD

/* these are for tracing in the executive layer --nenolod */
extern char *biosA0n[256];
extern char *biosB0n[256];
extern char *biosC0n[256];

void upse_ps1_bios_init(void);
void upse_ps1_bios_shutdown(void);
void upse_ps1_bios_exception(void);

extern void (*biosA0[256]) (void);
extern void (*biosB0[256]) (void);
extern void (*biosC0[256]) (void);

#endif
