#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <OgreRenderQueueListener.h>
#include <OgreSingleton.h>
#include <OgreUTFString.h>

#include "UiFont.h"
#include "UiWidget.h"



class UiManager : public Ogre::RenderQueueListener, public Ogre::Singleton< UiManager >
{
public:
    UiManager();
    virtual ~UiManager();

    void Initialise();
    void Update();
    void OnResize();

    void SetLanguage( const Ogre::String& language );
    void AddText( const Ogre::String& name, const Ogre::UTFString& text );
    void UnloadTexts();
    const Ogre::UTFString GetText( const Ogre::String& name );

    void AddFont( UiFont* font );
    UiFont* GetFont( const Ogre::String& name );

    void AddWidget( UiWidget* widget );
    UiWidget* GetWidget( const Ogre::String& name );
    UiWidget* ScriptGetWidget( const char* name );

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

private:
    std::map< Ogre::String, Ogre::UTFString > m_Texts;
    std::vector< UiFont* > m_Fonts;
    std::vector< UiWidget* > m_Widgets;
};



#endif // UI_MANAGER_H
