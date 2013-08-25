#include "Timer.h"

#include "ConfigVar.h"



ConfigVar cv_timer_scale_game( "timer_scale_game", "Timer speed for game related things", "1" );



template<>Timer *Ogre::Singleton< Timer >::msSingleton = NULL;



Timer::Timer():
    m_SystemTimeTotal( 0 ),
    m_SystemTimeDelta( 0 ),
    m_GameTimeTotal( 0 ),
    m_GameTimeDelta( 0 )
{
}



float
Timer::GetSystemTimeTotal()
{
    return m_SystemTimeTotal;
}



float
Timer::GetSystemTimeDelta()
{
    return m_SystemTimeDelta;
}



float
Timer::GetGameTimeTotal()
{
    return m_GameTimeTotal;
}



float
Timer::GetGameTimeDelta()
{
    return m_GameTimeDelta;
}



void
Timer::AddTime( float time )
{
    m_SystemTimeDelta = time;
    m_SystemTimeTotal += m_SystemTimeDelta;

    m_GameTimeDelta = time * cv_timer_scale_game.GetF();
    m_GameTimeTotal += m_GameTimeDelta;
}
