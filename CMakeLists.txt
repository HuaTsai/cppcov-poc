cmake_minimum_required(VERSION 3.10)
project(cppcov-poc)

option(COVERAGE "Enable coverage reporting" OFF)
option(TESTING "Enable testing" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (COVERAGE)
  set(CMAKE_BUILD_TYPE Debug)
  add_compile_options(--coverage)
  add_link_options(--coverage)
  message(STATUS "Coverage enabled")
else()
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB_RECURSE SOURCE_FILES include/*.hpp src/*.cc test/*.cc)
find_program(CLANG_FORMAT NAMES clang-format)
if(CLANG_FORMAT)
  message(STATUS "Running clang-format on source files...")
  foreach(SOURCE_FILE ${SOURCE_FILES})
    execute_process(COMMAND ${CLANG_FORMAT} -i ${SOURCE_FILE})
    message(STATUS "Formatted: ${SOURCE_FILE}")
  endforeach()
else()
  message(WARNING "clang-format not found! Source code formatting skipped.")
endif()

find_package(Eigen3 REQUIRED)

include_directories(include)

add_library(cppcov-poc SHARED src/add.cc src/minus.cc)

target_link_libraries(cppcov-poc Eigen3::Eigen)

add_executable(main src/main.cc)

target_link_libraries(main cppcov-poc)

# if (TESTING)
#   enable_testing()
#
#   include(FetchContent)
#   FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip  # Release 1.17.0
#   )
#   FetchContent_MakeAvailable(googletest)
#
#   add_executable(add_minus_test test/add_minus_test.cc)
#
#   target_link_libraries(add_minus_test gtest gtest_main cppcov-poc)
#
#   include(GoogleTest)
#
#   gtest_discover_tests(add_minus_test)
# endif()
