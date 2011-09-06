/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-memory-manager.h
 * Purpose: libupse: UPSE PS1 Memory Manager headers
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

#include "config.h"

#ifndef _UPSE__LIBUPSE__UPSE_PS1_MEMORY_MANAGER_H__GUARD
#define _UPSE__LIBUPSE__UPSE_PS1_MEMORY_MANAGER_H__GUARD

#ifdef WORDS_BIGENDIAN
static INLINE u16 BFLIP16(u16 x)
{
    return (((x >> 8) & 0xFF) | ((x & 0xFF) << 8));
}

static INLINE u32 BFLIP32(u32 x)
{
    return (((x >> 24) & 0xFF) | ((x >> 8) & 0xFF00) | ((x << 8) & 0xFF0000) | ((x << 24) & 0xFF000000));
}
#else
static INLINE u16 BFLIP16(u16 x)
{
    return x;
}

static INLINE u32 BFLIP32(u32 x)
{
    return x;
}
#endif

static INLINE s32 BFLIP32S(s32 x)
{
    return (s32) BFLIP32((u32) x);
}

static INLINE s16 BFLIP16S(s16 x)
{
    return (s16) BFLIP16((u16) x);
}

extern char *psxM;
#define psxMu32(mem)	(*(u32*)&psxM[(mem) & 0x1fffff])

extern char *psxP;
extern char *psxR;
#define psxRu32(mem)	(*(u32*)&psxR[(mem) & 0x7ffff])

extern char *psxH;

#define psxHu8(mem)	(*(u8*) &psxH[(mem) & 0xffff])

#define psxHu16(mem)   	(*(u16*)&psxH[(mem) & 0xffff])
#define psxHu32(mem)   	(*(u32*)&psxH[(mem) & 0xffff])

extern char **upse_ps1_memory_LUT;

#define PSXM(mem)		(upse_ps1_memory_LUT[(mem) >> 16] == 0 ? NULL : (void*)(upse_ps1_memory_LUT[(mem) >> 16] + ((mem) & 0xffff)))

#define PSXMu8(mem)	(*(u8 *)PSXM(mem))
#define PSXMu32(mem)    (*(u32*)PSXM(mem))

#define PSXMuR8(mem)        (PSXM(mem)?PSXMu8(mem):0)
#define PSXMuW8(mem,val)    (PSXM(mem)?PSXMu8(mem)=val:;)

int upse_ps1_memory_init();
void upse_ps1_memory_reset();
void upse_ps1_memory_shutdown();

u8 upse_ps1_memory_read_8(u32 mem);
u16 upse_ps1_memory_read_16(u32 mem);
u32 upse_ps1_memory_read_32(u32 mem);
void upse_ps1_memory_write_8(u32 mem, u8 value);
void upse_ps1_memory_write_16(u32 mem, u16 value);
void upse_ps1_memory_write_32(u32 mem, u32 value);

void LoadPSXMem(u32 address, s32 length, unsigned char *data);

#endif /* __PSXMEMORY_H__ */
