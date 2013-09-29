set(QGearsMain_SOURCE_DIR ../../QGearsMain)

# define header and source files for the library
set(HEADER_FILES
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsSerializer.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsTexCodec.h
  ${QGearsMain_SOURCE_DIR}/include/data/QGearsTexFile.h
)
set(SOURCE_FILES
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsSerializer.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsTexCodec.cpp
  ${QGearsMain_SOURCE_DIR}/src/data/QGearsTexFile.cpp
)

include_directories(
  ${Boost_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${QGearsMain_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#defines
add_definitions(-DBOOST_ALL_DYN_LINK)

add_library(DataPlugin SHARED
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

set_target_properties(DataPlugin PROPERTIES
  PREFIX ${PLUGIN_PREFIX}
  OUTPUT_NAME Data
)

set(LIBRARIES
  ${Boost_SYSTEM_LIBRARY}
  ${OGRE_LIBRARIES}
)

target_link_libraries(DataPlugin ${LIBRARIES})
