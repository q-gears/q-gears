#include "../../common/Logger.h"

#include "TdbFile.h"



TdbFile::TdbFile(const Ogre::String& file):
    LzsFile(file)
{
}



TdbFile::TdbFile(File* pFile):
    LzsFile(pFile)
{
}



TdbFile::TdbFile(File* pFile, const u32 offset, const u32 length):
    LzsFile(pFile, offset, length)
{
}



TdbFile::TdbFile(u8* pBuffer, const u32 offset, const u32 length):
    LzsFile(pBuffer, offset, length)
{
}



TdbFile::~TdbFile()
{
}



void
TdbFile::CreateTexture( const Ogre::PixelBox& pb, const int face_id, const int start_x, const int start_y )
{
    typedef std::vector< u8 > Face;
    std::vector< Face > face_row;
    Face face;
    // face 0
    face.push_back( 0x7e ); face.push_back( 0x00 ); face.push_back( 0x01 ); face.push_back( 0x02 ); face.push_back( 0x03 ); face.push_back( 0x04 ); face.push_back( 0x07 );
    face.push_back( 0x7e ); face.push_back( 0x05 ); face.push_back( 0x06 );
    face_row.push_back( face );
    face.clear();
    // face 1
    face.push_back( 0x7e ); face.push_back( 0x08 ); face.push_back( 0x09 ); face.push_back( 0x0a ); face.push_back( 0x0b ); face.push_back( 0x0c ); face.push_back( 0x0f );
    face.push_back( 0x7e ); face.push_back( 0x0d ); face.push_back( 0x0e );
    face_row.push_back( face );
    face.clear();
    // face 2
    face.push_back( 0x7e ); face.push_back( 0x10 ); face.push_back( 0x11 ); face.push_back( 0x12 ); face.push_back( 0x13 ); face.push_back( 0x14 ); face.push_back( 0x17 );
    face.push_back( 0x7e ); face.push_back( 0x15 ); face.push_back( 0x16 );
    face_row.push_back( face );
    face.clear();
    // face 3
    face.push_back(0x7e); face.push_back(0x18); face.push_back(0x19); face.push_back(0x1a); face.push_back(0x1b); face.push_back(0x1c); face.push_back(0x1f);
    face.push_back(0x7e); face.push_back(0x1d); face.push_back(0x1e);
    face_row.push_back( face );
    face.clear();
    // face 4
    face_row.push_back( face );
    face.clear();
    // face 5
    face_row.push_back( face );
    face.clear();
    // face 6
    face.push_back(0x7e); face.push_back(0x30); face.push_back(0x31); face.push_back(0x32); face.push_back(0x33); face.push_back(0x34); face.push_back(0x17);
    face.push_back(0x7e); face.push_back(0x35); face.push_back(0x36);
    face_row.push_back( face );
    face.clear();
    // face 7
    face_row.push_back( face );
    face.clear();
    // face 8
    face_row.push_back( face );
    face.clear();
    // face 9
    face_row.push_back( face );
    face.clear();
    // face a
    face_row.push_back( face );
    face.clear();
    // face b
    face_row.push_back( face );
    face.clear();
    // face c
    face.push_back(0x7e); face.push_back(0x54); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e);
    face.push_back(0x7e); face.push_back(0x55); face.push_back(0x7e);
    face_row.push_back( face );
    face.clear();
    // face d
    face.push_back(0x7e); face.push_back(0x56); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e);
    face.push_back(0x7e); face.push_back(0x57); face.push_back(0x7e);
    face_row.push_back( face );
    face.clear();
    // face e
    face_row.push_back( face );
    face.clear();
    // face f
    face_row.push_back( face );
    face.clear();
    // face 10
    face_row.push_back( face );
    face.clear();
    // face 11
    face.push_back(0x7e); face.push_back(0x5e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e);
    face.push_back(0x7e); face.push_back(0x5f); face.push_back(0x7e);
    face_row.push_back( face );
    face.clear();
    // face 12
    face.push_back( 0x7e ); face.push_back( 0x60 ); face.push_back( 0x7e ); face.push_back( 0x7e ); face.push_back( 0x7e ); face.push_back( 0x7e ); face.push_back( 0x7e );
    face.push_back( 0x7e ); face.push_back( 0x61 ); face.push_back( 0x7e );
    face_row.push_back( face );
    face.clear();
    // face 13
    face_row.push_back( face );
    face.clear();
    // face 14
    face_row.push_back( face );
    face.clear();
    // face 15
    face_row.push_back( face );
    face.clear();
    // face 16
    face_row.push_back( face );
    face.clear();
    // face 17
    face_row.push_back( face );
    face.clear();
    // face 18
    face_row.push_back( face );
    face.clear();
    // face 19
    face_row.push_back( face );
    face.clear();
    // face 1a
    face_row.push_back( face );
    face.clear();
    // face 1b
    face_row.push_back( face );
    face.clear();
    // face 1c
    face_row.push_back( face );
    face.clear();
    // face 1d
    face.push_back(0x7e); face.push_back(0x76); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e); face.push_back(0x7e);
    face.push_back(0x7e); face.push_back(0x77); face.push_back(0x7e);
    face_row.push_back( face );
    face.clear();

