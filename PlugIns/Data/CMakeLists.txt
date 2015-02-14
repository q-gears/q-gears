set(QGearsMain_SOURCE_DIR ../../QGearsMain)

# define header and source files for the library
set(HEADER_FILES
  ${QGearsMain_SOURCE_DIR}/include/QGearsPrerequisites.h
  ${QGearsMain_SOURCE_DIR}/include/common/QGearsManualObject.h
  ${QGearsMain_SOURCE_DIR}/include/common/QGearsStringUtil.h
  ${QGearsMain_SOURCE_DIR}/include/common/TypeDefine.h
  include/QGearsDataPlugin.h
)
set(SOURCE_FILES
  ${QGearsMain_SOURCE_DIR}/src/common/QGearsManualObject.cpp
  ${QGearsMain_SOURCE_DIR}/src/common/QGearsStringUtil.cpp
  ${QGearsMain_SOURCE_DIR}/src/common/TypeDefine.cpp
  src/QGearsDataPlugin.cpp
  src/QGearsDataPluginDll.cpp
)

include_directories(
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    ${OGRE_SAMPLES_INCLUDEPATH}
    ${QGearsMain_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies
)

#defines
#add_definitions(-DBOOST_ALL_DYN_LINK)

add_library(DataPlugin MODULE
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET DataPlugin PROPERTY FOLDER "q-gears")

set_target_properties(DataPlugin PROPERTIES
  PREFIX ${PLUGIN_PREFIX}
  OUTPUT_NAME Data
)

set(LIBRARIES
  ${OGRE_LIBRARIES} 
  FinalFantasy7
  q-gears-data
)

target_link_libraries(DataPlugin ${LIBRARIES})

if(NOT QGEARS_STATIC)
  set_target_properties(DataPlugin PROPERTIES
    COMPILE_DEFINITIONS QGEARS_DATAPLUGIN_EXPORTS
  )
    if(WIN32 OR APPLE)
      install(TARGETS DataPlugin LIBRARY DESTINATION .)
    else()
      install(TARGETS DataPlugin LIBRARY DESTINATION ./lib/q-gears/plugins/ )
    endif()
endif()
