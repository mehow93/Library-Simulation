cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
) 

FetchContent_MakeAvailable(googletest)

add_library(
    mylib
    Librarian.cpp
)

target_include_directories(mylib PUBLIC src)

enable_testing()

add_executable(
    librarian_tests
    tests/tests.cpp
)

target_link_libraries(
    librarian_tests
    PRIVATE
    mylib
    GTest::gtest_main
    GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(librarian_tests)