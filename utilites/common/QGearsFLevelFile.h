#ifndef __QGearsFLevelFile_H__
#define __QGearsFLevelFile_H__

#include "File.h"
#include "QGearsBackgroundFile.h"
#include "QGearsPaletteFile.h"

namespace QGears
{
    class FLevelFile : public File
    {
    public:
        FLevelFile( const File* pFile );
        virtual ~FLevelFile();
        File** getSections();

    private:
        void readHeader();
        void clearSections();

        u32 m_section_count;
        File* m_script;
        File* m_camera_matrix;
        File* m_model_loader;
        PaletteFile* m_palette;
        File* m_walkmesh;
        File* m_tile_map;
        File* m_encounter;
        BackgroundFile* m_background;

        File* m_sections[10];
    };

}

#endif // __QGearsFLevelFile_H__
