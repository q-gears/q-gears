#pragma once

#include <string>
#include <vector>
#include "common/make_unique.h"
#include "common/QGearsApplication.h"

class FF7DataInstaller
{
public:
    FF7DataInstaller();
    ~FF7DataInstaller();
    void Convert(std::string inputDir, std::string outputDir, const std::vector<std::string>& files);

private:
    void CreateDir(const std::string& dir);
    void ConvertFields(std::string archive, std::string inDir, std::string outDir);

    std::string mOutputDir;
    QGears::Application mApp;
};
