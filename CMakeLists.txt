cmake_minimum_required(VERSION 3.28)
project(NodeSystem)

set(CMAKE_CXX_STANDARD 14)

# Directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(EVENTS_DIR "${SRC_DIR}/Events")

# Source and header files
file(GLOB_RECURSE SOURCES
        "${SRC_DIR}/*.cpp"
)

file(GLOB_RECURSE HEADERS
        "${SRC_DIR}/*.h"
)

# Executable
add_executable(NodeSystem
        main.cpp
        ${SOURCES}
        ${HEADERS}
)

# Include directories
target_include_directories(NodeSystem PRIVATE ${SRC_DIR})

message(STATUS "Sources: ${SOURCES}")
message(STATUS "Headers: ${HEADERS}")
