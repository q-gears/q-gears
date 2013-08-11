#include "QGearsFLevelFile.h"

#include "Logger.h"
#include "QGearsBackgroundFile.h"

namespace QGears
{
    //---------------------------------------------------------------------
    FLevelFile::FLevelFile( const File* pFile ):
        File(pFile)
       ,m_section_count( 0 )
       ,m_script( NULL )
       ,m_camera_matrix( NULL )
       ,m_model_loader( NULL )
       ,m_palette( NULL )
       ,m_walkmesh( NULL )
       ,m_tile_map( NULL )
       ,m_encounter( NULL )
       ,m_background( NULL )
    {
        readHeader();
    }

    //---------------------------------------------------------------------
    FLevelFile::~FLevelFile()
    {
        clearSections();
    }

    //---------------------------------------------------------------------
    void FLevelFile::clearSections()
    {
        for( int i(0); i < 10; ++i )
        {
            if( m_sections[i] )
            {
                delete m_sections[i];
            }
            m_sections[i] = NULL;
        }
    }

    //---------------------------------------------------------------------
    File** FLevelFile::getSections()
    {
        return m_sections;
    }

    //---------------------------------------------------------------------
    void
    FLevelFile::readHeader()
    {
        u16 version = GetU16LE(0);
        m_section_count = GetU32LE(2);

        if ( version != 0 || m_section_count != 9 )
        {
            LOGGER->Log( "Warning: there should be 9 sections !\n" );
        }

        // 4 bytes for section offset 4 bytes for section size
        if ( m_section_count * 4 * 4 > m_BufferSize )
        {
            LOGGER->Log("Warning: not an flevel file!\n");
            return;
        }

        for( u32 i(0); i < 9; ++i )
        {
            LOGGER->Log("Info: reading section\n");
            u32 offset( GetU32LE( 6 + i * 4 ) );
            u32 section_start( offset + 4 );
            if ( section_start > m_BufferSize )
            {
                LOGGER->Log("Warning: section starts out of bounds!\n");
                return;
            }
            u32 length(  GetU32LE( offset ) );
            if ( section_start + length > m_BufferSize )
            {
                LOGGER->Log("Warning: not enought space for section!\n");
                return;
            }
            LOGGER->Log("Info: creating section file\n");
            File* section( NULL );
            switch ( i )
            {
                case 3:
                    section = m_palette = new PaletteFile( this, section_start, length );
                    break;
                case 8:
                    section = m_background = new BackgroundFile( this, section_start, length, m_palette );
                    m_sections[9] = new File( this, section_start, length );
                    break;

                case 0:
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                default:
                    section = new File( this, section_start, length );
            }
            m_sections[i] = section;
        }
    }

}
