cmake_minimum_required(VERSION 3.10)
project(FileTracker VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

enable_testing()


add_library(FileTrackerLib STATIC src/FileTracker.cpp)
target_include_directories(FileTrackerLib PUBLIC include)


add_executable(FileTracker src/FileTracker.cpp)
target_link_libraries(FileTracker FileTrackerLib)


add_executable(FileTracker_tests tests/FileTracker_tests.cpp)
target_link_libraries(FileTracker_tests gtest gtest_main FileTrackerLib)
include(GoogleTest)
gtest_discover_tests(FileTracker_tests)