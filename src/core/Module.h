#ifndef MODULE_H
#define MODULE_H

#include <OIS.h>
#include "Event.h"



enum MODULE_STATE
{
    MODULE_START,
    MODULE_RUN,
    MODULE_FINISH,
    MODULE_STOP,
    MODULE_PAUSE
};



class Module
{
public:
    virtual ~Module(){};

    virtual void Input(const Event& event) = 0;
    virtual void Update() = 0;

    void SetState(const MODULE_STATE state) {m_State = state;};
    const MODULE_STATE GetState() const {return m_State;};

private:
    MODULE_STATE m_State;
};



#endif // MODULE_H
