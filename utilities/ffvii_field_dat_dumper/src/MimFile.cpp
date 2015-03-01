#include "MimFile.h"

#include "../../common/Logger.h"



MimFile::MimFile( const Ogre::String& file )
    : LzsFile(file), m_Vram(Vram::MakeInstance())
{
    InnerGetImage();
}



MimFile::MimFile( File* pFile )
    : LzsFile(pFile), m_Vram(Vram::MakeInstance())
{
    InnerGetImage();
}



MimFile::MimFile( File* pFile, const u32 offset, const u32 length )
    : LzsFile(pFile, offset, length), m_Vram(Vram::MakeInstance())
{
    InnerGetImage();
}



MimFile::MimFile( u8* pBuffer, const u32 offset, const u32 length )
    : LzsFile(pBuffer, offset, length), m_Vram(Vram::MakeInstance())
{
    InnerGetImage();
}



MimFile::~MimFile()
{
}



Surface*
MimFile::GetSurface( const u16 page_x, const u16 page_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const int clut_start, const int clut_width, const Ogre::String& mod_type, const float mod_r, const float mod_g, const float mod_b )
{
    // lastest texture page x are on the border with vram so we need get smaller tex
    u16 size_x = ( page_x >= 15 && bpp == 1 ) ? 128 : 256;
    Surface* ret = CreateSurface( size_x, 256 );

    if( clut_y > mClutHeight + mClutVramPositionY )
    {
        LOGGER->Log( "MimFile::GetSurface: Warning: \"clut_number\" is greater than number of clut in file." );
        return ret;
    }

    // temp clut color
    ClutColor color;

    if( bpp == 0 )
    {
        for( int y = 0; y < 256; ++y )
        {
            for( int x = 0; x < 128; ++x )
            {
                u16 real_x = mImageVramPositionX + page_x * 128 + x;
                u16 real_y = mImageVramPositionY + page_y * 256 + y;

                int data = (m_Vram->GetU8(real_x, real_y) & 0x0f) + clut_x;
                u16 col = m_Vram->GetU16(data * 2, clut_y);

                color.r = ( ( col       ) & 31 ) * 255 / 31;
                color.g = ( ( col >>  5 ) & 31 ) * 255 / 31;
                color.b = ( ( col >> 10 ) & 31 ) * 255 / 31;
                if( data >= clut_start && data < clut_start + clut_width )
                {
                    GetModifiedClut( color, mod_type, mod_r, mod_g, mod_b );
                }
                u8 stp = (col & 0x80) >> 15;

                if( col == 0x0000 )
                {
                    color.a = 0;
                }
                else if( stp == 1 && color.r == 0 && color.g == 0 && color.b == 0 )
                {
                    color.a = 255;
                }
                else if( stp == 1 && ( color.r != 0 || color.g != 0 || color.b != 0 ) )
                {
                    color.a = 127;
                }
                else if( stp == 0 && ( color.r != 0 || color.g != 0 || color.b != 0 ) )
                {
                    color.a = 255;
                }

                memcpy( ret->pixels.data() + x * 8 + ret->width * 4 * y + 0x00, &color, sizeof( ClutColor ) );



                data = ((m_Vram->GetU8(real_x, real_y) & 0xf0) >> 4) + clut_x;
                col = m_Vram->GetU16(data * 2, clut_y);

                color.r = ( ( col       ) & 31 ) * 255 / 31;
                color.g = ( ( col >>  5 ) & 31 ) * 255 / 31;
                color.b = ( ( col >> 10 ) & 31 ) * 255 / 31;
                if( data >= clut_start && data < clut_start + clut_width )
                {
                    GetModifiedClut( color, mod_type, mod_r, mod_g, mod_b );
                }
                stp = ( col & 0x80 ) >> 15;

                if( col == 0x0000 )
                {
                    color.a = 0;
                }
                else if( stp == 1 && color.r == 0 && color.g == 0 && color.b == 0 )
                {
                    color.a = 255;
                }
                else if( stp == 1 && ( color.r != 0 || color.g != 0 || color.b != 0 ) )
                {
                    color.a = 127;
                }
                else if( stp == 0 && ( color.r != 0 || color.g != 0 || color.b != 0 ) )
                {
                    color.a = 255;
                }

                memcpy( ret->pixels.data() + x * 8 + ret->width * 4 * y + 0x04, &color, sizeof( ClutColor ) );
            }
        }
    }



    else if( bpp == 1 )
    {
        for( int y = 0; y < 256; ++y )
        {
            for( int x = 0; x < size_x; ++x )
            {
                u16 real_x = mImageVramPositionX + page_x * 128 + x;
                u16 real_y = mImageVramPositionY + page_y * 256 + y;

                u8 data = m_Vram->GetU8(real_x, real_y);
                u16 col = m_Vram->GetU16(data * 2 + clut_x * 2, clut_y);

                color.r = ( ( col       ) & 31 ) * 255 / 31;
                color.g = ( ( col >>  5 ) & 31 ) * 255 / 31;
                color.b = ( ( col >> 10 ) & 31 ) * 255 / 31;
                if( data >= clut_start && data < clut_start + clut_width )
                {
                    GetModifiedClut( color, mod_type, mod_r, mod_g, mod_b );
                }

                u8 stp = ( col & 0x8000 ) >> 15;

                if( col == 0x0000 )
                {
                    color.a = 0;
                }
                else if( stp == 1 && color.r == 0 && color.g == 0 && color.b == 0 )
                {
                    color.a = 255;
                }
                else if( stp == 1 && ( color.r != 0 || color.g != 0 || color.b != 0 ) )
                {
                    color.a = 127;
                }
                else if( stp == 0 && ( color.r != 0 || color.g != 0 || color.b != 0 ) )
                {
                    color.a = 255;
                }

                memcpy( ret->pixels.data() + x * 4 + ret->width * 4 * y, &color, sizeof( ClutColor ) );
            }
        }
    }



    else if ( bpp == 2 )
    {
        for( int y = 0; y < 256; ++y )
        {
            for( int x = 0; x < 256; ++x )
            {
                u16 real_x = mImageVramPositionX + page_x * 128 + x * 2;
                u16 real_y = mImageVramPositionY + page_y * 256 + y;

                u16 col = m_Vram->GetU16(real_x, real_y);

                color.r = ( ( col       ) & 31 ) * 255 / 31;
                color.g = ( ( col >>  5 ) & 31 ) * 255 / 31;
                color.b = ( ( col >> 10 ) & 31 ) * 255 / 31;

                if( col == 0x0000 )
                {
                    color.a = 0;
                }
                else
                {
                    color.a = 255;
                }

                memcpy( ret->pixels.data() + x * 4 + ret->width * 4 * y, &color, sizeof( ClutColor ) );
            }
        }
    }

    return ret;
}



