cmake_minimum_required(VERSION 3.16)

# Project name
project(SeachCSV)

# Find required Qt components
set(CMAKE_AUTOMOC ON) # Automatically process Qt's MOC files
set(CMAKE_AUTORCC ON) # Automatically process Qt's resource files (if needed)
set(CMAKE_AUTOUIC ON) # Automatically process Qt's UIC files (if using .ui)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Add executable and source files
add_executable(${PROJECT_NAME}
    main.cpp
    Database.cpp
    LinkedList.cpp
    Node.cpp
    Utils.cpp
    data/athletes.csv data/coaches.csv data/events.csv data/medallists.csv data/medals.csv data/medals_total.csv data/nocs.csv data/schedules.csv data/schedules_preliminary.csv data/teams.csv data/technical_officials.csv data/torch_route.csv data/venues.csv
    search.cpp
)

# Include header directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link against Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# Specify C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
