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

    void AddTime( float time );

private:
    float m_SystemTimeTotal;
    float m_SystemTimeDelta;
    float m_GameTimeTotal;
    float m_GameTimeDelta;
};



#endif // TIMER_H
