add_definitions(
    -DBOOST_TEST_DYN_LINK
    -DBOOST_TEST_MODULE="standalone"
)

set(QGearsMain_SOURCE_DIR ${QGears_SOURCE_DIR}/QGearsMain)

add_subdirectory(QGearsMain)
add_subdirectory(FinalFantasy7)
