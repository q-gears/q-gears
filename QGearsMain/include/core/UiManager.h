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


    void AddFont( UiFont* font );
    UiFont* GetFont( const Ogre::String& name );

    void AddPrototype( const Ogre::String& name, TiXmlNode* prototype );
    TiXmlNode* GetPrototype( const Ogre::String& name ) const;

    void AddWidget( UiWidget* widget );
    UiWidget* GetWidget( const Ogre::String& name );
    UiWidget* ScriptGetWidget( const char* name );

    void renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation );

private:
    std::vector< UiFont* > m_Fonts;
    struct UiPrototype
    {
        Ogre::String name;
        TiXmlNode* node;
    };
    std::vector< UiPrototype > m_Prototypes;
    std::vector< UiWidget* > m_Widgets;
};



#endif // UI_MANAGER_H
