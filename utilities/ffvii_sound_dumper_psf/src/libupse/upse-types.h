/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-types.h
 * Purpose: libupse: type aliases
 *
 * Copyright (c) 2007 William Pitcock <nenolod@sacredspiral.co.uk>
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#ifndef _UPSE__LIBUPSE__UPSE_TYPES_H__GUARD
#define _UPSE__LIBUPSE__UPSE_TYPES_H__GUARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdint.h>

#define INLINE inline

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef intptr_t sptr;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uintptr_t uptr;

#ifdef __GNUC__
# define upse_packed_t	__attribute__ ((packed))
#else
# define upse_packed_t
#endif

#endif
