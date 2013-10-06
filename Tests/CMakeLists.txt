add_definitions(
    -DBOOST_TEST_MODULE="standalone"
)

add_subdirectory(QGearsMain)
#add_executable(TestQGearsAFileSerializer
#  ${HEADER_FILES}
#  ${SOURCE_FILES}
#  test/test_QGearsAFileSerializer.cpp
#)

#target_link_libraries(TestQGearsAFileSerializer ${LIBRARIES})
#install(TARGETS TestQGearsAFileSerializer
#    RUNTIME DESTINATION ./test
#)

