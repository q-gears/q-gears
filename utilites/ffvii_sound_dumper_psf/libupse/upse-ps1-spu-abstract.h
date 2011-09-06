/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_util.c
 * Purpose: libupse: PS1 SPU abstraction
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

#ifndef _UPSE__LIBUPSE__UPSE_PS1_SPU_ABSTRACT_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_SPU_ABSTRACT_H__GUARD

#define H_SPUirqAddr     0x0da4
#define H_SPUaddr        0x0da6
#define H_SPUdata        0x0da8
#define H_SPUctrl        0x0daa
#define H_SPUstat        0x0dae
#define H_SPUon1         0x0d88
#define H_SPUon2         0x0d8a
#define H_SPUoff1        0x0d8c
#define H_SPUoff2        0x0d8e


void SPUirq(void);
u16 SPUreadRegister(u32 reg);
void SPUwriteRegister(u32 reg, u16 val);
int SPUasync(u32 cycle);
void SPUwriteDMAMem(u32 usPSXMem, int iSize);
void SPUreadDMAMem(u32 usPSXMem, int iSize);


#endif
