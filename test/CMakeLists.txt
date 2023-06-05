# GoogleTest requires at least C++11

CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.13.0
  OPTIONS
      "INSTALL_GTEST OFF"
      "gtest_force_shared_crt ON"
)

enable_testing()

file(GLOB_RECURSE TEST_SOURCE_FILE ${CMAKE_CURRENT_LIST_DIR}/*)

add_executable(
  ${PROJECT_NAME}_test EXCLUDE_FROM_ALL
  
  # test code
  ${TEST_SOURCE_FILE}
)

target_link_libraries(
  ${PROJECT_NAME}_test
  gtest_main
  
  # project library
  ${LIB_NAME}
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)

add_custom_target(
  test
  COMMAND ${CMAKE_BINARY_DIR}/test/${PROJECT_NAME}_test
  DEPENDS ${PROJECT_NAME}_test
)
