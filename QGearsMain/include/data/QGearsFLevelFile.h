/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsFLevelFile_H__
#define __QGearsFLevelFile_H__

#include <OgreTexture.h>

#include "common/QGearsResource.h"
#include "common/TypeDefine.h"
#include "map/QGearsBackground2DFile.h"
#include "map/QGearsWalkmeshFile.h"

#include "data/FF7ModelListFile.h"

#include "QGearsBackgroundFile.h"
#include "QGearsCameraMatrixFile.h"
#include "QGearsPaletteFile.h"
#include "QGearsHRCFile.h"

namespace QGears
{
    // TODO: move flevel stuff to ff7 as it is ff7 related!?
    using FF7::ModelListFile;
    using FF7::ModelListFilePtr;

    class FLevelTextureLoader;
    class FLevelBackground2DLoader;

    class FLevelFile : public Resource
    {
    public:

        FLevelFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~FLevelFile();

        static const String RESOURCE_TYPE;

        virtual const BackgroundFilePtr&    getBackground  ( void ) const;
        virtual const CameraMatrixFilePtr&  getCameraMatrix( void ) const;
        virtual const ModelListFilePtr&     getModelList   ( void ) const;
        virtual const PaletteFilePtr&       getPalette     ( void ) const;
        virtual const WalkmeshFilePtr&      getWalkmesh    ( void ) const;

        virtual void setBackground  ( const BackgroundFilePtr      &background    );
        virtual void setCameraMatrix( const CameraMatrixFilePtr    &camera_matrix );
        virtual void setModelList   ( const ModelListFilePtr       &model_list    );
        virtual void setPalette     ( const PaletteFilePtr         &palette       );
        virtual void setWalkmesh    ( const WalkmeshFilePtr        &walkmesh      );

        virtual String getBackground2DName( void ) const;
        virtual String getBackgroundTextureName( void ) const;

    protected:
        typedef std::vector<HRCFilePtr>         HRCList;
        typedef ModelListFile::ModelList        ModelList;
        typedef ModelListFile::AnimationList    AnimationList;

        static const String SUFFIX_BACKGROUND_TEXTURE;
        static const String SUFFIX_BACKGROUND_2D;

        virtual void loadImpl( void );
        virtual void loadModels( void );
        virtual void loadAnimations( const HRCFilePtr &model, const AnimationList &animations );
        virtual void unloadImpl( void );
        virtual size_t calculateSize( void ) const;

        virtual const String& getResourceType( void ) const;

    private:
        BackgroundFilePtr           m_background;
        CameraMatrixFilePtr         m_camera_matrix;
        ModelListFilePtr            m_model_list;
        PaletteFilePtr              m_palette;
        WalkmeshFilePtr             m_walkmesh;

        FLevelTextureLoader        *m_background_texture_loader;
        Ogre::TexturePtr            m_background_texture;
        FLevelBackground2DLoader   *m_background_2d_loader;
        Background2DFilePtr         m_background_2d;
        HRCList                     m_hrc_files;
    };

    typedef Ogre::SharedPtr<FLevelFile> FLevelFilePtr;
}

#endif // __QGearsFLevelFile_H__
