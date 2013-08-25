/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-30 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "data/QGearsTexCodec.h"

#include <OgreLogManager.h>
#include <OgreException.h>

#include "data/QGearsTexFile.h"

using Ogre::Codec;
using Ogre::DataStreamPtr;
using Ogre::Exception;
using Ogre::LogManager;
using Ogre::MemoryDataStreamPtr;
using Ogre::String;
using Ogre::StringUtil;

namespace QGears
{
    String TexCodec::ms_type_name( "tex" );

    //---------------------------------------------------------------------
    TexCodec::TexCodec()
    {
        //ctor
    }

    //---------------------------------------------------------------------
    TexCodec::~TexCodec()
    {
        //dtor
    }

    //---------------------------------------------------------------------
    String TexCodec::getType() const
    {
        return ms_type_name;
    }

    //---------------------------------------------------------------------
    void TexCodec::codeToFile( MemoryDataStreamPtr& input, const String& outFileName, Codec::CodecDataPtr& pData ) const
    {
        OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "Encoding not yet supported", "TexImageCodec::codeToFile");
    }

    //---------------------------------------------------------------------
    DataStreamPtr TexCodec::code( MemoryDataStreamPtr& input, Codec::CodecDataPtr& pData ) const
    {
        OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "Encoding not yet supported", "TexImageCodec::code");
    }

    //---------------------------------------------------------------------
    Codec::DecodeResult TexCodec::decode( DataStreamPtr& input ) const
    {
        TexFile tex_file;
        tex_file.read( input );

		DecodeResult ret;
		ret.first = MemoryDataStreamPtr( tex_file.getPixelData() );
		ret.second = Codec::CodecDataPtr( tex_file.getImageData() );
        return ret;
    }

    //---------------------------------------------------------------------
    String TexCodec::magicNumberToFileExt(const char *magicNumberPtr, size_t maxbytes) const
    {
        LogManager::getSingleton().logMessage( "TexImageCodec::magicNumberToFileExt: No Magic Number for TexImageCodec" );
        return StringUtil::BLANK;
    }

    //---------------------------------------------------------------------
    TexCodec *TexCodec::ms_tex_codex( NULL );

    //---------------------------------------------------------------------
    void TexCodec::install()
    {
        //install called - create stuff here
        if( ms_tex_codex == NULL )
        {
            ms_tex_codex = new TexCodec();
        }
    }

    //---------------------------------------------------------------------
    void TexCodec::initialise()
    {
        //intialise called - register stuff here
        LogManager::getSingleton().logMessage( "Registering TEX codec" );
        registerCodec( ms_tex_codex );
    }

    //---------------------------------------------------------------------
    void TexCodec::shutdown()
    {
        //shutdown called - unregister stuff here
        unRegisterCodec( ms_tex_codex );
    }

    //---------------------------------------------------------------------
    void TexCodec::uninstall()
    {
        //uninstall called - delete stuff here
        if( ms_tex_codex != NULL )
        {
            delete ms_tex_codex;
            ms_tex_codex = NULL;
        }
    }
}
