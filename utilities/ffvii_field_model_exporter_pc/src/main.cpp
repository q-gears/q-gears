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
#include <OgreMesh.h>

#include "FF7FieldModelExporterPC.h"
#include "common/TypeDefine.h"
#include "common/QGearsStringUtil.h"

#include "data/QGearsAFileManager.h"
#include "data/QGearsHRCFileManager.h"
#include "data/QGearsLZSFLevelFileManager.h"

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
    entity->setVisible( false );

    entitys.push_back( entity );
}

void exportMesh( const Ogre::MeshPtr &mesh )
{
    Ogre::MeshSerializer        mesh_ser;
    mesh_ser.exportMesh( mesh.getPointer(), mesh->getName() );

    Ogre::SkeletonPtr           skeleton( mesh->getSkeleton() );
    Ogre::SkeletonSerializer    sk_ser;
    sk_ser.exportSkeleton( skeleton.getPointer(), skeleton->getName() );

    Ogre::Mesh::SubMeshIterator it( mesh->getSubMeshIterator() );
    Ogre::MaterialSerializer    mat_ser;
    size_t i(0);
    while( it.hasMoreElements() )
    {
        Ogre::SubMesh *sub_mesh( it.getNext() );
        Ogre::MaterialPtr mat( Ogre::MaterialManager::getSingleton().getByName( sub_mesh->getMaterialName() ) );
        if( !mat.isNull() )
        {
            mat_ser.queueForExport( mat );
        }
        ++i;
    }
    QGears::String base_name;
    QGears::StringUtil::splitFull( mesh->getName(), base_name );
    mat_ser.exportQueued( base_name + QGears::EXT_MATERIAL );
}

int
main( int argc, char *argv[] )
{
    QGears::FF7::FieldModelExporterPC app( argc, argv );
    if( !app.initOgre() ) return 0;

    Ogre::SceneManager*         scene_manager( Ogre::Root::getSingleton().getSceneManager( "Scene" ) );
    QGears::AFilePtr            a;
    QGears::HRCFilePtr          hrc( QGears::HRCFileManager::getSingleton().load( "adda.hrc", "FFVII" ));
    QGears::AFileManager       &afl_mgr( QGears::AFileManager::getSingleton() );

    Ogre::MeshPtr mesh( Ogre::MeshManager::getSingleton().load( "sd_red.mesh", "FFVII" ) );
    Ogre::SkeletonPtr skeleton( mesh->getSkeleton() );

    a = afl_mgr.load( "aeae.a", "FFVII" );
    a->addTo( skeleton, "Idle" );
    a = afl_mgr.load( "aeaf.a", "FFVII" );
    a->addTo( skeleton, "Walk" );
    a = afl_mgr.load( "aeba.a", "FFVII" );
    a->addTo( skeleton, "Run" );

    attachMesh( mesh );
    entitys[0]->setVisible( true );

    QGears::LZSFLevelFileManager   &fmgr( QGears::LZSFLevelFileManager::getSingleton() );
    QGears::FLevelFilePtr           f( fmgr.load( "ancnt1", "FFVII" ) );

    mesh = Ogre::MeshManager::getSingleton().load( "n_cloud.mesh", "FFVII" );
    skeleton = mesh->getSkeleton();
    a = afl_mgr.load( "bvjf.a", "FFVII" );
    a->addTo( skeleton, "JumpFromTrain" );
    attachMesh( mesh );

    // Create background rectangle covering the whole screen
    Ogre::Rectangle2D* rect = new Ogre::Rectangle2D(true);
    rect->setCorners(-1.0, 1.0, 1.0, -1.0);
    rect->setMaterial( "map" );

    // Render the background before everything else
    rect->setRenderQueueGroup( Ogre::RENDER_QUEUE_BACKGROUND );

    // Use infinite AAB to always stay visible
    Ogre::AxisAlignedBox aabInf;
    aabInf.setInfinite();
    rect->setBoundingBox( aabInf );

    // Attach background to the scene
    Ogre::SceneNode* node = scene_manager->getRootSceneNode()->createChildSceneNode("Background");
    node->attachObject( rect );

    Ogre::Root::getSingleton().startRendering();
    skeleton.setNull();
    mesh.setNull();
    f.setNull();
    hrc.setNull();
    delete rect;

    return 0;
}
