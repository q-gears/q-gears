#include "ff7DataInstaller.h"

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <OgreConfigFile.h>
#include <OgreArchiveManager.h>
#include <OgreMeshSerializer.h>
#include <OgreSkeletonSerializer.h>
#include <OgreMeshManager.h>
#include <OgreRenderWindow.h>
#include <OgreHardwarePixelBuffer.h>

#include "QGearsGameState.h"
#include "data/QGearsAFileManager.h"
#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsCameraMatrixFileManager.h"
#include "data/QGearsHRCFileManager.h"
#include "data/QGearsLZSFLevelFileManager.h"
#include "data/QGearsPaletteFileManager.h"
#include "data/QGearsPFileManager.h"
#include "data/QGearsRSDFileManager.h"
#include "data/QGearsTexCodec.h"
#include "map/QGearsBackground2DFileManager.h"
#include "map/QGearsWalkmeshFileManager.h"
#include "data/FF7ModelListFileManager.h"
#include "data/QGearsLGPArchiveFactory.h"
#include "common/QGearsStringUtil.h"
#include "common/FF7NameLookup.h"
#include "data/QGearsTexCodec.h"

FF7DataInstaller::FF7DataInstaller()
#ifdef _DEBUG
    : mApp("plugins_d.cfg", "resources_d.cfg", "install_d.log")
#else
    : mApp("plugins.cfg", "resources.cfg", "install.log")
#endif
{
    mApp.initOgre(true);
}

FF7DataInstaller::~FF7DataInstaller()
{

}

void FF7DataInstaller::Convert(std::string inputDir, std::string outputDir, const std::vector<std::string>& files)
{
    for (const auto& file : files)
    {
        // TODO: Comparison will be incorrect on some platforms
        if (file == "field\\char.lgp")
        {
            auto fullPath = inputDir + file;
            mApp.getRoot()->addResourceLocation(fullPath, "LGP", "FFVII");
            ConvertFieldModels(fullPath, outputDir);
        }
    }
}

// TOOD: Share with pc model exporter
static void exportMesh(std::string outdir, const Ogre::MeshPtr &mesh)
{
    Ogre::MeshSerializer        mesh_ser;
    mesh_ser.exportMesh(mesh.getPointer(), outdir +  mesh->getName());

    Ogre::SkeletonPtr           skeleton(mesh->getSkeleton());
    Ogre::SkeletonSerializer    sk_ser;
    sk_ser.exportSkeleton(skeleton.getPointer(), outdir +  skeleton->getName());

    Ogre::Mesh::SubMeshIterator it(mesh->getSubMeshIterator());
    Ogre::MaterialSerializer    mat_ser;
    size_t i(0);
    while (it.hasMoreElements())
    {
        Ogre::SubMesh *sub_mesh(it.getNext());
        Ogre::MaterialPtr mat(Ogre::MaterialManager::getSingleton().getByName(sub_mesh->getMaterialName()));
        if (!mat.isNull())
        {
            mat_ser.queueForExport(mat);
        }
        ++i;
    }
    QGears::String base_name;
    QGears::StringUtil::splitFull(mesh->getName(), base_name);
    mat_ser.exportQueued(outdir + base_name + QGears::EXT_MATERIAL);
}


void FF7DataInstaller::ConvertFieldModels(std::string archive, std::string outDir)
{

    //QGears::LZSFLevelFileManager   &fmgr(QGears::LZSFLevelFileManager::getSingleton());

   // QGears::FLevelFilePtr           f = fmgr.load(archive, "FFVII").staticCast<QGears::FLevelFile>();

    Ogre::SceneManager*         scene_manager(Ogre::Root::getSingleton().createSceneManager(Ogre::ST_GENERIC, "Scene"));
    QGears::AFilePtr            a;
    Ogre::ResourcePtr hrc = QGears::HRCFileManager::getSingleton().load("adda.hrc", "FFVII");
    QGears::HRCFilePtr r = hrc.staticCast<QGears::HRCFile>();
    QGears::AFileManager       &afl_mgr(QGears::AFileManager::getSingleton());

    auto meshName = QGears::FF7::NameLookup::model("adda.hrc") + ".mesh";

    /*
    TODO:
      To figure out what .a files relate to which .hrc files, we need to enumerate every field
      and check its model loader data. These are always Idle, Walk, Run and then field specific
      ordering.
      Model loader is section 3 of the field file.

    */

    Ogre::MeshPtr mesh(Ogre::MeshManager::getSingleton().load(meshName, "FFVII"));
    Ogre::SkeletonPtr skeleton(mesh->getSkeleton());


    exportMesh(outDir, mesh);

}

