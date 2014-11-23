include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/backends
)

# define header and source files
set(HEADER_FILES
./src/engine/SoundManager.h
./src/engine/SoundBackend.h
./src/engine/backends/SoundBackendSDL.h
./src/SoundParser.h
./src/Main.h
)

set(SOURCE_FILES
./src/engine/backends/SoundBackendSDL.cpp
./src/engine/SoundManager.cpp
./src/SoundParser.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff9_sound_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ff9_sound_dumper PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ff9_sound_dumper    ${LIBRARIES})

install(TARGETS ff9_sound_dumper
    DESTINATION tools/ff9
)
