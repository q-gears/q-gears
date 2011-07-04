#ifndef UI_ANIMATION_H
#define UI_ANIMATION_H

#include <OgreString.h>
#include <vector>



class UiAnimation
{
public:
    UiAnimation( const Ogre::String& name );
    virtual ~UiAnimation();

    const Ogre::String& GetName() const;

private:
    UiAnimation();

protected:
    Ogre::String m_Name;
};



#endif // UI_ANIMATION_H
