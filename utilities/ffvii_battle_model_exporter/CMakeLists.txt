include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# define header and source files
set(HEADER_FILES
./src/MeshExtractor.h
./src/StageFile.h
./src/RamEffectFile.h
./src/EnemyFile.h
./src/MeshExtractor.cpp
./src/AnimationScriptDumper.h
./src/AnimationExtractor.h
)

set(SOURCE_FILES
./src/EnemyFile.cpp
./src/RamEffectFile.cpp
./src/AnimationExtractor.cpp
./src/MeshExtractor.cpp
./src/AnimationScriptDumper.cpp
./src/StageFile.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_battle_model_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff7_battle_model_exporter PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(ff7_battle_model_exporter "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()


if(WIN32)
  set_target_properties(ff7_battle_model_exporter PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_battle_model_exporter PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff7_battle_model_exporter    ${LIBRARIES})

install(TARGETS ff7_battle_model_exporter
    DESTINATION tools/ff7
)
