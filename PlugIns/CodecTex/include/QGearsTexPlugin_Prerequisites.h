/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-30 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef __QGearsTexPlugin_Prerequisites_H__
#define __QGearsTexPlugin_Prerequisites_H__

#include <OgrePrerequisites.h>

#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32 ) && !defined(__MINGW32__) && !defined(QGEARS_STATIC_LIB)
#   ifdef QGEARS_TEXPLUGIN_EXPORTS
#       define _QGearsTexPluginExport __declspec(dllexport)
#   else
#       define _QGearsTexPluginExport __declspec(dllimport)
#   endif
#elif defined ( OGRE_GCC_VISIBILITY )
#   define _QGearsTexPluginExport  __attribute__ ((visibility("default")))
#else
#   define _QGearsTexPluginExport
#endif


#endif // __QGearsTexPlugin_Prerequisites_H__
