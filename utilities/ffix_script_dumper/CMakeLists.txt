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

add_executable(ff9_script_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff9_script_dumper PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(ff9_script_dumper PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff9_script_dumper PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff9_script_dumper    ${LIBRARIES})

install(TARGETS ff9_script_dumper
    DESTINATION tools/ff9
)
