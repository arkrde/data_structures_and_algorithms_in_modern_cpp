cmake_minimum_required(VERSION 3.0) 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

project(dsa_cpp
    LANGUAGES CXX
) 
include(FetchContent)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()


# Enable testing using ctest
enable_testing()

# file(GLOB headers ${CMAKE_SOURCE_DIR}/dsa_cpp/include)


add_library(dsa_cpp INTERFACE)
target_include_directories(dsa_cpp INTERFACE include)

add_subdirectory(tests)