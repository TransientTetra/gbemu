include_directories(.)
set(LIBGBEMU_SOURCES
        ${LIBGBEMU_SOURCES}
        libgbemu/cpu.cpp
        libgbemu/cpu.hpp
        libgbemu/memory.cpp
        libgbemu/memory.hpp
        libgbemu/types.hpp
        libgbemu/registers.cpp
        libgbemu/registers.hpp
        libgbemu/state.cpp
        libgbemu/state.hpp
        )
add_library(libgbemu STATIC ${LIBGBEMU_SOURCES})
set_target_properties(libgbemu PROPERTIES PREFIX "")

set(LIBGEMU_TEST_SOURCES
        ${LIBGEMU_TEST_SOURCES}
        libgbemu/cpu.test.cpp
        libgbemu/cpu_8bit_loads.test.cpp
        libgbemu/cpu_8bit_alu.test.cpp
        libgbemu/memory.test.cpp
        libgbemu/registers.test.cpp
        )
add_executable(libgbemu_tests ${LIBGEMU_TEST_SOURCES})
target_link_libraries(libgbemu_tests libgbemu gtest_main)