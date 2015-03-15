#pragma once

// add this include because this is only common file between everything that uses Input fucntion
#include <OIS.h>


namespace QGears
{
    enum EventType
    {
        ET_NULL = 0,
        ET_KEY_PRESS,
        ET_KEY_REPEAT,
		ET_KEY_REPEAT_WAIT,
        ET_KEY_IMPULSE,
        ET_KEY_RELEASE,
        ET_MOUSE_PRESS,
        ET_MOUSE_RELEASE,
        ET_MOUSE_MOVE,
        ET_MOUSE_SCROLL
    };



    struct Event
    {
        Event() :
            type(ET_NULL),
            param1(0),
            param2(0)
        {
        };

        Event(EventType n) :
            type(n),
            param1(0),
            param2(0)
        {
        };

        Event(EventType n, float p1, float p2) :
            type(n),
            param1(p1),
            param2(p2)
        {
        };

        EventType type;
        float param1;
        float param2;
        Ogre::String event;
    };
}
