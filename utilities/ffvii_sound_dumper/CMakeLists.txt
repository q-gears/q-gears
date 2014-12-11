include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
./src/AkaoParser.h
./src/engine/SoundManager.h
./src/engine/SoundBackend.h
./src/engine/backends/SoundBackendSDL.h
./src/Main.h
)

set(SOURCE_FILES
./src/AkaoParser.cpp
./src/engine/backends/SoundBackendSDL.cpp
./src/engine/SoundManager.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_sound_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ff7_sound_dumper PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_sound_dumper PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ff7_sound_dumper    ${LIBRARIES})

install(TARGETS ff7_sound_dumper
    DESTINATION tools/ff7
)
