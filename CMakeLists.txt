cmake_minimum_required(VERSION 3.23)
project(gbemu)

set(CMAKE_CXX_STANDARD 17)

include_directories(libgbemu)

add_subdirectory(libs)

add_subdirectory(libgbemu)
add_subdirectory(gbemu)