include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES

)
set(SOURCE_FILES
flevel.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(flevel
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET flevel PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(flevel PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(flevel PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(flevel    ${LIBRARIES})

install(TARGETS flevel
    DESTINATION tools/ff7
)
