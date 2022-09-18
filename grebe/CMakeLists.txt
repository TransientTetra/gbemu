set(GREBE_SOURCES
        ${GREBE_SOURCES}
        grebe/main.cpp
        )

add_executable(grebe ${GREBE_SOURCES})
target_link_libraries(grebe libgrebe)