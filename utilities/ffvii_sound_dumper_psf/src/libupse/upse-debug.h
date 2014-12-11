/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse-debug.h
 * Purpose: libupse: UPSE debug infrastructure
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

#ifndef _UPSE__LIBUPSE__UPSE_DEBUG_H__GUARD
#define _UPSE__LIBUPSE__UPSE_DEBUG_H__GUARD

#undef UPSE_DEBUG

#define _ENTER _DEBUG("enter")
#define _LEAVE _DEBUG("leave")
#define _MESSAGE(tag, string, ...) do { fprintf(stderr, "libupse: %s: %s:%d (%s): " string "\n", \
    tag, __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__); } while(0)

#define _ERROR(...) _MESSAGE("ERROR", __VA_ARGS__)
#define _WARN(...)  _MESSAGE("WARN", __VA_ARGS__)

#ifdef UPSE_DEBUG
#define _DEBUG(...) _MESSAGE("DEBUG",  __VA_ARGS__)
#else
#define _DEBUG(...) {}
#endif

#endif
