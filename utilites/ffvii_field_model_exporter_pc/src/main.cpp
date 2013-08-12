/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-10 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include <fstream>

#include <OgreSceneManager.h>

#include "common/OgreBase.h"
#include "common/Logger.h"

#include "QGearsAFileSerializer.h"
#include "QGearsHRCFileSerializer.h"
#include "QGearsPFileSerializer.h"

void attachMesh( Ogre::MeshPtr mesh, const Ogre::String &name )
{
    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* entity = scene_manager->createEntity( mesh );
    entity->setDisplaySkeleton(true);
    entity->setDebugDisplayEnabled(true);
    entity->setVisible( true );
    //entity->getAnimationState( "Idle" )->setEnabled( true );
    //entity->getAnimationState( "Idle" )->setLoop( true );
    Ogre::SceneNode* root_node = scene_manager->getRootSceneNode();
    root_node->attachObject( entity );

    Ogre::MeshSerializer ser;
    ser.exportMesh( mesh.getPointer(), "test.mesh" );
}

Ogre::DataStreamPtr getStream( const Ogre::String& file_name )
{
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name.c_str(), std::ifstream::binary ) );
    Ogre::FileStreamDataStream *stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    return Ogre::DataStreamPtr( stream );
}

int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "FFVII Field Model Exporter" );

    Ogre::DataStreamPtr         stream;
    QGears::AFile               a;
    QGears::AFileSerializer     a_ser;
    QGears::HRCFile             hrc;
    QGears::HRCFileSerializer   hrc_ser;
    QGears::PFile               p;
    QGears::PFileSerializer     p_ser;

    stream = getStream( "../../../output/data_orig/field/char/aaaa.hrc" );
    hrc_ser.importHRCFile( stream, &hrc );

    stream = getStream( "../../../output/data_orig/field/char/aaba.p" );
    p_ser.importPFile( stream, &p );

    stream = getStream( "../../../output/data_orig/field/char/acfe.a" );
    a_ser.importAFile( stream, &a );

    Ogre::SkeletonPtr skeleton( hrc.createSkeleton( hrc.getName(), "General" ) );
    Ogre::ManualObject* mo( p.getManualObject() );
    Ogre::MeshPtr mesh( mo->convertToMesh( "n_cloud" ) );
    //Ogre::VertexDeclaration * decl = mesh->getSubMesh(0)->vertexData->vertexDeclaration;
    //mesh->getSubMesh(0)->vertexData->reorganiseBuffers(decl->getAutoOrganisedDeclaration(true,false));
    mesh->_notifySkeleton( skeleton );
    Ogre::Mesh::SubMeshIterator it( mesh->getSubMeshIterator() );
    Ogre::Bone* head( skeleton->getBone( "head" ) );
    u16 bone_index( head->getHandle() );
    while( it.hasMoreElements() )
    {
        Ogre::SubMesh* sub_mesh( it.getNext() );
        int vertex_number = sub_mesh->vertexData->vertexCount;
        for (int i = 0; i < vertex_number; ++i)
        {
            Ogre::VertexBoneAssignment vba;
            vba.vertexIndex = i;
            vba.boneIndex = bone_index;
            vba.weight = 1.0;
            sub_mesh->addBoneAssignment( vba );
        }
    }
    attachMesh( mesh, "test" );

    // cloud animations
    // acfe
    // aaff
    // aaga
    // bvjf

    Ogre::Root::getSingleton().startRendering();
    DeinitializeOgreBase();

    return 0;
}
