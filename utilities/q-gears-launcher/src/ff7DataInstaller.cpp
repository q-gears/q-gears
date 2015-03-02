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
#include "data/QGearsMapListFile.h"
#include "decompiler/sudm.h"
#include <memory>

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

const int kInactiveGateWayId = 32767;

class SpawnPointDb
{
public:
    // Id of the field the gateways records from N other number of fields are linking to
    u16 mTargetFieldId = 0;

    class Record
    {
    public:
        u16 mFieldId = 0;
        u32 GatewayIndex = 0;
        QGears::TriggersFile::Gateway mGateway;
    };
    std::vector<Record> mGatewaysToThisField;
};
typedef std::map<u16, SpawnPointDb> FieldSpawnPointsMap;

static size_t FieldId(const std::string& name, const std::vector<std::string>& fieldIdToNameLookup)
{
    for (size_t i = 0; i < fieldIdToNameLookup.size(); i++)
    {
        if (fieldIdToNameLookup[i] == name)
        {
            return i;
        }
    }
    throw std::runtime_error("No Id found for field name");
}

static void FF7PcFieldToQGearsField(QGears::FLevelFilePtr& field, const std::string& outDir, const std::vector<std::string>& fieldIdToNameLookup, const FieldSpawnPointsMap& spawnMap)
{
    // Save out the tiles as a PNG image
    

    try
    {
        // Get the raw script bytes
        const std::vector<u8> rawFieldData = field->getRawScript();

        // Decompile to LUA
        FF7FieldScriptFormatter formatter;
        std::string luaScript = SUDM::FF7::Field::Decompile(field->getName(), rawFieldData, formatter);
        std::ofstream scriptFile(outDir + "/" + field->getName() + ".lua");
        if (scriptFile.is_open())
        {
            scriptFile << luaScript;
        }
        else
        {
            std::cerr << "Failed to open script file for writing" << std::endl;
        }
    }
    catch (const ::InternalDecompilerError& ex)
    {
        std::cerr << "InternalDecompilerError: " << ex.what() << std::endl;
    }

    // TODO: Insert triggers into LUA script
    //const QGears::ModelListFilePtr& models = field->getModelList();
    //const QGears::ModelListFile::ModelDescription& desc = models->getModels().at(0);
    
    const QGears::TriggersFilePtr& triggers = field->getTriggers();

    // Write out the map file which links all the other files together for a given field
    {
        TiXmlDocument doc;
        std::unique_ptr<TiXmlElement> element(new TiXmlElement("map"));

        // Script
        std::unique_ptr<TiXmlElement> xmlScriptElement(new TiXmlElement("script"));
        xmlScriptElement->SetAttribute("file_name", field->getName() + ".lua");
        element->LinkEndChild(xmlScriptElement.release());

        // Background
        std::unique_ptr<TiXmlElement> xmlBackground2d(new TiXmlElement("background2d"));
        xmlBackground2d->SetAttribute("file_name", field->getName() + "_bg.xml");
        element->LinkEndChild(xmlBackground2d.release());
        
        // walkmesh
        std::unique_ptr<TiXmlElement> xmlWalkmesh(new TiXmlElement("walkmesh"));
        xmlWalkmesh->SetAttribute("file_name", field->getName() + "_wm.xml");
        element->LinkEndChild(xmlWalkmesh.release());


        std::unique_ptr<TiXmlElement> xmlMovementRotation(new TiXmlElement("movement_rotation"));
        xmlMovementRotation->SetAttribute("degree", std::to_string(triggers->MovementRotation()));
        element->LinkEndChild(xmlMovementRotation.release());

        // TODO: entity_script - name
        
        // TODO: entity_model - name, file_name,  position, direction
        // We set char 1 position to be position of first entity_point so player is spawned in sane
        // position if map is manually loaded via console.
        // None player chars set their first position in the init scripts. We know its a entity_model
        // because it uses PC opcode in init script.

        // entity_manager:get_entity("cl") is done via CHAR opcode


        // TODO: Get these scales from the field game data,  1024 for md1_1 and 512 for md1_2, DAT CFG has them as 2 and 1?
        const float downscaler_next = 128.0f; //  * MapIdToScale( map_id );
        const float downscaler_this = 128.0f; // * field.scale

        const auto& gateways = triggers->GetGateways();
        for (size_t i = 0; i < gateways.size(); i++)
        {
            const QGears::TriggersFile::Gateway& gateway = gateways[i];
            // if not inactive gateway
            if (gateway.destinationFieldId != kInactiveGateWayId)
            {
                std::unique_ptr<TiXmlElement> xmlEntityTrigger(new TiXmlElement("entity_trigger"));

                xmlEntityTrigger->SetAttribute("name", "Gateway" + std::to_string(i));

                xmlEntityTrigger->SetAttribute("point1",
                    Ogre::StringConverter::toString(
                    Ogre::Vector3(gateway.exit_line[0].x, gateway.exit_line[0].y, gateway.exit_line[0].z) / downscaler_this));

                xmlEntityTrigger->SetAttribute("point2",
                    Ogre::StringConverter::toString(
                    Ogre::Vector3(gateway.exit_line[1].x, gateway.exit_line[1].y, gateway.exit_line[1].z) / downscaler_this));

                // enabled hard coded to true
                xmlEntityTrigger->SetAttribute("enabled", "true");
                element->LinkEndChild(xmlEntityTrigger.release());
            }
        }

        // Get this fields Id
        const size_t thisFieldId = FieldId(field->getName(), fieldIdToNameLookup);

        // Use that to find the pre-computed list of gateways in all other fields that link to this field
        auto spawnIterator = spawnMap.find(thisFieldId);

        // If not found that it probably just means no other fields have doors to this one
        if (spawnIterator != std::end(spawnMap))
        {
            const std::vector<SpawnPointDb::Record>& spawnPointRecords = spawnIterator->second.mGatewaysToThisField;

            for (size_t i = 0; i < spawnPointRecords.size(); i++)
            {
                const QGears::TriggersFile::Gateway& gateway = spawnPointRecords[i].mGateway;
                // entity_point
                std::unique_ptr<TiXmlElement> xmlEntityPoint(new TiXmlElement("entity_point"));

                // Must also include the gateway index for the case where 2 fields have more than one door linking to each other
                xmlEntityPoint->SetAttribute("name", "Spawn_" + fieldIdToNameLookup.at(spawnPointRecords[i].mFieldId) + "_" + std::to_string(spawnPointRecords[i].GatewayIndex));


                xmlEntityPoint->SetAttribute("position",
                    Ogre::StringConverter::toString(
                    Ogre::Vector3(gateway.destination.x, gateway.destination.y, gateway.destination.z) / downscaler_next));

                const float rotation = (360.0f * static_cast<float>(gateway.dir)) / 255.0f;
                xmlEntityPoint->SetAttribute("rotation", std::to_string(rotation));

                element->LinkEndChild(xmlEntityPoint.release());
            }
        }

        doc.LinkEndChild(element.release());
        doc.SaveFile(outDir + "/" + field->getName() + ".xml");
    }


    const QGears::PaletteFilePtr& pal = field->getPalette();
    const QGears::BackgroundFilePtr& bg = field->getBackground();
    std::unique_ptr<Ogre::Image> bgImage(bg->createImage(pal));
    bgImage->save(outDir + "/" + field->getName() + ".png");

    {
        TiXmlDocument doc;
        std::unique_ptr<TiXmlElement> element(new TiXmlElement("background2d"));

        // Magic constants
        const int kScaleUpFactor = 3;
        const int kPsxScreenWidth = 320;
        const int kPsxScreenHeight = 240;

        // Get texture atlas size
        const int width = bgImage->getWidth();
        const int height = bgImage->getHeight();

        const QGears::CameraMatrixFilePtr& camMatrix = field->getCameraMatrix();
        const Ogre::Vector3 position = camMatrix->getPosition();
        const Ogre::Quaternion orientation = camMatrix->getOrientation();
        const Ogre::Degree fov = camMatrix->getFov(static_cast<float>(kPsxScreenHeight));

     
        const int min_x = triggers->getCameraRange().left * kScaleUpFactor;
        const int min_y = triggers->getCameraRange().top * kScaleUpFactor;
        const int max_x = triggers->getCameraRange().right * kScaleUpFactor;
        const int max_y = triggers->getCameraRange().bottom * kScaleUpFactor;

        element->SetAttribute("image", field->getName() + ".png");
        element->SetAttribute("position", Ogre::StringConverter::toString(position));
        element->SetAttribute("orientation", Ogre::StringConverter::toString(orientation));
        element->SetAttribute("fov", Ogre::StringConverter::toString(fov));
        element->SetAttribute("range", std::to_string(min_x) + " " + std::to_string(min_y) + " " + std::to_string(max_x) + " " + std::to_string(max_y));
        element->SetAttribute("clip", std::to_string(kPsxScreenWidth * kScaleUpFactor) + " " + std::to_string(kPsxScreenHeight * kScaleUpFactor));
   
        // Write out the *_BG.XML data
        auto& layers = bg->getLayers();
        for (const auto& layer : layers)
        {
            // TODO: Should we only output tiles to construct enabled layers?
          //  if (layer.enabled)
            {
               
                for (const QGears::BackgroundFile::SpriteData& sprite : layer.sprites)
                {
                    std::unique_ptr<TiXmlElement> xmlElement(new TiXmlElement("tile"));

                    xmlElement->SetAttribute("destination",
                        Ogre::StringConverter::toString(sprite.dst.x * kScaleUpFactor) + " " +
                        Ogre::StringConverter::toString(sprite.dst.y * kScaleUpFactor));

                    xmlElement->SetAttribute("width", Ogre::StringConverter::toString(sprite.width * kScaleUpFactor));
                    xmlElement->SetAttribute("height", Ogre::StringConverter::toString(sprite.height * kScaleUpFactor));

                    // Each tile is added to a big texture atlas with hard coded size of 1024x1024, convert UV's to the 0.0f to 1.0f range
                    const float u0 = static_cast<float>(sprite.src.x) / bgImage->getWidth();
                    const float v0 = static_cast<float>(sprite.src.y) / bgImage->getHeight();

                    const float u1 = static_cast<float>(sprite.src.x + sprite.width) / bgImage->getWidth();
                    const float v1 = static_cast<float>(sprite.src.y + sprite.height) / bgImage->getHeight();

                    xmlElement->SetAttribute("uv", 
                        Ogre::StringConverter::toString(u0) + " " + Ogre::StringConverter::toString(v0) + " " +
                        Ogre::StringConverter::toString(u1) + " " + Ogre::StringConverter::toString(v1)
                        );

                    // TODO: Figure out how to scale this value correctly
                    xmlElement->SetAttribute("depth", "999" /* Ogre::StringConverter::toString(static_cast<float>(sprite.depth) / (4096.0f/10.0f))*/);

                    // TODO: Copied from DatFile::AddTile - add to common method
                    Ogre::String blending_str = "";
                    if (sprite.blending == 0)
                    {
                        blending_str = "alpha";
                    }
                    else if (sprite.blending == 1)
                    {
                        blending_str = "add";
                    }
                    else if (sprite.blending == 2)
                    {
                        blending_str = "subtract";
                    }
                    else
                    {
                        // TODO: Should probably throw to fail conversion
                        blending_str = "unknown";
                    }
                    xmlElement->SetAttribute("blending", blending_str);
                    
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



static void CollectSpawnPoints(QGears::FLevelFilePtr& field, const std::vector<std::string>& fieldIdToNameLookup, FieldSpawnPointsMap& spawnPoints)
{
    const size_t thisFieldId = FieldId(field->getName(), fieldIdToNameLookup);
    const QGears::TriggersFilePtr& triggers = field->getTriggers();
    const auto& gateways = triggers->GetGateways();
    for (size_t i = 0; i < gateways.size(); i++)
    {
        const QGears::TriggersFile::Gateway& gateway = gateways[i];
        if (gateway.destinationFieldId != kInactiveGateWayId)
        {
            auto it = spawnPoints.find(gateway.destinationFieldId);
            if (it != std::end(spawnPoints))
            {
                // Add to the list of gateways that link to destinationFieldId
                SpawnPointDb::Record rec;
                rec.mFieldId = thisFieldId;
                rec.mGateway = gateway;
                rec.GatewayIndex = i;
                it->second.mGatewaysToThisField.push_back(rec);
            }
            else
            {
                // Create a new record for destinationFieldId
                SpawnPointDb db;
                db.mTargetFieldId = gateway.destinationFieldId;

                SpawnPointDb::Record rec;
                rec.mFieldId = thisFieldId;
                rec.mGateway = gateway;
                rec.GatewayIndex = i;
                db.mGatewaysToThisField.push_back(rec);

                spawnPoints.insert(std::make_pair(db.mTargetFieldId, db));
            }
        }
    }
}

static bool IsAFieldFile(Ogre::String& resourceName)
{
    return (!QGears::StringUtil::endsWith(resourceName, ".tex")
        && !QGears::StringUtil::endsWith(resourceName, ".tut")
        && !QGears::StringUtil::endsWith(resourceName, ".siz")
        && resourceName != "maplist");
}

void FF7DataInstaller::ConvertFields(std::string archive, std::string outDir)
{
    // List whats in the LGP archive
    Ogre::StringVectorPtr resources = mApp.ResMgr()->listResourceNames("FFVIIFields", "*");

    // Load the map list field
    QGears::MapListFilePtr mapList = QGears::MapListFileManager::getSingleton().load("maplist", "FFVIIFields").staticCast<QGears::MapListFile>();

    // On the first pass collate required field information
    FieldSpawnPointsMap spawnPoints;
    for (auto& resourceName : *resources)
    {
        // Exclude things that are not fields
        if (IsAFieldFile(resourceName))
        {
            QGears::FLevelFilePtr field = QGears::LZSFLevelFileManager::getSingleton().load(resourceName, "FFVIIFields").staticCast<QGears::FLevelFile>();
            CollectSpawnPoints(field, mapList->GetMapList(), spawnPoints);
        }
    }

    // Now we can do the full conversion with the collated data
    for (auto& resourceName : *resources)
    {
        // Exclude things that are not fields
        if (IsAFieldFile(resourceName))
        {
            if (resourceName == "md1_2") // Testing conversion only on this field for now
            {
                QGears::FLevelFilePtr field = QGears::LZSFLevelFileManager::getSingleton().load(resourceName, "FFVIIFields").staticCast<QGears::FLevelFile>();
                FF7PcFieldToQGearsField(field, outDir, mapList->GetMapList(), spawnPoints);
            }
        }
    }
    
}
