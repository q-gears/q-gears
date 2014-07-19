/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-22 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsPaletteFile_H__
#define __QGearsPaletteFile_H__

#include <OgreColourValue.h>
#include <OgreResource.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class PaletteFile : public Ogre::Resource
    {
    public:

        PaletteFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~PaletteFile();

        static const String RESOURCE_TYPE;

        typedef Ogre::ColourValue   Color;
        typedef std::vector<Color>  Page;
        typedef std::vector<Page>   PageList;

        virtual PageList&  getPages( void ) { return m_pages; }

        virtual const Page& getPage( size_t index ) const { return m_pages[index]; }

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;

    private:
        PageList m_pages;
    };

    typedef Ogre::SharedPtr<PaletteFile> PaletteFilePtr;
}

#endif // __QGearsPaletteFile_H__
