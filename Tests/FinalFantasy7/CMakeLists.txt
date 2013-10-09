file(COPY misc DESTINATION .)

include_directories(
    ${QGears_INCLUDE_DIRS}
    ${QGearsMain_SOURCE_DIR}/include
    ${QGears_SOURCE_DIR}/SupportedGames/FinalFantasy7/include
)

set(LIBRARIES
    ${QGears_TEST_LIBRARIES}
    QGearsMain
    FinalFantasy7
)

add_executable(TestFF7FLevelFileSerializer
    src/test_FF7FLevelFileSerializer
)
target_link_libraries(TestFF7FLevelFileSerializer ${LIBRARIES})
add_test(TestFF7FLevelFileSerializer TestFF7FLevelFileSerializer)


add_executable(TestFF7ModelListFileSerializer
    src/test_FF7ModelListFileSerializer.cpp
)
target_link_libraries(TestFF7ModelListFileSerializer ${LIBRARIES})
add_test(TestFF7ModelListFileSerializer TestFF7ModelListFileSerializer)


add_executable(TestFF7WalkmeshFileSerializer
    src/test_FF7WalkmeshFileSerializer.cpp
)
target_link_libraries(TestFF7WalkmeshFileSerializer ${LIBRARIES})
add_test(TestFF7WalkmeshFileSerializer TestFF7WalkmeshFileSerializer)
