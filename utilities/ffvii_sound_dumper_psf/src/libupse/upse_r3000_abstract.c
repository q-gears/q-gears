/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_r3000_abstract.c
 * Purpose: libupse: r3K abstract implementation factory
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "upse-internal.h"

upse_r3000_cpu_registers_t upse_r3000_cpu_regs;

int psxInit()
{
    if (upse_ps1_memory_init() == -1)
	return -1;

    return upse_r3000_cpu_init();
}

void psxReset()
{
    upse_r3000_cpu_reset();
    upse_ps1_memory_reset();

    memset(&upse_r3000_cpu_regs, 0, sizeof(upse_r3000_cpu_regs));

    upse_r3000_cpu_regs.pc = 0xbfc00000;	// Start in bootstrap
    upse_r3000_cpu_regs.CP0.r[12] = 0x10900000;	// COP0 enabled | BEV = 1 | TS = 1
    upse_r3000_cpu_regs.CP0.r[15] = 0x00000002;	// PRevID = Revision ID, same as R3000A

    upse_ps1_hal_reset();
    upse_ps1_bios_init();

    /* start up the bios */
    if (upse_has_custom_bios())
        psxExecuteBios();
}

void psxShutdown()
{
    upse_ps1_memory_shutdown();
    upse_ps1_bios_shutdown();

    upse_r3000_cpu_shutdown();
    SPUclose();
}

void psxException(u32 code, u32 bd)
{
    // Set the Cause
    upse_r3000_cpu_regs.CP0.n.Cause = code;

#ifdef PSXCPU_LOG
    if (bd)
	PSXCPU_LOG("bd set\n");
#endif
    // Set the EPC & PC
    if (bd)
    {
	upse_r3000_cpu_regs.CP0.n.Cause |= 0x80000000;
	upse_r3000_cpu_regs.CP0.n.EPC = (upse_r3000_cpu_regs.pc - 4);
    }
    else
	upse_r3000_cpu_regs.CP0.n.EPC = (upse_r3000_cpu_regs.pc);

    if (upse_r3000_cpu_regs.CP0.n.Status & 0x400000)
	upse_r3000_cpu_regs.pc = 0xbfc00180;
    else
	upse_r3000_cpu_regs.pc = 0x80000080;

    // Set the Status
    upse_r3000_cpu_regs.CP0.n.Status = (upse_r3000_cpu_regs.CP0.n.Status & ~0x3f) | ((upse_r3000_cpu_regs.CP0.n.Status & 0xf) << 2);

    if (!upse_has_custom_bios())
        upse_ps1_bios_exception();
}

void psxBranchTest()
{
    if ((upse_r3000_cpu_regs.cycle - psxNextsCounter) >= psxNextCounter)
	psxRcntUpdate();

    if (psxHu32(0x1070) & psxHu32(0x1074))
    {
	if ((upse_r3000_cpu_regs.CP0.n.Status & 0x401) == 0x401)
	{
	    psxException(0x400, 0);
	}
    }

}
void psxExecuteBios()
{
    while (upse_r3000_cpu_regs.pc != 0x80030000)
        upse_r3000_cpu_execute_block();
}
