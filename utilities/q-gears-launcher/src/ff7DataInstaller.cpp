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
#include "decompiler/sudm.h"

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
        if (file == "field/char.lgp")
        {
            /*
            auto fullPath = inputDir + file;
            mApp.getRoot()->addResourceLocation(fullPath, "LGP", "FFVII");
            ConvertFieldModels(fullPath, outputDir);
            mApp.getRoot()->removeResourceLocation(fullPath, "FFVII");*/
        }
        else if (file == "field/flevel.lgp")
        {
            auto fullPath = inputDir + file;
            mApp.getRoot()->addResourceLocation(fullPath, "LGP", "FFVIIFields");
            ConvertFields(fullPath, outputDir);
            mApp.getRoot()->removeResourceLocation(fullPath, "FFVIIFields");
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
    Ogre::StringVectorPtr resources = mApp.ResMgr()->listResourceNames("FFVII", "*.hrc");
    for (auto& resourceName : *resources)
    {
        if (QGears::StringUtil::endsWith(resourceName, ".hrc"))
        {
            //try
            {
                Ogre::ResourcePtr hrc = QGears::HRCFileManager::getSingleton().load(resourceName, "FFVII");

                Ogre::String baseName;
                QGears::StringUtil::splitBase(resourceName, baseName);

                auto meshName = QGears::FF7::NameLookup::model(baseName) + ".mesh";

                Ogre::MeshPtr mesh(Ogre::MeshManager::getSingleton().load(meshName, "FFVII"));
                Ogre::SkeletonPtr skeleton(mesh->getSkeleton());
                exportMesh(outDir, mesh);
            }
           // catch (const Ogre::Exception& ex)
            {
               // std::cout << "ERROR converting: " << resourceName << " Exception: " << ex.what() << std::endl;
            }
        }
    }


    /*
    TODO:
    To figure out what .a files relate to which .hrc files, we need to enumerate every field
    and check its model loader data. These are always Idle, Walk, Run and then field specific
    ordering.
    Model loader is section 3 of the field file.
    */
}

class FF7FieldScriptFormatter : public SUDM::IScriptFormatter
{
public:
    virtual bool ExcludeFunction(const std::string& ) override
    {
        // Include everything for now
        return false;
    }


    virtual std::string RenameIdentifer(const std::string& name) override
    {
        // Don't rename anything for now
        return name;
    }
};

