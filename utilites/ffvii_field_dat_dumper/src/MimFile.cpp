#include "MimFile.h"

#include "../../common/Logger.h"



MimFile::MimFile( const Ogre::String& file ):
    LzsFile( file )
{
    InnerGetImage();
}



MimFile::MimFile( File* pFile ):
    LzsFile( pFile )
{
    InnerGetImage();
}



MimFile::MimFile( File* pFile, const u32 offset, const u32 length ):
    LzsFile( pFile, offset, length )
{
    InnerGetImage();
}



MimFile::MimFile( u8* pBuffer, const u32 offset, const u32 length ):
    LzsFile( pBuffer, offset, length )
{
    InnerGetImage();
}



MimFile::~MimFile()
{
}



Surface*
MimFile::GetSurface( const u16 page_x, const u16 page_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const Ogre::String& type, const float r_mod, const float g_mod, const float b_mod )
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

                u8 data = m_Vram.GetU8( real_x, real_y ) & 0x0F;
                u16 col = m_Vram.GetU16( data * 2 + clut_x * 2, clut_y );

                color.r = ( ( col       ) & 31 ) * 255 / 31;
                color.g = ( ( col >>  5 ) & 31 ) * 255 / 31;
                color.b = ( ( col >> 10 ) & 31 ) * 255 / 31;
                if( type == "mult" )
                {
                    color.r *= r_mod;
                    color.g *= g_mod;
                    color.b *= b_mod;
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

                memcpy(ret->pixels + x * 8 + ret->width * 4 * y + 0x00, &color, sizeof(ClutColor));



                data    = (m_Vram.GetU8(real_x, real_y) & 0xF0) >> 4;
                col     = m_Vram.GetU16(data * 2 + clut_x * 2, clut_y);

                color.r = ((col      ) & 31) * 255 / 31;
                color.g = ((col >>  5) & 31) * 255 / 31;
                color.b = ((col >> 10) & 31) * 255 / 31;
                if( type == "mult" )
                {
                    color.r *= r_mod;
                    color.g *= g_mod;
                    color.b *= b_mod;
                }
                stp = (col & 0x80) >> 15;

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

                memcpy(ret->pixels + x * 8 + ret->width * 4 * y + 0x04, &color, sizeof(ClutColor));
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

                u8 data = m_Vram.GetU8( real_x, real_y );
                u16 col = m_Vram.GetU16( data * 2 + clut_x * 2, clut_y );

                color.r = ((col      ) & 31) * 255 / 31;
                color.g = ((col >>  5) & 31) * 255 / 31;
                color.b = ((col >> 10) & 31) * 255 / 31;
                if( type == "mult" )
                {
                    color.r *= r_mod;
                    color.g *= g_mod;
                    color.b *= b_mod;
                }
                u8 stp = (col & 0x8000) >> 15;

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

                memcpy(ret->pixels + x * 4 + ret->width * 4 * y, &color, sizeof(ClutColor));
            }
        }
    }

    return ret;
}



void
MimFile::InnerGetImage()
{
    // get number of clut
    MimHeader* mim_header = (MimHeader*)m_Buffer;

    mClutVramPositionX = mim_header->x;
    mClutVramPositionY = mim_header->y;
    mClutWidth         = mim_header->width;
    mClutHeight        = mim_header->height;

//    LOGGER->Log("mClutVramPositionY %d", mClutVramPositionY);

    for( int y = 0; y < mClutHeight; ++y )
    {
        for( int x = 0; x < mClutWidth; ++x )
        {
            u16 color = GetU16LE(sizeof(MimHeader) + y * mClutWidth * 2 + x * 2);
            m_Vram.PutU16(x * 2 + mClutVramPositionX, y + mClutVramPositionY, color);
        }
    }



    // set image buffer
    MimHeader2* mim_header2 = (MimHeader2*)((u8*)m_Buffer + mim_header->header2_offset);
    mImageVramPositionX = mim_header2->x * 2;
    mImageVramPositionY = mim_header2->y;
    mImageWidth         = mim_header2->width * 2;
    mImageHeight        = mim_header2->height;

    for (int y = 0; y < mImageHeight; ++y)
    {
        for (int x = 0; x < mImageWidth; ++x)
        {
            u8 data = GetU8(mim_header->header2_offset + sizeof(MimHeader2) + y * mImageWidth + x);
            m_Vram.PutU8(x + mImageVramPositionX, y + mImageVramPositionY, data);
        }
    }



    // add to image buffer
    u32 data_3_offset = mim_header->header2_offset + mim_header2->data_size;

    if (m_BufferSize > data_3_offset)
    {
        MimHeader2* mim_header3 = (MimHeader2*)((u8*)m_Buffer + data_3_offset);

        if (mim_header3->data_size > 0)
        {
            u16 image_vram_position_x = mim_header3->x * 2;
            u16 image_vram_position_y = mim_header3->y;
            u16 image_width           = mim_header3->width * 2;
            u16 image_height          = mim_header3->height;

            for (int y = 0; y < image_height; ++y)
            {
                for (int x = 0; x < image_width; ++x)
                {
                    u8 data = GetU8(data_3_offset + sizeof(MimHeader2) + y * image_width + x);
                    m_Vram.PutU8( x + image_vram_position_x, y + image_vram_position_y, data );
                }
            }

            // update image size
            u16 first_end_x     = mImageVramPositionX + mImageWidth;
            u16 second_end_x    = image_vram_position_x + image_width;
            u16 min_start_x     = (mImageVramPositionX < image_vram_position_x) ? mImageVramPositionX : image_vram_position_x;
            u16 max_end_x       = (first_end_x > second_end_x) ? first_end_x : second_end_x;

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
