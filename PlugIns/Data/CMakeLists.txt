set(QGearsMain_SOURCE_DIR ../../QGearsMain)

# define header and source files for the library
set(HEADER_FILES
  ${QGearsMain_SOURCE_DIR}/include/QGearsPrerequisites.h
  ${QGearsMain_SOURCE_DIR}/include/common/QGearsManualObject.h
  ${QGearsMain_SOURCE_DIR}/include/common/QGearsStringUtil.h
  ${QGearsMain_SOURCE_DIR}/include/common/TypeDefine.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsAFile.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsAFileSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsBackgroundFile.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsBackgroundFileManager.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsBackgroundFileSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsHRCFile.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsHRCFileManager.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsHRCFileSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsHRCMeshLoader.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsHRCSkeletonLoader.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsLZSDataStream.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsPFile.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsPFileManager.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsPFileSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsPaletteFile.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsPaletteFileManager.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsPaletteFileSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsRSDFile.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsRSDFileManager.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsRSDFileSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsTexCodec.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsTexFile.h
  include/QGearsDataPlugin.h
)
set(SOURCE_FILES
  ${QGearsMain_SOURCE_DIR}/src/common/QGearsManualObject.cpp
  ${QGearsMain_SOURCE_DIR}/src/common/QGearsStringUtil.cpp
  ${QGearsMain_SOURCE_DIR}/src/common/TypeDefine.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsAFile.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsAFileSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsBackgroundFile.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsBackgroundFileManager.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsBackgroundFileSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsHRCFile.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsHRCFileManager.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsHRCFileSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsHRCMeshLoader.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsHRCSkeletonLoader.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsLZSDataStream.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsPFile.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsPFileManager.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsPFileSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsPaletteFile.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsPaletteFileManager.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsPaletteFileSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsRSDFile.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsRSDFileManager.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsRSDFileSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsTexCodec.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsTexFile.cpp
  src/QGearsDataPlugin.cpp
  src/QGearsDataPluginDll.cpp
)

include_directories(
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    ${OGRE_SAMPLES_INCLUDEPATH}
    ${QGearsMain_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#defines
#add_definitions(-DBOOST_ALL_DYN_LINK)

add_library(DataPlugin MODULE
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

set_target_properties(DataPlugin PROPERTIES
  PREFIX ${PLUGIN_PREFIX}
  OUTPUT_NAME Data
)

set(LIBRARIES
  ${OGRE_LIBRARIES}
)

target_link_libraries(DataPlugin ${LIBRARIES})

if(NOT QGEARS_STATIC)
  set_target_properties(DataPlugin PROPERTIES
    COMPILE_DEFINITIONS QGEARS_DATAPLUGIN_EXPORTS
  )
  install(TARGETS DataPlugin
    LIBRARY DESTINATION ./
  )
endif()
