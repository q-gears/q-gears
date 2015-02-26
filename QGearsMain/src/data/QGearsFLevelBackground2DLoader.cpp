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
#include "data/QGearsFLevelBackground2DLoader.h"

#include "data/QGearsFLevelFile.h"
#include "map/QGearsBackground2DFile.h"

#include "FF7Common.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    FLevelBackground2DLoader::FLevelBackground2DLoader( FLevelFile &flevel_file ) :
        m_flevel_file( flevel_file )
    {
    }

    //-------------------------------------------------------------------------
    FLevelBackground2DLoader::~FLevelBackground2DLoader()
    {
    }

    //-------------------------------------------------------------------------
    void
    FLevelBackground2DLoader::loadResource( Ogre::Resource *resource )
    {
        Background2DFile *background_2d( static_cast<Background2DFile *>(resource) );
        assert( background_2d );

        m_flevel_file.load();
        background_2d->_notifyOrigin( m_flevel_file.getName() );
        background_2d->setTextureName( m_flevel_file.getBackgroundTextureName() );
        background_2d->setClip( Ogre::Vector2( FF7::SCREEN_WIDTH, FF7::SCREEN_HEIGHT ) );

        CameraMatrixFilePtr camera_matrix( m_flevel_file.getCameraMatrix() );
        Ogre::Real scale(Ogre::Real(camera_matrix->getCount()));
        background_2d->setPosition( camera_matrix->getPosition() / -( scale * FF7::FIELD_POSITION_SCALE ) );

        background_2d->setOrientation( camera_matrix->getOrientation() );

        background_2d->setFov( camera_matrix->getFov( FF7::SCREEN_WIDTH ) );

        Ogre::Vector4 range( 0, 0, 0, 0 );

        TileList& tiles( background_2d->getTiles() );
        BackgroundFilePtr background( m_flevel_file.getBackground() );
        BackgroundFile::SpritePtrList sprites;
        background->addAllSprites( sprites );

        auto it    ( sprites.begin() );
        auto it_end( sprites.end() );
        Ogre::Real step( BackgroundFile::SPRITE_WIDTH / 1024.0 );
        Ogre::Vector4   uv( 0, 0, step, step );
        Ogre::Vector4   col( step, 0, step, 0 );
        Ogre::Vector4   row( 0, step, 0, step );
        while( it != it_end )
        {
            const SpriteData& sprite( **it );
            Tile tile;
            tile.width  = BackgroundFile::SPRITE_WIDTH;
            tile.height = BackgroundFile::SPRITE_HEIGHT;
            tile.blending = B_ALPHA;
            tile.depth = sprite.depth / ( scale * FF7::FIELD_DEPTH_SCALE );
            /*
            if depth >= 1
                if( ??? / 4.0 < depth )
                    if( depth < 4095 )
                    else
                        depth = 0.9999
                else
                    depth = depth / 1000.0
            else
                depth = 0.0001
            */

            tile.destination.x = sprite.dst.x;
            tile.destination.y = sprite.dst.y;
            tile.uv = uv;
            range.x = std::min( tile.destination.x, range.x );
            range.y = std::min( tile.destination.y, range.y );
            range.z = std::max( tile.destination.x + tile.width , range.z );
            range.w = std::max( tile.destination.y + tile.height, range.w );
            tiles.push_back( tile );

            uv += col;
            if( uv.x >= 1 )
            {
                uv.x = 0;
                uv.z = step;
                uv += row;
            }
            ++it;
        }
        background_2d->setRange( range );
    }

    //-------------------------------------------------------------------------
}
