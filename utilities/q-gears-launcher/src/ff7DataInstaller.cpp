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
#include "common/FF7NameLookup.h"
#include "data/QGearsTexCodec.h"
#include "data/QGearsMapListFile.h"
#include "decompiler/sudm.h"
#include <memory>
#include <QDir>
#include "common/make_unique.h"

FF7DataInstaller::FF7DataInstaller(std::string inputDir, std::string outputDir, std::function<void(std::string)> fnWriteOutputLine)
#ifdef _DEBUG
    : mApp("plugins_d.cfg", "resources_d.cfg", "install_d.log"),
#else
    : mApp("plugins.cfg", "resources.cfg", "install.log"),
#endif
    mInputDir(inputDir),
    mOutputDir(outputDir),
    mfnWriteOutputLine(fnWriteOutputLine)
{
    if (!mApp.initOgre(true))
    {
        throw std::runtime_error("Ogre init failure");
    }

}

FF7DataInstaller::~FF7DataInstaller()
{

}

int FF7DataInstaller::CalcProgress()
{
    // TODO: Make more accurate with mIteratorCounter and mProgressStepNumElements
    float curStep = mState / static_cast<float>(eMaxStates);
    curStep = curStep * 100.0f;
    return static_cast<int>(curStep);
}

int FF7DataInstaller::Progress()
{
    switch (mState)
    {
    case eIdle:
        mfnWriteOutputLine("Loading flevel.lgp");
        mProgressStepNumElements = 1;
        mIteratorCounter = 0;
        mFieldsLgp = std::make_unique<ScopedLgp>(mApp.getRoot(), mInputDir + "field/flevel.lgp", "LGP", "FFVIIFields");
        mState = eInitCollectFieldSpawnPointsAndScaleFactors;
        return CalcProgress();
    case eInitCollectFieldSpawnPointsAndScaleFactors:
        mfnWriteOutputLine("Collecting spawn points and scale factors");
        InitCollectSpawnAndScaleFactors();
        return CalcProgress();
    case eCollectFieldSpawnPointsAndScaleFactors:
        CollectionFieldSpawnAndScaleFactors();
        return CalcProgress();
    case eConvertFieldsIteration:
        ConvertFieldsIteration();
        return CalcProgress();
    case eWriteMapListOfConvertedFieldsStart:
        mfnWriteOutputLine("Write fields");
        WriteMapsXmlBegin();
        return CalcProgress();
    case eWriteMapListOfConvertedFieldsIteration:
        WriteMapsXmlIteration();
        return CalcProgress();
    case eWriteMapListOfConvertedFieldsEnd:
        EndWriteMapsXml();
        return CalcProgress();
    case eConvertFieldModelsBegin:
        mfnWriteOutputLine("Converting field models");
        ConvertFieldModelsBegin();
        return CalcProgress();
    case eConvertFieldModelsIteration:
        ConvertFieldModelsIteration();
        return CalcProgress();
    case eDone:
    default:
        return 100;
    }
}

static std::string FieldModelDir()
{
    return "models/ffvii/field/units";
}


