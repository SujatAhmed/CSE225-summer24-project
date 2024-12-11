
cmake_minimum_required(VERSION 3.16)

# Project name and version
project(ParisOlympics2024 VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(lib)

# Gather source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "lib/*.h")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

