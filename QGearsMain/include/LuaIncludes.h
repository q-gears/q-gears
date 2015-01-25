#pragma once

// Wraps the LUA includes for platform specific build workarounds
#ifdef __APPLE__
// Something in the Apple headers seems to #define nil as __NULL 
// this then causes a build error in luabind:
// luabind/nil.hpp:36:40: error: expected unqualified-id
// extern LUABIND_API detail::nil_type nil;
#undef nil

// Causes a build error, usually an ICE on g++
#undef check
#endif

#include <luabind/luabind.hpp>
#include <luabind/yield_policy.hpp>


extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

