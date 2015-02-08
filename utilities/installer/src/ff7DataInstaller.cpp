#include "ff7DataInstaller.h"

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <OgreConfigFile.h>
#include <OgreArchiveManager.h>
#include <OgreMeshSerializer.h>
#include <OgreSkeletonSerializer.h>
#include <OgreMeshManager.h>

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
{
    try
    {
        m_root = std::make_unique<Ogre::Root>("plugins_d.cfg", "", "installer.log");

        if (!m_root->showConfigDialog())
        {
            //        return false;
        }
        m_render_window = m_root->initialise(true, "testing");


        Ogre::ArchiveManager::getSingleton().addArchiveFactory(new QGears::LGPArchiveFactory());

        mResourceManagers.emplace_back(std::make_shared<QGears::CameraMatrixFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::PaletteFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::WalkmeshFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::FF7::ModelListFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::HRCFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::RSDFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::AFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::PFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::LZSFLevelFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::BackgroundFileManager>());
        mResourceManagers.emplace_back(std::make_shared<QGears::Background2DFileManager>());

        QGears::TexCodec::install();
        QGears::TexCodec::initialise();
    }
    catch (const Ogre::Exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

FF7DataInstaller::~FF7DataInstaller()
{
    mResourceManagers.clear();
    QGears::TexCodec::shutdown();
    QGears::TexCodec::uninstall();
}

void FF7DataInstaller::Convert(std::string inputDir, std::string outputDir, const std::vector<std::string>& files)
{
    for (const auto& file : files)
    {
        if (file == "field\\char.lgp")
        {
            auto fullPath = inputDir + file;
         //   m_root->addResourceLocation(inputDir, "FileSystem", "FFVII");
            m_root->addResourceLocation(fullPath, "LGP", "FFVII");

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

    // TODO: Crashes as technique index out of bounds in the material
    Ogre::MeshPtr mesh(Ogre::MeshManager::getSingleton().load(meshName, "FFVII"));
    Ogre::SkeletonPtr skeleton(mesh->getSkeleton());


    exportMesh(outDir, mesh);

}

