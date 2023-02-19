# GoogleTest requires at least C++11

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#   TEST_EXCLUDE_FROM_MAIN true
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)
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
