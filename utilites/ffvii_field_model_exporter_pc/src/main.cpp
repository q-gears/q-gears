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
#include "QGearsHRCFileManager.h"
#include "QGearsPFileSerializer.h"

void attachMesh( Ogre::MeshPtr &mesh )
{
    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* entity = scene_manager->createEntity( mesh );
    entity->setDisplaySkeleton( true );
    entity->setDebugDisplayEnabled( true );
    entity->getAnimationState( "Idle" )->setEnabled( true );
    entity->getAnimationState( "Idle" )->setLoop( true );
    Ogre::SceneNode* root_node = scene_manager->getRootSceneNode();
    root_node->showBoundingBox( true );
    root_node->attachObject( entity );

    entitys.push_back( entity );
}

Ogre::DataStreamPtr getStream( const Ogre::String& file_name )
{
    return Ogre::ResourceGroupManager::getSingleton().openResource( file_name );
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
    QGears::HRCFileManager      *hrc_manager;
    QGears::AFile               a;
    QGears::AFileSerializer     a_ser;
    QGears::HRCFilePtr          hrc;
    QGears::PFile               p;
    QGears::PFileSerializer     p_ser;
    Ogre::String                unit( "n_cloud");

    hrc_manager = new QGears::HRCFileManager();
    hrc = hrc_manager->load( "field/char/aaaa.hrc", "Game" );

    Ogre::LogManager::getSingleton().stream()
      << "\n " << " hrc Ressource: " << hrc->getName();

    Ogre::SkeletonPtr skeleton( hrc->createSkeleton( unit + ".skeleton", "General" ) );
    Ogre::MeshPtr mesh( Ogre::MeshManager::getSingleton().create( unit + ".mesh", "General" ) );
    mesh->_notifySkeleton( skeleton );
    mesh->setSkeletonName( skeleton->getName() );

    stream = getStream( "field/char/aaac.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "hip", "aaab" );

    stream = getStream( "field/char/aaae.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "chest", "aaad" );

    stream = getStream( "field/char/aaba.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "head", "aaaf" );

    stream = getStream( "field/char/aafd.p" );
    p_ser.importPFile( stream, &p );
    p.addGroups( mesh.getPointer(), "r_foot", "aafc" );

    stream = getStream( "field/char/acfe.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Idle" );
    stream = getStream( "field/char/aaff.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Walk" );
    stream = getStream( "field/char/aaga.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Run" );
    stream = getStream( "field/char/bvjf.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "JumpFromTrain" );

    sk_ser.exportSkeleton( skeleton.getPointer(), skeleton->getName() );

    mesh_ser.exportMesh( mesh.getPointer(), mesh->getName() );
    attachMesh( mesh );

    mesh.setNull();
    entitys[0]->setVisible( true );

    Ogre::Root::getSingleton().startRendering();
    hrc.setNull();
    delete hrc_manager;
    DeinitializeOgreBase();

    return 0;
}
