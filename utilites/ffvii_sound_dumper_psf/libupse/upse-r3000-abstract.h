/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-r3000-abstract.h
 * Purpose: libupse: r3K abstract implementation factory headers
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

#ifndef _UPSE__LIBUPSE__UPSE_R3000_ABSTRACT_H__GUARD
#define _UPSE__LIBUPSE__UPSE_R3000_ABSTRACT_H__GUARD

#include <stdio.h>

#include "upse-internal.h"

typedef union
{
    struct
    {
	u32 r0, at, v0, v1, a0, a1, a2, a3, t0, t1, t2, t3, t4, t5, t6, t7, s0, s1, s2, s3, s4, s5, s6, s7, t8, t9, k0, k1, gp, sp, s8, ra, lo, hi;
    } n upse_packed_t;
    u32 r[34];			/* Lo, Hi in r[33] and r[34] */
} psxGPRRegs;

typedef union
{
    struct
    {
	u32 Index, Random, EntryLo0, EntryLo1,
	    Context, PageMask, Wired, Reserved0,
	    BadVAddr, Count, EntryHi, Compare,
	    Status, Cause, EPC, PRid, Config, LLAddr, WatchLO, WatchHI, XContext, Reserved1, Reserved2, Reserved3, Reserved4, Reserved5, ECC, CacheErr, TagLo, TagHi, ErrorEPC, Reserved6;
    } n upse_packed_t;
    u32 r[32];
} psxCP0Regs;

typedef struct
{
    psxGPRRegs GPR;		/* General Purpose Registers */
    psxCP0Regs CP0;		/* Coprocessor0 Registers */
    u32 pc;			/* Program counter */
    u32 code;			/* The instruction */
    u32 cycle;
    u32 interrupt;
} upse_r3000_cpu_registers_t;

extern upse_r3000_cpu_registers_t upse_r3000_cpu_regs;

#define _i32(x) (s32)x
#define _u32(x) (u32)x

#define _i16(x) (s16)x
#define _u16(x) (u32)x

#define _i8(x) (s8)x
#define _u8(x) (u8)x

/**** R3000A Instruction Macros ****/
#define _PC_       upse_r3000_cpu_regs.pc	// The next PC to be executed

#define _Funct_  ((upse_r3000_cpu_regs.code      ) & 0x3F)	// The funct part of the instruction register
#define _Rd_     ((upse_r3000_cpu_regs.code >> 11) & 0x1F)	// The rd part of the instruction register
#define _Rt_     ((upse_r3000_cpu_regs.code >> 16) & 0x1F)	// The rt part of the instruction register
#define _Rs_     ((upse_r3000_cpu_regs.code >> 21) & 0x1F)	// The rs part of the instruction register
#define _Sa_     ((upse_r3000_cpu_regs.code >>  6) & 0x1F)	// The sa part of the instruction register
#define _Im_     ((u16)upse_r3000_cpu_regs.code)	// The immediate part of the instruction register
#define _Target_ (upse_r3000_cpu_regs.code & 0x03ffffff)	// The target part of the instruction register

#define _Imm_	((s16)upse_r3000_cpu_regs.code)	// sign-extended immediate
#define _ImmU_	(upse_r3000_cpu_regs.code&0xffff)	// zero-extended immediate

#define _rRs_   upse_r3000_cpu_regs.GPR.r[_Rs_]	// Rs register
#define _rRt_   upse_r3000_cpu_regs.GPR.r[_Rt_]	// Rt register
#define _rRd_   upse_r3000_cpu_regs.GPR.r[_Rd_]	// Rd register
#define _rSa_   upse_r3000_cpu_regs.GPR.r[_Sa_]	// Sa register
#define _rFs_   upse_r3000_cpu_regs.CP0.r[_Rd_]	// Fs register

#define _c2dRs_ upse_r3000_cpu_regs.CP2D.r[_Rs_]	// Rs cop2 data register
#define _c2dRt_ upse_r3000_cpu_regs.CP2D.r[_Rt_]	// Rt cop2 data register
#define _c2dRd_ upse_r3000_cpu_regs.CP2D.r[_Rd_]	// Rd cop2 data register
#define _c2dSa_ upse_r3000_cpu_regs.CP2D.r[_Sa_]	// Sa cop2 data register

#define _rHi_   upse_r3000_cpu_regs.GPR.n.hi	// The HI register
#define _rLo_   upse_r3000_cpu_regs.GPR.n.lo	// The LO register

#define _JumpTarget_    ((_Target_ * 4) + (_PC_ & 0xf0000000))	// Calculates the target during a jump instruction
#define _BranchTarget_  ((s16)_Im_ * 4 + _PC_)	// Calculates the target during a branch instruction

#define _SetLink(x)     upse_r3000_cpu_regs.GPR.r[x] = _PC_ + 4;	// Sets the return address in the link register

int psxInit();
void psxReset();
void psxShutdown();
void psxException(u32 code, u32 bd);
void psxBranchTest();
void psxExecuteBios();

int upse_r3000_cpu_init(void);
void upse_r3000_cpu_reset(void);
void upse_r3000_cpu_execute(void);
void upse_r3000_cpu_execute_block(void);
void upse_r3000_cpu_clear(u32 Addr, u32 Size);
void upse_r3000_cpu_shutdown(void);

#endif /* __R3000A_H__ */
