# define header and source files for the library
set(HEADER_FILES
  include/modules/worldmap/WorldMapModule.h

  include/common/QGearsManualObject.h
  include/common/QGearsResource.h
  include/common/QGearsStringUtil.h
  include/common/TypeDefine.h
  include/common/LzsFile.h
  include/common/File.h
  include/common/FileSystem.h
  include/common/make_unique.h
  include/map/QGearsBackground2DFile.h
  include/map/QGearsBackground2DFileManager.h
  include/map/QGearsBackground2DFileXMLSerializer.h
  include/map/QGearsTile.h
  include/map/QGearsMapFile.h
  include/map/QGearsMapFileManager.h
  include/map/QGearsMapFileXMLSerializer.h
  include/map/QGearsWalkmeshFile.h
  include/map/QGearsWalkmeshFileManager.h
  include/map/QGearsWalkmeshFileXMLSerializer.h
  include/LuaIncludes.h
  include/QGearsGameState.h
  include/QGearsPrerequisites.h
  include/core/particles/emitters/ParticlePointEmitter.h
  include/core/particles/emitters/ParticlePointEmitterFactory.h
  include/core/particles/renderer/ParticleEntityAdditionalData.h
  include/core/particles/renderer/ParticleEntityRenderer.h
  include/core/particles/renderer/ParticleEntityRendererDictionary.h
  include/core/particles/renderer/ParticleEntityRendererFactory.h
  include/core/particles/Particle.h
  include/core/particles/ParticleAdditionalData.h
  include/core/particles/ParticleEmitter.h
  include/core/particles/ParticleEmitterDictionary.h
  include/core/particles/ParticleEmitterFactory.h
  include/core/particles/ParticleEmitterTranslator.h
  include/core/particles/ParticlePool.h
  include/core/particles/ParticlePoolMap.h
  include/core/particles/ParticleRenderer.h
  include/core/particles/ParticleRendererFactory.h
  include/core/particles/ParticleRendererTranslator.h
  include/core/particles/ParticleSystem.h
  include/core/particles/ParticleSystemFactory.h
  include/core/particles/ParticleSystemManager.h
  include/core/particles/ParticleSystemTranslator.h
  include/core/particles/ParticleSystemTranslatorManager.h
  include/core/particles/ParticleTechnique.h
  include/core/particles/ParticleTechniqueTranslator.h
  include/core/particles/ParticleVisual.h
  include/core/Assert.h
  include/core/Background2D.h
  include/core/Background2DAnimation.h
  include/core/CameraManager.h
  include/core/CameraManagerCommands.h
  include/core/ConfigCmd.h
  include/core/ConfigCmdManager.h
  include/core/ConfigCmdManagerCommands.h
  include/core/ConfigFile.h
  include/core/ConfigVar.h
  include/core/ConfigVarManager.h
  include/core/Console.h
  include/core/DebugDraw.h
  include/core/Entity.h
  include/core/EntityCollision.h
  include/core/EntityDirection.h
  include/core/EntityManager.h
  include/core/EntityModel.h
  include/core/EntityPoint.h
  include/core/EntityTrigger.h
  include/core/Event.h
  include/core/GameFrameListner.h
  include/core/InputManager.h
  include/core/InputManagerCommands.h
  include/core/Logger.h
  include/core/Module.h
  include/core/ScriptManager.h
  include/core/ScriptManagerBinds.h
  include/core/ScriptManagerCommands.h
  include/core/Timer.h
  include/core/UiAnimation.h
  include/core/UiFont.h
  include/core/UiManager.h
  include/core/UiSprite.h
  include/core/UiTextArea.h
  include/core/UiWidget.h
  include/core/Utilites.h
  include/core/Walkmesh.h
  include/core/XmlBackground2DFile.h
  include/core/XmlFile.h
  include/core/XmlFontFile.h
  include/core/XmlFontsFile.h
  include/core/XmlMapFile.h
  #include/core/XmlMapsFile.h
  include/core/XmlPrototypesFile.h
  include/core/XmlScreenFile.h
  include/core/XmlScreensFile.h
  include/core/XmlScriptsFile.h
  include/core/XmlTextFile.h
  include/core/XmlTextsFile.h
  include/core/DialogsManager.h
  include/core/ScriptManagerBinds.h
  include/core/TextManager.h
  include/core/TextManagerCommands.h
  #include/viewer/ViewerModule.h
  include/data/QGearsXMLSerializer.h
)

