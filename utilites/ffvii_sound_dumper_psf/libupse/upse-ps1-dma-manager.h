/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-dma-manager.h
 * Purpose: libupse: UPSE PS1 DMA Manager headers           
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

#ifndef _UPSE__LIBUPSE__UPSE_PS1_DMA_MANAGER_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_DMA_MANAGER_H__GUARD

void psxDma2(u32 madr, u32 bcr, u32 chcr);

void psxDma3(u32 madr, u32 bcr, u32 chcr);

void psxDma4(u32 madr, u32 bcr, u32 chcr);

void psxDma6(u32 madr, u32 bcr, u32 chcr);

#endif
