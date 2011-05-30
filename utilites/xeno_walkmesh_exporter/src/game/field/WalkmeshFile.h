#ifndef WALKMESHFILE_H
#define WALKMESHFILE_H



#include "Walkmesh.h"
#include "../filesystem/File.h"
#include "../../common/filesystem/GameFileSystem.h"



class WalkmeshFile : public File
{
    public:
                 WalkmeshFile(const std::string &file);

                 WalkmeshFile(File *file);

        virtual ~WalkmeshFile();

        void     GetWalkmesh(Walkmesh* walkmesh);



    private:
};



#endif // WALKMESHFILE_H
