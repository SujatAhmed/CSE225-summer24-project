cmake_minimum_required(VERSION 3.10)
project(OlympicsInformationSystem)

# Set the C++ standard to C++17 (or modify it if needed)
set(CMAKE_CXX_STANDARD 17)

# Add source files for the main project
set(SOURCE_FILES
    main.cpp
)

# Add source files for the lib directory
set(LIBRARY_SOURCES
    lib/Database.cpp
    lib/LinkedList.cpp
    lib/Node.cpp
    lib/Utils.cpp
)

# Add header files (optional, just to organize them)
set(LIBRARY_HEADERS
    lib/Database.h
    lib/LinkedList.h
    lib/Node.h
    lib/Utils.h
)

# Add an executable target
add_executable(main ${SOURCE_FILES} ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

# Optionally, if you have any include directories
# Add the "lib" directory to the include paths
target_include_directories(main PRIVATE lib)

# If you want to add other directories (e.g., "data" and "results"), they are data files
# and typically not added to the build, but you can specify a custom folder for convenience
set(DATA_DIR ${CMAKE_SOURCE_DIR}/data)
set(RESULTS_DIR ${CMAKE_SOURCE_DIR}/results)

# Optional: If you need to define a custom installation path
# install(TARGETS OlympicsInformationSystem DESTINATION bin)

