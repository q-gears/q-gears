# define header and source files for the library
set(HEADER_FILES
  include/map/FF7WalkmeshFileSerializer.h
  include/FF7Common.h
  #include/FF7Character.h
)
set(SOURCE_FILES
  src/map/FF7WalkmeshFileSerializer.cpp
  #src/FF7Character.cpp
)


include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGears_SOURCE_DIR}/QGearsMain/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(FinalFantasy7 STATIC
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

set(LIBRARIES
    ${OGRE_LIBRARIES}
    ${OIS_LIBRARIES}
    QGearsMain
)

target_link_libraries(FinalFantasy7 ${LIBRARIES})
