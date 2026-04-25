cmake_minimum_required(VERSION 3.10)

project(physics_playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(sim ${SOURCES})

target_include_directories(sim PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(sim
    sfml-graphics
    sfml-window
    sfml-system
)
