/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-11 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef __QGearsHRCFile_H__
#define __QGearsHRCFile_H__

#include <OgreResource.h>
#include <OgreMesh.h>
#include <OgreSkeleton.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class HRCMeshLoader;
    class HRCSkeletonLoader;

    class HRCFile : public Ogre::Resource
    {
    public:
        static const float kDownScaler;

        HRCFile( Ogre::ResourceManager *creator, const String &name
                ,Ogre::ResourceHandle handle, const String &group
                ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~HRCFile();

        typedef std::vector<String> RSDNameList;

        struct Bone
        {
            String      name;
            String      parent;
            Ogre::Real  length;
            RSDNameList rsd_names;
        };

        typedef std::vector<Bone> BoneList;

        virtual void            setSkeletonName( const String& name );
        virtual const String&   getSkeletonName( void )     const { return m_skeleton_name; }
        virtual       String    getSkeletonFileName( void ) const;
        virtual       String    getMeshFileName( void )     const;
        virtual       BoneList& getBones( void )       { return m_bones; }
        virtual const BoneList& getBones( void ) const { return m_bones; }

        virtual Ogre::SkeletonPtr   getSkeleton( void ) const;

        static const String RESOURCE_TYPE;

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;
        virtual size_t calculateSize( const Bone &bone ) const;

    private:
        String      m_skeleton_name;
        BoneList    m_bones;

        HRCMeshLoader      *m_mesh_loader;
        HRCSkeletonLoader  *m_skeleton_loader;
        Ogre::SkeletonPtr   m_skeleton;
        Ogre::MeshPtr       m_mesh;
    };

    typedef Ogre::SharedPtr<HRCFile> HRCFilePtr;
}

#endif // __QGearsHRCFile_H__
