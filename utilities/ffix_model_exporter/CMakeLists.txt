include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# define header and source files
set(HEADER_FILES
./src/MeshExtractor.h
./src/ModelFile.h
./src/MeshExtractor.cpp
./src/AnimationExtractor.h
)
set(SOURCE_FILES
./src/ModelFile.cpp
./src/AnimationExtractor.cpp
./src/MeshExtractor.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ffix_model_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(ffix_model_exporter PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(ffix_model_exporter    ${LIBRARIES})

install(TARGETS ffix_model_exporter
    DESTINATION tools/ff7
)
