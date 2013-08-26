/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-26 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsBackground2DFile.h"

#include <OgreLogManager.h>
#include <OgreResourceGroupManager.h>

#include "data/QGearsBackground2DFileSerializer.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    Background2DFile::RESOURCE_TYPE( "QGearsBackground2DFile" );

    //---------------------------------------------------------------------
    Background2DFile::Background2DFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
    {
        createParamDictionary( getResourceType() );
    }

    //---------------------------------------------------------------------
    Background2DFile::~Background2DFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::loadImpl()
    {
        Background2DFileSerializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        serializer.importBackground2DFile( stream, this );
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::unloadImpl()
    {
    }

    //---------------------------------------------------------------------
    size_t
    Background2DFile::calculateSize() const
    {
        return 0;
    }

    //---------------------------------------------------------------------
}
