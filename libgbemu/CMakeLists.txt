include_directories(.)
set(LIBGBEMU_SOURCES
        ${LIBGBEMU_SOURCES}
        libgbemu/cpu.cpp
        libgbemu/cpu.hpp
        libgbemu/memory.cpp
        libgbemu/memory.hpp
        libgbemu/types.hpp)
add_library(libgbemu STATIC ${LIBGBEMU_SOURCES})

set(LIBGEMU_TEST_SOURCES
        ${LIBGEMU_TEST_SOURCES}
        libgbemu/cpu.test.cpp
        libgbemu/memory.test.cpp
        )
add_executable(unit_tests ${LIBGEMU_TEST_SOURCES})
target_link_libraries(unit_tests libgbemu gtest_main)