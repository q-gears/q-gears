#include "modules/worldmap/WorldMapModule.h"
#include "data/worldmap/MapFileSerializer.h"
#include "data/worldmap/MapFile.h"
#include <OgreSceneManager.h>
#include <OgreManualObject.h>
#include <OgreRoot.h>
#include "core/CameraManager.h"
#include <OgreHardwarePixelBuffer.h>
#include <OgreEntity.h>

#include "data/worldmap/TxzFile.h"
#include "data/worldmap/TxzFileSerializer.h"
#include "data/worldmap/MapFileManager.h"

template<> QGears::WorldMapModule *Ogre::Singleton< QGears::WorldMapModule >::msSingleton = nullptr;

BEGIN_QGEARS

using namespace Ogre;

struct harcoded_texture_info
{
    uint32 id;
    const char* mName;
    uint32 mWidth;
    uint32 mHeight;
    uint32 mU;
    uint32 mV;
};

static harcoded_texture_info gTextures[] =
{
    { 0, "pond",  32,  32,  0,  352 },
    { 1, "riv_m2",  32,  32,  128,  64 },
    { 2, "was_gs",  64,  64,  64,  192 },
    { 3, "wpcltr",  32,  128,  0,  256 },
    { 4, "wpcltr2",  32,  32,  160,  64 },
    { 5, "bzdun",  64,  64,  192,  192 },
    { 6, "bone",  32,  32,  224,  384 },
    { 7, "bone2",  32,  32,  224,  416 },
    { 8, "bornwd",  64,  64,  160,  320 },
    { 9, "bridge",  32,  64,  192,  0 },
    { 10, "bridge2",  32,  32,  224,  0 },
    { 11, "cave",  32,  32,  224,  448 },
    { 12, "cave2",  32,  32,  224,  320 },
    { 13, "cave_s",  32,  32,  160,  224 },
    { 14, "cdl_cl2",  64,  32,  96,  96 },
    { 15, "cf01",  64,  32,  192,  288 },
    { 16, "clf_bgs",  64,  32,  192,  384 },
    { 17, "clf_ggl",  64,  64,  128,  256 },
    { 18, "clf_ggs",  64,  32,  192,  352 },
    { 19, "clf_l",  64,  64,  0,  0 },
    { 20, "clf_ld",  64,  64,  64,  0 },
    { 21, "clf_lf",  64,  64,  128,  0 },
    { 22, "clf_lg",  32,  64,  0,  96 },
    { 23, "clf_lr",  32,  64,  128,  0 },
    { 24, "clf_lsg",  32,  64,  64,  64 },
    { 25, "clf_r",  32,  32,  0,  96 },
    { 26, "clf_s",  64,  32,  192,  0 },
    { 27, "clf_sd",  64,  32,  192,  32 },
    { 28, "clf_sf",  64,  32,  0,  64 },
    { 29, "clf_sg",  32,  32,  32,  96 },
    { 30, "clf_sg2",  32,  32,  0,  160 },
    { 31, "clf_sr",  32,  32,  32,  96 },
    { 32, "clf_ss",  32,  32,  32,  128 },
    { 33, "clf_ssd",  32,  32,  0,  224 },
    { 34, "clf_ssw",  32,  32,  224,  32 },
    { 35, "clf_sw",  32,  32,  192,  32 },
    { 36, "clf_w02",  64,  64,  128,  64 },
    { 37, "clf_w03",  64,  64,  192,  64 },
    { 38, "clf_was",  64,  32,  64,  64 },
    { 39, "clfeg",  32,  32,  192,  320 },
    { 40, "clfegd",  32,  32,  0,  320 },
    { 41, "clftop",  64,  32,  192,  64 },
    { 42, "clftop2",  32,  32,  128,  64 },
    { 43, "cndl_cl",  64,  32,  96,  128 },
    { 44, "cndlf",  64,  64,  160,  64 },
    { 45, "cndlf02",  64,  64,  208,  64 },
    { 46, "comtr",  16,  32,  144,  96 },
    { 47, "cosinn",  32,  32,  224,  416 },
    { 48, "cosinn2",  32,  32,  192,  448 },
    { 49, "csmk",  32,  32,  64,  64 },
    { 50, "csmk2",  32,  32,  96,  64 },
    { 51, "cstds01",  32,  32,  224,  160 },
    { 52, "cstds02",  64,  64,  0,  448 },
    { 53, "des01",  32,  32,  160,  320 },
    { 54, "desert",  64,  64,  128,  128 },
    { 55, "desor",  64,  32,  160,  64 },
    { 56, "ds1",  32,  32,  0,  256 },
    { 57, "ds_s1",  32,  32,  192,  288 },
    { 58, "dsee1",  32,  32,  96,  288 },
    { 59, "dsrt_d",  32,  32,  224,  0 },
    { 60, "dsrt_e",  64,  128,  64,  128 },
    { 61, "edes01",  32,  32,  224,  320 },
    { 62, "elm01",  32,  32,  160,  0 },
    { 63, "elm02",  32,  32,  64,  96 },
    { 64, "elm_gro",  64,  64,  0,  96 },
    { 65, "elm_r",  32,  32,  192,  0 },
    { 66, "elm_r2",  32,  32,  224,  0 },
    { 67, "fall1",  32,  32,  128,  256 },
    { 68, "farm01",  32,  32,  160,  32 },
    { 69, "farm02",  32,  32,  192,  32 },
    { 70, "farm_g",  32,  32,  128,  64 },
    { 71, "farm_r",  32,  16,  128,  48 },
    { 72, "fld",  64,  64,  64,  96 },
    { 73, "fld_02",  64,  64,  0,  64 },
    { 74, "fld_s",  64,  64,  0,  160 },
    { 75, "fld_s2",  32,  32,  224,  256 },
    { 76, "fld_sw",  64,  64,  128,  192 },
    { 77, "fld_v",  128,  128,  0,  128 },
    { 78, "fld_vd",  32,  64,  96,  128 },
    { 79, "fld_vd2",  32,  64,  192,  416 },
    { 80, "fvedge",  32,  64,  0,  0 },
    { 81, "gclf_d",  128,  64,  128,  128 },
    { 82, "gclf_g",  32,  64,  224,  128 },
    { 83, "gclfwa",  128,  64,  64,  320 },
    { 84, "gclfwa2",  32,  64,  160,  320 },
    { 85, "gclfwag",  32,  64,  32,  320 },
    { 86, "gg_gro",  64,  64,  64,  448 },
    { 87, "gg_mts",  64,  128,  0,  128 },
    { 88, "ggmk",  64,  64,  128,  448 },
    { 89, "ggmt",  128,  128,  0,  0 },
    { 90, "ggmt_e",  128,  32,  0,  96 },
    { 91, "ggmt_ed",  128,  32,  128,  96 },
    { 92, "ggmt_eg",  32,  32,  96,  224 },
    { 93, "ggmtd",  128,  128,  128,  0 },
    { 94, "ggs_g",  32,  32,  32,  64 },
    { 95, "ggshr",  32,  32,  192,  96 },
    { 96, "ggshrg",  32,  32,  224,  96 },
    { 97, "gia",  64,  32,  64,  224 },
    { 98, "gia2",  64,  32,  0,  224 },
    { 99, "gia_d",  64,  32,  128,  224 },
    { 100, "gia_d2",  64,  32,  64,  224 },
    { 101, "gia_g",  32,  32,  192,  224 },
    { 102, "gia_g2",  32,  32,  128,  224 },
    { 103, "gmt_eda",  32,  32,  0,  352 },
    { 104, "gonclf",  128,  64,  96,  64 },
    { 105, "gredge",  32,  32,  192,  192 },
    { 106, "hyouga",  64,  64,  192,  64 },
    { 107, "iceclf",  64,  32,  64,  96 },
    { 108, "iceclfd",  64,  32,  128,  96 },
    { 109, "iceclfg",  32,  32,  32,  224 },
    { 110, "jun",  64,  64,  192,  192 },
    { 111, "jun_d",  64,  64,  128,  192 },
    { 112, "jun_e",  64,  16,  0,  240 },
    { 113, "jun_gro",  64,  64,  0,  64 },
    { 114, "junmk",  32,  32,  0,  96 },
    { 115, "junn01",  32,  32,  160,  112 },
    { 116, "junn02",  32,  32,  192,  112 },
    { 117, "junn03",  32,  32,  224,  112 },
    { 118, "junn04",  32,  32,  64,  128 },
    { 119, "jutmpl01",  64,  64,  128,  192 },
    { 120, "lake-e",  32,  32,  96,  192 },
    { 121, "lake_ef",  32,  32,  128,  224 },
    { 122, "lake_fl",  128,  32,  160,  224 },
    { 123, "lostclf",  32,  64,  128,  384 },
    { 124, "lostmt",  128,  32,  128,  448 },
    { 125, "lostmtd",  128,  32,  128,  480 },
    { 126, "lostmts",  64,  32,  160,  384 },
    { 127, "lostwd_e",  32,  32,  64,  480 },
    { 128, "lostwod",  64,  64,  0,  448 },
    { 129, "lst1",  32,  32,  192,  256 },
    { 130, "lstwd_e2",  32,  32,  96,  480 },
    { 131, "mzes",  32,  32,  224,  128 },
    { 132, "mzmt_e",  128,  64,  128,  64 },
    { 133, "mzmt_ed",  128,  32,  128,  128 },
    { 134, "mzmt_edw",  128,  32,  128,  160 },
    { 135, "mzmt_ew",  128,  32,  0,  128 },
    { 136, "mzmt_o",  128,  32,  64,  416 },
    { 137, "mzmt_od",  128,  32,  64,  448 },
    { 138, "mzmt_s",  128,  32,  0,  192 },
    { 139, "mzmt_sd",  128,  32,  0,  160 },
    { 140, "md01",  32,  32,  96,  16 },
    { 141, "md02",  128,  128,  0,  0 },
    { 142, "md03",  16,  16,  112,  64 },
    { 143, "md04",  32,  32,  128,  16 },
    { 144, "md05",  64,  16,  96,  0 },
    { 145, "md06",  16,  32,  96,  48 },
    { 146, "md07",  16,  16,  112,  48 },
    { 147, "md_mt",  128,  128,  128,  0 },
    { 148, "md_mtd",  128,  128,  0,  0 },
    { 149, "md_mts",  64,  128,  64,  160 },
    { 150, "md_snow",  128,  32,  128,  0 },
    { 151, "md_snw2",  128,  32,  128,  32 },
    { 152, "md_snwd",  128,  64,  0,  128 },
    { 153, "md_snwe",  64,  64,  96,  320 },
    { 154, "md_snws",  64,  64,  128,  128 },
    { 155, "md_snwt",  128,  32,  0,  192 },
    { 156, "md_snww",  32,  32,  224,  224 },
    { 157, "md_sw_s",  128,  128,  0,  0 },
    { 158, "md_swd2",  32,  32,  192,  256 },
    { 159, "md_swnp",  128,  128,  0,  96 },
    { 160, "mdsrt_e",  128,  32,  128,  192 },
    { 161, "mdsrt_ed",  128,  32,  128,  224 },
    { 162, "mdsrt_eg",  32,  32,  64,  224 },
    { 163, "midil",  32,  32,  32,  192 },
    { 164, "midild",  32,  32,  224,  192 },
    { 165, "mt_ewg",  32,  32,  64,  96 },
    { 166, "mt_road",  64,  64,  192,  128 },
    { 167, "mt_se",  32,  32,  160,  416 },
    { 168, "mt_se2",  64,  64,  128,  256 },
    { 169, "mt_sg01",  32,  32,  0,  224 },
    { 170, "mt_sg02",  32,  32,  32,  224 },
    { 171, "mt_sg03",  32,  32,  0,  192 },
    { 172, "mt_sg04",  32,  32,  160,  384 },
    { 173, "mtcoin",  64,  64,  0,  256 },
    { 174, "mtwas_e",  128,  32,  0,  224 },
    { 175, "mtwas_ed",  128,  32,  0,  224 },
    { 176, "ncol_gro",  64,  64,  64,  384 },
    { 177, "ncole01",  32,  32,  224,  384 },
    { 178, "ncole02",  32,  32,  192,  416 },
    { 179, "nivl_gro",  64,  64,  128,  384 },
    { 180, "nivl_mt",  128,  64,  0,  0 },
    { 181, "nivl_top",  32,  32,  0,  64 },
    { 182, "nivlr",  32,  32,  192,  384 },
    { 183, "port",  32,  32,  96,  224 },
    { 184, "port_d",  32,  32,  160,  0 },
    { 185, "rzclf02",  64,  64,  128,  128 },
    { 186, "rct_gro",  64,  128,  0,  416 },
    { 187, "riv_cls",  64,  64,  64,  0 },
    { 188, "riv_l1",  32,  32,  96,  320 },
    { 189, "riv_m",  32,  32,  0,  224 },
    { 190, "rivr",  32,  32,  64,  224 },
    { 191, "rivrclf",  64,  64,  128,  192 },
    { 192, "rivs1",  32,  32,  128,  320 },
    { 193, "rivshr",  64,  64,  192,  192 },
    { 194, "rivssr",  64,  32,  192,  224 },
    { 195, "rivstrt",  32,  32,  192,  160 },
    { 196, "rm1",  32,  32,  32,  288 },
    { 197, "rocet",  32,  32,  128,  160 },
    { 198, "rs_ss",  32,  32,  96,  224 },
    { 199, "sango",  32,  32,  224,  320 },
    { 200, "sango2",  32,  32,  224,  352 },
    { 201, "sango3",  32,  32,  128,  384 },
    { 202, "sango4",  64,  64,  0,  384 },
    { 203, "sdun",  64,  64,  0,  160 },
    { 204, "sdun02",  64,  64,  64,  160 },
    { 205, "sh1",  32,  32,  32,  256 },
    { 206, "sh_s1",  32,  32,  224,  288 },
    { 207, "shedge",  32,  64,  160,  160 },
    { 208, "shlm_1",  32,  32,  192,  320 },
    { 209, "shol",  128,  128,  128,  96 },
    { 210, "shol_s",  64,  64,  192,  192 },
    { 211, "shor",  128,  128,  0,  0 },
    { 212, "shor_s",  64,  64,  128,  192 },
    { 213, "shor_s2",  32,  32,  224,  416 },
    { 214, "shor_v",  32,  32,  192,  0 },
    { 215, "silo",  32,  32,  224,  32 },
    { 216, "slope",  128,  32,  0,  384 },
    { 217, "snow_es",  32,  32,  192,  480 },
    { 218, "snow_es2",  32,  32,  224,  480 },
    { 219, "snow_es3",  32,  32,  224,  448 },
    { 220, "snw_mt",  128,  128,  0,  0 },
    { 221, "snw_mtd",  128,  128,  128,  0 },
    { 222, "snw_mte",  64,  32,  0,  96 },
    { 223, "snw_mted",  64,  32,  64,  96 },
    { 224, "snw_mts",  64,  128,  64,  0 },
    { 225, "snw_mts2",  64,  32,  128,  192 },
    { 226, "snwfld",  64,  64,  0,  64 },
    { 227, "snwfld_s",  64,  32,  128,  128 },
    { 228, "snwgra",  64,  64,  192,  192 },
    { 229, "snwhm01",  32,  32,  32,  0 },
    { 230, "snwhm02",  32,  32,  32,  32 },
    { 231, "snwods",  32,  32,  224,  192 },
    { 232, "snwood",  64,  64,  192,  128 },
    { 233, "snwtrk",  32,  64,  96,  256 },
    { 234, "sse_s1",  32,  32,  32,  320 },
    { 235, "ssee1",  32,  32,  64,  288 },
    { 236, "sst1",  32,  32,  224,  256 },
    { 237, "stown_r",  32,  32,  192,  256 },
    { 238, "stw_gro",  64,  64,  0,  384 },
    { 239, "subrg2",  32,  32,  224,  160 },
    { 240, "susbrg",  64,  64,  192,  96 },
    { 241, "sw_se",  64,  64,  0,  0 },
    { 242, "swclf_l",  64,  64,  64,  128 },
    { 243, "swclf_ld",  64,  64,  192,  128 },
    { 244, "swclf_lg",  32,  64,  0,  192 },
    { 245, "swclf_s",  64,  32,  128,  96 },
    { 246, "swclf_sd",  64,  32,  192,  96 },
    { 247, "swclf_sg",  32,  32,  32,  192 },
    { 248, "swclf_wg",  32,  32,  192,  192 },
    { 249, "swfld_s2",  64,  32,  128,  160 },
    { 250, "swfld_s3",  32,  32,  160,  192 },
    { 251, "swmd_cg",  32,  32,  128,  192 },
    { 252, "swmd_clf",  64,  32,  64,  192 },
    { 253, "swp1",  32,  32,  0,  288 },
    { 254, "trk",  64,  64,  128,  0 },
    { 255, "tyo_f",  128,  128,  128,  128 },
    { 256, "tyosnw",  64,  128,  64,  384 },
    { 257, "uf1",  32,  32,  160,  256 },
    { 258, "utai01",  32,  32,  32,  96 },
    { 259, "utai02",  32,  32,  224,  64 },
    { 260, "utai_gro",  64,  64,  128,  96 },
    { 261, "utaimt",  32,  32,  0,  128 },
    { 262, "utaimtd",  32,  32,  96,  96 },
    { 263, "utaimtg",  32,  32,  96,  128 },
    { 264, "wa1",  32,  32,  192,  320 },
    { 265, "wzs1",  32,  32,  128,  288 },
    { 266, "wzshr",  32,  32,  160,  32 },
    { 267, "wzshr2",  32,  32,  32,  128 },
    { 268, "wzshrs",  32,  32,  32,  160 },
    { 269, "was",  128,  128,  0,  96 },
    { 270, "was_d",  64,  32,  0,  224 },
    { 271, "was_g",  64,  64,  0,  192 },
    { 272, "was_s",  128,  128,  128,  0 },
    { 273, "wasfld",  64,  64,  64,  256 },
    { 274, "wdedge",  64,  64,  64,  160 },
    { 275, "we1",  32,  32,  96,  256 },
    { 276, "we_s1",  32,  32,  160,  288 },
    { 277, "wedged",  32,  64,  128,  160 },
    { 278, "wod-e2",  32,  32,  64,  224 },
    { 279, "wood",  64,  64,  192,  0 },
    { 280, "wood_d",  64,  64,  192,  160 },
    { 281, "wtrk",  32,  64,  64,  96 }
};

