#include "ArchiveFile.h"



ArchiveFile::ArchiveFile( const Ogre::String& file ):
    File( file )
{
    Extract();
}



ArchiveFile::ArchiveFile(File* file, const u32& offset, const u32& length ):
    File( file, offset, length )
{
    Extract();
}



ArchiveFile::ArchiveFile( u8* buffer, const u32& offset, const u32& length ):
    File( buffer, offset, length )
{
    Extract();
}



ArchiveFile::ArchiveFile( File *file ):
    File( file )
{
    Extract();
}



ArchiveFile::~ArchiveFile()
{
}



void
ArchiveFile::Extract()
{
    u16 circle_size = 4096;
    u16 F = 18;

    u8 circle_buffer[ 4096 ];
    int r = 0;
    for( u16 i = 0; i < circle_size - F; ++i )
    {
        circle_buffer[ i ] = 0;
    }
    r = circle_size - F;

    // current position in mBuffer (compressed)
    u32 comp_position = 0;

    u32 decomp_length = GetU32LE( comp_position );
    comp_position += 0x04;
    u8 *decomp_buffer = ( u8* )malloc( sizeof( u8 ) * decomp_length );

    // current position in decomp_buffer
    u32 decomp_position = 0;

    // decompression
    while( decomp_position < decomp_length )
    {
        // Control byte
        u8 control_byte = GetU8( comp_position++ );

        for( u8 shift = 0; shift < 8; ++shift )
        {
            if( ( control_byte & ( 1 << shift ) ) == 0 )
            {
                // not compressed
                // copy byte in circle burrer and in decomp_buffer
                u8 temp = GetU8( comp_position++ );
                decomp_buffer[ decomp_position++ ] = temp;
                circle_buffer[ r++ ]               = temp;
                r &= circle_size - 1;
            }
            else
            {
                // compressed
                // get 2 bytes
                u8 reference1 = GetU8( comp_position++ );
                u8 reference2 = GetU8( comp_position++ );
                // offset for circle_buffer
                u16 reference_offset = reference1 | ( ( reference2 & 0x0f ) << 8 );
                // length are always lesser than real by 3
                u8 reference_length = ( ( reference2 & 0xf0 ) >> 4 ) + 3;

                // copy bytes
                for( int i = 0; i < reference_length; ++i )
                {
                    u8 temp = circle_buffer[ ( r - reference_offset ) & ( circle_size - 1 ) ];
                    decomp_buffer[ decomp_position++ ] = temp;
                    circle_buffer[ r++ ]               = temp;
                    r &= circle_size - 1;
                }
            }
        }
    }

    free( m_Buffer );
    m_Buffer = decomp_buffer;
    m_BufferSize = decomp_length;
}
