/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_ps1_counters.c
 * Purpose: libupse: PS1 timekeeping implementation
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

#include <string.h>

#include "upse-internal.h"

psxCounter psxCounters[5];

u32 psxNextCounter, psxNextsCounter;

static int cnts = 4;
static u32 last = 0;

static void psxRcntUpd(u32 index)
{
    psxCounters[index].sCycle = upse_r3000_cpu_regs.cycle;
    if (((!(psxCounters[index].mode & 1)) || (index != 2)) && psxCounters[index].mode & 0x30)
    {
	if (psxCounters[index].mode & 0x10)
	{			// Interrupt on target
	    psxCounters[index].Cycle = ((psxCounters[index].target - psxCounters[index].count) * psxCounters[index].rate) / BIAS;
	}
	else
	{			// Interrupt on 0xffff
	    psxCounters[index].Cycle = ((0xffff - psxCounters[index].count) * psxCounters[index].rate) / BIAS;
	}
    }
    else
	psxCounters[index].Cycle = 0xffffffff;
}

static void psxRcntReset(u32 index)
{
    psxCounters[index].count = 0;
    psxRcntUpd(index);

    psxHu32(0x1070) |= BFLIP32(psxCounters[index].interrupt);
    if (!(psxCounters[index].mode & 0x40))
    {				// Only 1 interrupt
	psxCounters[index].Cycle = 0xffffffff;
    }
}

static void psxRcntSet()
{
    int i;

    psxNextCounter = 0x7fffffff;
    psxNextsCounter = upse_r3000_cpu_regs.cycle;

    for (i = 0; i < cnts; i++)
    {
	s32 count;

	if (psxCounters[i].Cycle == 0xffffffff)
	    continue;

	count = psxCounters[i].Cycle - (upse_r3000_cpu_regs.cycle - psxCounters[i].sCycle);

	if (count < 0)
	{
	    psxNextCounter = 0;
	    break;
	}

	if (count < (s32) psxNextCounter)
	{
	    psxNextCounter = count;
	}
    }
}

void psxRcntInit()
{

    memset(psxCounters, 0, sizeof(psxCounters));

    psxCounters[0].rate = 1;
    psxCounters[0].interrupt = 0x10;
    psxCounters[1].rate = 1;
    psxCounters[1].interrupt = 0x20;
    psxCounters[2].rate = 1;
    psxCounters[2].interrupt = 64;

    psxCounters[3].interrupt = 1;
    psxCounters[3].mode = 0x58;	// The VSync counter mode
    psxCounters[3].target = 1;
    psxUpdateVSyncRate();

    cnts = 4;

    psxRcntUpd(0);
    psxRcntUpd(1);
    psxRcntUpd(2);
    psxRcntUpd(3);
    psxRcntSet();
    last = 0;
}


int CounterSPURun(void)
{
    u32 cycles;

    if (upse_r3000_cpu_regs.cycle < last)
    {
	cycles = 0xFFFFFFFF - last;
	cycles += upse_r3000_cpu_regs.cycle;
    }
    else
	cycles = upse_r3000_cpu_regs.cycle - last;

    if (cycles >= 16)
    {
	if (!SPUasync(cycles))
	    return (0);
	last = upse_r3000_cpu_regs.cycle;
    }
    return (1);
}

/* Set by spu irq stuff in spu code to number of cpu cycles to back
   up(if necessary).  Very crazy hack.  Eh, not implemented.  Hmm.
   TODO!
*/
s32 spuirqvoodoo = -1;

void CounterDeadLoopSkip()
{
    s32 min, x, lmin;

    lmin = 0x7FFFFFFF;

    for (x = 0; x < 4; x++)
    {
	if (psxCounters[x].Cycle != 0xffffffff)
	{
	    min = psxCounters[x].Cycle;
	    min -= (upse_r3000_cpu_regs.cycle - psxCounters[x].sCycle);
	    if (min < lmin)
		lmin = min;
//        if(min<0) exit();
//        printf("Poo: %d, ",min);
	}
    }

    if (lmin > 0)
    {
//       printf("skip %u\n",lmin);
	upse_r3000_cpu_regs.cycle += lmin;
    }
}