static const char* kWorldResourceGroup = "FFVII_World";

static void createReferenceTextureFileInstance(QGears::TxzFileSerializer& s)
{
    class TestFile : public QGears::TxzFile
    {
    public:
        TestFile() : QGears::TxzFile( nullptr, "", 0, "" ) {}
    };

    const char* file_name = "/home/paul/qgears/data/cd1/world/wm0.txz";
    std::ifstream ifs( file_name, std::ifstream::binary );


    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( &ifs, false ) );

   // Ogre::LogManager log;
    TestFile f;


    s.import( stream, f );
}

static void createReferenceFileInstance(std::function<void(Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)> callBack)
{
    class TestFile : public QGears::WorldMapFile
    {
    public:
        TestFile() : QGears::WorldMapFile( nullptr, "", 0, "" ) {}
    };

    const char* file_name = "./data/wm/WM0.MAP";
    std::ifstream ifs( file_name, std::ifstream::binary );
    if (!ifs.is_open())
    {
        LogManager::getSingleton().logMessage("ERROR: Failed to open ./data/wm/WM0.MAP");
        return;
    }

    {
//        BOOST_REQUIRE( ifs.is_open() );
        Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( &ifs, false ) );
//        BOOST_REQUIRE( stream->isReadable() );

        //Ogre::LogManager log;
        TestFile f;

       // log.createLog( "Default Log", true, true, true );

        callBack(stream, f);

       // log.destroyLog( "Default Log" );
    }
}

