cmake_minimum_required(VERSION 3.10)
project(cppcov-poc VERSION 1.2.3)

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

find_program(CLANG_TIDY NAMES clang-tidy)
if(CLANG_TIDY)
  message(STATUS "clang-tidy found: ${CLANG_TIDY}")
  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY}")
else()
  message(WARNING "clang-tidy not found! Static analysis skipped.")
endif()

find_package(Eigen3 REQUIRED)

add_library(cppcov-poc SHARED)

target_include_directories(cppcov-poc PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_sources(cppcov-poc PRIVATE
  src/add.cc
  src/minus.cc
)

target_link_libraries(cppcov-poc Eigen3::Eigen)

set_property(TARGET cppcov-poc PROPERTY VERSION ${PROJECT_VERSION})

add_executable(main)

target_sources(main PRIVATE
  src/main.cc
)

target_link_libraries(main cppcov-poc)

install(
  TARGETS cppcov-poc
  EXPORT cppcovTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT cppcovTargets
  FILE cppcovTargets.cmake
  NAMESPACE cppcov::
  DESTINATION lib/cmake/cppcov-poc
)

if (TESTING)
  enable_testing()
  add_executable(add_minus_test test/add_minus_test.cc)
  target_link_libraries(add_minus_test cppcov-poc gtest gtest_main)
  include(GoogleTest)
  gtest_discover_tests(add_minus_test)
endif()
