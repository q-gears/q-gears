INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

# This is where the ui generated header files end up
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
    src/mainwindow.h
	src/ff7DataInstaller.h
)
set(SOURCE_FILES
    src/Main.cpp
    src/mainwindow.cpp
	src/ff7DataInstaller.cpp
)

set(INSTALLER_FORMS
   src/mainwindow.ui
)

QT4_WRAP_UI(INSTALLER_FORM_HEADERS ${INSTALLER_FORMS})
QT4_WRAP_CPP(INSTALLER_HEADERS_MOC ${HEADER_FILES})

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(installer
  ${HEADER_FILES}
  ${SOURCE_FILES}
  ${INSTALLER_FORM_HEADERS}
  ${INSTALLER_HEADERS_MOC}
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

target_link_libraries(installer    ${LIBRARIES} ${QT_LIBRARIES})

install(TARGETS installer
    DESTINATION .
)
