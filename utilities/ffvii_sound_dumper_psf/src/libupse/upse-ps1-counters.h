/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-ps1-counters.h
 * Purpose: libupse: PS1 timekeeping implementation headers
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

#ifndef __PSXCOUNTERS_H__
#define __PSXCOUNTERS_H__

typedef struct
{
    u32 count, mode, target;
    u32 sCycle, Cycle, rate, interrupt;
} psxCounter;

extern psxCounter psxCounters[5];

extern u32 psxNextCounter, psxNextsCounter;

void psxRcntInit();
void psxRcntUpdate();
void psxRcntWcount(u32 index, u32 value);
void psxRcntWmode(u32 index, u32 value);
void psxRcntWtarget(u32 index, u32 value);
u32 psxRcntRcount(u32 index);

void psxUpdateVSyncRate();

int CounterSPURun(void);
void CounterDeadLoopSkip();

#endif /* __PSXCOUNTERS_H__ */
