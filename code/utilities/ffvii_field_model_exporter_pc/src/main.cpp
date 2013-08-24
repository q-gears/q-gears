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

#include <Ogre.h>

#include "common/OgreBase.h"

#include "data/QGearsAFileSerializer.h"
#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsPaletteFileManager.h"

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
    Ogre::MaterialSerializer    mat_ser;
    Ogre::SkeletonSerializer    sk_ser;
    QGears::AFileSerializer     a_ser;
    QGears::AFile               a;

    Ogre::MeshPtr mesh( Ogre::MeshManager::getSingleton().load( "field/char/sd_red_sk.mesh", "Game" ) );
    Ogre::SkeletonPtr skeleton( mesh->getSkeleton() );

    stream = getStream( "field/char/aeae.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Idle" );
    stream = getStream( "field/char/aeaf.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Walk" );
    stream = getStream( "field/char/aeba.a" );
    a_ser.importAFile( stream, &a );
    a.addTo( skeleton, "Run" );

    QGears::BackgroundFileManager  *bmgr( QGears::BackgroundFileManager::getSingletonPtr() );
    QGears::PaletteFileManager     *pmgr( QGears::PaletteFileManager::getSingletonPtr() );
    QGears::PaletteFilePtr      p( pmgr->load( "ancnt1.palette", "General" ) );
    QGears::BackgroundFilePtr   b( bmgr->load( "ancnt1.background", "General" ) );

    Ogre::Image *image( b->createImage( p ) );
    image->save( "ancnt1.png" );
    delete image;

    b.setNull();
    p.setNull();

    //sk_ser.exportSkeleton( skeleton.getPointer(), skeleton->getName() );
    //mesh_ser.exportMesh( mesh.getPointer(), mesh->getName() );

    attachMesh( mesh );

    entitys[0]->setVisible( true );

    Ogre::Root::getSingleton().startRendering();
    skeleton.setNull();
    mesh.setNull();
    DeinitializeOgreBase();

    return 0;
}
