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

#include <QDir>

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
    // TODO: Just validate required files are present
    for (const auto& file : files)
    {
        if (file == "field/flevel.lgp")
        {
            auto fullPath = inputDir + file;
            mApp.getRoot()->addResourceLocation(fullPath, "LGP", "FFVIIFields");
            ConvertFields(fullPath, inputDir, outputDir);
            mApp.getRoot()->removeResourceLocation(fullPath, "FFVIIFields");
        }
    }
}

static std::string FieldModelDir()
{
    return "models/ffvii/field/units";
}


// TOOD: Share with pc model exporter
static void exportMesh(std::string outdir, const Ogre::MeshPtr &mesh)
{
    Ogre::MeshSerializer        mesh_ser;

    Ogre::SkeletonPtr           skeleton(mesh->getSkeleton());
    Ogre::SkeletonSerializer    sk_ser;
    sk_ser.exportSkeleton(skeleton.getPointer(), outdir +  skeleton->getName());

    mesh->setSkeletonName(FieldModelDir() + "/" + mesh->getSkeletonName());

    mesh_ser.exportMesh(mesh.getPointer(), outdir + mesh->getName());


    Ogre::Mesh::SubMeshIterator it(mesh->getSubMeshIterator());
    Ogre::MaterialSerializer    mat_ser;
    size_t i(0);
    std::set<std::string> textures;
    while (it.hasMoreElements())
    {
        Ogre::SubMesh *sub_mesh(it.getNext());
        Ogre::MaterialPtr mat(Ogre::MaterialManager::getSingleton().getByName(sub_mesh->getMaterialName()));
        if (!mat.isNull())
        {
            for (size_t techNum = 0; techNum < mat->getNumTechniques(); techNum++)
            {
                Ogre::Technique* tech = mat->getTechnique(techNum);
                if (tech)
                {
                    for (size_t passNum = 0; passNum < tech->getNumPasses(); passNum++)
                    {
                        Ogre::Pass* pass = tech->getPass(passNum);
                        if (pass)
                        {
                            for (size_t textureUnitNum = 0; textureUnitNum < pass->getNumTextureUnitStates(); textureUnitNum++)
                            {
                                Ogre::TextureUnitState* unit = pass->getTextureUnitState(textureUnitNum);
                                if (unit)
                                {
                                    if (unit->getTextureName().empty() == false)
                                    {
                                        // Ensure the output material script references png files rather than tex files
                                        textures.insert(unit->getTextureName());
                                        Ogre::String baseName;
                                        QGears::StringUtil::splitBase(unit->getTextureName(), baseName);
                                        unit->setTextureName(FieldModelDir() + "/" + baseName + ".png");
                                    }
                                }
                            }
                        }
                    }
                }
            }

            mat_ser.queueForExport(mat);
        }
        ++i;
    }
    QGears::String base_name;
    QGears::StringUtil::splitFull(mesh->getName(), base_name);
    mat_ser.exportQueued(outdir + base_name + QGears::EXT_MATERIAL);

    for (auto& textureName : textures)
    {
        Ogre::TexturePtr texturePtr = Ogre::TextureManager::getSingleton().load(textureName.c_str(), "FFVII");
        Ogre::Image image;
        texturePtr->convertToImage(image);

        Ogre::String baseName;
        QGears::StringUtil::splitBase(textureName, baseName);
        image.save(outdir + baseName + ".png");
    }
}

static std::string FieldName(const std::string& name)
{
    return "ffvii_" + name;
}

void FF7DataInstaller::CreateDir(const std::string& path)
{
    QString target = QString::fromStdString(mOutputDir + path);
    QDir dir(target);
    if (!dir.mkpath("."))
    {
        throw std::runtime_error("Failed to mkpath");
    }
}

static std::string FieldMapDir()
{
    return "maps/ffvii/field";
}

class FF7FieldScriptFormatter : public SUDM::IScriptFormatter
{
public:
    FF7FieldScriptFormatter(const std::string& fieldName, const QGears::ModelListFilePtr& models)
        : mFieldName(fieldName), mModelLoader(models)
    {

    }

    // Renames a variable, return empty string for generated name
    virtual std::string VarName(unsigned int bank, unsigned int addr) override
    {
        return QGears::FF7::NameLookup::FieldScriptVarName(bank, addr);
    }

