include_directories(.)
set(LIBGBEMU_SOURCES
        ${LIBGBEMU_SOURCES}
        libgbemu/cpu.cpp
        libgbemu/cpu.hpp
        libgbemu/memory.cpp
        libgbemu/memory.hpp
        libgbemu/types.hpp)
add_library(libgbemu STATIC ${LIBGBEMU_SOURCES})

add_executable(unit_tests libgbemu/cpu.test.cpp libgbemu/memory.test.cpp)
target_link_libraries(unit_tests libgbemu gtest_main)