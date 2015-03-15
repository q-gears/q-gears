#include "core/ConfigVar.h"
#include "core/Timer.h"


ConfigVar cv_timer_scale_game("timer_scale_game", "Timer speed for game related things", "1");
template<>Timer *Ogre::Singleton<Timer>::msSingleton = nullptr;


Timer::Timer():
    m_SystemTimeTotal(0),
    m_SystemTimeDelta(0),
    m_GameTimeTotal(0),
    m_GameTimeDelta( 0 ),
    m_GameTimer( 0 )
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
Timer::AddTime( const float time )
{
    m_SystemTimeDelta = time;
    m_SystemTimeTotal += m_SystemTimeDelta;

    m_GameTimeDelta = time * cv_timer_scale_game.GetF();
    m_GameTimeTotal += m_GameTimeDelta;

    if( m_GameTimer > 0 )
    {
        m_GameTimer -= time;
        if( m_GameTimer < 0 )
        {
            m_GameTimer = 0;
        }
    }
}



void
Timer::SetGameTimer( const float timer )
{
    m_GameTimer = timer;
}



int
Timer::GetGameTimer() const
{
    return (int) m_GameTimer;
}
