/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-16 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsRSDFile_H__
#define __QGearsRSDFile_H__

#include <OgreResource.h>
#include <OgreMaterial.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class RSDFile : public Ogre::Resource
    {
    public:
        RSDFile( Ogre::ResourceManager *creator, const String &name
                ,Ogre::ResourceHandle handle, const String &group
                ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~RSDFile();

        static const String RESOURCE_TYPE;

        typedef std::vector<String>             TextureNameList;
        typedef std::vector<Ogre::MaterialPtr>  MaterialList;

        virtual void setPolygonName ( const String &polygon_name );
        virtual void setMaterialName( const String &material_name );
        virtual void setGroupName   ( const String &group_name );

        virtual const String& getPolygonName ( void ) const;
        virtual const String& getMaterialName( void ) const;
        virtual const String& getGroupName   ( void ) const;
        virtual size_t getTextureNameCount   ( void ) const;
        virtual TextureNameList& getTextureNames( void );
        virtual String getMaterialBaseName( void ) const;

    protected:
        virtual void    loadImpl();
        virtual void    unloadImpl();
        virtual size_t  calculateSize() const;
        virtual void    addTexture( Ogre::Pass *pass, const size_t index ) const;

    private:
        String          m_polygon_name;
        String          m_material_name;
        String          m_group_name;
        TextureNameList m_texture_names;
        MaterialList    m_materials;
    };

    typedef Ogre::SharedPtr<RSDFile> RSDFilePtr;
}

#endif // __QGearsRSDFile_H__
