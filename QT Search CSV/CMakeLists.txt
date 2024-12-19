cmake_minimum_required(VERSION 3.16)

# Project name
project(SearchCSV)

# Enable Qt features for MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON) # Automatically process Qt's MOC files
set(CMAKE_AUTORCC ON) # Automatically process Qt's resource files (if needed)
set(CMAKE_AUTOUIC ON) # Automatically process Qt's UIC files (if using .ui)

# Find required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Add executable and source files
add_executable(${PROJECT_NAME}
    main.cpp
    searchInCSV.cpp
    Database.cpp
    LinkedList.cpp
    Node.cpp
    Utils.cpp
)

# Include header directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Include CSV data directory for runtime (Optional if needed for relative path handling)
install(DIRECTORY data/ DESTINATION ${CMAKE_BINARY_DIR}/data)

# Link against Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# Specify C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
