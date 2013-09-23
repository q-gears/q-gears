/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-09-22 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsLGPArchive_H__
#define __QGearsLGPArchive_H__

#include <OgreArchive.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class LGPArchive : public Ogre::Archive
    {
        public:
            LGPArchive( const String &name, const String &archType );
            virtual ~LGPArchive();

            /// @copydoc Ogre::Archive::isCaseSensitive
            bool isCaseSensitive(void) const { return true; }

            /// @copydoc Ogre::Archive::load
            void load();

            /// @copydoc Ogre::Archive::unload
            void unload();

            /// @copydoc Ogre::Archive::open
            Ogre::DataStreamPtr open(const String& filename, bool readOnly = true) const;

            /// @copydoc Archive::create
            Ogre::DataStreamPtr create(const String& filename) const;

            /// @copydoc Archive::remove
            void remove(const String& filename) const;

            /// @copydoc Archive::list
            Ogre::StringVectorPtr list(bool recursive = true, bool dirs = false);

            /// @copydoc Archive::listFileInfo
            Ogre::FileInfoListPtr listFileInfo(bool recursive = true, bool dirs = false);

            /// @copydoc Archive::find
            Ogre::StringVectorPtr find(const String& pattern, bool recursive = true,
                bool dirs = false);

            /// @copydoc Archive::findFileInfo
            Ogre::FileInfoListPtr findFileInfo(const String& pattern, bool recursive = true,
                bool dirs = false) const;

            /// @copydoc Archive::exists
            bool exists(const String& filename);

            /// @copydoc Archive::getModifiedTime
            time_t getModifiedTime(const String& filename);


            struct FileEntry
            {
                String file_name;
                uint32 file_offset;
                uint8  unknown1;
                uint16 unknown2;

                uint32 data_offset;
                uint32 data_size;
            };

            typedef std::vector<FileEntry> FileList;

            virtual FileList& getFiles( void );

        protected:

        private:
            FileList            m_files;
            Ogre::DataStreamPtr m_lgp_file;
    };
}

#endif // __QGearsLGPArchive_H__