    // Renames an entity
    virtual std::string EntityName(const std::string& entity) override
    {
        return QGears::FF7::NameLookup::FieldScriptEntityName(entity);
    }

    // Names an animation, can't return empty
    virtual std::string AnimationName(int charId, int id) override
    {
        // Get the animation file name, then look up the friendly name of the "raw" animation
        const auto& modelInfo = mModelLoader->getModels().at(charId);
        const auto rawName = modelInfo.animations.at(id).name;

        // Trim off ".yos" or whatever other crazy extension the model loader adds in
        Ogre::String baseName;
        QGears::StringUtil::splitBase(rawName, baseName);

        QGears::StringUtil::toLowerCase(baseName);
        return QGears::FF7::NameLookup::animation(baseName);
    }

    // Get name of char from its id, can't return empty
    virtual std::string CharName(int charId) override
    {
        return QGears::FF7::NameLookup::CharName(charId);
    }

    // Renames a function in an entity
    virtual std::string FunctionName(const std::string& entity, const std::string& funcName) override
    {
        return QGears::FF7::NameLookup::FieldScriptFunctionName(mFieldName, entity, funcName);
    }

    // Sets the header comment for a function in an entity
    virtual std::string FunctionComment(const std::string& entity, const std::string& funcName) override
    {
        return QGears::FF7::NameLookup::FieldScriptFunctionComment(mFieldName, entity, funcName);
    }

private:
    std::string mFieldName;
    const QGears::ModelListFilePtr& mModelLoader;
};

static std::string CreateGateWayScript(const std::string& gatewayEntityName, const std::string& targetMapName, const std::string& sourceSpawnPointName)
{
    return "\nEntityContainer[ \"" + gatewayEntityName + "\" ] = {\n"
        "on_start = function(self)\n"
        "   return 0\n"
        "end,\n"
        "on_enter_line = function(self, entity)\n"
        "    return 0\n"
        "end,\n\n"
        "on_move_to_line = function(self, entity)\n"
        "   return 0\n"
        "end,\n\n"
        "on_cross_line = function(self, entity)\n"
        "   if entity == \"Cloud\" then\n"
        "       load_field_map_request(\"" + targetMapName + "\", \"" + sourceSpawnPointName + "\")\n"
        "   end\n\n"
        "   return 0\n"
        "end,\n\n"
        "on_leave_line = function(self, entity)\n"
        "   return 0\n"
        "end,\n"
        "}\n\n";

}

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

typedef std::map<std::string, std::set<std::string>> ModelAnimationMap;
class ModelsAndAnimationsDb
{
public:
    std::string NormalizeAnimationName(const std::string& name)
    {
        Ogre::String baseName;
        QGears::StringUtil::splitBase(name, baseName);
        std::transform(baseName.begin(), baseName.end(), baseName.begin(), ::tolower);
        return baseName + ".a";
    }

    std::set<std::string>& ModelAnimations(const std::string model)
    {
        // HACK FIX LGP READING
        std::string modelLower = model;
        std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);

        return mMap[modelLower];
    }

    std::string ModelMetaDataName(const std::string& modelName)
    {
        // If not in meta data then just replace .hrc with .mesh
        Ogre::String baseName;
        QGears::StringUtil::splitBase(modelName, baseName);
        return QGears::FF7::NameLookup::model(baseName) + ".mesh";
    }

//private:
    ModelAnimationMap mMap;
};

typedef std::set<std::string> MapCollection;


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

