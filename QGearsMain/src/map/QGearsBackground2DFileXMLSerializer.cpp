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
#include "map/QGearsBackground2DFileXMLSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const String Background2DFileXMLSerializer::BLENDING_ALPHA( "alpha" );
    const String Background2DFileXMLSerializer::BLENDING_ADD  ( "add"   );

    //---------------------------------------------------------------------
    Background2DFileXMLSerializer::Background2DFileXMLSerializer() :
        XMLSerializer()
    {
    }

    //---------------------------------------------------------------------
    Background2DFileXMLSerializer::~Background2DFileXMLSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::readHeader( TiXmlNode* node )
    {
        if( node == NULL || node->ValueStr() != "background2d" )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"not a valid background2d file, no <background2d> in root"
                ,"Background2DFileXMLSerializer::readHeader" );
        }
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::importBackground2DFile( Ogre::DataStreamPtr &stream, Background2DFile* pDest )
    {
        TiXmlDocument document;
        parse( stream, document );

        TiXmlNode* node = document.RootElement();
        readHeader( node );

        String texture_name("");
        readAttribute( *node, texture_name, "image" );
        if( texture_name.empty() )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"image attribute not set"
                ,"Background2DFileXMLSerializer::importBackground2DFile" );
        }
        pDest->setTextureName( texture_name );


        Ogre::Quaternion range( -100000, -100000, 100000, 100000 );
        readAttribute( *node, range, "range" );
        pDest->setRange( range );

        Ogre::Vector3 position( Ogre::Vector3::ZERO );
        readAttribute( *node, position, "position" );
        pDest->setPosition( position );

        Ogre::Quaternion orientation( Ogre::Quaternion::IDENTITY );
        readAttribute( *node, orientation, "orientation" );
        pDest->setOrientation( orientation );

        Ogre::Real fov( 45 );
        readAttribute( *node, fov, "fov" );
        pDest->setFov( Ogre::Radian( Ogre::Degree( fov ) ) );

        readVector( *node, pDest->getTiles(), "tile" );
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::readObject( TiXmlNode& node, Tile& pDest )
    {
        pDest.width = 0;
        readInt( node, pDest.width, "width" );

        pDest.height = 0;
        readInt( node, pDest.height, "height" );

        pDest.destination = Ogre::Vector2::ZERO;
        readAttribute( node, pDest.destination, "destination" );

        pDest.uv = Ogre::Vector4::ZERO;
        readAttribute( node, pDest.uv, "uv" );

        pDest.depth = 0;
        readAttribute( node, pDest.depth, "depth" );

        String blending_name( BLENDING_ALPHA );
        readAttribute( node, blending_name, "blending" );
        pDest.blending = Background2D::ALPHA;
        if( blending_name == BLENDING_ADD )
        {
            pDest.blending = Background2D::ADD;
        }
    }
/*
        if( node2->Type() == TiXmlNode::TINYXML_ELEMENT && node2->ValueStr() == "animation" )
        {
            Ogre::String name = GetString( node2, "name", "" );
            if( name != "" )
            {
                Background2DAnimation* animation = new Background2DAnimation( name, background, tile_id );

                animation->SetLength( GetFloat( node2, "length", 0 ) );

                Ogre::String uv = GetString( node2, "uv", "" );
                if( uv != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( uv, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            float time = Ogre::StringConverter::parseReal( data[ 0 ] );
                            Ogre::Vector4 value = Ogre::StringConverter::parseVector4( data[ 1 ] );
                            animation->AddUVKeyFrame( time, value.x, value.y, value.z, value.w );
                        }
                    }
                }

                background->AddAnimation( animation );
            }
        }
    */

    //---------------------------------------------------------------------
}
