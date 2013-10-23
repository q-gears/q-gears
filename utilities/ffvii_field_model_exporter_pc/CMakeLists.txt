add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_field_model_exporter_pc
    src/main.cpp
)

if(WIN32)
  set_target_properties(ff7_field_model_exporter_pc PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ff7_field_model_exporter_pc    ${LIBRARIES})

install(TARGETS ff7_field_model_exporter_pc
    DESTINATION tools/ff7
)
