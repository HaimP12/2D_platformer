cmake_minimum_required(VERSION 3.25)
project(platformer)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_PREFIX_PATH "/usr/local/lib/cmake")
# Add Raylib
find_package(raylib REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        src/*.cpp
        src/*.c
)

#include_directories(/usr/local/include)
#link_directories(/usr/local/lib)

add_executable(${PROJECT_NAME} ${SOURCES})

# Link Raylib and dependencies
target_link_libraries(${PROJECT_NAME} raylib
        GL
        m
        pthread
        dl
        rt
        X11
)