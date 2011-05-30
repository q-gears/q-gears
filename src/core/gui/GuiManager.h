#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include <OgreSingleton.h>

#include "GuiEffect.h"
#include "../Event.h"



class GuiManager : public Ogre::Singleton< GuiManager >
{
public:
    GuiManager();
    virtual ~GuiManager();

    void Input( const Event& event );
    void Update();

private:
    Ogre::Overlay*  m_Overlay;

    GuiEffect* m_GuiEffect;
};



#endif // GUI_MANAGER_H
