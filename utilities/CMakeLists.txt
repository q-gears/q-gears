include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGears_SOURCE_DIR}/QGearsMain/include
    ${QGears_SOURCE_DIR}/SupportedGames/FinalFantasy7/include
    ${CMAKE_CURRENT_SOURCE_DIR}/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ZLIB_INCLUDE_DIRS}
)

# define header and source files for the library
set(HEADER_FILES
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
)

set(SOURCE_FILES
./common/Logger.cpp
./common/BinGZipFile.cpp
./common/DrawSkeleton.cpp
./common/Surface.cpp
./common/OgreGenUtilites.cpp
./common/FontFile.cpp
./common/TimToVram.cpp
./common/Vram.cpp
./common/OgreBase.cpp
./common/src/QGearsUtility.cpp
)

add_library(Utility STATIC
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

target_link_libraries(Utility
    ${OGRE_LIBRARIES}
    ${OIS_LIBRARIES}
    ${ZLIB_LIBRARIES}
)
SET_PROPERTY(TARGET Utility PROPERTY FOLDER "utilities")

add_subdirectory(ffix_model_exporter)
add_subdirectory(ffix_script_dumper)
add_subdirectory(ffix_sound_dumper)
add_subdirectory(ffvii_battle_model_exporter)
add_subdirectory(ffvii_battle_scene_dumper)
add_subdirectory(ffvii_field_dat_dumper)
add_subdirectory(ffvii_field_model_exporter)
add_subdirectory(ffvii_field_model_exporter_pc)
add_subdirectory(ffvii_font_exporter)
add_subdirectory(ffvii_sound_dumper)
add_subdirectory(ffvii_sound_dumper_psf)
add_subdirectory(flevel)
add_subdirectory(lzs)
add_subdirectory(q-gears-launcher)
add_subdirectory(xeno_cd_extract)
add_subdirectory(xeno_model_exporter)
add_subdirectory(xeno_script_dumper)
add_subdirectory(xeno_sound_dumper)
add_subdirectory(xeno_walkmesh_exporter)
