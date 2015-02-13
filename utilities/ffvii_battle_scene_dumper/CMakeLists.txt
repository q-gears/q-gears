include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# define header and source files
set(HEADER_FILES
./src/FFVIIString.h
./src/EnemyFile.h
./src/PlayerFile.h
)

set(SOURCE_FILES
./src/PlayerFile.cpp
./src/EnemyFile.cpp
./src/FFVIIString.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_battle_scene_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff7_battle_scene_dumper PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(ff7_battle_scene_dumper "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(ff7_battle_scene_dumper PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_battle_scene_dumper PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff7_battle_scene_dumper    ${LIBRARIES})

install(TARGETS ff7_battle_scene_dumper
    DESTINATION tools/ff7
)
