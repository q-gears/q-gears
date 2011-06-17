#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <OgreSingleton.h>



class UiManager : public Ogre::Singleton< UiManager >
{
public:
    UiManager();
    virtual ~UiManager();

    void Update();
};



#endif // UI_MANAGER_H
