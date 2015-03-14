#ifndef TIMER_H
#define TIMER_H

#include <OgreSingleton.h>



class Timer : public Ogre::Singleton< Timer >
{
public:
    Timer();

    float GetSystemTimeTotal();
    float GetSystemTimeDelta();
    float GetGameTimeTotal();
    float GetGameTimeDelta();

    void AddTime( const float time );

    void SetGameTimer( const float timer );
    int GetGameTimer() const;

private:
    float m_SystemTimeTotal;
    float m_SystemTimeDelta;
    float m_GameTimeTotal;
    float m_GameTimeDelta;

    float m_GameTimer;
};



#endif // TIMER_H
