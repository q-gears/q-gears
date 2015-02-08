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
    void ConvertFieldModels(std::string archive, std::string outDir);

    QGears::Application mApp;
};
