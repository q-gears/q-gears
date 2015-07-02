find_package ( Qt4 REQUIRED )
include ( ${QT_USE_FILE} )
include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR}
	)
set ( q-gears-launcher_HDRS
	src/mainwindow.h
	src/ff7DataInstaller.h
    src/ff7FieldTextWriter.h
	)

set ( q-gears-launcher_SRCS
	src/main.cpp
	src/mainwindow.cpp
	src/ff7DataInstaller.cpp
    src/ff7FieldTextWriter.cpp
	)

set ( q-gears-launcher_UIS
	src/mainwindow.ui
	)
QT4_WRAP_UI(UIS ${q-gears-launcher_UIS})

set ( q-gears-launcher_MOCS
	src/mainwindow.h
	)
QT4_WRAP_CPP(MOCS ${q-gears-launcher_MOCS})

add_definitions(
    -DQGEARS_ADD_MANAGERS
)
add_executable ( q-gears-launcher ${q-gears-launcher_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )

SET_PROPERTY(TARGET q-gears-launcher PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(q-gears-launcher "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(q-gears-launcher PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(q-gears-launcher PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
    Sudm_Lib
)


target_link_libraries ( q-gears-launcher  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${LIBRARIES})

if(WIN32 OR APPLE)
  install(TARGETS q-gears-launcher DESTINATION . ) 
else()
  install(TARGETS q-gears-launcher RUNTIME DESTINATION bin ) 
endif()
