include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
./src/ArchiveFile.h
./src/FieldFile.h
./src/ArchiveFile.cpp
./src/FieldModel.h
./src/ModelFile.h
./src/AnimatedModel.h
./src/AnimationExtractor.h
)

set(SOURCE_FILES
./src/ModelFile.cpp
./src/FieldFile.cpp
./src/ArchiveFile.cpp
./src/AnimationExtractor.cpp
./src/FieldModel.cpp
./src/AnimatedModel.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(xeno_model_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

if(WIN32)
  set_target_properties(xeno_model_exporter PROPERTIES WIN32_EXECUTABLE ON)
endif()

set(LIBRARIES
    Utility
)
target_link_libraries(xeno_model_exporter    ${LIBRARIES})

install(TARGETS xeno_model_exporter
    DESTINATION tools/xeno
)