static void FF7PcFieldToQGearsField(QGears::FLevelFilePtr& field, const std::string& outDir)
{
    // Save out the tiles as a PNG image
    
    const QGears::BackgroundFilePtr& bg = field->getBackground();

    try
    {
        // Get the raw script bytes
        const std::vector<u8> rawFieldData = field->getRawScript();

        // Decompile to LUA
        FF7FieldScriptFormatter formatter;
        std::string luaScript = SUDM::FF7::Field::Decompile(field->getName(), rawFieldData, formatter);
        std::cout << luaScript << std::endl;
    }
    catch (const ::InternalDecompilerError& ex)
    {
        std::cerr << "InternalDecompilerError: " << ex.what() << std::endl;
    }

    
    const QGears::PaletteFilePtr& pal = field->getPalette();
    std::unique_ptr<Ogre::Image> bgImage(bg->createImage(pal));
    bgImage->save(outDir + "/" + field->getName() + ".png");

    {
        TiXmlDocument doc;
        std::unique_ptr<TiXmlElement> element(new TiXmlElement("background2d"));

        auto& layers = bg->getLayers();
        const QGears::CameraMatrixFilePtr& camMatrix = field->getCameraMatrix();


        // TODO: Write out the *_BG.XML data
        for (auto& layer : layers)
        {
          //  if (layer.enabled)
            {
               
                for (QGears::BackgroundFile::SpriteData& sprite : layer.sprites)
                {
                    std::unique_ptr<TiXmlElement> xmlElement(new TiXmlElement("tile"));

                    // Not sure why it needs to be * 3
                    xmlElement->SetAttribute("destination", Ogre::StringConverter::toString(sprite.dst.x * 3) + " " + Ogre::StringConverter::toString(sprite.dst.y * 3));

                    // Each tile is added to a big texture atlas with hard coded size of 1024x1024
                    const float u0 = static_cast<float>(sprite.dst.x) / 1024.0f;
                    const float v0 = static_cast<float>(sprite.dst.y) / 1024.0f;

                    const float u1 = static_cast<float>(sprite.dst.x+sprite.width) / 1024.0f;
                    const float v1 = static_cast<float>(sprite.dst.y+sprite.height) / 1024.0f;

                    xmlElement->SetAttribute("uv", 
                        Ogre::StringConverter::toString(u0) + " " + Ogre::StringConverter::toString(v0) + " " +
                        Ogre::StringConverter::toString(u1) + " " + Ogre::StringConverter::toString(v1)
                        );

                    // TODO: Needs converting somehow
                    xmlElement->SetAttribute("depth", "999"/* Ogre::StringConverter::toString(sprite.depth)*/);


                    // TODO: Convert properly
                    xmlElement->SetAttribute("blending", "alpha" /* Ogre::StringConverter::toString(sprite.blending)*/);
                    
                    element->LinkEndChild(xmlElement.release());
                }
               
            }
        }
        doc.LinkEndChild(element.release());
        doc.SaveFile(outDir + "/" + field->getName() + "_bg.xml");
    }

    {
        // Save out the walk mesh as XML
        const QGears::WalkmeshFilePtr& walkmesh = field->getWalkmesh();

        TiXmlDocument doc;
        std::unique_ptr<TiXmlElement> element(new TiXmlElement("walkmesh"));
        for (QGears::WalkmeshFile::Triangle& tri : walkmesh->getTriangles())
        {
            std::unique_ptr<TiXmlElement> xmlElement(new TiXmlElement("triangle"));
            xmlElement->SetAttribute("a", Ogre::StringConverter::toString(tri.a));
            xmlElement->SetAttribute("b", Ogre::StringConverter::toString(tri.b));
            xmlElement->SetAttribute("c", Ogre::StringConverter::toString(tri.c));
            xmlElement->SetAttribute("a_b", std::to_string(tri.access_side[0]));
            xmlElement->SetAttribute("b_c", std::to_string(tri.access_side[1]));
            xmlElement->SetAttribute("c_a", std::to_string(tri.access_side[2]));
            element->LinkEndChild(xmlElement.release());
        }
        doc.LinkEndChild(element.release());
        doc.SaveFile(outDir + "/" + field->getName() + "_wm.xml");
    }
}

void FF7DataInstaller::ConvertFields(std::string archive, std::string outDir)
{
    // Everything in here is a field
    Ogre::StringVectorPtr resources = mApp.ResMgr()->listResourceNames("FFVIIFields", "*");
    for (auto& resourceName : *resources)
    {
        if (!QGears::StringUtil::endsWith(resourceName, ".tex")
         && !QGears::StringUtil::endsWith(resourceName, ".tut")
         && !QGears::StringUtil::endsWith(resourceName, ".siz")
         && resourceName != "maplist" && resourceName == "md1_2")
        {
            //try
            {
                QGears::FLevelFilePtr field = QGears::LZSFLevelFileManager::getSingleton().load(resourceName, "FFVIIFields").staticCast<QGears::FLevelFile>();
                FF7PcFieldToQGearsField(field, outDir);
            }
            /*
            catch (const Ogre::Exception& ex)
            {
                std::cout << "ERROR converting: " << resourceName << " Exception: " << ex.what() << std::endl;
            }
            catch (const std::exception& ex)
            {
                std::cout << "ERROR converting: " << resourceName << " Exception: " << ex.what() << std::endl;
            }*/
        }
    }
}
