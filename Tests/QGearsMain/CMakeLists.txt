set(QGearsMain_SOURCE_DIR ${QGears_SOURCE_DIR}/QGearsMain)

file(COPY misc DESTINATION .)

include_directories(
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    "${QGearsMain_SOURCE_DIR}/include"
    "${QGearsMain_SOURCE_DIR}/src"
)

set(HEADER_FILES
    ${QGearsMain_SOURCE_DIR}/include/common/QGearsResource.h
    ${QGearsMain_SOURCE_DIR}/include/data/QGearsSerializer.h
)
set(SOURCE_FILES
    ${QGearsMain_SOURCE_DIR}/src/common/QGearsResource.cpp
    ${QGearsMain_SOURCE_DIR}/src/data/QGearsSerializer.cpp
)

add_executable(TestQGearsAFileSerializer
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${QGearsMain_SOURCE_DIR}/include/data/QGearsAFile.h
    ${QGearsMain_SOURCE_DIR}/include/data/QGearsAFileSerializer.h
    ${QGearsMain_SOURCE_DIR}/src/data/QGearsAFile.cpp
    ${QGearsMain_SOURCE_DIR}/src/data/QGearsAFileSerializer.cpp
    src/test_QGearsAFileSerializer.cpp
)

target_link_libraries(TestQGearsAFileSerializer ${QGears_TEST_LIBRARIES})
add_test(TestQGearsAFileSerializer TestQGearsAFileSerializer)

add_executable(TestQGearsWalkmeshFileSerializer
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${QGearsMain_SOURCE_DIR}/include/data/QGearsWalkmeshFile.h
    ${QGearsMain_SOURCE_DIR}/include/data/QGearsWalkmeshFileSerializer.h
    ${QGearsMain_SOURCE_DIR}/src/data/QGearsWalkmeshFile.cpp
    ${QGearsMain_SOURCE_DIR}/src/data/QGearsWalkmeshFileSerializer.cpp
    src/test_QGearsWalkmeshFileSerializer.cpp
)

target_link_libraries(TestQGearsWalkmeshFileSerializer ${QGears_TEST_LIBRARIES})
add_test(TestQGearsWalkmeshFileSerializer TestQGearsWalkmeshFileSerializer)
