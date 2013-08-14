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

#include <OgreLogManager.h>
#include <OgreSceneManager.h>

#include "common/OgreBase.h"

#include "QGearsAFileSerializer.h"
#include "QGearsHRCFileSerializer.h"
#include "QGearsPFileSerializer.h"

void attachMesh( const Ogre::String &mesh_name )
{
    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* entity = scene_manager->createEntity( mesh_name );
    entity->setDisplaySkeleton(true);
    entity->setDebugDisplayEnabled(true);
    entity->getAnimationState( "Idle" )->setEnabled( true );
    entity->getAnimationState( "Idle" )->setLoop( true );
    Ogre::SceneNode* root_node = scene_manager->getRootSceneNode();
    root_node->attachObject( entity );
    entitys.push_back( entity );
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

    Ogre::SceneManager*         scene_manager( Ogre::Root::getSingleton().getSceneManager( "Scene" ) );
    Ogre::ManualObject*         mo( scene_manager->createManualObject() );
    Ogre::DataStreamPtr         stream;
    Ogre::MeshSerializer        mesh_ser;
    Ogre::SkeletonSerializer    sk_ser;
    QGears::AFile               a;
    QGears::AFileSerializer     a_ser;
    QGears::HRCFile             hrc;
    QGears::HRCFileSerializer   hrc_ser;
    QGears::PFile               p;
    QGears::PFileSerializer     p_ser;
    Ogre::String                unit( "n_cloud");

    stream = getStream( "../../../output/data_orig/field/char/aaaa.hrc" );
    hrc_ser.importHRCFile( stream, &hrc );
    Ogre::SkeletonPtr skeleton( hrc.createSkeleton( unit, "General" ) );
    Ogre::MeshPtr mesh( Ogre::MeshManager::getSingleton().create( unit, "General" ) );
    mesh->_notifySkeleton( skeleton );
    mesh->setSkeletonName( skeleton->getName() + ".skeleton" );

    stream = getStream( "../../../output/data_orig/field/char/aaac.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "hip", "aaab" );

    stream = getStream( "../../../output/data_orig/field/char/aaae.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "chest", "aaad" );

    stream = getStream( "../../../output/data_orig/field/char/aaba.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "head", "aaaf" );

    stream = getStream( "../../../output/data_orig/field/char/acfe.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Idle" );
    stream = getStream( "../../../output/data_orig/field/char/aaff.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Walk" );
    stream = getStream( "../../../output/data_orig/field/char/aaga.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Run" );
    stream = getStream( "../../../output/data_orig/field/char/bvjf.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "JumpFromTrain" );

    sk_ser.exportSkeleton( skeleton.getPointer(), skeleton->getName() + ".skeleton" );

    mesh_ser.exportMesh( mesh.getPointer(), mesh->getName() + ".mesh" );
    attachMesh( mesh->getName() + ".mesh" );

    mesh.setNull();
    entitys[0]->setVisible( true );

    Ogre::Root::getSingleton().startRendering();
    DeinitializeOgreBase();

    return 0;
}
