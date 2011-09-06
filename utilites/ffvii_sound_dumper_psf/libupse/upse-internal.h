/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-internal.h
 * Purpose: libupse: UPSE Internal header
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

#ifndef __PSXCOMMON_H__
#define __PSXCOMMON_H__

#if PSS_STYLE==2

#define PSS "\\"
#define PS '\\'

#elif PSS_STYLE==1

#define PSS "/"
#define PS '/'

#elif PSS_STYLE==3

#define PSS "\\"
#define PS '\\'
#endif

#include <zlib.h>

#include <sys/types.h>
#include "upse-types.h"

void __Log(char *fmt, ...);

#define BIAS	2
#define PSXCLK	33868800	/* 33.8688 Mhz */

#include "upse.h"
#include "upse-debug.h"
#include "upse-r3000-abstract.h"
#include "upse-ps1-memory-manager.h"
#include "upse-ps1-hal.h"
#include "upse-ps1-bios-base.h"
#include "upse-ps1-dma-manager.h"
#include "upse-ps1-counters.h"
#include "upse-ps1-executive.h"
#include "upse-ps1-spu-abstract.h"
#include "upse-ps1-spu-base.h"

#endif /* __PSXCOMMON_H__ */
