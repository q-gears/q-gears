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
#ifndef __QGearsTexCodec_H__
#define __QGearsTexCodec_H__

#include <OgreImageCodec.h>

#include "QGearsTexPlugin_Prerequisites.h"

namespace QGears
{
    class _QGearsTexPluginExport TexCodec : public Ogre::ImageCodec
    {
    public:
        TexCodec();
        virtual ~TexCodec();

        /// @copydoc Ogre::ImageCodec::getType
        virtual Ogre::String getType() const;

        /// @copydoc Ogre::Codec::code
        Ogre::DataStreamPtr code( Ogre::MemoryDataStreamPtr& input, Ogre::Codec::CodecDataPtr& pData ) const;

        /// @copydoc Ogre::Codec::codeToFile
        void codeToFile( Ogre::MemoryDataStreamPtr& input, const Ogre::String& outFileName, Ogre::Codec::CodecDataPtr& pData ) const;

        /// @copydoc Ogre::Codec::decode
        Ogre::Codec::DecodeResult decode( Ogre::DataStreamPtr& input ) const;

        /// @copydoc Ogre::Codec::magicNumberToFileExt
        virtual Ogre::String magicNumberToFileExt(const char *magicNumberPtr, size_t maxbytes) const;

        static Ogre::String ms_type_name;

        /// @copydoc Ogre::Plugin::install
        static void install();

        /// @copydoc Ogre::Plugin::initialise
        static void initialise();

        /// @copydoc Ogre::Plugin::shutdown
        static void shutdown();

        /// @copydoc Ogre::Plugin::uninstall
        static void uninstall();

      private:
        static TexCodec *ms_tex_codex;
    };
}

#endif // __QGearsTexCodec_H__
