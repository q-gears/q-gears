add_definitions(
    -DBOOST_TEST_MODULE="standalone"
)

if(UNIX OR APPLE)
    add_definitions(
        -DBOOST_TEST_DYN_LINK
    )
endif()

set(QGearsMain_SOURCE_DIR ${QGears_SOURCE_DIR}/QGearsMain)

add_subdirectory(QGearsMain)
add_subdirectory(FinalFantasy7)
