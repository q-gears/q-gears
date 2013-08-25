// $Id$

#ifndef WALKMESH_h
#define WALKMESH_h

#include <OgrePrerequisites.h>
#include <OgreSimpleRenderable.h>
#include <vector>

#include "../../core/ui/MovableTextArea.h"



struct WalkmeshTriangle
{
    WalkmeshTriangle():
        a(0, 0, 0),
        b(0, 0, 0),
        c(0, 0, 0),
        locked(false)
    {
        access_side[0] = -1;
        access_side[1] = -1;
        access_side[2] = -1;
    }

    Ogre::Vector3 a;
    Ogre::Vector3 b;
    Ogre::Vector3 c;

    int           access_side[3];
    bool          locked;

    int           unknown1;
    int           unknown2;
};



class _OgreExport Walkmesh : public Ogre::SimpleRenderable
{
public:
                         Walkmesh(void);
    virtual             ~Walkmesh(void);

    void                 AddTriangle(const WalkmeshTriangle& triangle);

    const int            GetAccessSide(const int triangle_id, const unsigned char side) const;
    const Ogre::Vector3& GetA(const int triangle_id) const;
    const Ogre::Vector3& GetB(const int triangle_id) const;
    const Ogre::Vector3& GetC(const int triangle_id) const;
    void                 LockWalkmesh(const int triangle_id, const bool lock);
    const bool           IsLocked(const int triangle_id) const;

    void                 SetUpWalkmesh(void);

    Ogre::Real           getSquaredViewDepth(const Ogre::Camera* cam) const;
    Ogre::Real           getBoundingRadius(void) const;

    virtual void         setVisible(bool visible);

private:
    void                 SetUpWalkmeshVertices(void);

private:
    Ogre::Overlay*                m_Overlay;
    std::vector<WalkmeshTriangle> m_Triangles;
    std::vector<MovableTextArea*> m_TriangleTexts;
};



#endif // WALK_MESH_h
