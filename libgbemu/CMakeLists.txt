include_directories(.)
set(LIBGBEMU_SOURCES
        ${LIBGBEMU_SOURCES}
        libgbemu/cpu.cpp
        )
add_library(libgbemu STATIC ${LIBGBEMU_SOURCES})