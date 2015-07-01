#pragma once

#include <string>
#include <vector>
#include "common/make_unique.h"
#include "common/QGearsApplication.h"
#include "common/FF7NameLookup.h"
#include "data/QGearsTriggersFile.h"
#include "common/QGearsStringUtil.h"
#include "data/QGearsFLevelFile.h"
#include "ff7FieldTextWriter.h"

class ScopedLgp
{
public:
    ScopedLgp(const ScopedLgp&) = delete;
    ScopedLgp& operator = (const ScopedLgp&) = delete;
    ScopedLgp(Ogre::Root* root, std::string fullPath, std::string type, std::string group)
        : mRoot(root), mFullPath(fullPath), mGroup(group)
    {
        if (mRoot)
        {
            mRoot->addResourceLocation(mFullPath, type, mGroup);
        }
    }

    ~ScopedLgp()
    {
        if (mRoot)
        {
            mRoot->removeResourceLocation(mFullPath, mGroup);
        }
    }

private:
    Ogre::Root* mRoot;
    std::string mFullPath;
    std::string mGroup;
};


typedef std::set<std::string> MapCollection;

class SpawnPointDb
{
public:
    // Id of the field the gateways records from N other number of fields are linking to
    u16 mTargetFieldId = 0;

    class Record
    {
    public:
        // Field that wants to link to mTargetFieldId
        u16 mFieldId = 0;

        // Index of the gateway in mFieldId
        u32 GatewayIndexOrMapJumpAddress = 0;

        // Gateway data
        QGears::TriggersFile::Gateway mGateway;

        bool mFromScript = false;

        // Only used from script calls
        std::string mEntityName;
        std::string mScriptFunctionName;
    };

    std::vector<Record> mGatewaysToThisField;
};

typedef std::map<u16, SpawnPointDb> FieldSpawnPointsMap;
typedef std::map<u16, float> FieldScaleFactorMap;



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

class FF7DataInstaller
{
public:
    FF7DataInstaller(std::string inputDir, std::string outputDir, std::function<void(std::string)> fnWriteOutputLine);
    ~FF7DataInstaller();
    int Progress();
private:
    int CalcProgress();
    void CreateDir(const std::string& dir);
    void InitCollectSpawnAndScaleFactors();
    void CollectionFieldSpawnAndScaleFactors();
    void ConvertFieldsIteration();
    void WriteMapsXmlBegin();
    void WriteMapsXmlIteration();
    void EndWriteMapsXml();
    void ConvertFieldModelsBegin();
    void ConvertFieldModelsIteration();

    enum eStates
    {
        eIdle,
        eInitCollectFieldSpawnPointsAndScaleFactors,
        eCollectFieldSpawnPointsAndScaleFactors,
        eConvertFieldsIteration,
        eWriteMapListOfConvertedFieldsStart,
        eWriteMapListOfConvertedFieldsIteration,
        eWriteMapListOfConvertedFieldsEnd,
        eConvertFieldModelsBegin,
        eConvertFieldModelsIteration,
        eMaxStates,
        eDone,
    };
    eStates mState = eIdle;
    std::string mInputDir;
    std::string mOutputDir;
    QGears::Application mApp; // Singleton so can't recreate, will crash 2nd time round

    std::unique_ptr<ScopedLgp> mFieldsLgp;
    std::unique_ptr<ScopedLgp> mFieldModelsLgp;


    // Kept in scope as progress is incremented per call rather than one big blocking method
    Ogre::StringVectorPtr mFLevelFileList;
    std::vector<std::string> mMapList;
    FieldSpawnPointsMap mCollectedSpawnPoints;
    FieldScaleFactorMap mCollectedScaleFactors;
    ModelsAndAnimationsDb mModelsAndAnimationsUsedByConvertedFields;
    MapCollection mConvertedMapList;
    MapCollection::iterator mConvertedMapListIt;
    size_t mIteratorCounter;

    size_t mConversionStep;
    size_t mProgressStepNumElements;
    QGears::FLevelFilePtr mField;

    Ogre::StringVectorPtr mFieldModelFileList;

    std::unique_ptr<TiXmlDocument> mDoc;
    std::unique_ptr<TiXmlElement> mElement;

    ModelAnimationMap::iterator mModelAnimationMapIterator;

    std::function<void(std::string)> mfnWriteOutputLine;

    FF7FieldTextWriter mFieldTextWriter;
};