void psxUpdateVSyncRate()
{
    //if (Config.PsxType) // ntsc - 0 | pal - 1
    //     psxCounters[3].rate = (PSXCLK / 50);// / BIAS;
    //else
    psxCounters[3].rate = (PSXCLK / 60);	// / BIAS;
}

void psxRcntUpdate()
{
    if ((upse_r3000_cpu_regs.cycle - psxCounters[3].sCycle) >= psxCounters[3].Cycle)
    {
	//printf("%d\n",(upse_r3000_cpu_regs.cycle - psxCounters[3].sCycle)- psxCounters[3].Cycle);
	psxRcntUpd(3);
	psxHu32(0x1070) |= BFLIP32(1);
    }
    if ((upse_r3000_cpu_regs.cycle - psxCounters[0].sCycle) >= psxCounters[0].Cycle)
    {
	psxRcntReset(0);
    }

    if ((upse_r3000_cpu_regs.cycle - psxCounters[1].sCycle) >= psxCounters[1].Cycle)
    {
	psxRcntReset(1);
    }

    if ((upse_r3000_cpu_regs.cycle - psxCounters[2].sCycle) >= psxCounters[2].Cycle)
    {
	psxRcntReset(2);
    }

    psxRcntSet();
}

void psxRcntWcount(u32 index, u32 value)
{
    psxCounters[index].count = value;
    psxRcntUpd(index);
    psxRcntSet();
}

void psxRcntWmode(u32 index, u32 value)
{
    psxCounters[index].mode = value;
    psxCounters[index].count = 0;

    if (index == 0)
    {
	switch (value & 0x300)
	{
	  case 0x100:
	      psxCounters[index].rate = ((psxCounters[3].rate /** BIAS*/ ) / 386) / 262;	// seems ok
	      break;
	  default:
	      psxCounters[index].rate = 1;
	}
    }
    else if (index == 1)
    {
	switch (value & 0x300)
	{
	  case 0x100:
	      psxCounters[index].rate = (psxCounters[3].rate /** BIAS*/ ) / 262;	// seems ok
	      //psxCounters[index].rate = (PSXCLK / 60)/262; //(psxCounters[3].rate*16/262);
	      //printf("%d\n",psxCounters[index].rate);
	      break;
	  default:
	      psxCounters[index].rate = 1;
	}
    }
    else if (index == 2)
    {
	switch (value & 0x300)
	{
	  case 0x200:
	      psxCounters[index].rate = 8;	// 1/8 speed
	      break;
	  default:
	      psxCounters[index].rate = 1;	// normal speed
	}
    }

    // Need to set a rate and target
    psxRcntUpd(index);
    psxRcntSet();
}

void psxRcntWtarget(u32 index, u32 value)
{
//      SysPrintf("writeCtarget[%ld] = %lx\n", index, value);
    psxCounters[index].target = value;
    psxRcntUpd(index);
    psxRcntSet();
}

u32 psxRcntRcount(u32 index)
{
    u32 ret;

//      if ((!(psxCounters[index].mode & 1)) || (index!=2)) {
    if (psxCounters[index].mode & 0x08)
    {				// Wrap at target
	//if (Config.RCntFix) { // Parasite Eve 2
	//      ret = (psxCounters[index].count + /*BIAS **/ ((upse_r3000_cpu_regs.cycle - psxCounters[index].sCycle) / psxCounters[index].rate)) & 0xffff;
	//} else {
	ret = (psxCounters[index].count + BIAS * ((upse_r3000_cpu_regs.cycle - psxCounters[index].sCycle) / psxCounters[index].rate)) & 0xffff;
	//}
    }
    else
    {				// Wrap at 0xffff
	ret = (psxCounters[index].count + BIAS * (upse_r3000_cpu_regs.cycle / psxCounters[index].rate)) & 0xffff;
	//if (Config.RCntFix) { // Vandal Hearts 1/2
	//      ret/= 16;
	//}
    }
//              return (psxCounters[index].count + BIAS * ((upse_r3000_cpu_regs.cycle - psxCounters[index].sCycle) / psxCounters[index].rate)) & 0xffff;
//      } else return 0;

//      SysPrintf("readCcount[%ld] = %lx (mode %lx, target %lx, cycle %lx)\n", index, ret, psxCounters[index].mode, psxCounters[index].target, upse_r3000_cpu_regs.cycle);

    return ret;
}
