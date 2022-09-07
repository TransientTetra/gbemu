cmake_minimum_required(VERSION 3.23)
project(gbemu)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libgbemu)

set(GBEMU_SOURCES
        ${GBEMU_SOURCES}
        gbemu/gbemu/main.cpp
        )

add_executable(gbemu ${GBEMU_SOURCES})
target_link_libraries(gbemu libgbemu)