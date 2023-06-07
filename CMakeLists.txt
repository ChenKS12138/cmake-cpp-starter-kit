cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

project(
  cmake-cpp-starter-kit
  LANGUAGES CXX
  VERSION 1.0
)

# Project Options
option(
  build_testing
  "build testing"
  ON
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# setup cpm
set(CPM_DOWNLOAD_LOCATION ${CMAKE_BINARY_DIR}/CPM.cmake)
file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/cpm.cmake
        ${CPM_DOWNLOAD_LOCATION})
include(${CPM_DOWNLOAD_LOCATION})

# abseil
set(ABSL_PROPAGATE_CXX_STD ON)
CPMAddPackage(
  NAME absl
  GITHUB_REPOSITORY "abseil/abseil-cpp"
  GIT_TAG "20230125.3"
)

# proto
# add_subdirectory(proto)
# include_directories(${CMAKE_BINARY_DIR}/proto)

set(BIN_NAME main)
set(LIB_NAME lib${PROJECT_NAME})

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
  absl::base
  absl::strings
  absl::log
  absl::log_initialize

  #proto
  serviceproto
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
  add_subdirectory(test)
endif()

