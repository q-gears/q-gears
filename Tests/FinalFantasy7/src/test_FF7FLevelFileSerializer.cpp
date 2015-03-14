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
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsFLevelFileSerializer.h"

#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsCameraMatrixFileManager.h"
#include "data/QGearsHRCFileManager.h"
#include "data/QGearsPaletteFileManager.h"
#include "data/QGearsLZSFLevelFileManager.h"
#include "data/FF7ModelListFileManager.h"
#include "map/QGearsBackground2DFileManager.h"
#include "map/QGearsWalkmeshFileManager.h"

using namespace Ogre;

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::FLevelFile
    {
    public:
        TestFile() : QGears::FLevelFile( NULL, "reference.flevel", 0, "General" ) {}
    };

    class TestTexture : public Texture
    {
    public:
        TestTexture( ResourceManager* creator, const String& name, ResourceHandle handle,
                  const String& group, bool isManual = false, ManualResourceLoader* loader = 0 )
            : Texture( creator, name, handle, group, isManual, loader )
        {}

    protected:
        virtual void loadImpl() {}
        virtual void unloadImpl() {}
        virtual HardwarePixelBufferSharedPtr getBuffer( size_t, size_t ){ return HardwarePixelBufferSharedPtr( NULL ); }
        virtual void createInternalResourcesImpl(){}
        virtual void freeInternalResourcesImpl(){}
    };

    class TestTextureManager : public TextureManager
    {
    public:
        virtual PixelFormat getNativeFormat( TextureType ttype, PixelFormat format, int usage )
        {
            return format;
        }
        virtual bool    isHardwareFilteringSupported( TextureType ttype, PixelFormat format, int usage, bool preciseFormatOnly=false )
        {
            return false;
        }

    protected:
        virtual Resource* createImpl( const String &name
          , ResourceHandle handle, const String &group, bool isManual
          , ManualResourceLoader *loader
          , const NameValuePairList *createParams )
        {
            return new TestTexture( this, name, handle, group, isManual, loader );
        }
    };


    LogManager                          logMgr;
    Root                                root("","");
    ResourceGroupManager               &rgm( ResourceGroupManager::getSingleton() );
    TestTextureManager                  tmgr;
    QGears::CameraMatrixFileManager     cmgr;
    QGears::WalkmeshFileManager         wmgr;
    QGears::PaletteFileManager          pmgr;
    QGears::BackgroundFileManager       bmgr;
    QGears::Background2DFileManager     b2mgr;
    QGears::FF7::ModelListFileManager   mmgr;
    QGears::HRCFileManager              hmgr;
    QGears::LZSFLevelFileManager        fmgr;
    logMgr.createLog( "Default Log", true, true, true );

    rgm.addResourceLocation( "misc", "FileSystem" );
    rgm.initialiseAllResourceGroups();

    TestFile        file;
    DataStreamPtr   stream( rgm.openResource( file.getName(), file.getGroup() ) );
    BOOST_REQUIRE( stream->isReadable() );

    QGears::FLevelFileSerializer    ser;
    ser.importFLevelFile( stream, &file );
    BOOST_CHECK_EQUAL( 757890, stream->tell() );

    QGears::BackgroundFilePtr       background   ( file.getBackground() );
    QGears::CameraMatrixFilePtr     camera_matrix( file.getCameraMatrix() );
    QGears::FF7::ModelListFilePtr   model_list   ( file.getModelList() );
    QGears::PaletteFilePtr          palette      ( file.getPalette() );
    QGears::WalkmeshFilePtr         walkmesh     ( file.getWalkmesh() );

    BOOST_REQUIRE( !background.isNull() );
    BOOST_REQUIRE( !camera_matrix.isNull() );
    BOOST_REQUIRE( !model_list.isNull() );
    BOOST_REQUIRE( !palette.isNull() );
    BOOST_REQUIRE( !walkmesh.isNull() );
    BOOST_CHECK_EQUAL( "reference.background", background->getName() );
    BOOST_CHECK_EQUAL( "reference.cam_matrix", camera_matrix->getName() );
    BOOST_CHECK_EQUAL( "reference.model_list", model_list->getName() );
    BOOST_CHECK_EQUAL( "reference.palette"   , palette->getName() );
    BOOST_CHECK_EQUAL( "reference.walkmesh"  , walkmesh->getName() );
    Matrix3 m3_expected(
        1, -0, -0
       ,0, -1, -0
       ,0, -0, -1
    );
    BOOST_CHECK_EQUAL( m3_expected, camera_matrix->getMatrix() );
    BOOST_CHECK_EQUAL( Vector3( -1, 2, -3 ), camera_matrix->getPosition() );
    BOOST_CHECK_EQUAL( 2, camera_matrix->getCount() );
    BOOST_CHECK_EQUAL( 12345, camera_matrix->getFocalLength() );


    Ogre::Image *image( background->createImage( palette ) );
    // TODO: FIX ME ON OSX
    //image->save( file.getName() + ".png" );
    delete image;

    QGears::FLevelFilePtr lzs_file = fmgr.load( "reference_compressed.flevel", "General" ).staticCast<QGears::FLevelFile>();
    BOOST_CHECK( !lzs_file->getPalette().isNull() );
    BOOST_CHECK( !lzs_file->getBackground().isNull() );

    image = lzs_file->getBackground()->createImage( lzs_file->getPalette() );
    // TODO: FIX ME ON OSX
    //image->save( lzs_file->getName() + ".png" );
    delete image;

    lzs_file.setNull();
    logMgr.destroyLog( "Default Log" );
    stream->close();
}
