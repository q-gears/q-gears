#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <OgreSingleton.h>

#include "UiWidget.h"



class UiManager : public Ogre::Singleton< UiManager >
{
public:
    UiManager();
    virtual ~UiManager();

    void Update();

private:
    UiWidget* m_BaseWidget;
};



#endif // UI_MANAGER_H
