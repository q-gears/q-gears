include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES

)
set(SOURCE_FILES
extract.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(xeno_cd_extract
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET xeno_cd_extract PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(xeno_cd_extract PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(xeno_cd_extract PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(xeno_cd_extract    ${LIBRARIES})

install(TARGETS xeno_cd_extract
    DESTINATION tools/xeno
)
