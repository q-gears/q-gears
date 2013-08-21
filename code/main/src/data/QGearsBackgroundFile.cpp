/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-11 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsBackgroundFile.h"

#include <OgreResourceGroupManager.h>

#include "data/QGearsBackgroundFileSerializer.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    BackgroundFile::RESOURCE_TYPE( "QGearsBackgroundFile" );

    //---------------------------------------------------------------------
    BackgroundFile::BackgroundFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
    {
        createParamDictionary( RESOURCE_TYPE );
    }

    //---------------------------------------------------------------------
    BackgroundFile::~BackgroundFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    BackgroundFile::loadImpl()
    {
        BackgroundFileSerializer serializer;
        Ogre::DataStreamPtr stream( Ogre::ResourceGroupManager::getSingleton().openResource( mName, mGroup, true, this ) );
        serializer.importBackgroundFile( stream, this );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFile::unloadImpl()
    {
        memset( m_layers , 0, sizeof( m_layers  ) );
        memset( m_palette, 0, sizeof( m_palette ) );
        for( size_t i(PAGE_COUNT); i--; )
        {
            m_pages[i].enabled = false;
            m_pages[i].unknown_02 = 0;
            m_pages[i].value_size = 0;
            m_pages[i].data.clear();
        }
    }

    //---------------------------------------------------------------------
    size_t
    BackgroundFile::calculateSize() const
    {
        size_t data_size( 0 );
        for( size_t i(LAYER_COUNT); i--; )
        {
            data_size += calculateSize( m_layers[i] );
        }

        for( size_t i(PAGE_COUNT); i--; )
        {
            data_size += calculateSize( m_pages[i] );
        }

        return data_size;
    }

    //---------------------------------------------------------------------
    size_t
    BackgroundFile::calculateSize( const Layer &layer ) const
    {
        return sizeof( layer.enabled )
              +sizeof( layer.width )
              +sizeof( layer.height )
              +sizeof( layer.unknown_06 )
              +sizeof( layer.unknown_08 )
              +sizeof( layer.unknown_0E )
              +layer.sprites.size() * sizeof( layer.sprites[0] );
    }

    //---------------------------------------------------------------------
    size_t
    BackgroundFile::calculateSize( const Page &page ) const
    {
        return sizeof( page.enabled )
              +sizeof( page.unknown_02 )
              +sizeof( page.value_size )
              +page.data.size();
    }

    //---------------------------------------------------------------------
}
