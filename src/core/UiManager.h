#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <OgreRenderQueueListener.h>
#include <OgreSingleton.h>

#include "UiWidget.h"



class UiManager : public Ogre::RenderQueueListener, public Ogre::Singleton< UiManager >
{
public:
    UiManager();
    virtual ~UiManager();

    void Update();

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

private:
    UiWidget* m_BaseWidget;
};



#endif // UI_MANAGER_H