/*
// eye and mouth by face id
7E202122232427 7E2627 4
7E28292A2B2C2F 7E2D2E 5
7E38393A3B3C3F 7E3D3E 7
7E404142434447 7E4546 8
7E48494A4B4C4F 7E4D4E 9
7E507E7E7E7E7E 7E517E a
7E527E7E7E7E7E 7E537E b
7E587E7E7E7E7E 7E597E e
7E5A7E7E7E7E7E 7E5B7E f
7E5C7E7E7E7E7E 7E5D7E 10
7E627E7E7E7E7E 7E637E 13
7E647E7E7E7E7E 7E657E 14
7E667E7E7E7E7E 7E677E 15
7E687E7E7E7E7E 7E697E 16
7E6A7E7E7E7E7E 7E6B7E 17
7E6C7E7E7E7E7E 7E6D7E 18
7E6E7E7E7E7E7E 7E6F7E 19
7E707E7E7E7E7E 7E717E 1a
7E727E7E7E7E7E 7E737E 1b
7E747E7E7E7E7E 7E757E 1c
7E787E7E7E7E7E 7E797E 1e
7E7A7E7E7E7E7E 7E7B7E 1f
7E7C7E7E7E7E7E 7E7D7E 20
*/


    if( face_id >= static_cast<int>(face_row.size()) || face_row[ face_id ].size() == 0 )
    {
        LOGGER->Log( "[ERROR] There is no data for face id: 0x" + HexToString( face_id, 2, '0' ) );
        return;
    }

    int offset_to_clut = GetU32LE( 0xc ) + face_id * 32;

    int start_x_new = start_x;
    int start_y_new = start_y;

    // eyes should be created twice
    bool second_eye = false;

    for( size_t i = 1; i < face_row[ face_id ].size(); ++i )
    {
        int offset_to_image = GetU32LE( 0x8 ) + face_row[ face_id ][ i ] * 512;

        if( i == 7 ) // mouth starts here. mouth always starts from 0xa0
        {
            start_x_new = start_x;
            start_y_new += 160;
        }

        for( u32 y = 0; y < 32; ++y )
        {
            u32* data = static_cast< u32* >( pb.data ) + ( y + start_y_new ) * pb.rowPitch;

            for( u32 x = 0; x < 16; ++x )
            {
                u8 pixel = GetU8( offset_to_image + y * 16 + x );
                u16 clut1 = GetU16LE( offset_to_clut + ( pixel & 0xf ) * 2 );
                u16 clut2 = GetU16LE( offset_to_clut + ( pixel >> 4 ) * 2 );

                u32 ogre_pixel1 = ( ( ( clut1 & 0x1f ) * 255 / 31 ) << 0x18 ) | ( ( ( ( clut1 >>  5 ) & 0x1f ) * 255 / 31 ) << 0x10 ) | ( ( ( ( clut1 >> 10 ) & 0x1f ) * 255 / 31 ) << 0x8 ) | 0;

                u8 stp = ( clut1 & 0x8000 ) >> 15;
                if( stp == 0 && ( ogre_pixel1 & 0xffffff00 ) == 0 )
                {
                    ogre_pixel1 |= 0;
                }
                else if( stp == 0 && ( ogre_pixel1 & 0xffffff00) != 0 )
                {
                    ogre_pixel1 |= 255;
                }
                else if( stp == 1 && ( ogre_pixel1 & 0xffffff00 ) == 0 )
                {
                    ogre_pixel1 |= 255;
                }
                else if( stp == 1 && ( ogre_pixel1 & 0xffffff00 ) != 0 )
                {
                    ogre_pixel1 |= 255 / 4;
                }

                u32 ogre_pixel2 = ( ( ( clut2 & 0x1f ) * 255 / 31 ) << 0x18 ) | ( ( ( ( clut2 >>  5 ) & 0x1f ) * 255 / 31 ) << 0x10 ) | ( ( ( ( clut2 >> 10 ) & 0x1f ) * 255 / 31 ) << 0x8 ) | 0;

                stp = ( clut2 & 0x8000 ) >> 15;
                if( stp == 0 && ( ogre_pixel2 & 0xffffff00 ) == 0 )
                {
                    ogre_pixel2 |= 0;
                }
                else if( stp == 0 && ( ogre_pixel2 & 0xffffff00 ) != 0 )
                {
                    ogre_pixel2 |= 255;
                }
                else if( stp == 1 && ( ogre_pixel2 & 0xffffff00 ) == 0 )
                {
                    ogre_pixel2 |= 255;
                }
                else if( stp == 1 && ( ogre_pixel2 & 0xffffff00 ) != 0 )
                {
                    ogre_pixel2 |= 255 / 4;
                }

                data[ start_x_new + x * 2 + 0 ] = ogre_pixel1;
                data[ start_x_new + x * 2 + 1 ] = ogre_pixel2;
            }
        }

        if( second_eye == false && i < 7 )
        {
            --i;
            second_eye = true;
        }
        else
        {
            second_eye = false;
        }

        start_x_new += 32;
    }
}
