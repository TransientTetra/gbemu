cmake_minimum_required(VERSION 3.23)
project(grebe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(libgrebe)

add_subdirectory(libs)

add_subdirectory(libgrebe)
add_subdirectory(grebe)
