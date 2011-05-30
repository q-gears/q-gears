// $Id$

#ifndef LINE_TRIGGER_LINE_h
#define LINE_TRIGGER_LINE_h

#include <Ogre.h>



class _OgreExport LineTriggerLine : public Ogre::SimpleRenderable
{
public:
                 LineTriggerLine(const Ogre::Vector3& point1, const Ogre::Vector3& point2);
    virtual     ~LineTriggerLine(void);

    void         SetPoints(const Ogre::Vector3& point1, const Ogre::Vector3& point2);

    Ogre::Real   getSquaredViewDepth(const Ogre::Camera* cam) const;
    Ogre::Real   getBoundingRadius(void) const;
};



#endif // LINE_TRIGGER_LINE_h
