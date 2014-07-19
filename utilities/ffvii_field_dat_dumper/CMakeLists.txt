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

add_executable(ffvii_field_dat_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ffvii_field_dat_dumper PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ffvii_field_dat_dumper    ${LIBRARIES})

install(TARGETS ffvii_field_dat_dumper
    DESTINATION tools/ff7
)
