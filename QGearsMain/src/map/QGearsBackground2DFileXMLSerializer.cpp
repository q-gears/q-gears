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
    const String Background2DFileXMLSerializer::BLENDING_ALPHA   ( "alpha"    );
    const String Background2DFileXMLSerializer::BLENDING_ADD     ( "add"      );
    const String Background2DFileXMLSerializer::BLENDING_SUBTRACT( "subtract" );

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
    Background2DFileXMLSerializer::readHeader( TiXmlNode *node )
    {
        if( node == nullptr || node->ValueStr() != "background2d" )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"not a valid background2d file, no <background2d> in root"
                ,"Background2DFileXMLSerializer::readHeader" );
        }
    }

    //---------------------------------------------------------------------
    bool
    Background2DFileXMLSerializer::readAttribute( TiXmlNode &node, const String &attribute, Blending &pDest, const Blending &pDefault )
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == nullptr )
        {
            pDest = pDefault;
            return false;
        }
        if( *value == BLENDING_ADD )
        {
            pDest = B_ADD;
            return true;
        }
        if( *value == BLENDING_ALPHA )
        {
            pDest = B_ALPHA;
            return true;
        }
        if( *value == BLENDING_SUBTRACT )
        {
            pDest = B_SUBTRACT;
            return true;
        }
        pDest = pDefault;
        return false;
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::importBackground2DFile( Ogre::DataStreamPtr &stream
                                                          ,Background2DFile *pDest )
    {
        TiXmlDocument document;
        parse( stream, document );

        TiXmlNode *root_node( document.RootElement() );
        readHeader( root_node );
        TiXmlNode &node( *root_node );

        String texture_name;
        readAttribute( node, "image", texture_name );
        if( texture_name.empty() )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"image attribute not set"
                ,"Background2DFileXMLSerializer::importBackground2DFile" );
        }
        pDest->setTextureName( texture_name );

        Ogre::Vector2 clip;
        readAttribute( node, "clip", clip, Ogre::Vector2( 320, 240 ) );
        pDest->setClip( clip );

        Ogre::Vector4 range;
        readAttribute( node, "range", range, Ogre::Vector4( -100000, -100000, 100000, 100000 ) );
        pDest->setRange( range );

        Ogre::Vector3 position;
        readAttribute( node, "position", position );
        pDest->setPosition( position );

        Ogre::Quaternion orientation;
        readAttribute( node, "orientation", orientation );
        pDest->setOrientation( orientation );

        Ogre::Real fov;
        readAttribute( node, "fov", fov, Ogre::Real( 45 ) );
        pDest->setFov( Ogre::Radian( Ogre::Degree( fov ) ) );

        readVector( node, "tile", pDest->getTiles() );
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::readObject( TiXmlNode& node, Tile& pDest )
    {
        readAttribute( node, "width", pDest.width );
        readAttribute( node, "height", pDest.height );
        readAttribute( node, "destination", pDest.destination );
        readAttribute( node, "uv", pDest.uv );
        readAttribute( node, "depth", pDest.depth );
        readAttribute( node, "blending", pDest.blending, B_ALPHA );
        readMap( node, "animation", "name", pDest.animations );
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::readObject( TiXmlNode& node, Animation& pDest )
    {
        readAttribute( node, "length", pDest.length );
        readVector( node, "keyframe", pDest.key_frames );
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::readObject( TiXmlNode& node, KeyFrame& pDest )
    {
        readAttribute( node, "time", pDest.time );
        readAttribute( node, "uv", pDest.uv );
    }

    //---------------------------------------------------------------------
}
