#include "core/EntityTrigger.h"

#include "core/DebugDraw.h"
#include "core/Entity.h"
#include "core/ConfigVar.h"



ConfigVar cv_debug_trigger( "debug_trigger", "Draw entity trigger debug info", "0" );



EntityTrigger::EntityTrigger( const Ogre::String& name ):
    m_Name(name),
    m_Enabled( false ),
    m_Point1( Ogre::Vector3::ZERO ),
    m_Point2( Ogre::Vector3::ZERO )
{
}



EntityTrigger::~EntityTrigger()
{
}



void
EntityTrigger::UpdateDebug()
{
    if( cv_debug_trigger.GetB() == true )
    {
        if( m_Enabled == false )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.5f, 0.5f, 0.5f ) );
        }
        else if( m_Activators.size() > 0 )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.9f, 0.5f ) );
        }
        else
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.5f, 0.9f ) );
        }
        DEBUG_DRAW.Line3d( m_Point1, m_Point2 );

        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 30, 40 );

        Ogre::Vector3 center = m_Point2 - ( ( m_Point2 - m_Point1 ) / 2 );

        DEBUG_DRAW.Text( center, 0, 0, m_Name );

        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.9f, 0.5f ) );
        for( unsigned int i = 0; i < m_Activators.size(); ++i )
        {
            DEBUG_DRAW.Text( center, 0, ( i + 1 ) * 16, m_Activators[ i ]->GetName() );
        }
    }
}



const Ogre::String&
EntityTrigger::GetName() const
{
    return m_Name;
}



void
EntityTrigger::SetEnabled( const bool enabled )
{
    m_Enabled = enabled;

    if( enabled == false )
    {
        m_Activators.clear();
    }
}



bool
EntityTrigger::IsEnabled() const
{
    return m_Enabled;
}



void
EntityTrigger::AddActivator( Entity* activator )
{
    // add only if this activator don't exist
    unsigned int i = 0;
    for( ; i < m_Activators.size(); ++i )
    {
        if( m_Activators[ i ] == activator )
        {
            break;
        }
    }
    if( i == m_Activators.size() )
    {
        m_Activators.push_back( activator );
    }
}



void
EntityTrigger::RemoveActivator( Entity* activator )
{
    for( unsigned int i = 0; i < m_Activators.size(); ++i )
    {
        if( m_Activators[ i ] == activator )
        {
            m_Activators.erase( m_Activators.begin() + i );
            return;
        }
    }
}



bool
EntityTrigger::IsActivator( Entity* activator )
{
    for( unsigned int i = 0; i < m_Activators.size(); ++i )
    {
        if( m_Activators[ i ] == activator )
        {
            return true;
        }
    }

    return false;
}



void
EntityTrigger::SetPoints( const Ogre::Vector3& point1, const Ogre::Vector3& point2 )
{
    m_Point1 = point1;
    m_Point2 = point2;
}



const Ogre::Vector3&
EntityTrigger::GetPoint1() const
{
    return m_Point1;
}



const Ogre::Vector3&
EntityTrigger::GetPoint2() const
{
    return m_Point2;
}
