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
#ifndef __QGearsPrerequisites_H__
#define __QGearsPrerequisites_H__

#include <OgrePrerequisites.h>

#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32 ) && !defined(__MINGW32__) && !defined(QGEARS_STATIC_LIB)
#   ifdef QGEARS_EXPORTS
#       define _QGearsExport __declspec(dllexport)
#   else
#       define _QGearsExport __declspec(dllimport)
#   endif
#elif defined ( OGRE_GCC_VISIBILITY )
#   define _QGearsExport  __attribute__ ((visibility("default")))
#else
#   define _QGearsExport
#endif


#endif // __QGearsPrerequisites_H__