set(HEADER_FILES_DATA
  include/common/QGearsApplication.h
include/data/worldmap/MapFile.h
  include/data/worldmap/MapFileManager.h
  include/data/worldmap/MapFileSerializer.h
  include/data/worldmap/TxzFile.h
  include/data/worldmap/TxzFileManager.h
  include/data/worldmap/TxzFileSerializer.h
  include/data/QGearsAFile.h
  include/data/QGearsAFileManager.h
  include/data/QGearsAFileSerializer.h
  include/data/QGearsBackgroundFile.h
  include/data/QGearsBackgroundFileManager.h
  include/data/QGearsBackgroundFileSerializer.h
  include/data/QGearsBackgroundTextureLoader.h
  include/data/QGearsCameraMatrixFile.h
  include/data/QGearsCameraMatrixFileManager.h
  include/data/QGearsCameraMatrixFileSerializer.h
  include/data/QGearsFLevelBackground2DLoader.h
  include/data/QGearsFLevelFile.h
  include/data/QGearsFLevelFileManager.h
  include/data/QGearsFLevelFileSerializer.h
  include/data/QGearsFLevelTextureLoader.h
  include/data/QGearsHRCFile.h
  include/data/QGearsHRCFileManager.h
  include/data/QGearsHRCFileSerializer.h
  include/data/QGearsHRCMeshLoader.h
  include/data/QGearsHRCSkeletonLoader.h
  include/data/QGearsLGPArchive.h
  include/data/QGearsLGPArchiveFactory.h
  include/data/QGearsLGPArchiveSerializer.h
  include/data/QGearsLZSDataStream.h
  include/data/QGearsLZSFLevelFile.h
  include/data/QGearsLZSFLevelFileManager.h
  include/data/QGearsPaletteFile.h
  include/data/QGearsPaletteFileManager.h
  include/data/QGearsPaletteFileSerializer.h
  include/data/QGearsPFile.h
  include/data/QGearsPFileManager.h
  include/data/QGearsPFileSerializer.h
  include/data/QGearsRSDFile.h
  include/data/QGearsRSDFileManager.h
  include/data/QGearsRSDFileSerializer.h
  include/data/QGearsSerializer.h
  include/data/QGearsTexCodec.h
  include/data/QGearsTexFile.h
  include/data/QGearsTriggersFile.h
  include/data/QGearsMapListFile.h
)

