#include "EntityPoint.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "ScriptManager.h"



ConfigVar cv_debug_point( "debug_point", "Draw point debug info", "false" );



EntityPoint::EntityPoint( const Ogre::String& name ):
    m_Name( name ),
    m_Position( Ogre::Vector3::ZERO ),
    m_Rotation( 0 )
{
}



EntityPoint::~EntityPoint()
{
}



void
EntityPoint::UpdateDebug()
{
    if( cv_debug_point.GetB() == true )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        Ogre::Vector3 point1 = m_Position;
        point1.z += 0.5f;
        Ogre::Vector3 point2 = m_Position;
        point2.z -= 0.5f;
        DEBUG_DRAW.Line3d( point1, point2 );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 30, 40 );
        DEBUG_DRAW.Text( m_Position, 0, 0, m_Name );
    }
}



const Ogre::String&
EntityPoint::GetName() const
{
    return m_Name;
}



void
EntityPoint::SetPosition( const Ogre::Vector3& point )
{
    m_Position = point;

}



const Ogre::Vector3&
EntityPoint::GetPosition() const
{
    return m_Position;
}



void
EntityPoint::ScriptGetPosition() const
{
    ScriptManager::getSingleton().AddValueToStack( m_Position.x );
    ScriptManager::getSingleton().AddValueToStack( m_Position.y );
    ScriptManager::getSingleton().AddValueToStack( m_Position.z );
}



void
EntityPoint::SetRotation( const float rotation )
{
    m_Rotation = rotation;
}



float
EntityPoint::GetRotation() const
{
    return m_Rotation;
}



float
EntityPoint::ScriptGetRotation() const
{
    return m_Rotation;
}
