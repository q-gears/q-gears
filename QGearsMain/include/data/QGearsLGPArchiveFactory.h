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
#ifndef __QGearsLGPArchiveFactory_H__
#define __QGearsLGPArchiveFactory_H__

#include <OgreArchiveFactory.h>

#include "QGearsLGPArchive.h"

namespace QGears
{
    class LGPArchiveFactory : public Ogre::ArchiveFactory
    {
        public:
            LGPArchiveFactory();
            virtual ~LGPArchiveFactory();

            /// @copydoc FactoryObj::getType
            const String& getType(void) const
            {
                return ARCHIVE_TYPE;
            }

            /// @copydoc FactoryObj::createInstance
            Ogre::Archive* createInstance( const String& name )
            {
                return OGRE_NEW LGPArchive( name, ARCHIVE_TYPE );
            }
            /// @copydoc FactoryObj::destroyInstance
            void destroyInstance( Ogre::Archive* arch ) { delete arch; }

        protected:
            static const String ARCHIVE_TYPE;

        private:
    };
}

#endif // __QGearsLGPArchiveFactory_H__
