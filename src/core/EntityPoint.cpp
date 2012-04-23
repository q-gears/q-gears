#include "EntityPoint.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "ScriptManager.h"



ConfigVar cv_debug_point( "debug_point", "Draw point debug info", "false" );



EntityPoint::EntityPoint( const Ogre::String& name ):
    m_Name( name ),
    m_Point( Ogre::Vector3::ZERO )
{
}



EntityPoint::~EntityPoint()
{
}



void
EntityPoint::Update()
{
    if( cv_debug_point.GetB() == true )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        Ogre::Vector3 point1 = m_Point;
        point1.z += 0.5f;
        Ogre::Vector3 point2 = m_Point;
        point2.z -= 0.5f;
        DEBUG_DRAW.Line3d( point1, point2 );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 30, 40 );
        DEBUG_DRAW.Text( m_Point, 0, 0, m_Name );
    }
}



const Ogre::String&
EntityPoint::GetName() const
{
    return m_Name;
}



void
EntityPoint::SetPoint( const Ogre::Vector3& point )
{
    m_Point = point;

}



const Ogre::Vector3&
EntityPoint::GetPoint() const
{
    return m_Point;
}



void
EntityPoint::ScriptGetPoint() const
{
    ScriptManager::getSingleton().AddValueToStack( m_Point.x );
    ScriptManager::getSingleton().AddValueToStack( m_Point.y );
    ScriptManager::getSingleton().AddValueToStack( m_Point.z );
}
