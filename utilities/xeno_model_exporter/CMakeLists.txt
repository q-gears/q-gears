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
SET_PROPERTY(TARGET xeno_model_exporter PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(xeno_model_exporter "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(xeno_model_exporter PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(xeno_model_exporter PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(xeno_model_exporter    ${LIBRARIES})

install(TARGETS xeno_model_exporter
    DESTINATION tools/xeno
)
