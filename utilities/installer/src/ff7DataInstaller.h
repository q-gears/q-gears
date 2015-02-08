#pragma once

#include <string>
#include <vector>
#include "common/make_unique.h"
#include <OgreRoot.h>

class FF7DataInstaller
{
public:
    FF7DataInstaller();
    ~FF7DataInstaller();
    void Convert(std::string inputDir, std::string outputDir, const std::vector<std::string>& files);

private:
    void ConvertFieldModels(std::string archive, std::string outDir);
    std::unique_ptr<Ogre::Root> m_root;

    std::vector<std::shared_ptr<Ogre::ResourceManager>> mResourceManagers;

    Ogre::RenderWindow* m_render_window = nullptr; // Not owned
};
