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
#include "data/QGearsFLevelFile.h"

#include <OgreLogManager.h>
#include <OgreTextureManager.h>

#include "common/FF7NameLookup.h"
#include "common/QGearsStringUtil.h"
#include "data/QGearsAFileManager.h"
#include "data/QGearsFLevelBackground2DLoader.h"
#include "data/QGearsFLevelFileSerializer.h"
#include "data/QGearsFLevelTextureLoader.h"
#include "data/QGearsHRCFileManager.h"
#include "map/QGearsBackground2DFileManager.h"
#include "FF7Common.h"
#include "core/Logger.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    FLevelFile::RESOURCE_TYPE( "QGearsFLevelFile" );
    const String    FLevelFile::SUFFIX_BACKGROUND_TEXTURE( "/texture" );
    const String    FLevelFile::SUFFIX_BACKGROUND_2D     ( "/background_2d" );

    //--------------------------------------------------------------------------
    FLevelFile::FLevelFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Resource( creator, name, handle, group, isManual, loader )
       ,m_background_texture_loader( nullptr )
       ,m_background_2d_loader( nullptr )
    {
        createParamDictionary( getResourceType() );
    }

    //--------------------------------------------------------------------------
    FLevelFile::~FLevelFile()
    {
        if( m_background_texture_loader )
        {
            assert( !m_background_texture.isNull() );
            Ogre::TextureManager::getSingleton().remove( m_background_texture->getHandle() );
            delete m_background_texture_loader;
            m_background_texture_loader = nullptr;
        }
        m_background_texture.setNull();

        if( m_background_2d_loader )
        {
            assert( !m_background_2d.isNull() );
            Background2DFileManager::getSingleton().remove( m_background_2d->getHandle() );
            delete m_background_2d_loader;
            m_background_2d_loader = nullptr;
        }
        m_background_2d.setNull();

        unload();
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::loadImpl()
    {
        FLevelFileSerializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        if (stream.isNull())
        {
            LOG_ERROR("Failed to open resource");
        }

        serializer.importFLevelFile( stream, this );

        String background_texture_name( getBackgroundTextureName() );
        if( m_background_texture_loader == nullptr )
        {
            m_background_texture_loader = new FLevelTextureLoader( *this );
            m_background_texture = Ogre::TextureManager::getSingleton().create( background_texture_name, mGroup, true, m_background_texture_loader );
        }

        String background_2d_name( getBackground2DName() );
        if( m_background_2d_loader == nullptr )
        {
            m_background_2d_loader = new FLevelBackground2DLoader( *this );
            m_background_2d = Background2DFileManager::getSingleton().createResource( background_2d_name, mGroup, true, m_background_2d_loader ).staticCast<Background2DFile>();
        }
    }

    //--------------------------------------------------------------------------
    void FLevelFile::loadModels()
    {
        HRCFileManager &hrc_mgr( HRCFileManager::getSingleton() );
        ModelList      &models( m_model_list->getModels() );
        ModelList::const_iterator it    ( models.begin() )
                                , it_end( models.end()   );
        while( it != it_end )
        {
            String hrc_name( it->hrc_name );
            Ogre::LogManager::getSingleton().stream()
                << "Loading Model: " << hrc_name;
            StringUtil::toLowerCase( hrc_name );
            HRCFilePtr  hrc =  hrc_mgr.load( hrc_name, mGroup ).staticCast<HRCFile>();
            loadAnimations( hrc, it->animations );
            m_hrc_files.push_back( hrc );
            ++it;
        }
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::loadAnimations( const HRCFilePtr &model, const AnimationList &animations )
    {
        AFileManager    &a_mgr( AFileManager::getSingleton() );
        AnimationList::const_iterator it    ( animations.begin() )
                                    , it_end( animations.end()   );
        while( it != it_end )
        {
            String animation_name;
            StringUtil::splitBase( it->name, animation_name );
            StringUtil::toLowerCase( animation_name );
            String animation_filename( animation_name + FF7::EXT_A );
            AFilePtr animation = a_mgr.load( animation_filename, model->getGroup() ).staticCast<AFile>();
            animation_name = FF7::NameLookup::animation( animation_name );
            Ogre::LogManager::getSingleton().stream()
                << " Adding Animation: " << animation_name;
            animation->addTo( model->getSkeleton(), animation_name );
            ++it;
        }
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::unloadImpl()
    {
        m_background.setNull();
        m_camera_matrix.setNull();
        m_palette.setNull();
        m_model_list.setNull();
        m_walkmesh.setNull();
        m_hrc_files.clear();
        m_triggers.setNull();
    }

    //--------------------------------------------------------------------------
    const String&
    FLevelFile::getResourceType( void ) const
    {
        return RESOURCE_TYPE;
    }

    //--------------------------------------------------------------------------
    size_t
    FLevelFile::calculateSize() const
    {
        // data is only stored in section resources
        return 0;
    }

    const std::vector<u8>& FLevelFile::getRawScript() const
    {
        return m_rawScript;
    }

    //--------------------------------------------------------------------------
    const BackgroundFilePtr&
    FLevelFile::getBackground( void ) const
    {
        return m_background;
    }

    void FLevelFile::setRawScript(const std::vector<u8>& scriptData)
    {
        m_rawScript = scriptData;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::setBackground( const BackgroundFilePtr &background )
    {
        m_background = background;
    }

    //--------------------------------------------------------------------------
    const CameraMatrixFilePtr&
    FLevelFile::getCameraMatrix( void ) const
    {
        return m_camera_matrix;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::setCameraMatrix( const CameraMatrixFilePtr &camera_matrix )
    {
        m_camera_matrix = camera_matrix;
    }

    //--------------------------------------------------------------------------
    const PaletteFilePtr&
    FLevelFile::getPalette( void ) const
    {
        return m_palette;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::setPalette( const PaletteFilePtr &palette )
    {
        m_palette = palette;
    }

    //--------------------------------------------------------------------------
    const ModelListFilePtr&
    FLevelFile::getModelList() const
    {
        return m_model_list;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::setModelList(const ModelListFilePtr &model_list)
    {
        m_model_list = model_list;
    }

    //--------------------------------------------------------------------------
    const WalkmeshFilePtr&
    FLevelFile::getWalkmesh() const
    {
        return m_walkmesh;
    }

    const TriggersFilePtr& FLevelFile::getTriggers() const
    {
        return m_triggers;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFile::setWalkmesh( const WalkmeshFilePtr &walkmesh )
    {
        m_walkmesh = walkmesh;
    }

    void FLevelFile::setTriggers(const TriggersFilePtr& triggers)
    {
        m_triggers = triggers;
    }

    //--------------------------------------------------------------------------
    String
    FLevelFile::getBackgroundTextureName( void ) const
    {
        String base_name;
        StringUtil::splitFull( getName(), base_name );
        base_name += SUFFIX_BACKGROUND_TEXTURE;
        return base_name;
    }

    //--------------------------------------------------------------------------
    String
    FLevelFile::getBackground2DName( void ) const
    {
        String base_name;
        StringUtil::splitFull( getName(), base_name );
        base_name += SUFFIX_BACKGROUND_2D;
        return base_name;
    }

    //--------------------------------------------------------------------------
}
