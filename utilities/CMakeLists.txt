include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGears_SOURCE_DIR}/QGearsMain/include
    ${QGears_SOURCE_DIR}/SupportedGames/FinalFantasy7/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# define header and source files for the library
set(HEADER_FILES
  common/FileSystem.h
  common/Logger.h
  common/OgreBase.h
)
set(SOURCE_FILES
  common/FileSystem.cpp
  common/Logger.cpp
  common/OgreBase.cpp
)

add_library(Utility STATIC
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

set(LIBRARIES
    ${OGRE_LIBRARIES}
    ${OIS_LIBRARIES}
    QGearsMain
)

target_link_libraries(Utility ${LIBRARIES})


add_subdirectory(ffvii_field_model_exporter_pc)