// TOOD: Share with pc model exporter
static void exportMesh(std::string outdir, const Ogre::MeshPtr &mesh)
{
    QGears::String baseMeshName;
    QGears::StringUtil::splitFull(mesh->getName(), baseMeshName);

    Ogre::MeshSerializer        mesh_ser;

    Ogre::SkeletonPtr           skeleton(mesh->getSkeleton());
    Ogre::SkeletonSerializer    sk_ser;
    sk_ser.exportSkeleton(skeleton.getPointer(), outdir + baseMeshName + ".skeleton");

    mesh->setSkeletonName(FieldModelDir() + "/" + baseMeshName + ".skeleton");

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
                                        unit->setTextureName(FieldModelDir() + "/" + baseMeshName + "_" + baseName + ".png");
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

    mat_ser.exportQueued(outdir + baseMeshName + QGears::EXT_MATERIAL);

    for (auto& textureName : textures)
    {
        Ogre::TexturePtr texturePtr = Ogre::TextureManager::getSingleton().load(textureName.c_str(), "FFVII");
        Ogre::Image image;
        texturePtr->convertToImage(image);

        Ogre::String baseName;
        QGears::StringUtil::splitBase(textureName, baseName);
        image.save(outdir + baseMeshName + "_" + baseName + ".png");
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

class BaseFF7FieldScriptFormatter : public SUDM::IScriptFormatter
{
public:
    BaseFF7FieldScriptFormatter(const std::string& fieldName, const std::vector<std::string>& fieldIdToNameLookup, FieldSpawnPointsMap& spawnPoints)
        : mFieldName(fieldName), mFieldIdToNameLookup(fieldIdToNameLookup), mSpawnPoints(spawnPoints)
    {

    }

    virtual std::string SpawnPointName(unsigned int /*targetMapId*/, const std::string& entity, const std::string& funcName, unsigned int address) override
    {
        return mFieldName + "_" + entity + "_" + funcName + "_addr_" + std::to_string(address);
    }

    virtual std::string MapName(unsigned int mapId) override
    {
        return FieldName(mFieldIdToNameLookup[mapId]);
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

protected:
    std::string mFieldName;
    FieldSpawnPointsMap& mSpawnPoints;
    const std::vector<std::string>& mFieldIdToNameLookup;
};

class FF7FieldScriptFormatter : public BaseFF7FieldScriptFormatter
{
public:
    FF7FieldScriptFormatter(const std::string& fieldName, const QGears::ModelListFilePtr& models, const std::vector<std::string>& fieldIdToNameLookup, FieldSpawnPointsMap& spawnPoints)
        : BaseFF7FieldScriptFormatter(fieldName, fieldIdToNameLookup, spawnPoints), mModelLoader(models)
    {

    }

    // Names an animation, can't return empty
    virtual std::string AnimationName(int charId, int id) override
    {
        // Get the animation file name, then look up the friendly name of the "raw" animation
        if (static_cast<unsigned int>(charId) >= mModelLoader->getModels().size())
        {
            std::cout << "ERROR CHAR ID IS OUT OF BOUNDS" << std::endl;
            return std::to_string(id);
        }

        const auto& modelInfo = mModelLoader->getModels().at(charId);
        if (static_cast<unsigned int>(id) >= modelInfo.animations.size())
        {
            std::cout << "ERROR ANIMATION ID IS OUT OF BOUNDS" << std::endl;
            return std::to_string(id);
        }

        const auto rawName = modelInfo.animations.at(id).name;

        // Trim off ".yos" or whatever other crazy extension the model loader adds in
        Ogre::String baseName;
        QGears::StringUtil::splitBase(rawName, baseName);

        QGears::StringUtil::toLowerCase(baseName);
        return QGears::FF7::NameLookup::animation(baseName);
    }

private:
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
        "       if not FFVII.Data.DisableGateways then\n"
        "           load_field_map_request(\"" + targetMapName + "\", \"" + sourceSpawnPointName + "\")\n"
        "       end\n"
        "   end\n\n"
        "   return 0\n"
        "end,\n\n"
        "on_leave_line = function(self, entity)\n"
        "   return 0\n"
        "end,\n"
        "}\n\n";

}

const int kInactiveGateWayId = 32767;




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

static float FieldScaleFactor(const FieldScaleFactorMap& scaleFactorMap, size_t fieldId)
{
    auto it = scaleFactorMap.find(fieldId);
    if (it == std::end(scaleFactorMap))
    {
        throw std::runtime_error("Scale factor not found for field id");
    }
    return it->second;
}


static void FF7PcFieldToQGearsField(
    FF7FieldTextWriter& fieldTextWriter,
    QGears::FLevelFilePtr& field,
    const std::string& outDir,
    const std::vector<std::string>& fieldIdToNameLookup,
    FieldSpawnPointsMap& spawnMap,
    const FieldScaleFactorMap& scaleFactorMap,
    ModelsAndAnimationsDb& modelAnimationDb,
    MapCollection& maps,
    std::function<void(std::string)> fnWriteOutputLine)
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
    FF7FieldScriptFormatter formatter(field->getName(), models, fieldIdToNameLookup, spawnMap);
    try
    {
        // Get the raw script bytes
        const std::vector<u8> rawFieldData = field->getRawScript();

        // Decompile to LUA
        decompiled = SUDM::FF7::Field::Decompile(field->getName(), rawFieldData, formatter, gatewayScriptData, "EntityContainer = {}\n\n");
        std::ofstream scriptFile(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/script.lua");
        if (scriptFile.is_open())
        {
            scriptFile << decompiled.luaScript;
            try
            {
                fieldTextWriter.Write(rawFieldData, field->getName());
            }
            catch (const std::out_of_range&)
            {
                fnWriteOutputLine("Failed to read texts");
            }
        }
        else
        {
            fnWriteOutputLine("[ERROR] Failed to open script file for writing");
            std::cerr << "Failed to open script file for writing" << std::endl;
        }
    }
    catch (const ::InternalDecompilerError& ex)
    { 
        fnWriteOutputLine("[ERROR] internal decompiler error");
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

        // Get this fields Id
        const size_t thisFieldId = FieldId(field->getName(), fieldIdToNameLookup);

        // Use that to find the pre-computed list of gateways in all other fields that link to this field
        auto spawnIterator = spawnMap.find(thisFieldId);

        Ogre::Vector3 firstEntityPoint = Ogre::Vector3::ZERO;

        // If not found that it probably just means no other fields have doors to this one
        if (spawnIterator != std::end(spawnMap))
        {
            const std::vector<SpawnPointDb::Record>& spawnPointRecords = spawnIterator->second.mGatewaysToThisField;

            for (size_t i = 0; i < spawnPointRecords.size(); i++)
            {
                const QGears::TriggersFile::Gateway& gateway = spawnPointRecords[i].mGateway;
                // entity_point
                std::unique_ptr<TiXmlElement> xmlEntityPoint(new TiXmlElement("entity_point"));

                if (spawnPointRecords[i].mFromScript)
                {
                    // Spawn points from map jumps have a another algorithm
                    xmlEntityPoint->SetAttribute("name", fieldIdToNameLookup.at(spawnPointRecords[i].mFieldId) + "_" + spawnPointRecords[i].mEntityName + "_" + spawnPointRecords[i].mScriptFunctionName + "_addr_" + std::to_string(spawnPointRecords[i].GatewayIndexOrMapJumpAddress));
                }
                else
                {
                    // Must also include the gateway index for the case where 2 fields have more than one door linking to each other
                    xmlEntityPoint->SetAttribute("name", "Spawn_" + fieldIdToNameLookup.at(spawnPointRecords[i].mFieldId) + "_" + std::to_string(spawnPointRecords[i].GatewayIndexOrMapJumpAddress));
                }

                const float downscaler_next = 128.0f * FieldScaleFactor(scaleFactorMap, gateway.destinationFieldId);

                // Position Z is actually the target walkmesh triangle ID, so this is tiny bit more
                // complex as we have to say "get the Z value of the triangle with that ID". Note that ID actually just means index.
                unsigned int triIndex = static_cast<unsigned int>(gateway.destination.z);
                if (triIndex >= field->getWalkmesh()->getTriangles().size())
                {
                    std::cout << "WARNING MAP JUMP TRIANGLE OUT OF BOUNDS" << std::endl;
                    triIndex = 0;
                }
                const float zOfTriangleWithId = field->getWalkmesh()->getTriangles().at(triIndex).a.z;

                const Ogre::Vector3 posVec(gateway.destination.x / downscaler_next, gateway.destination.y / downscaler_next, zOfTriangleWithId);
                if (posVec != Ogre::Vector3::ZERO && firstEntityPoint == Ogre::Vector3::ZERO)
                {
                    firstEntityPoint = posVec;
                }

                xmlEntityPoint->SetAttribute("position", Ogre::StringConverter::toString(posVec));

                const float rotation = (360.0f * static_cast<float>(gateway.dir)) / 255.0f;
                xmlEntityPoint->SetAttribute("rotation", std::to_string(rotation));

                element->LinkEndChild(xmlEntityPoint.release());
            }
        }


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

                if (desc.type == QGears::ModelListFile::PLAYER)
                {
                    // For player models we set the position in the xml because if a map is loaded manually this is where the player
                    // will end up. Hence we set the position to the first entity_point that we have
                    xmlEntityScript->SetAttribute("position", Ogre::StringConverter::toString(firstEntityPoint));
                }
                else
                {
                    xmlEntityScript->SetAttribute("position", Ogre::StringConverter::toString(Ogre::Vector3::ZERO));
                }


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


        const float downscaler_this = 128.0f * FieldScaleFactor(scaleFactorMap, thisFieldId);

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

        doc.LinkEndChild(element.release());
        doc.SaveFile(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/map.xml");

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
            const Ogre::Vector3 position = camMatrix->getPosition() / FieldScaleFactor(scaleFactorMap, thisFieldId);
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
            doc.SaveFile(outDir + "/" + FieldMapDir() + "/" + field->getName() + "/bg.xml");
        }

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

class FF7FieldScriptGatewayCollector : public BaseFF7FieldScriptFormatter
{
public:
    FF7FieldScriptGatewayCollector(const std::string& fieldName, const std::vector<std::string>& fieldIdToNameLookup, FieldSpawnPointsMap& spawnPoints, size_t thisFieldId)
        : BaseFF7FieldScriptFormatter(fieldName, fieldIdToNameLookup, spawnPoints), mThisFieldId(thisFieldId)
    {

    }

    virtual void AddSpawnPoint(unsigned int targetMapId, const std::string& entity, const std::string& funcName, unsigned int address, int x, int y, int z, int angle) override
    {
        auto it = mSpawnPoints.find(targetMapId);

        QGears::TriggersFile::Gateway gw = {};
        gw.destinationFieldId = targetMapId;
        gw.destination.x = x;
        gw.destination.y = y;
        gw.destination.z = z;
        gw.dir = angle;

        if (it != std::end(mSpawnPoints))
        {
            // Add to the list of gateways that link to destinationFieldId
            SpawnPointDb::Record rec;
            rec.mFromScript = true;
            rec.mFieldId = mThisFieldId;
            rec.mGateway = gw;
            rec.mEntityName = entity;
            rec.mScriptFunctionName = funcName;
            rec.GatewayIndexOrMapJumpAddress = address;
            it->second.mGatewaysToThisField.push_back(rec);
        }
        else
        {
            // Create a new record for destinationFieldId
            SpawnPointDb db;
            db.mTargetFieldId = targetMapId;

            SpawnPointDb::Record rec;
            rec.mFromScript = true;
            rec.mFieldId = mThisFieldId;
            rec.mGateway = gw;
            rec.mEntityName = entity;
            rec.mScriptFunctionName = funcName;
            rec.GatewayIndexOrMapJumpAddress = address;
            db.mGatewaysToThisField.push_back(rec);

            mSpawnPoints.insert(std::make_pair(db.mTargetFieldId, db));
        }
    }
private:
    size_t mThisFieldId;

};

static void CollectSpawnPoints(QGears::FLevelFilePtr& field, const std::vector<std::string>& fieldIdToNameLookup, FieldSpawnPointsMap& spawnPoints)
{
    const size_t thisFieldId = FieldId(field->getName(), fieldIdToNameLookup);

    // Decompile the script just so we can collect up the MAPJUMP's we need this to construct the full list of entries
    // to each field
    try
    {
        // Get the raw script bytes
        SUDM::FF7::Field::DecompiledScript decompiled;
        const std::vector<u8> rawFieldData = field->getRawScript();

        // Decompile to LUA
        FF7FieldScriptGatewayCollector formatter(field->getName(), fieldIdToNameLookup, spawnPoints, thisFieldId);
        decompiled = SUDM::FF7::Field::Decompile(field->getName(), rawFieldData, formatter, "", "EntityContainer = {}\n\n");
    }
    catch (const ::InternalDecompilerError& ex)
    {
        std::cerr << "InternalDecompilerError: " << ex.what() << std::endl;
    }

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
                rec.GatewayIndexOrMapJumpAddress = i;
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
                rec.GatewayIndexOrMapJumpAddress = i;
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

// Exclude fields which cause fatal crash bugs :)
// this can be removed when whatever is causing the crash(s) is fixed
static bool WillCrash(Ogre::String& resourceName)
{
    if (
        // crashes in back ground image generation
        resourceName == "bugin1a" ||

        // Hangs in decompliation
        resourceName == "frcyo" ||

        // bg image crash
        resourceName == "fr_e" ||
        resourceName == "las4_2" ||
        resourceName == "las4_3" ||
        resourceName == "lastmap" ||
        resourceName == "md_e1" ||
        resourceName == "trnad_3"
        )
    {
        // NOTE: Even so, conversion of all models will fail with a bone index out of bounds
        return true;
    }
    return false;
}

static bool IsTestField(Ogre::String& resourceName)
{
    if (
        resourceName == "startmap" ||
        resourceName == "md1stin" ||
        resourceName == "md1_1" ||
        resourceName == "md1_2" ||
        resourceName == "md8_1" ||
        resourceName == "nmkin_1" ||
        resourceName == "nmkin_2" ||
        resourceName == "nmkin_3" ||
        resourceName == "nrthmk" ||
        resourceName == "elevtr1" ||
        resourceName == "tin_1" ||
        resourceName == "tin_2" ||
        resourceName == "rootmap" ||
        resourceName == "md8_4"
        )
    {
        return true;
    }
    return false;
}

static void CollectFieldScaleFactors(QGears::FLevelFilePtr& field, FieldScaleFactorMap& scaleFactors, const std::vector<std::string>& fieldIdToNameLookup)
{
    scaleFactors[FieldId(field->getName(), fieldIdToNameLookup)] = ::SUDM::FF7::Field::ScaleFactor(field->getRawScript());
}

void FF7DataInstaller::InitCollectSpawnAndScaleFactors()
{
    mProgressStepNumElements = 1;

    CreateDir(FieldMapDir());
    CreateDir(FieldModelDir());

    // List whats in the LGP archive
    mFLevelFileList = mApp.ResMgr()->listResourceNames("FFVIIFields", "*");

    // Load the map list field
    QGears::MapListFilePtr mapList = QGears::MapListFileManager::getSingleton().load("maplist", "FFVIIFields").staticCast<QGears::MapListFile>();
    mMapList = mapList->GetMapList();

    mIteratorCounter = 0;
    mConversionStep = 0;
    mState = eCollectFieldSpawnPointsAndScaleFactors;
}

void FF7DataInstaller::CollectionFieldSpawnAndScaleFactors()
{
    // On the first pass collate required field information
    mProgressStepNumElements = mFLevelFileList->size();
    if (mIteratorCounter < mFLevelFileList->size())
    {
        auto resourceName = (*mFLevelFileList)[mIteratorCounter];
        // Exclude things that are not fields
        if (IsAFieldFile(resourceName) /*&& IsTestField(resourceName)*/)
        {
            mConversionStep++;

            if (mConversionStep == 1)
            {
                mField = QGears::LZSFLevelFileManager::getSingleton().load(resourceName, "FFVIIFields").staticCast<QGears::FLevelFile>();
                mfnWriteOutputLine("Load field " + resourceName);
                return;
            }

            if (mConversionStep == 2)
            {
                mfnWriteOutputLine("Read spawn points from scripts");
                CollectSpawnPoints(mField, mMapList, mCollectedSpawnPoints);
                return;
            }
           
            if (mConversionStep == 3)
            {
                mfnWriteOutputLine("Read scale factor");
                CollectFieldScaleFactors(mField, mCollectedScaleFactors, mMapList);
                mConversionStep = 0;
                mIteratorCounter++;
                return;
            }
        }
        else
        {
            mIteratorCounter++;
        }
    }
    else
    {
        mField.setNull();
        mIteratorCounter = 0;
        mState = eConvertFieldsIteration;
        mFieldTextWriter.Begin(mOutputDir + "/texts/english/dialogs_mission1.xml");
    }
}

void FF7DataInstaller::ConvertFieldsIteration()
{
    // Now we can do the full conversion with the collated data
    mProgressStepNumElements = mFLevelFileList->size();
    if (mIteratorCounter < mFLevelFileList->size())
    {
        auto resourceName = (*mFLevelFileList)[mIteratorCounter];

        // Exclude things that are not fields
        if (IsAFieldFile(resourceName))
        {
            mIteratorCounter++;

            if (/*IsTestField(resourceName) &&*/
                !WillCrash(resourceName))
            {
                mfnWriteOutputLine("Converting field " + resourceName);
                std::cout << "Converting: " << resourceName << std::endl;
                CreateDir(FieldMapDir() + "/" + resourceName);

                QGears::FLevelFilePtr field = QGears::LZSFLevelFileManager::getSingleton().load(resourceName, "FFVIIFields").staticCast<QGears::FLevelFile>();
                FF7PcFieldToQGearsField(mFieldTextWriter, field, mOutputDir, mMapList, mCollectedSpawnPoints, mCollectedScaleFactors, mModelsAndAnimationsUsedByConvertedFields, mConvertedMapList, mfnWriteOutputLine);
            }
            else
            {
                mfnWriteOutputLine("[ERROR] Skip field " + resourceName + " due to crash or hang issue");
                std::cout << "Skip: " << resourceName << " as it has a crash or hang issue" << std::endl;
            }
        }
        else
        {
            mIteratorCounter++;
        }
    }
    else
    {
        mIteratorCounter = 0;
        mState = eWriteMapListOfConvertedFieldsStart;
        mFieldTextWriter.End();
    }
}

void FF7DataInstaller::WriteMapsXmlBegin()
{
    // Write out maps.xml
    mProgressStepNumElements = 1;
    mDoc = std::make_unique<TiXmlDocument>();
    mElement = std::make_unique<TiXmlElement>("maps");
    mIteratorCounter = 0;
    mState = eWriteMapListOfConvertedFieldsIteration;
    mIteratorCounter = 0;
    mConvertedMapListIt = mConvertedMapList.begin();
}

void FF7DataInstaller::WriteMapsXmlIteration()
{
    // TODO: Probably need to inject "empty" and "test" fields
    mProgressStepNumElements = mConvertedMapList.size();
    if (mConvertedMapListIt != mConvertedMapList.end())
    {
        auto map = *mConvertedMapListIt;

        mfnWriteOutputLine("Writing field " + FieldName(map));
        std::unique_ptr<TiXmlElement> xmlElement(new TiXmlElement("map"));
        xmlElement->SetAttribute("name", FieldName(map));
        xmlElement->SetAttribute("file_name", FieldMapDir() + "/" + map + "/map.xml");
        mElement->LinkEndChild(xmlElement.release());

        mIteratorCounter++;
        mConvertedMapListIt++;
    }
    else
    {
        mState = eWriteMapListOfConvertedFieldsEnd;
    }
}

void FF7DataInstaller::EndWriteMapsXml()
{
    mProgressStepNumElements = 1;
    mDoc->LinkEndChild(mElement.release());
    mDoc->SaveFile(mOutputDir + "/maps.xml");
    mState = eConvertFieldModelsBegin;
}

void FF7DataInstaller::ConvertFieldModelsBegin()
{
    // TODO: Convert models and animations in modelAnimationDb
    mProgressStepNumElements = 1;
    mFieldModelsLgp = std::make_unique<ScopedLgp>(mApp.getRoot(), mInputDir + "field/char.lgp", "LGP", "FFVII");
    mFieldModelFileList = mApp.ResMgr()->listResourceNames("FFVII", "*");
    mIteratorCounter = 0;
    mState = eConvertFieldModelsIteration;
    mIteratorCounter = 0;
    mConversionStep = 0;
    mModelAnimationMapIterator = mModelsAndAnimationsUsedByConvertedFields.mMap.begin();
}

void FF7DataInstaller::ConvertFieldModelsIteration()
{
    mProgressStepNumElements = mModelsAndAnimationsUsedByConvertedFields.mMap.size();
    if (mModelAnimationMapIterator != mModelsAndAnimationsUsedByConvertedFields.mMap.end())
    {
        if (mConversionStep == 0)
        {
            mfnWriteOutputLine("Converting model " + mModelAnimationMapIterator->first);
            mConversionStep++;
        }
        else
        {
            try
            {
                Ogre::ResourcePtr hrc = QGears::HRCFileManager::getSingleton().load(mModelAnimationMapIterator->first, "FFVII");

                Ogre::String baseName;
                QGears::StringUtil::splitBase(mModelAnimationMapIterator->first, baseName);

                auto meshName = QGears::FF7::NameLookup::model(baseName) + ".mesh";

                Ogre::MeshPtr mesh(Ogre::MeshManager::getSingleton().load(meshName, "FFVII"));
                Ogre::SkeletonPtr skeleton(mesh->getSkeleton());

                for (auto& anim : mModelAnimationMapIterator->second)
                {
                    QGears::AFileManager       &afl_mgr(QGears::AFileManager::getSingleton());
                    QGears::AFilePtr  a = afl_mgr.load(anim, "FFVII").staticCast<QGears::AFile>();

                    // Convert the FF7 name to a more readable name set in the meta data
                    Ogre::String baseName;
                    QGears::StringUtil::splitBase(anim, baseName);
                    a->addTo(skeleton, QGears::FF7::NameLookup::animation(baseName));
                }

                exportMesh(mOutputDir + "/" + FieldModelDir() + "/", mesh);
            }
            catch (const Ogre::Exception& ex)
            {
                mfnWriteOutputLine("[ERROR] converting model " + mModelAnimationMapIterator->first + " msg: " + ex.what());
            }
            catch (const std::exception& ex)
            {
                mfnWriteOutputLine("[ERROR] converting model " + mModelAnimationMapIterator->first + " msg: " + ex.what());
            }
            mIteratorCounter++;
            mModelAnimationMapIterator++;
            mConversionStep = 0;
        }
    }
    else
    {
        mState = eDone;
    }
}
