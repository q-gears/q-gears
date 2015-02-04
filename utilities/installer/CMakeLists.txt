include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES

)
set(SOURCE_FILES
    src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(installer
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET installer PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(installer "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(installer PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(installer PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
)

target_link_libraries(installer    ${LIBRARIES})

install(TARGETS installer
    DESTINATION .
)
