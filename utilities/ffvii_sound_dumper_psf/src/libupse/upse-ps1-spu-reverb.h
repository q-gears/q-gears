/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-spu-reverb.h
 * Purpose: libupse: PS1 SPU reverb header
 *
 * Copyright (c) 2007 William Pitcock <nenolod@sacredspiral.co.uk>
 * Portions copyright (c) 2002 Pete Bernert <BlackDove@addcom.de>
 * Portions copyright (c) 2003 Neill Corlett
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#ifndef _UPSE__LIBUPSE__UPSE_PS1_SPU_REVERB_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_SPU_REVERB_H__GUARD

extern void MixREVERBLeftRight(s32 * oleft, s32 * oright, s32 inleft, s32 inright);

#endif
