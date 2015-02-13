include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
    src/MimFile.h
    src/DatFile.h
)
set(SOURCE_FILES
    src/MimFile.cpp
    src/DatFile.cpp
    src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_field_dat_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff7_field_dat_dumper PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(ff7_field_dat_dumper "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(ff7_field_dat_dumper PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_field_dat_dumper PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff7_field_dat_dumper    ${LIBRARIES})

install(TARGETS ff7_field_dat_dumper
    DESTINATION tools/ff7
)
