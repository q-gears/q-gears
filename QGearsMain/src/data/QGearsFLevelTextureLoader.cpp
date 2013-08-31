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
#include "data/QGearsFLevelTextureLoader.h"

#include <OgreTexture.h>

#include "data/QGearsFLevelFile.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    FLevelTextureLoader::FLevelTextureLoader( FLevelFile &flevel_file ) :
        m_flevel_file( flevel_file )
    {
    }

    //-------------------------------------------------------------------------
    FLevelTextureLoader::~FLevelTextureLoader()
    {
    }

    //-------------------------------------------------------------------------
    void
    FLevelTextureLoader::loadResource( Ogre::Resource *resource )
    {
        Ogre::Texture *texture( static_cast<Ogre::Texture *>(resource) );
        assert( texture );

        m_flevel_file.load();
        texture->_notifyOrigin( m_flevel_file.getName() );
        texture->setTextureType( Ogre::TEX_TYPE_2D );
        texture->setNumMipmaps( 0 );
        texture->setGamma( 1.0 );
        texture->setTreatLuminanceAsAlpha( false );
        texture->setFormat( Ogre::PF_UNKNOWN );
        texture->setHardwareGammaEnabled( false );

        BackgroundFilePtr   background( m_flevel_file.getBackground() );
        PaletteFilePtr      palette   ( m_flevel_file.getPalette() );
        Ogre::Image *img( background->createImage( palette ) );
        Ogre::ConstImagePtrList images;
        images.push_back( img );
        texture->_loadImages( images );
        delete img;
    }

    //-------------------------------------------------------------------------
}
