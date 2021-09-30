# Set minimum version of CMake.
cmake_minimum_required(VERSION 3.11)

# Set project name and version
project(Atom VERSION 0.0.1)

# Install dependencies
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Set environment variables
include(${PROJECT_SOURCE_DIR}/cmake/SetEnv.cmake)

# Library sources
add_subdirectory(${LIBRARY_FOLDER})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")

# Library examples
enable_testing()
add_subdirectory(test)
