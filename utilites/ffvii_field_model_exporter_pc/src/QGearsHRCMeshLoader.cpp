/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-13 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsHRCMeshLoader.h"

#include <OgreMesh.h>

#include "QGearsPFile.h"
#include "QGearsPFileManager.h"
#include "QGearsHRCFile.h"
#include "QGearsRSDFileManager.h"
#include "QGearsStringUtil.h"

namespace QGears
{
    typedef HRCFile::Bone           Bone;
    typedef HRCFile::BoneList       BoneList;
    typedef HRCFile::RSDNameList    RSDNameList;

    //-------------------------------------------------------------------------
    HRCMeshLoader::HRCMeshLoader( HRCFile &hrc_file ) :
        m_hrc_file( hrc_file )
    {
    }

    //-------------------------------------------------------------------------
    HRCMeshLoader::~HRCMeshLoader()
    {
    }

    //-------------------------------------------------------------------------
    void
    HRCMeshLoader::loadResource( Ogre::Resource *resource )
    {
        Ogre::Mesh *mesh( static_cast<Ogre::Mesh *>( resource ) );
        assert( mesh );

        m_hrc_file.load();
        mesh->_notifyOrigin( m_hrc_file.getName() );
        mesh->setSkeletonName( m_hrc_file.getSkeletonFileName() );

        String path;
        StringUtil::splitPath( m_hrc_file.getName(), path );

        BoneList::const_iterator it( m_hrc_file.getBones().begin() );
        BoneList::const_iterator end( m_hrc_file.getBones().end() );
        while( it != end )
        {
            loadBone( mesh, *(it++), path );
        }
    }

    //-------------------------------------------------------------------------
    void
    HRCMeshLoader::loadBone( Ogre::Mesh *mesh, const Bone &bone, const String &path )
    {
        const String &bone_name( bone.name );
        RSDNameList::const_iterator it( bone.rsd_names.begin() );
        RSDNameList::const_iterator end( bone.rsd_names.end() );
        String rsd_base, rsd_file_name, p_file_name;
        while( it != end )
        {
            rsd_base = path + *it;
            StringUtil::toLowerCase( rsd_base );
            rsd_file_name = rsd_base + EXT_RSD;
            RSDFilePtr rsd_file( RSDFileManager::getSingleton().load( rsd_file_name, m_hrc_file.getGroup() ) );
            assert( !rsd_file.isNull() );

            p_file_name = path + rsd_file->getPolygonName();
            StringUtil::toLowerCase( p_file_name );
            p_file_name = StringUtil::replaceAll( p_file_name, EXT_PLY, EXT_P );
            PFilePtr p_file( PFileManager::getSingleton().load( p_file_name, m_hrc_file.getGroup() ) );
            assert( !p_file.isNull() );

            p_file->addGroups( mesh, bone_name, rsd_file );

            ++it;
        }
    }

    //-------------------------------------------------------------------------
}
