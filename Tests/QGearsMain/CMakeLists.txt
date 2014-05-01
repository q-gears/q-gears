file(COPY misc DESTINATION .)

include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGearsMain_SOURCE_DIR}/include
)

set(LIBRARIES
    ${QGears_TEST_LIBRARIES}
    QGearsMain
)

add_executable(TestQGearsAFileSerializer
    src/test_QGearsAFileSerializer.cpp
)
target_link_libraries(TestQGearsAFileSerializer ${LIBRARIES})
add_test(TestQGearsAFileSerializer TestQGearsAFileSerializer)


add_executable(TestQGearsMapFileXMLSerializer
    src/test_QGearsMapFileXMLSerializer.cpp
)
target_link_libraries(TestQGearsMapFileXMLSerializer ${LIBRARIES})
add_test(TestQGearsMapFileXMLSerializer TestQGearsMapFileXMLSerializer)


add_executable(TestQGearsWalkmeshFileXMLSerializer
    src/test_QGearsWalkmeshFileXMLSerializer.cpp
)
target_link_libraries(TestQGearsWalkmeshFileXMLSerializer ${LIBRARIES})
add_test(TestQGearsWalkmeshFileXMLSerializer TestQGearsWalkmeshFileXMLSerializer)


add_executable(TestQGearsLGPArchive
    src/test_QGearsLGPArchive.cpp
)
target_link_libraries(TestQGearsLGPArchive ${LIBRARIES})
add_test(TestQGearsLGPArchive TestQGearsLGPArchive)


