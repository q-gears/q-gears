/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-hal.h
 * Purpose: libupse: PS1 HAL implementation header
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

#ifndef _UPSE__LIBUPSE__UPSE_PS1_HAL_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_HAL_H__GUARD

void upse_ps1_hal_reset();
u8 upse_ps1_hal_read_8(u32 add);
u16 upse_ps1_hal_read_16(u32 add);
u32 upse_ps1_hal_read_32(u32 add);
void upse_ps1_hal_write_8(u32 add, u8 value);
void upse_ps1_hal_write_16(u32 add, u16 value);
void upse_ps1_hal_write_32(u32 add, u32 value);

#endif