set(SOURCE_FILES_DATA
  src/common/QGearsApplication.cpp
  src/data/QGearsAFile.cpp
  src/data/QGearsAFileManager.cpp
  src/data/QGearsAFileSerializer.cpp
  src/data/worldmap/MapFile.cpp
  src/data/worldmap/MapFileManager.cpp
  src/data/worldmap/MapFileSerializer.cpp
  src/data/worldmap/TxzFile.cpp
  src/data/worldmap/TxzFileManager.cpp
  src/data/worldmap/TxzFileSerializer.cpp
  src/data/QGearsBackgroundFile.cpp
  src/data/QGearsBackgroundFileManager.cpp
  src/data/QGearsBackgroundFileSerializer.cpp
  src/data/QGearsBackgroundTextureLoader.cpp
  src/data/QGearsCameraMatrixFile.cpp
  src/data/QGearsCameraMatrixFileManager.cpp
  src/data/QGearsCameraMatrixFileSerializer.cpp
  src/data/QGearsFLevelBackground2DLoader.cpp
  src/data/QGearsFLevelFile.cpp
  src/data/QGearsFLevelFileManager.cpp
  src/data/QGearsFLevelFileSerializer.cpp
  src/data/QGearsFLevelTextureLoader.cpp
  src/data/QGearsHRCFile.cpp
  src/data/QGearsHRCFileManager.cpp
  src/data/QGearsHRCFileSerializer.cpp
  src/data/QGearsHRCMeshLoader.cpp
  src/data/QGearsHRCSkeletonLoader.cpp
  src/data/QGearsLGPArchive.cpp
  src/data/QGearsLGPArchiveFactory.cpp
  src/data/QGearsLGPArchiveSerializer.cpp
  src/data/QGearsLZSDataStream.cpp
  src/data/QGearsLZSFLevelFile.cpp
  src/data/QGearsLZSFLevelFileManager.cpp
  src/data/QGearsPaletteFile.cpp
  src/data/QGearsPaletteFileManager.cpp
  src/data/QGearsPaletteFileSerializer.cpp
  src/data/QGearsPFile.cpp
  src/data/QGearsPFileManager.cpp
  src/data/QGearsPFileSerializer.cpp
  src/data/QGearsRSDFile.cpp
  src/data/QGearsRSDFileManager.cpp
  src/data/QGearsRSDFileSerializer.cpp
  src/data/QGearsSerializer.cpp
  src/data/QGearsTexCodec.cpp
  src/data/QGearsTexFile.cpp
  src/data/QGearsTriggersFile.cpp
  src/data/QGearsMapListFile.cpp
)

set(SOURCE_FILES
  src/modules/worldmap/WorldMapModule.cpp

  src/common/QGearsManualObject.cpp
  src/common/QGearsResource.cpp
  src/common/QGearsStringUtil.cpp
  src/common/TypeDefine.cpp
  src/common/LzsFile.cpp
  src/common/File.cpp
  src/common/FileSystem.cpp
  src/core/particles/emitters/ParticlePointEmitter.cpp
  src/core/particles/Particle.cpp
  src/core/particles/ParticleEmitter.cpp
  src/core/particles/ParticleEmitterDictionary.cpp
  src/core/particles/ParticleEmitterTranslator.cpp
  src/core/particles/ParticleRenderer.cpp
  src/core/particles/ParticleRendererTranslator.cpp
  src/core/particles/ParticleSystem.cpp
  src/core/particles/ParticleSystemFactory.cpp
  src/core/particles/ParticleSystemManager.cpp
  src/core/particles/ParticleSystemTranslator.cpp
  src/core/particles/ParticleSystemTranslatorManager.cpp
  src/core/particles/ParticleTechnique.cpp
  src/core/particles/ParticleTechniqueTranslator.cpp
  src/core/particles/ParticleVisual.cpp
  src/core/particles/renderer/ParticleEntityRenderer.cpp
  src/core/particles/renderer/ParticleEntityRendererDictionary.cpp
  src/core/Background2D.cpp
  src/core/Background2DAnimation.cpp
  src/core/CameraManager.cpp
  src/core/ConfigCmd.cpp
  src/core/ConfigCmdManager.cpp
  src/core/ConfigFile.cpp
  src/core/ConfigVar.cpp
  src/core/ConfigVarManager.cpp
  src/core/Console.cpp
  src/core/DebugDraw.cpp
  src/core/Entity.cpp
  src/core/EntityCollision.cpp
  src/core/EntityDirection.cpp
  src/core/EntityManager.cpp
  src/core/EntityModel.cpp
  src/core/EntityPoint.cpp
  src/core/EntityTrigger.cpp
  src/core/GameFrameListner.cpp
  src/core/InputManager.cpp
  src/core/ScriptManager.cpp
  src/core/Timer.cpp
  src/core/UiAnimation.cpp
  src/core/UiFont.cpp
  src/core/UiManager.cpp
  src/core/UiSprite.cpp
  src/core/UiTextArea.cpp
  src/core/UiWidget.cpp
  src/core/Utilites.cpp
  src/core/Walkmesh.cpp
  src/core/XmlBackground2DFile.cpp
  src/core/XmlFile.cpp
  src/core/XmlFontFile.cpp
  src/core/XmlFontsFile.cpp
  src/core/XmlMapFile.cpp
  src/core/XmlMapsFile.cpp
  src/core/XmlPrototypesFile.cpp
  src/core/XmlScreenFile.cpp
  src/core/XmlScreensFile.cpp
  src/core/XmlScriptsFile.cpp
  src/core/XmlTextFile.cpp
  src/core/XmlTextsFile.cpp
  src/core/DialogsManager.cpp
  src/core/TextManager.cpp
  src/map/QGearsBackground2DFile.cpp
  src/map/QGearsBackground2DFileManager.cpp
  src/map/QGearsBackground2DFileXMLSerializer.cpp
  src/map/QGearsMapFile.cpp
  src/map/QGearsMapFileManager.cpp
  src/map/QGearsMapFileXMLSerializer.cpp
  src/map/QGearsWalkmeshFile.cpp
  src/map/QGearsWalkmeshFileManager.cpp
  src/map/QGearsWalkmeshFileXMLSerializer.cpp
  #src/viewer/ViewerModule.cpp
  src/QGearsGameState.cpp
  src/data/QGearsXMLSerializer.cpp
)
if(QGears_SOUND)
    set(HEADER_FILES
        ${HEADER_FILES}
        include/core/AudioManager.h
        include/core/XmlMusicsFile.h
    )
    set(SOURCE_FILES
        ${SOURCE_FILES}
        src/core/AudioManager.cpp
        src/core/XmlMusicsFile.cpp
    )
