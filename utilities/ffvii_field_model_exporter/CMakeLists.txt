include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# define header and source files
set(HEADER_FILES
./src/Model.h
./src/MeshFile.h
./src/DatFile.h
./src/MeshFile.cpp
./src/AnimationFile.h
./src/BsxFile.h
./src/SkeletonFile.h
./src/BcxFile.h
./src/TdbFile.h
)

set(SOURCE_FILES
./src/AnimationFile.cpp
./src/DatFile.cpp
./src/MeshFile.cpp
./src/Model.cpp
./src/TdbFile.cpp
./src/BcxFile.cpp
./src/BsxFile.cpp
./src/Main.cpp
./src/SkeletonFile.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_field_model_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff7_field_model_exporter PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(ff7_field_model_exporter "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(ff7_field_model_exporter PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_field_model_exporter PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff7_field_model_exporter    ${LIBRARIES})

install(TARGETS ff7_field_model_exporter
    DESTINATION tools/ff7
)
