cmake_minimum_required(VERSION 3.14)

project(ParisOlympicsAnalysis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON) # Enable MOC processing

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ParisOlympicsAnalysis main.cpp)

target_link_libraries(ParisOlympicsAnalysis Qt6::Widgets)
