/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsLZSFLevelFile.h"

#include "data/QGearsLZSDataStream.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    LZSFLevelFile::RESOURCE_TYPE( "QGearsLZSFLevelFile" );

    //---------------------------------------------------------------------
    LZSFLevelFile::LZSFLevelFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        FLevelFile( creator, name, handle, group, isManual, loader )
    {
    }

    //---------------------------------------------------------------------
    LZSFLevelFile::~LZSFLevelFile()
    {
    }

    //---------------------------------------------------------------------
    const String&
    LZSFLevelFile::getResourceType( void ) const
    {
        return RESOURCE_TYPE;
    }

    //---------------------------------------------------------------------
    Ogre::DataStreamPtr
    LZSFLevelFile::openResource( void )
    {
        Ogre::DataStreamPtr compressed( FLevelFile::openResource() );
        return Ogre::DataStreamPtr( new QGears::LZSDataStream( compressed->getName(), compressed ) );
    }


    //---------------------------------------------------------------------
}
