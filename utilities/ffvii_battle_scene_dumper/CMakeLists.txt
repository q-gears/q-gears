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

add_executable(ffvii_battle_scene_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ffvii_battle_scene_dumper PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ffvii_battle_scene_dumper    ${LIBRARIES})

install(TARGETS ffvii_battle_scene_dumper
    DESTINATION tools/ff7
)
