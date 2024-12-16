
cmake_minimum_required(VERSION 3.16)

# Project name and version
project(ParisOlympics2024 VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Gather source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")
# Find Python libraries

add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets)
