/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_ps1_executive.c
 * Purpose: libupse: PS1 application executive (lowlevel "Kernel")
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

#include "upse-internal.h"

/* tracing */
#ifdef UPSE_TRACE
# define _TRACE(...) _MESSAGE("TRACE", __VA_ARGS__)
#else
# define _TRACE(...) {}
#endif

#define _CALL(id, idN) do { _TRACE("call<%s> %s<%p> [0x%x]", #id, idN[call], id[call], call); id[call](); } while(0)
#define _UNIMPLEMENTED(id, idN) do { _WARN("call<%s> %s<%p> [0x%x]", #id, idN[call], id[call], call); } while(0)

static void upse_ps1_executive_dummy(void)
{
    upse_r3000_cpu_regs.pc = upse_r3000_cpu_regs.GPR.n.ra;

    psxBranchTest();
}

static void upse_ps1_executive_run_bios_A0(void)
{
    u32 call = upse_r3000_cpu_regs.GPR.n.t1 & 0xff;

    if (biosA0[call])
	_CALL(biosA0, biosA0n);
    else
	_UNIMPLEMENTED(biosA0, biosA0n);

    psxBranchTest();
}

static void upse_ps1_executive_run_bios_B0(void)
{
    u32 call = upse_r3000_cpu_regs.GPR.n.t1 & 0xff;

    if (biosB0[call])
	_CALL(biosB0, biosB0n);
    else
	_UNIMPLEMENTED(biosB0, biosB0n);

    psxBranchTest();
}

static void upse_ps1_executive_run_bios_C0()
{
    u32 call = upse_r3000_cpu_regs.GPR.n.t1 & 0xff;

    if (biosC0[call])
	_CALL(biosC0, biosC0n);
    else
	_UNIMPLEMENTED(biosC0, biosC0n);

    psxBranchTest();
}

static void upse_ps1_executive_bootstrap(void)
{				// 0xbfc00000
}

typedef struct
{
    u32 _pc0;
    u32 gp0;
    u32 t_addr;
    u32 t_size;
    u32 d_addr;
    u32 d_size;
    u32 b_addr;
    u32 b_size;
    u32 s_addr;
    u32 s_size;
    u32 _sp, _fp, _gp, ret, base;
} upse_packed_t upse_ps1_executive_exec_record_t;

static void upse_ps1_executive_task_switch(void)
{
    upse_ps1_executive_exec_record_t *header = (upse_ps1_executive_exec_record_t *) PSXM(upse_r3000_cpu_regs.GPR.n.s0);

    //SysPrintf("ExecRet %x: %x\n", upse_r3000_cpu_regs.GPR.n.s0, header->ret);

    upse_r3000_cpu_regs.GPR.n.ra = BFLIP32(header->ret);
    upse_r3000_cpu_regs.GPR.n.sp = BFLIP32(header->_sp);
    upse_r3000_cpu_regs.GPR.n.s8 = BFLIP32(header->_fp);
    upse_r3000_cpu_regs.GPR.n.gp = BFLIP32(header->_gp);
    upse_r3000_cpu_regs.GPR.n.s0 = BFLIP32(header->base);

    upse_r3000_cpu_regs.GPR.n.v0 = 1;
    upse_r3000_cpu_regs.pc = upse_r3000_cpu_regs.GPR.n.ra;
}

void (*psxHLEt[256])(void) =
{
    upse_ps1_executive_dummy,
    upse_ps1_executive_run_bios_A0,
    upse_ps1_executive_run_bios_B0,
    upse_ps1_executive_run_bios_C0,
    upse_ps1_executive_bootstrap,
    upse_ps1_executive_task_switch
};
