cmake_minimum_required(VERSION 3.14)
project(cpp)

set(CMAKE_CXX_STANDARD 20)


add_library(RationalNumber STATIC RationalNumber.cpp)

add_executable(main main.cpp)

enable_testing()
add_subdirectory(Google_tests)


