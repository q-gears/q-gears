/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-29 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsFLevelBackground2DLoader_H__
#define __QGearsFLevelBackground2DLoader_H__

#include <OgreResource.h>

#include "data/QGearsBackgroundFile.h"
#include "map/QGearsBackground2DFile.h"

namespace QGears
{
    class FLevelFile;

    class FLevelBackground2DLoader : public Ogre::ManualResourceLoader
    {
    public:
        explicit FLevelBackground2DLoader( FLevelFile& flevel_file );
        virtual ~FLevelBackground2DLoader();

        virtual void loadResource( Ogre::Resource *resource );

    protected:
        typedef Background2DFile::TileList  TileList;
        typedef BackgroundFile::Layer       Layer;
        typedef BackgroundFile::SpriteData  SpriteData;
        typedef BackgroundFile::SpriteList  SpriteList;

    private:
        FLevelFile  &m_flevel_file;
    };
}

#endif // __QGearsFLevelBackground2DLoader_H__
