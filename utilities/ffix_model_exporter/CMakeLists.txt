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

add_executable(ff9_model_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff9_model_exporter PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(ff9_model_exporter "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(ff9_model_exporter PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff9_model_exporter PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff9_model_exporter    ${LIBRARIES})

install(TARGETS ff9_model_exporter
    DESTINATION tools/ff9
)
