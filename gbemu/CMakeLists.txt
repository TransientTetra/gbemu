set(GBEMU_SOURCES
        ${GBEMU_SOURCES}
        gbemu/main.cpp
        )

add_executable(gbemu ${GBEMU_SOURCES})
target_link_libraries(gbemu libgbemu)