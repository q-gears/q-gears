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
SET_PROPERTY(TARGET ff7_font_exporter PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(ff7_font_exporter PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_font_exporter PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
    ${ZLIB_LIBRARIES}
)
target_link_libraries(ff7_font_exporter    ${LIBRARIES})

install(TARGETS ff7_font_exporter
    DESTINATION tools/ff7
)