void
MimFile::InnerGetImage()
{
    // get number of clut
    MimHeader* mim_header = ( MimHeader* )m_Buffer;

    mClutVramPositionX = mim_header->x;
    mClutVramPositionY = mim_header->y;
    mClutWidth         = mim_header->width;
    mClutHeight        = mim_header->height;

    for( int y = 0; y < mClutHeight; ++y )
    {
        for( int x = 0; x < mClutWidth; ++x )
        {
            u16 color = GetU16LE( sizeof( MimHeader ) + y * mClutWidth * 2 + x * 2 );
            m_Vram->PutU16(x * 2 + mClutVramPositionX, y + mClutVramPositionY, color);
        }
    }



    // set image buffer
    MimHeader2* mim_header2 = ( MimHeader2* )( ( u8* )m_Buffer + mim_header->header2_offset );
    mImageVramPositionX = mim_header2->x * 2;
    mImageVramPositionY = mim_header2->y;
    mImageWidth         = mim_header2->width * 2;
    mImageHeight        = mim_header2->height;

    for( int y = 0; y < mImageHeight; ++y )
    {
        for( int x = 0; x < mImageWidth; ++x )
        {
            u8 data = GetU8( mim_header->header2_offset + sizeof( MimHeader2 ) + y * mImageWidth + x );
            m_Vram->PutU8( x + mImageVramPositionX, y + mImageVramPositionY, data );
        }
    }



    // add to image buffer
    u32 data_3_offset = mim_header->header2_offset + mim_header2->data_size;

    if( m_BufferSize > data_3_offset )
    {
        MimHeader2* mim_header3 = ( MimHeader2* )( ( u8* )m_Buffer + data_3_offset );

        if (mim_header3->data_size > 0)
        {
            u16 image_vram_position_x = mim_header3->x * 2;
            u16 image_vram_position_y = mim_header3->y;
            u16 image_width           = mim_header3->width * 2;
            u16 image_height          = mim_header3->height;

            for( int y = 0; y < image_height; ++y )
            {
                for( int x = 0; x < image_width; ++x )
                {
                    u8 data = GetU8( data_3_offset + sizeof( MimHeader2 ) + y * image_width + x );
                    m_Vram->PutU8(x + image_vram_position_x, y + image_vram_position_y, data);
                }
            }

            // update image size
            u16 first_end_x     = mImageVramPositionX + mImageWidth;
            u16 second_end_x    = image_vram_position_x + image_width;
            u16 min_start_x     = ( mImageVramPositionX < image_vram_position_x ) ? mImageVramPositionX : image_vram_position_x;
            u16 max_end_x       = ( first_end_x > second_end_x ) ? first_end_x : second_end_x;

            mImageVramPositionX = min_start_x;
            mImageWidth         = max_end_x - min_start_x;

            u16 first_end_y     = mImageVramPositionY + mImageHeight;
            u16 second_end_y    = image_vram_position_y + image_height;
            u16 min_start_y     = (mImageVramPositionY < image_vram_position_y) ? mImageVramPositionY : image_vram_position_y;
            u16 max_end_y       = (first_end_y > second_end_y) ? first_end_y : second_end_y;

            mImageVramPositionY = min_start_y;
            mImageHeight        = max_end_y - min_start_y;
        }
    }

    mImageVramPositionX = 0;
    mImageVramPositionY = 0;
    mImageWidth  = 2048;
    mImageHeight = 512;

    //m_Vram.Save( "export" );
}



