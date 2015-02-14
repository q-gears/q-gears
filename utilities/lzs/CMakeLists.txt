include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES

)
set(SOURCE_FILES
lzs.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(lzs
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET lzs PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(lzs PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(lzs PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(lzs    ${LIBRARIES})

install(TARGETS lzs
    DESTINATION tools/ff7
)
