include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
    include/FF7FieldModelExporterPC.h
)
set(SOURCE_FILES
    src/FF7FieldModelExporterPC.cpp
    src/main.cpp
)

#add_definitions(
#    -DQGEARS_ADD_MANAGERS
#)

add_executable(ff7_field_model_exporter_pc
  ${SOURCE_FILES}
  ${HEADER_FILES}
)
SET_PROPERTY(TARGET ff7_field_model_exporter_pc PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(ff7_field_model_exporter_pc "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(ff7_field_model_exporter_pc PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_field_model_exporter_pc PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    q-gears-data

    QGearsMain


    ${OGRE_LIBRARIES}
    ${OIS_LIBRARIES}
    ${ZLIB_LIBRARIES}
Utility

)
target_link_libraries(ff7_field_model_exporter_pc    ${LIBRARIES})

install(TARGETS ff7_field_model_exporter_pc
    DESTINATION tools/ff7
)
