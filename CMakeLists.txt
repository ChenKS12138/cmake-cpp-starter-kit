cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Project Options
option(
  build_testing
  "build testing"
  ON
)

#abseil
set(ABSL_PROPAGATE_CXX_STD ON)
add_subdirectory(contrib/abseil)
include_directories(${CMAKE_SOURCE_DIR}/contrib/abseil)

project(
  cmake-cpp-starter-kit
  LANGUAGES CXX
  VERSION 1.0
)

set(BIN_NAME main)
set(LIB_NAME lib${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Project lib
# Some code which is irrelevant to environment. This is benefit to testing.
file(
  GLOB_RECURSE
  LIB_FILES
  ${CMAKE_SOURCE_DIR}/source/*
)
add_library(
  ${LIB_NAME}
  ${LIB_FILES}
)

target_link_libraries(
  ${LIB_NAME}

  #abseil
  absl_base
  absl_strings
  absl_log
  absl_log_initialize
)

# project executable binary
file(
  GLOB_RECURSE
  BIN_FILES
  ${CMAKE_SOURCE_DIR}/standalone/*
)
add_executable(
  ${BIN_NAME}
  ${BIN_FILES}
)
target_link_libraries(
  ${BIN_NAME}
  ${LIB_NAME}
)

# For generate compile_commands.json
add_custom_target(
  copy-if-compile ALL
  ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_BINARY_DIR}/compile_commands.json
  ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
)

# For format target
file(
  GLOB_RECURSE
  filetofmt${PROJECT_NAME}

  ${CMAKE_SOURCE_DIR}/source/*
  ${CMAKE_SOURCE_DIR}/include/*
  ${CMAKE_SOURCE_DIR}/standalone/*
)
add_custom_target(
  format
  command clang-format -i 
  filetofmt${PROJECT_NAME}
)

if (build_testing) 
  # test
  add_subdirectory(${CMAKE_SOURCE_DIR}/contrib/googletest)
  add_subdirectory(test)
endif()

