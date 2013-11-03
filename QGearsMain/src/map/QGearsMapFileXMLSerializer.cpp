/*
-----------------------------------------------------------------------------
Copyright (c) 27.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#include "map/QGearsMapFileXMLSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //--------------------------------------------------------------------------
    MapFileXMLSerializer::MapFileXMLSerializer() :
        XMLSerializer()
    {
    }
    
    //--------------------------------------------------------------------------
    MapFileXMLSerializer::~MapFileXMLSerializer()
    {
    }
    
    //--------------------------------------------------------------------------
    void MapFileXMLSerializer::readHeader( TiXmlNode *node )
    {
        if( node == NULL || node->ValueStr() != "map" )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"not a valid map file, no <map> in root"
                ,"MapFileXMLSerializer::readHeader" );
        }
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::importMapFile( Ogre::DataStreamPtr &stream, MapFile *pDest )
    {
        TiXmlDocument document;
        parse( stream, document );

        TiXmlNode *root_node( document.RootElement() );
        readHeader( root_node );

        TiXmlNode &node( *root_node );
        readScript( node, pDest );
        readBackground2D( node, pDest );
        readWalkmesh( node, pDest );
        readForwardDirection( node, pDest );
        readEntities( node, pDest );
    }
    
    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readScript( TiXmlNode &node, MapFile *pDest )
    {
        TiXmlNode *child( findChildNode( node, "script" ) );
        if( child != NULL )
        {
            String file_name;
            readAttribute( *child, "file_name", file_name );
            pDest->setScriptName( file_name );
        }
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readBackground2D( TiXmlNode &node, MapFile *pDest )
    {
        TiXmlNode *child( findChildNode( node, "background2d" ) );
        if( child != NULL )
        {
            String file_name;
            readAttribute( *child, "file_name", file_name );
            pDest->setBackground2dName( file_name );
        }
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readWalkmesh( TiXmlNode &node, MapFile *pDest )
    {
        TiXmlNode *child( findChildNode( node, "walkmesh" ) );
        if( child != NULL )
        {
            String file_name;
            readAttribute( *child, "file_name", file_name );
            pDest->setWalkmeshName( file_name );
        }
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readForwardDirection( TiXmlNode &node, MapFile *pDest )
    {
        TiXmlNode *child( findChildNode( node, "movement_rotation" ) );
        if( child != NULL )
        {
            Ogre::Real degree;
            readAttribute( *child, "degree", degree );
            pDest->setForwardDirection( degree );
        }
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readEntities(TiXmlNode &node, MapFile *pDest)
    {
        // TODO: implement factory pattern
        readVector( node, "entity_trigger", pDest->getTriggers() );
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readObject( TiXmlNode &node, MapFileXMLSerializer::TriggerData &pDest )
    {
        readAttribute( node, "name"   , pDest.name );
        readAttribute( node, "point1" , pDest.point1 );
        readAttribute( node, "point2" , pDest.point2 );
        readAttribute( node, "enabled", pDest.enabled );
    }

    //--------------------------------------------------------------------------
    template<typename ValueType>
    void
    MapFileXMLSerializer::readVector(TiXmlNode &node, const String &tag, std::vector<ValueType> &pDest)
    {
        pDest.clear();
        TiXmlNode* child( node.FirstChild() );
        while( child != NULL )
        {
            if( child->Type() == TiXmlNode::TINYXML_ELEMENT && child->ValueStr() == tag )
            {
                ValueType in_tmp;
                readObject( *child, in_tmp );
                pDest.push_back( in_tmp );
            }
            child = child->NextSibling();
        }
    }

    //--------------------------------------------------------------------------
    void
    MapFileXMLSerializer::readVector(TiXmlNode &node, const String &tag, TriggerList &pDest)
    {
        pDest.clear();
        TriggerDataList trigger_data;
        readVector( node, tag, trigger_data );
        TriggerDataList::const_iterator it( trigger_data.begin() )
                                     , end( trigger_data.end() );
        while( it != end )
        {
            TriggerList::value_type trigger( it->name );
            trigger.SetEnabled( it->enabled );
            trigger.SetPoints( it->point1, it->point2 );
            pDest.push_back( trigger );
            ++it;
        }
    }

    //--------------------------------------------------------------------------
}

