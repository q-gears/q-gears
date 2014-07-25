include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# define header and source files
set(HEADER_FILES
./src/TextFile.h
./src/ScriptFile.h
)

set(SOURCE_FILES
./src/TextFile.cpp
./src/Main.cpp
./src/ScriptFile.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ffix_script_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ffix_script_dumper PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ffix_script_dumper    ${LIBRARIES})

install(TARGETS ffix_script_dumper
    DESTINATION tools/ff7
)
