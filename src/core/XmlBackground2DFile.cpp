#include "XmlBackground2DFile.h"

#include "Background2D.h"
#include "EntityManager.h"
#include "Logger.h"




XmlBackground2DFile::XmlBackground2DFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlBackground2DFile::~XmlBackground2DFile()
{
}



void
XmlBackground2DFile::Load()
{
    TiXmlNode* node = m_File.RootElement();
    Background2D* background = EntityManager::getSingleton().GetBackground2D();

    if( node == NULL || node->ValueStr() != "background2d" )
    {
        LOG_ERROR( "XML 2D Background loader: " + m_File.ValueStr() + " is not a valid background2d file! No <background2d> in root." );
        return;
    }

    Ogre::String image = GetString( node, "image", "" );

    if( image != "" )
    {
        background->SetImage( image );

        node = node->FirstChild();
        while( node != NULL )
        {
            if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "tile" )
            {
                int width = GetInt( node, "width", 0 );
                int height = GetInt( node, "height", 0 );

                if( width != 0 && height != 0 )
                {
                    Ogre::Vector2 destination = GetVector2( node, "destination", Ogre::Vector2::ZERO );
                    Ogre::Vector2 uv1 = GetVector2( node, "uv1", Ogre::Vector2::ZERO );
                    Ogre::Vector2 uv2 = GetVector2( node, "uv2", Ogre::Vector2::ZERO );
                    float depth = GetFloat( node, "depth", 0 );

                    background->AddTile( destination.x, destination.y, width, height, depth, uv1.x, uv1.y, uv2.x, uv2.y );
                }
            }

            node = node->NextSibling();
        }
    }
}