endif()

include_directories(
    ${QGears_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include

    # TODO: remove dependency on ff7 related code
    ${QGears_SOURCE_DIR}/SupportedGames/FinalFantasy7/include
    ${CMAKE_CURRENT_SOURCE_DIR}/SupportedGames/FinalFantasy7/include

)

#compiler options
if (MSVC)
else()
if(WIN32)
    add_definitions(
      -W
      -mthreads
      -fmessage-length=0
      -fexceptions
      -fident
    )

    #linker options
    add_definitions(
      -Wl,--enable-runtime-pseudo-reloc
      -Wl,--enable-auto-image-base
      -Wl,--add-stdcall-alias
    )
endif()
endif()

#defines
if(WIN32)
  #check usage and remove if uneccessary
  add_definitions(-DWIN32 -D__WIN32__ -D_WINDOWS)
endif()

add_library(QGearsMain STATIC
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

# Coverage uses more memory, combined with PCH can cause OOM/ICE
#if ($ENV{COVERAGE}!=1)
cotire(QGearsMain)
#endif()
SET_PROPERTY(TARGET QGearsMain PROPERTY FOLDER "q-gears")

add_library(q-gears-data STATIC
 ${HEADER_FILES_DATA}
 ${SOURCE_FILES_DATA}
 )
add_dependencies(q-gears-data configure_qgears_version)
# Coverage uses more memory, combined with PCH can cause OOM/ICE
if ($ENV{COVERAGE}!=1)
cotire(q-gears-data)
endif()
SET_PROPERTY(TARGET q-gears-data PROPERTY FOLDER "q-gears")


add_executable(q-gears
  src/Main.cpp
)
SET_PROPERTY(TARGET q-gears PROPERTY FOLDER "q-gears")


if (APPLE)
target_link_libraries(q-gears "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if( WIN32 AND NOT (CMAKE_BUILD_TYPE MATCHES "Debug") )
    set_target_properties( q-gears PROPERTIES WIN32_EXECUTABLE ON )
	if (MSVC)
        set_target_properties(q-gears PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif()
endif()

target_link_libraries(QGearsMain 
    ${QGears_LIBRARIES}
    LuaBind
	liblua
    TinyXml
    FinalFantasy7
)

target_link_libraries(q-gears 
	QGearsMain
	${Boost_LIBRARIES}
    q-gears-data
)

target_link_libraries(q-gears-data
    QGearsMain
)

if(WIN32 OR APPLE)
  install(TARGETS q-gears DESTINATION .)
else()
  install(TARGETS q-gears RUNTIME DESTINATION ./games)
endif()
