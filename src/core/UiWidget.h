#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <OgreString.h>
#include <vector>



class UiWidget
{
public:
                        UiWidget( const Ogre::String& name );
                        UiWidget( const Ogre::String& name, UiWidget* parent );
    virtual            ~UiWidget();

    void                Update();

    const Ogre::String& GetName() const;

    void                AddChild( UiWidget *widget );
    void                RemoveChild( UiWidget *widget );
    UiWidget*           GetChild( const Ogre::String& name );
    void                RemoveAllChildren();

private:
    UiWidget();

private:
    Ogre::String             m_Name;

    UiWidget*                m_Parent;
    std::vector< UiWidget* > m_Children;
};



#endif // UI_WIDGET_H
