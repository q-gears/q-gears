include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
./src/FontFile.h
./src/Main.h
)
set(SOURCE_FILES
./src/FontFile.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_font_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ff7_font_exporter PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ff7_font_exporter    ${LIBRARIES})

install(TARGETS ff7_font_exporter
    DESTINATION tools/ff7
)
