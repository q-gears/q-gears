# define header and source files for the library
set(HEADER_FILES
  #include/common/QGearsManualObject.h
  include/common/QGearsResource.h
  include/common/QGearsStringUtil.h
  include/common/TypeDefine.h
  include/data/QGearsAFile.h
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
  include/data/QGearsXMLSerializer.h
  include/map/QGearsBackground2DFile.h
  include/map/QGearsBackground2DFileManager.h
  include/map/QGearsBackground2DFileXMLSerializer.h
  include/map/QGearsTile.h
  include/map/QGearsWalkmeshFile.h
  include/map/QGearsWalkmeshFileManager.h
  include/map/QGearsWalkmeshFileXMLSerializer.h
  include/QGearsGameState.h
  include/QGearsPrerequisites.h
  src/core/particles/emitters/ParticlePointEmitter.h
  src/core/particles/emitters/ParticlePointEmitterFactory.h
  src/core/particles/renderer/ParticleEntityAdditionalData.h
  src/core/particles/renderer/ParticleEntityRenderer.h
  src/core/particles/renderer/ParticleEntityRendererDictionary.h
  src/core/particles/renderer/ParticleEntityRendererFactory.h
  src/core/particles/Particle.h
  src/core/particles/ParticleAdditionalData.h
  src/core/particles/ParticleEmitter.h
  src/core/particles/ParticleEmitterDictionary.h
  src/core/particles/ParticleEmitterFactory.h
  src/core/particles/ParticleEmitterTranslator.h
  src/core/particles/ParticlePool.h
  src/core/particles/ParticlePoolMap.h
  src/core/particles/ParticleRenderer.h
  src/core/particles/ParticleRendererFactory.h
  src/core/particles/ParticleRendererTranslator.h
  src/core/particles/ParticleSystem.h
  src/core/particles/ParticleSystemFactory.h
  src/core/particles/ParticleSystemManager.h
  src/core/particles/ParticleSystemTranslator.h
  src/core/particles/ParticleSystemTranslatorManager.h
  src/core/particles/ParticleTechnique.h
  src/core/particles/ParticleTechniqueTranslator.h
  src/core/particles/ParticleVisual.h
  src/core/Assert.h
  #src/core/AudioManager.h
  src/core/Background2D.h
  src/core/Background2DAnimation.h
  src/core/CameraManager.h
  src/core/CameraManagerCommands.h
  src/core/ConfigCmd.h
  src/core/ConfigCmdManager.h
  src/core/ConfigCmdManagerCommands.h
  src/core/ConfigFile.h
  src/core/ConfigVar.h
  src/core/ConfigVarManager.h
  src/core/Console.h
  src/core/DebugDraw.h
  src/core/Entity.h
  src/core/EntityCollision.h
  src/core/EntityDirection.h
  src/core/EntityManager.h
  src/core/EntityModel.h
  src/core/EntityPoint.h
  src/core/EntityTrigger.h
  src/core/Event.h
  src/core/GameFrameListner.h
  src/core/InputManager.h
  src/core/InputManagerCommands.h
  src/core/Logger.h
  src/core/Module.h
  src/core/ScriptManager.h
  src/core/ScriptManagerBinds.h
  src/core/ScriptManagerCommands.h
  src/core/Timer.h
  src/core/UiAnimation.h
  src/core/UiFont.h
  src/core/UiManager.h
  src/core/UiSprite.h
  src/core/UiTextArea.h
  src/core/UiWidget.h
  src/core/Utilites.h
  src/core/Walkmesh.h
  src/core/XmlBackground2DFile.h
  src/core/XmlFile.h
  src/core/XmlFontFile.h
  src/core/XmlFontsFile.h
  src/core/XmlMapFile.h
  #src/core/XmlMapsFile.h
  src/core/XmlMusicsFile.h
  src/core/XmlPrototypesFile.h
  src/core/XmlScreenFile.h
  src/core/XmlScreensFile.h
  src/core/XmlScriptsFile.h
  src/core/XmlTextFile.h
  src/core/XmlTextsFile.h
  src/core/XmlWalkmeshFile.h
  #src/viewer/ViewerModule.h
)
set(SOURCE_FILES
  src/common/QGearsManualObject.cpp
  src/common/QGearsResource.cpp
  src/common/QGearsStringUtil.cpp
  src/common/TypeDefine.cpp
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
  #src/core/AudioManager.cpp
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
  #src/core/XmlMusicsFile.cpp
  src/core/XmlPrototypesFile.cpp
  src/core/XmlScreenFile.cpp
  src/core/XmlScreensFile.cpp
  src/core/XmlScriptsFile.cpp
  src/core/XmlTextFile.cpp
  src/core/XmlTextsFile.cpp
  src/core/XmlWalkmeshFile.cpp
  src/data/QGearsAFile.cpp
  src/data/QGearsAFileSerializer.cpp
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
  src/data/QGearsXMLSerializer.cpp
  src/map/QGearsBackground2DFile.cpp
  src/map/QGearsBackground2DFileManager.cpp
  src/map/QGearsBackground2DFileXMLSerializer.cpp
  src/map/QGearsWalkmeshFile.cpp
  src/map/QGearsWalkmeshFileManager.cpp
  src/map/QGearsWalkmeshFileXMLSerializer.cpp
  #src/viewer/ViewerModule.cpp
  src/QGearsGameState.cpp
)

aux_source_directory( src/core/library/lua Lua_FILES)
aux_source_directory( src/core/library/luabind LuaBind_FILES)
aux_source_directory( src/core/library/tinyxml TinyXml_FILES)

add_library(Lua STATIC ${Lua_FILES})
add_library(LuaBind STATIC ${LuaBind_FILES})
add_library(TinyXml STATIC ${TinyXml_FILES})
target_link_libraries(LuaBind Lua)

include_directories(
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    ${OGRE_SAMPLES_INCLUDEPATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/library
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/library/tinyxml
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#compiler options
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

#defines
add_definitions(-DTIXML_USE_STL)

if(WIN32)
  #check usage and remove if uneccessary
  add_definitions(-DWIN32 -D__WIN32__ -D_WINDOWS)
endif()

add_library(QGearsMain SHARED
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

add_executable(q-gears
  src/Main.cpp
)

if(WIN32)
  set_target_properties(q-gears PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    ${OGRE_LIBRARIES}
    ${OIS_LIBRARIES}
    LuaBind
    TinyXml
)

target_link_libraries(QGearsMain ${LIBRARIES})
target_link_libraries(q-gears    QGearsMain ${LIBRARIES})

install(TARGETS QGearsMain q-gears
    DESTINATION ./
)
