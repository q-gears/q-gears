#include "DatFile.h"
#include "../../common/Logger.h"



DatFile::DatFile(const Ogre::String& file):
    LzsFile(file)
{
}



DatFile::DatFile(File *file, const u32 offset, const u32 length):
    LzsFile(file, offset, length)
{
}



DatFile::DatFile(u8* buffer, const u32 offset, const u32 length):
    LzsFile(buffer, offset, length)
{
}



DatFile::DatFile(File *file):
    LzsFile(file)
{
}



DatFile::~DatFile()
{
}



void
DatFile::GetModelData( const int model_id, DatModelData& data )
{
    LOGGER->Log( "\nDUMP sector 7 for model id " + HexToString( model_id, 2, '0' ) + "\n" );

    // get sector 7
    u32 offset = 0x1C + GetU32LE( 0x18 ) - GetU32LE( 0x00 ) + 4 + model_id * 8;

    data.face_id = GetU8( offset + 0x00 );
    LOGGER->Log( "face_id: 0x"  + HexToString( data.face_id, 2, '0' ) + "\n" );

    data.number_of_bones = GetU8( offset + 0x01 );
    LOGGER->Log( "number_of_bones: 0x" + HexToString( data.number_of_bones, 2, '0' ) + "\n" );

    data.number_of_parts = GetU8( offset + 0x02 );
    LOGGER->Log( "number_of_parts: 0x" + HexToString( data.number_of_parts, 2, '0' ) + "\n" );

    data.number_of_animation = GetU8( offset + 0x03 );
    LOGGER->Log( "number_of_animation: 0x" + HexToString( data.number_of_animation, 2, '0' ) + "\n" );

    data.global_model_id = GetU8( offset + 0x07 );
    LOGGER->Log( "global_model_id: 0x" + HexToString( data.global_model_id, 2, '0' ) + "\n" );
}
