#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <OgreRenderQueueListener.h>
#include <OgreSingleton.h>
#include <OgreUTFString.h>
#include <tinyxml/tinyxml.h>

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
    void AddText( const Ogre::String& name, TiXmlNode* text );
    void UnloadTexts();
    TiXmlNode* GetText( const Ogre::String& name ) const;

    void AddFont( UiFont* font );
    UiFont* GetFont( const Ogre::String& name );

    void AddPrototype( const Ogre::String& name, TiXmlNode* prototype );
    TiXmlNode* GetPrototype( const Ogre::String& name ) const;

    void AddWidget( UiWidget* widget );
    UiWidget* GetWidget( const Ogre::String& name );
    UiWidget* ScriptGetWidget( const char* name );

    void renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation );

private:
    std::vector< UiWidget* > m_Widgets;
    struct UiText
    {
        Ogre::String name;
        TiXmlNode* node;
    };
    std::vector< UiText > m_Texts;
    std::vector< UiFont* > m_Fonts;
    struct UiPrototype
    {
        Ogre::String name;
        TiXmlNode* node;
    };
    std::vector< UiPrototype > m_Prototypes;
};


#endif // UI_MANAGER_H