static float From16BitFixedPoint(QGears::sint16 coord)
{
 //   return float(coord);

    return (float(coord) / 4096.0f);
}

void test(const std::vector<std::vector<TxzFileSerializer::rgba>>& data)
{
    //Ogre::TexturePtr texture = Ogre::TextureManager::getSingleton().load("clf_l.png.png", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);


    // kWorldResourceGroup

    Ogre::TexturePtr texture = Ogre::TextureManager::getSingleton().createManual("BackgroundTex",
                                                                                 Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                                                 Ogre::TEX_TYPE_2D,
                                                                                 640, 256, 0,
                                                                                 Ogre::PF_B8G8R8, Ogre:: TU_DYNAMIC);

    Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("BackgroundMat",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

    material->getTechnique(0)->getPass(0)->createTextureUnitState("BackgroundTex");



    //material->getTechnique(0)->getPass(0)->setSceneBlending(Ogre::SBT_TRANSPARENT_COLOUR);


    Ogre::HardwarePixelBufferSharedPtr pixelBuffer = texture->getBuffer();
    pixelBuffer->lock(Ogre::HardwareBuffer::HBL_DISCARD);
    const Ogre::PixelBox& pixelBox = pixelBuffer->getCurrentLock();
    Ogre::uint8* pDest = static_cast<Ogre::uint8*>(pixelBox.data);
    for(size_t i=0; i < 256; i++)
    {
       for(size_t j=0; j < 640; j++)
       {
          *pDest++ = data[i][j].b;
          *pDest++ = data[i][j].g;
          *pDest++ = data[i][j].r;
          *pDest++ = 0;
       }
    }

    pixelBuffer->unlock();
}

float ToTextureCoordU(uint8 coord, uint16 tId)
{
    return (float(coord) - float(gTextures[tId].mU)) / float(gTextures[tId].mWidth);
    //return (float(gTextures[tId].mU) + float(coord)) / 256.0f;

}

float ToTextureCoordV(uint8 coord, uint16 tId)
{
    return (float(coord) - float(gTextures[tId].mV)) / float(gTextures[tId].mHeight);

    //return (float(gTextures[tId].mV) + float(coord)) / 640.0f;

}

std::vector<TexturePtr> gLoadedTextures;
std::vector<MaterialPtr> gMats;
std::map<int, ManualObject*> gObjToTextureId;

static void LoadTextures()
{
    if (gLoadedTextures.empty())
    {
        for (int i=0; i<sizeof(gTextures)/sizeof(gTextures[0]); i++)
        {
            std::string textureName = std::string(gTextures[i].mName) + ".tex";
            ResourceGroupManager::getSingleton().declareResource(textureName.c_str(), "Texture", "TEST");
            TexturePtr tmp = Ogre::TextureManager::getSingleton().load(textureName.c_str(), "TEST", TEX_TYPE_2D, 1, 1.0f, false );
            gLoadedTextures.emplace_back(tmp);

            Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create(gTextures[i].mName ,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
            material->getTechnique(0)->getPass(0)->createTextureUnitState(textureName.c_str());
            material->getTechnique(0)->getPass(0)->setTextureFiltering(TFO_NONE);


            gMats.emplace_back(material);


        }
    }
}

void createTestMap(SceneManager* mSceneMgr)
{
    std::vector<QGears::MapFileSerializer::SBlock> blocks;
    createReferenceFileInstance([&](Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)
    {
        QGears::MapFileSerializer s;
        s.importMapFile( stream, file );
        blocks = s.mBlocks;
    });

    if (blocks.empty())
    {
        // Load failed
        return;
    }
/*
    // TODO: Get PSX textures working
    QGears::TxzFileSerializer s;
    createReferenceTextureFileInstance(s);

    std::vector<std::vector<TxzFileSerializer::rgba>> data = s.GetWorldMapTexture(19);
    test(data);
*/

    LoadTextures();

    int c = 0;

    const auto kSpace = From16BitFixedPoint(8182);

    size_t numBlocks = blocks.size();

    int mapX = 0;
    int mapY = 0;



    for ( unsigned int k=0; k<numBlocks; k++ )
    {
        // 7x9 size
        QGears::MapFileSerializer::SBlock& block = blocks[k];

        int blockX = 0;
        int blockY = 0;

        for ( size_t i=0; i<block.mMeshes.size(); i++ )
        {
            QGears::MapFileSerializer::SBlockPart& part = block.mMeshes[i];

            for ( size_t j=0; j<part.mTris.size(); j++)
            {
                QGears::MapFileSerializer::BlockTriangle& tri = part.mTris.at(j);

                ManualObject* manual = nullptr;
                auto it = gObjToTextureId.find(tri.TextureInfo);
                if (it==gObjToTextureId.end())
                {
                    manual = mSceneMgr->createManualObject(("zzz_manual" + std::to_string(c++)).c_str());
                    manual->begin(gTextures[tri.TextureInfo].mName, RenderOperation::OT_TRIANGLE_LIST);
                    manual->setDebugDisplayEnabled(true);
                    manual->setDynamic(false);
                    gObjToTextureId[tri.TextureInfo] = manual;
                }
                else
                {
                    manual = it->second;
                }

                const float xPos = (blockX * kSpace) + (mapX * kSpace * 4);
                const float yPos = (blockY * kSpace) + (mapY * kSpace * 4);

                // v1
                QGears::MapFileSerializer::Vertex v1 = part.mVertices.at(tri.Vertex2Index);
                manual->position(From16BitFixedPoint(v1.X)+xPos, From16BitFixedPoint(v1.Y), From16BitFixedPoint(v1.Z)+yPos);
                manual->textureCoord(ToTextureCoordU(tri.uVertex2, tri.TextureInfo), ToTextureCoordV(tri.vVertex2, tri.TextureInfo));

                // v2
                v1 = part.mVertices.at(tri.Vertex1Index);
                manual->position(From16BitFixedPoint(v1.X)+xPos, From16BitFixedPoint(v1.Y), From16BitFixedPoint(v1.Z)+yPos);
                manual->textureCoord(ToTextureCoordU(tri.uVertex1, tri.TextureInfo), ToTextureCoordV(tri.vVertex1, tri.TextureInfo));

                // v3
                v1 = part.mVertices.at(tri.Vertex0Index);
                manual->position(From16BitFixedPoint(v1.X)+xPos, From16BitFixedPoint(v1.Y), From16BitFixedPoint(v1.Z)+yPos);
                manual->textureCoord(ToTextureCoordU(tri.uVertex0, tri.TextureInfo), ToTextureCoordV(tri.vVertex0, tri.TextureInfo));


            }

            blockX++;
            if (blockX >= 4 )
            {
                blockX = 0;
                blockY++;
            }
        }
        mapX++;
        if (mapX >= 9 )
        {
            mapX = 0;
            mapY++;
        }

    }

    for (auto& it : gObjToTextureId)
    {
        it.second->end();
        SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
        node->attachObject(it.second);
        node->setPosition( 0, 0, 0);
    }
}

void WorldMapModule::Init()
{
    createTestMap(Root::getSingleton().getSceneManager("Scene"));
    CameraManager::getSingleton().EnableWireFrame(true);
}

END_QGEARS
