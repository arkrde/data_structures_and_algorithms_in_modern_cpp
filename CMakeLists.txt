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

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0)
FetchContent_MakeAvailable(googletest)

# Enable testing using ctest
enable_testing()

file(GLOB headers ${CMAKE_SOURCE_DIR}/dsa_cpp/include)

# Add source directories
add_subdirectory(tests)

message("status:")
message("cpp compiler:  " ${CMAKE_CXX_COMPILER})
message("build type:    " ${CMAKE_BUILD_TYPE})