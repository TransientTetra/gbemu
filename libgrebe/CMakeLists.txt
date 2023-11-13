cmake_minimum_required(VERSION 3.23)
project(libgrebe)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
set(LIBGREBE_SOURCES
        ${LIBGREBE_SOURCES}
        libgrebe/core/cpu/control_unit.cpp
        libgrebe/core/cpu/control_unit.hpp
        libgrebe/core/mmu/mmu.cpp
        libgrebe/core/mmu/mmu.hpp
        libgrebe/core/cpu/registers.hpp
        libgrebe/state.hpp
        libgrebe/memory_loader.cpp
        libgrebe/memory_loader.hpp
        libgrebe/core/cpu/decoder.cpp
        libgrebe/core/cpu/decoder.hpp
        libgrebe/core/cpu/opcodes.hpp
        libgrebe/core/cpu/instructions.cpp
        libgrebe/core/cpu/instructions.hpp
        libgrebe/memory_locations.hpp
        libgrebe/utils.cpp
        libgrebe/utils.hpp
        libgrebe/core/cpu/interrupt_handler.cpp
        libgrebe/core/cpu/interrupt_handler.hpp
        libgrebe/display/lcd.cpp
        libgrebe/display/lcd.hpp
        libgrebe/core/ppu/ppu.cpp
        libgrebe/core/ppu/ppu.hpp
        libgrebe/common/synchronous_component.hpp
        libgrebe/core/core.hpp
        libgrebe/core/core.cpp
        libgrebe/core/cpu/cpu.cpp
        libgrebe/core/cpu/cpu.hpp
        libgrebe/common/addressable.hpp
        libgrebe/core/mmu/bootrom.hpp
        libgrebe/core/mmu/bootrom.cpp
        libgrebe/core/mmu/vram.hpp
        libgrebe/core/mmu/vram.cpp
        libgrebe/core/mmu/hram.hpp
        libgrebe/core/mmu/hram.cpp
        libgrebe/core/mmu/wram.hpp
        libgrebe/core/mmu/wram.cpp
        libgrebe/core/mmu/hardware_registers.hpp
        libgrebe/core/mmu/hardware_registers.cpp
        libgrebe/core/cpu/timer.hpp
        libgrebe/core/cpu/timer.cpp
        )

add_library(libgrebe STATIC ${LIBGREBE_SOURCES})
set_target_properties(libgrebe PROPERTIES PREFIX "")

set(LIBGREBE_TEST_SOURCES
        ${LIBGREBE_TEST_SOURCES}
        libgrebe/core/cpu/control_unit.test.cpp
        libgrebe/core/cpu/control_unit_loads.test.cpp
        libgrebe/core/cpu/control_unit_alu.test.cpp
        libgrebe/core/cpu/control_unit_alu_inc.test.cpp
        libgrebe/core/cpu/control_unit_alu_dec.test.cpp
        libgrebe/core/cpu/control_unit_alu_add.test.cpp
        libgrebe/core/cpu/control_unit_alu_adc.test.cpp
        libgrebe/core/cpu/control_unit_alu_and.test.cpp
        libgrebe/core/cpu/control_unit_alu_xor.test.cpp
        libgrebe/core/cpu/control_unit_alu_or.test.cpp
        libgrebe/core/cpu/control_unit_alu_cp.test.cpp
        libgrebe/core/mmu/mmu.test.hpp
        libgrebe/core/mmu/mmu.test.cpp
        libgrebe/core/cpu/registers.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_bit.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_res.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_rl.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_rlc.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_rr.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_rrc.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_set.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_sla.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_sra.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_srl.test.cpp
        libgrebe/core/cpu/control_unit_bit_ops_swap.test.cpp
        libgrebe/core/cpu/control_unit_control_flow.test.cpp
        libgrebe/core/cpu/control_unit.test.hpp
        libgrebe/core/core.test.hpp
        libgrebe/core/core.test.cpp
        libgrebe/core/common.test.hpp
        libgrebe/core/common.test.cpp
        libgrebe/core/mmu/hardware_registers.test.cpp
        libgrebe/core/cpu/timer.test.hpp
        libgrebe/core/cpu/timer.test.cpp
        )
add_executable(libgrebe_tests ${LIBGREBE_TEST_SOURCES})
target_link_libraries(libgrebe_tests libgrebe gtest_main)
