cmake_minimum_required(VERSION 3.23)
project(libgrebe)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
set(LIBGREBE_SOURCES
        ${LIBGREBE_SOURCES}
        libgrebe/core/cpu.cpp
        libgrebe/core/cpu.hpp
        libgrebe/core/memory.cpp
        libgrebe/core/memory.hpp
        libgrebe/types.hpp
        libgrebe/core/registers.cpp
        libgrebe/core/registers.hpp
        libgrebe/state.cpp
        libgrebe/state.hpp
        libgrebe/memory_loader.cpp
        libgrebe/memory_loader.hpp
        libgrebe/core/decoder.cpp
        libgrebe/core/decoder.hpp
        libgrebe/core/opcodes.hpp
        libgrebe/core/instructions.cpp
        libgrebe/core/instructions.hpp
        libgrebe/memory_locations.hpp
        libgrebe/utils.cpp
        libgrebe/utils.hpp
        libgrebe/core/interrupt_handler.cpp
        libgrebe/core/interrupt_handler.hpp
        libgrebe/display/lcd.cpp
        libgrebe/display/lcd.hpp
        libgrebe/display/ppu.cpp
        libgrebe/display/ppu.hpp
        )

add_library(libgrebe STATIC ${LIBGREBE_SOURCES})
set_target_properties(libgrebe PROPERTIES PREFIX "")

set(LIBGREBE_TEST_SOURCES
        ${LIBGREBE_TEST_SOURCES}
        libgrebe/core/cpu.test.cpp
        libgrebe/core/cpu_loads.test.cpp
        libgrebe/core/cpu_alu.test.cpp
        libgrebe/core/memory.test.cpp
        libgrebe/core/registers.test.cpp
        libgrebe/core/cpu_bit_ops.test.cpp
        libgrebe/core/cpu_control_flow.test.cpp
        libgrebe/core/cpu.test.hpp
        )
add_executable(libgrebe_tests ${LIBGREBE_TEST_SOURCES})
target_link_libraries(libgrebe_tests libgrebe gtest_main)
