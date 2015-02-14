file(COPY misc DESTINATION .)

include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGearsMain_SOURCE_DIR}/include
)

set(LIBRARIES
    ${QGears_TEST_LIBRARIES}
    QGearsMain
	q-gears-data
)

add_executable(TestQGearsAFileSerializer
    src/test_QGearsAFileSerializer.cpp
)
SET_PROPERTY(TARGET TestQGearsAFileSerializer PROPERTY FOLDER "tests")

target_link_libraries(TestQGearsAFileSerializer ${LIBRARIES})
add_test(NAME TestQGearsAFileSerializer COMMAND TestQGearsAFileSerializer)


add_executable(TestQGearsMapFileXMLSerializer
    src/test_QGearsMapFileXMLSerializer.cpp
)
SET_PROPERTY(TARGET TestQGearsMapFileXMLSerializer PROPERTY FOLDER "tests")

target_link_libraries(TestQGearsMapFileXMLSerializer ${LIBRARIES})
add_test(NAME TestQGearsMapFileXMLSerializer COMMAND TestQGearsMapFileXMLSerializer)

# field walk mesh
add_executable(TestQGearsWalkmeshFileXMLSerializer
    src/test_QGearsWalkmeshFileXMLSerializer.cpp
)
SET_PROPERTY(TARGET TestQGearsWalkmeshFileXMLSerializer PROPERTY FOLDER "tests")

target_link_libraries(TestQGearsWalkmeshFileXMLSerializer ${LIBRARIES})
add_test(NAME TestQGearsWalkmeshFileXMLSerializer COMMAND TestQGearsWalkmeshFileXMLSerializer)

# LGP archive
add_executable(TestQGearsLGPArchive
    src/test_QGearsLGPArchive.cpp
)
SET_PROPERTY(TARGET TestQGearsLGPArchive PROPERTY FOLDER "tests")

target_link_libraries(TestQGearsLGPArchive ${LIBRARIES})
add_test(NAME TestQGearsLGPArchive COMMAND TestQGearsLGPArchive)

# HRC archive
add_executable(TestQGearsHRCSerializer
    src/test_QGearsHRCSerializer.cpp
)
SET_PROPERTY(TARGET TestQGearsHRCSerializer PROPERTY FOLDER "tests")

target_link_libraries(TestQGearsHRCSerializer ${LIBRARIES})
add_test(NAME TestQGearsHRCSerializer COMMAND TestQGearsHRCSerializer)

# world map
add_executable(TestMapSerializer
    src/test_MapSerializer.cpp
)
SET_PROPERTY(TARGET TestMapSerializer PROPERTY FOLDER "tests")

target_link_libraries(TestMapSerializer ${LIBRARIES})
# TODO FIX ME - test not currently working
#add_test(TestMapSerializer TestMapSerializer)


add_executable(TestTxzSerializer
    src/test_TxzSerializer.cpp
)
SET_PROPERTY(TARGET TestTxzSerializer PROPERTY FOLDER "tests")


target_link_libraries(TestTxzSerializer ${LIBRARIES})
# TODO FIX ME - test not currently working
#add_test(TestTxzSerializer TestTxzSerializer)