void
MimFile::GetModifiedClut( MimFile::ClutColor& clut, const Ogre::String& mod_type, const float mod_r, const float mod_g, const float mod_b )
{
    if( mod_type == "mult" )
    {
        if( clut.r * mod_r >= 256 )
        {
            clut.r = 255;
        }
        else if( clut.r * mod_r < 0 )
        {
            clut.r = 0;
        }
        else
        {
            clut.r *= u8(mod_r);
        }

        if( clut.g * mod_g >= 256 )
        {
            clut.g = 255;
        }
        else if(clut.g * mod_g < 0 )
        {
            clut.g = 0;
        }
        else
        {
            clut.g *= u8(mod_g);
        }

        if( clut.b * mod_b >= 256 )
        {
            clut.b = 255;
        }
        else if( clut.b * mod_b < 0 )
        {
            clut.b = 0;
        }
        else
        {
            clut.b *= u8(mod_b);
        }
    }
    else if( mod_type == "add" )
    {
        if( clut.r + mod_r * 8 >= 256 )
        {
            clut.r = 255;
        }
        else if( clut.r + mod_r * 8 < 0 )
        {
            clut.r = 0;
        }
        else
        {
            clut.r += u8(mod_r * 8);
        }

        if( clut.g + mod_g * 8 >= 256 )
        {
            clut.g = 255;
        }
        else if( clut.g + mod_g * 8 < 0 )
        {
            clut.g = 0;
        }
        else
        {
            clut.g += u8(mod_g * 8);
        }

        if( clut.b + mod_b * 8 >= 256 )
        {
            clut.b = 255;
        }
        else if( clut.b + mod_b * 8 < 0 )
        {
            clut.b = 0;
        }
        else
        {
            clut.b += u8(mod_b * 8);
        }
    }
}



/*
bool
MimFile::ClutCheck(const u16 page_x, const u16 page_y, const u16 clut_x, const u8 bpp, const u8 src_x, const u8 src_y, const u8 width, const u8 height, const u16 check_clut_x, const u16 check_clut_width )
{
    if( bpp == 0 )
    {
        for( int y = src_y; y < src_y + height; ++y )
        {
            for( int x = src_x / 2; x < ( src_x + width ) / 2; ++x )
            {
                u16 real_x = mImageVramPositionX + page_x * 128 + x;
                u16 real_y = mImageVramPositionY + page_y * 256 + y;

                u8 data = ( m_Vram.GetU8( real_x, real_y ) & 0x0f ) * 2 + clut_x * 3;

                if( data > check_clut_x + check_clut_width || data < check_clut_x )
                {
                    return false;
                }

                data = ( ( m_Vram.GetU8( real_x, real_y ) & 0xf0 ) >> 4 ) * 2 + clut_x * 2;

                if( data > check_clut_x + check_clut_width || data < check_clut_x )
                {
                    return false;
                }
            }
        }
    }
    else if( bpp == 1 )
    {
LOGGER->Log( "TileCompare: src_x=" + IntToString( src_x ) + " width=" + IntToString( width ) + "\n" );
LOGGER->Log( "TileCompare: src_y=" + IntToString( src_y ) + " height=" + IntToString( height ) + "\n" );
LOGGER->Log( "TileCompare: clut_x=" + IntToString( src_x ) + " check_clut_width=" + IntToString( check_clut_width ) + "\n" );

        for( int y = src_y; y < src_y + height; ++y )
        {
            for( int x = src_x; x < src_x + width; ++x )
            {
                u16 real_x = mImageVramPositionX + page_x * 128 + x;
                u16 real_y = mImageVramPositionY + page_y * 256 + y;

                u8 data = m_Vram.GetU8( real_x, real_y );
                u16 col = m_Vram.GetU16( data * 2 + clut_x * 2, 493 );
LOGGER->Log( "TileCompare: x=" + IntToString( x ) + " y=" + IntToString( y ) + "\n" );
LOGGER->Log( "TileCompare: data=0x" + HexToString( data, 2, '0' ) + " col=0x" + HexToString( col, 4, '0' ) + "\n" );

                if( data >= check_clut_x + check_clut_width || data < check_clut_x )
                {
                    //return false;
                }
            }
        }
    }

    return true;
}
*/
