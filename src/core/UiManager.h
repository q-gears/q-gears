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

    void Initialise();

    void Update();

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

private:
    std::vector< UiWidget* > m_Widgets;
};



#endif // UI_MANAGER_H