static void FF7PcFieldToQGearsField(
    QGears::FLevelFilePtr& field,
    const std::string& outDir,
    const std::vector<std::string>& fieldIdToNameLookup,
    const FieldSpawnPointsMap& spawnMap,
    ModelsAndAnimationsDb& modelAnimationDb,
    MapCollection& maps)
{
    // Generate triggers script to insert into main decompiled FF7 field -> LUA script
    std::string gatewayScriptData;
    const QGears::TriggersFilePtr& triggers = field->getTriggers();
    const auto& gateways = triggers->GetGateways();

    for (size_t i = 0; i < gateways.size(); i++)
    {
        const QGears::TriggersFile::Gateway& gateway = gateways[i];
        if (gateway.destinationFieldId != kInactiveGateWayId)
        {
            const std::string gatewayEntityName = "Gateway" + std::to_string(i);
            gatewayScriptData += CreateGateWayScript(gatewayEntityName, FieldName(fieldIdToNameLookup.at(gateway.destinationFieldId)), "Spawn_" + field->getName() + "_" + std::to_string(i));
        }
    }

    const QGears::ModelListFilePtr& models = field->getModelList();
    SUDM::FF7::Field::DecompiledScript decompiled;
    try
    {
        // Get the raw script bytes
        const std::vector<u8> rawFieldData = field->getRawScript();

        // Decompile to LUA
        FF7FieldScriptFormatter formatter(field->getName(), models);
        decompiled = SUDM::FF7::Field::Decompile(field->getName(), rawFieldData, formatter, gatewayScriptData, "EntityContainer = {}\n\n");
        std::ofstream scriptFile(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/script.lua");
        if (scriptFile.is_open())
        {
            scriptFile << decompiled.luaScript;
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


    // Write out the map file which links all the other files together for a given field
    {
        TiXmlDocument doc;
        std::unique_ptr<TiXmlElement> element(new TiXmlElement("map"));

        // Script
        std::unique_ptr<TiXmlElement> xmlScriptElement(new TiXmlElement("script"));
        xmlScriptElement->SetAttribute("file_name", FieldMapDir() + "/" + field->getName() + "/script.lua");
        element->LinkEndChild(xmlScriptElement.release());

        // Background
        std::unique_ptr<TiXmlElement> xmlBackground2d(new TiXmlElement("background2d"));
        xmlBackground2d->SetAttribute("file_name", FieldMapDir() + "/" + field->getName() + "/bg.xml");
        element->LinkEndChild(xmlBackground2d.release());
        
        // walkmesh
        std::unique_ptr<TiXmlElement> xmlWalkmesh(new TiXmlElement("walkmesh"));
        xmlWalkmesh->SetAttribute("file_name", FieldMapDir() + "/" + field->getName() + "/wm.xml");
        element->LinkEndChild(xmlWalkmesh.release());

        // Angle player moves when "up" is pressed
        std::unique_ptr<TiXmlElement> xmlMovementRotation(new TiXmlElement("movement_rotation"));
        xmlMovementRotation->SetAttribute("degree", std::to_string(triggers->MovementRotation()));
        element->LinkEndChild(xmlMovementRotation.release());

        for (const auto& it : decompiled.entities)
        {
            const int charId = it.second;
            if (charId != -1)
            {
                const QGears::ModelListFile::ModelDescription& desc = models->getModels().at(charId);

                auto& animVec = modelAnimationDb.ModelAnimations(desc.hrc_name);
                for (auto& anim : desc.animations)
                {
                    animVec.insert(modelAnimationDb.NormalizeAnimationName(anim.name));
                }

                std::unique_ptr<TiXmlElement> xmlEntityScript(new TiXmlElement("entity_model"));
                xmlEntityScript->SetAttribute("name", it.first);

                // TODO: Add to list of HRC's to convert, obtain name of target converted .mesh file
                auto lowerCaseHrcName = desc.hrc_name;
                QGears::StringUtil::toLowerCase(lowerCaseHrcName);
                xmlEntityScript->SetAttribute("file_name", FieldModelDir() + "/" + modelAnimationDb.ModelMetaDataName(lowerCaseHrcName));

                // TODO: entity_model - name, file_name,  position, direction
                // We set char 1 position to be position of first entity_point so player is spawned in sane
                // position if map is manually loaded via console.
                // None player chars set their first position in the init scripts. We know its a entity_model
                // because it uses PC opcode in init script.
                // entity_manager:get_entity("cl") is done via CHAR opcode
                xmlEntityScript->SetAttribute("position", "0 0 0");

                xmlEntityScript->SetAttribute("direction", "0");

                // TODO: This isn't quite right, the models animation translation seems to be inverted?
                xmlEntityScript->SetAttribute("scale", "0.03125 0.03125 0.03125");
                xmlEntityScript->SetAttribute("root_orientation", "0.7071067811865476 0.7071067811865476 0 0");


                element->LinkEndChild(xmlEntityScript.release());

            }
            else
            {
                std::unique_ptr<TiXmlElement> xmlEntityScript(new TiXmlElement("entity_script"));
                xmlEntityScript->SetAttribute("name", it.first);
                element->LinkEndChild(xmlEntityScript.release());
            }
        }

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
        doc.SaveFile(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/map.xml");
    }


    const QGears::PaletteFilePtr& pal = field->getPalette();
    const QGears::BackgroundFilePtr& bg = field->getBackground();
    std::unique_ptr<Ogre::Image> bgImage(bg->createImage(pal));
    bgImage->save(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/tiles.png");

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

        element->SetAttribute("image", FieldMapDir() + "/" + field->getName() + "/tiles.png");
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
                    else if (sprite.blending == 1 || sprite.blending == 3) // 3 is source + 0.25 * destination
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
        doc.SaveFile(outDir + "/" + FieldMapDir() + "/" + field->getName() +"/bg.xml");
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
        doc.SaveFile(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/wm.xml");
    }

    maps.insert(field->getName());
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

static bool IsTestField(Ogre::String& resourceName)
{
    if (
        resourceName == "startmap" ||
        resourceName == "md1stin" ||
        resourceName == "md1_1" ||
        resourceName == "md1_2" ||
        resourceName == "nmkin_1" ||
        resourceName == "nmkin_2" ||
        resourceName == "nmkin_3" ||
        resourceName == "nrthmk" ||
        resourceName == "elevtr1" ||
        resourceName == "tin_2"
        )
    {
        return true;
    }
    return false;
}

void FF7DataInstaller::ConvertFields(std::string archive, std::string inputDir, std::string outDir)
{
    mOutputDir = outDir;

    CreateDir(FieldMapDir());
    CreateDir(FieldModelDir());

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

    ModelsAndAnimationsDb modelAnimationDb;
    MapCollection maps;

    // Now we can do the full conversion with the collated data
    for (auto& resourceName : *resources)
    {
        // Exclude things that are not fields
        if (IsAFieldFile(resourceName))
        {
            if (IsTestField(resourceName))
            {
                CreateDir(FieldMapDir() + "/" + resourceName);

                QGears::FLevelFilePtr field = QGears::LZSFLevelFileManager::getSingleton().load(resourceName, "FFVIIFields").staticCast<QGears::FLevelFile>();
                FF7PcFieldToQGearsField(field, outDir, mapList->GetMapList(), spawnPoints, modelAnimationDb, maps);
            }
        }
    }
    
    {
        // Write out maps.xml
        TiXmlDocument doc;
        std::unique_ptr<TiXmlElement> element(new TiXmlElement("maps"));

        // TODO: Probably need to inject "empty" and "test" fields

        for (const auto& map : maps)
        {
            std::unique_ptr<TiXmlElement> xmlElement(new TiXmlElement("map"));
            xmlElement->SetAttribute("name", FieldName(map));
            xmlElement->SetAttribute("file_name", FieldMapDir() + "/" + map + "/map.xml");
            element->LinkEndChild(xmlElement.release());
        }
        doc.LinkEndChild(element.release());
        doc.SaveFile(outDir + "/maps.xml");
    }

    // TODO: Convert models and animations in modelAnimationDb
    auto fullPath = inputDir + "field/char.lgp";
    mApp.getRoot()->addResourceLocation(fullPath, "LGP", "FFVII");
    Ogre::StringVectorPtr resources2 = mApp.ResMgr()->listResourceNames("FFVII", "*");


    for (auto& name : modelAnimationDb.mMap)
    {
        Ogre::ResourcePtr hrc = QGears::HRCFileManager::getSingleton().load(name.first, "FFVII");

        Ogre::String baseName;
        QGears::StringUtil::splitBase(name.first, baseName);

        auto meshName = QGears::FF7::NameLookup::model(baseName) + ".mesh";

        Ogre::MeshPtr mesh(Ogre::MeshManager::getSingleton().load(meshName, "FFVII"));
        Ogre::SkeletonPtr skeleton(mesh->getSkeleton());
        
        for (auto& anim : name.second)
        {
            QGears::AFileManager       &afl_mgr(QGears::AFileManager::getSingleton());
            QGears::AFilePtr  a = afl_mgr.load(anim, "FFVII").staticCast<QGears::AFile>();

            // Convert the FF7 name to a more readble name set in the meta data
            Ogre::String baseName;
            QGears::StringUtil::splitBase(anim, baseName);
            a->addTo(skeleton, QGears::FF7::NameLookup::animation(baseName));
        }

        exportMesh(outDir + "/" + FieldModelDir() + "/", mesh);

    }

    mApp.getRoot()->removeResourceLocation(fullPath, "FFVII");


}
