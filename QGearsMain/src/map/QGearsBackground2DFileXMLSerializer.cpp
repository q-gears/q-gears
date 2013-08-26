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
                ,"Background2DFileXMLSerializer::importBackground2DFile" );
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
        pDest->setTextureName( texture_name );

        Ogre::Quaternion range( -100000, -100000, 100000, 100000 );
        readAttribute( *node, range, "range" );
        pDest->setRange( range );
/*
    Ogre::String image = GetString( node, "image", "" );

    if( image != "" )
    {
        background->SetImage( image );

        Ogre::Quaternion range = GetQuaternion( node, "range", Ogre::Quaternion( -100000, -100000, 100000, 100000 ) );
        background->SetRange( ( int )range.w, ( int )range.x, ( int )range.y, ( int )range.z );

        Ogre::Vector3 position = GetVector3( node, "position", Ogre::Vector3::ZERO );
        Ogre::Quaternion orientation = GetQuaternion( node, "orientation", Ogre::Quaternion::IDENTITY );
        float fov = GetFloat( node, "fov", 45 );
        CameraManager::getSingleton().Set2DCamera( position, orientation, Ogre::Radian( Ogre::Degree( fov ) ) );

        int tile_id = 0;

        node = node->FirstChild();
        while( node != NULL )
        {
            if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "tile" )
            {
                int width = GetInt( node, "width", 0 );
                int height = GetInt( node, "height", 0 );

                Ogre::Vector2 destination = GetVector2( node, "destination", Ogre::Vector2::ZERO );
                Ogre::Vector4 uv = GetVector4( node, "uv", Ogre::Vector4::ZERO );
                float depth = GetFloat( node, "depth", 0 );
                Ogre::String blending_str = GetString( node, "blending", "alpha" );

                Background2D::Blending blending = ( blending_str == "add" ) ? Background2D::ADD : Background2D::ALPHA;

                Ogre::Vector4 distance = Ogre::Vector4( 0, 0, -depth, 1 );
                Ogre::Vector4 res = CameraManager::getSingleton().GetCurrentCamera()->getProjectionMatrixWithRSDepth() * distance;
                res = res / res.w;
                background->AddTile( destination.x, destination.y, width, height, res.z, uv.x, uv.y, uv.z, uv.w, blending );

                TiXmlNode* node2 = node->FirstChild();
                while( node2 != NULL )
                {
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

                    node2 = node2->NextSibling();
                }

                ++tile_id;
            }

            node = node->NextSibling();
        }
    }
    */
    }

    //---------------------------------------------------------------------
}
