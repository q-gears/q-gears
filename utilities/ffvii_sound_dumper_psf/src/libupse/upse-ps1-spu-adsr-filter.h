/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-spu-adsr-filter.h
 * Purpose: libupse: PS1 SPU ADSR filter header
 *
 * Copyright (c) 2007 William Pitcock <nenolod@sacredspiral.co.uk>
 * Portions copyright (c) 2002 Pete Bernert <BlackDove@addcom.de>
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#ifndef _UPSE__LIBUPSE__UPSE_PS1_SPU_ADSR_FILTER_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_SPU_ADSR_FILTER_H__GUARD

void InitADSR(void);
void StartADSR(int ch);
int MixADSR(int ch);

#endif
