cmake_minimum_required(VERSION 3.23)
project(libgrebe)

include_directories(.)
set(LIBGREBE_SOURCES
        ${LIBGREBE_SOURCES}
        libgrebe/cpu.cpp
        libgrebe/cpu.hpp
        libgrebe/memory.cpp
        libgrebe/memory.hpp
        libgrebe/types.hpp
        libgrebe/registers.cpp
        libgrebe/registers.hpp
        libgrebe/state.cpp
        libgrebe/state.hpp
        libgrebe/memory_loader.cpp
        libgrebe/memory_loader.hpp
        libgrebe/cpu_opcodes.cpp
        )
add_library(libgrebe STATIC ${LIBGREBE_SOURCES})
set_target_properties(libgrebe PROPERTIES PREFIX "")

set(LIBGEMU_TEST_SOURCES
        ${LIBGEMU_TEST_SOURCES}
        libgrebe/cpu.test.cpp
        libgrebe/cpu_8bit_loads.test.cpp
        libgrebe/cpu_8bit_alu.test.cpp
        libgrebe/memory.test.cpp
        libgrebe/registers.test.cpp
        libgrebe/cpu_bit_ops.test.cpp
        libgrebe/cpu_control_flow.test.cpp
        )
add_executable(libgrebe_tests ${LIBGEMU_TEST_SOURCES})
target_link_libraries(libgrebe_tests libgrebe gtest_main)