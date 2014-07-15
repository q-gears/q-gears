include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGears_SOURCE_DIR}/QGearsMain/include
    ${QGears_SOURCE_DIR}/SupportedGames/FinalFantasy7/include
    ${CMAKE_CURRENT_SOURCE_DIR}/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# define header and source files for the library
set(HEADER_FILES
./common/File.h
./common/LzsFile.h
./common/FontFile.h
./common/include/QGearsUtility.h
./common/Logger.h
./common/Surface.h
./common/TimToVram.h
./common/BinGZipFile.h
./common/OgreBase.h
./common/OgreGenUtilites.h
./common/Vram.h
./common/DrawSkeleton.h
./common/FileSystem.h

)

set(SOURCE_FILES
./common/Logger.cpp
./common/BinGZipFile.cpp
./common/DrawSkeleton.cpp
./common/Surface.cpp
./common/File.cpp
./common/OgreGenUtilites.cpp
./common/FontFile.cpp
./common/LzsFile.cpp
./common/TimToVram.cpp
./common/Vram.cpp
./common/OgreBase.cpp
./common/src/QGearsUtility.cpp
./common/FileSystem.cpp
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
add_subdirectory(ffvii_field_dat_dumper)
