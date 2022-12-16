cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

#abseil
add_subdirectory(contrib/abseil)
include_directories(${CMAKE_SOURCE_DIR}/contrib/abseil)

project(
  cmake-cpp-practice
  LANGUAGES CXX
  VERSION 1.0
)

set(BIN_NAME main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(
  GLOB_RECURSE CMAKE_CPP_STARTERKIT_BIN
  ${CMAKE_SOURCE_DIR}/source/*.cc
  ${CMAKE_SOURCE_DIR}/source/*.hpp
  ${CMAKE_SOURCE_DIR}/source/*.h
)

file(
  GLOB_RECURSE CMAKE_CPP_STARTERKIT_HEADER
  ${CMAKE_SOURCE_DIR}/include/*.h
  ${CMAKE_SOURCE_DIR}/include/*.hpp
)

add_executable(
  ${BIN_NAME}
  ${CMAKE_CPP_STARTERKIT_BIN}
)

target_link_libraries(
  ${BIN_NAME}

  #abseil
  absl_base
  absl_strings
  absl_log
  absl_log_initialize
)

add_custom_target(
  copy-if-compile ALL
  ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_BINARY_DIR}/compile_commands.json
  ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
)

add_custom_target(
  format
  command clang-format -i 
  ${CMAKE_CPP_STARTERKIT_BIN}
  ${CMAKE_CPP_STARTERKIT_HEADER}
)
