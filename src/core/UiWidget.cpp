#include "UiWidget.h"



UiWidget::UiWidget( const Ogre::String& name ):
    m_Name( name ),
    m_Parent( NULL )
{
}



UiWidget::UiWidget( const Ogre::String& name, UiWidget* parent ):
    m_Name( name ),
    m_Parent( parent )
{
}



UiWidget::~UiWidget()
{
    RemoveAllChildren();
}



void
UiWidget::Update()
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->Update();
    }
}



const Ogre::String&
UiWidget::GetName() const
{
    return m_Name;
}



void
UiWidget::RemoveAllChildren()
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        delete m_Children[ i ];
    }
    m_Children.clear();
}
