# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(Game)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# Set the compiler config
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(flags "-std=c++1z -stdlib=libc++ -m64 -Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(flags "/std:c++17 /W4 /WX /EHsc /ZI /MACHINE:X64")
endif()
  
if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${flags}")
endif()

# Include Conan dependencies
include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/includes")

add_executable(Game
  ${PROJECT_SOURCE_DIR}/Dependencies/Lib/glad.cpp
  ${PROJECT_SOURCE_DIR}/Code/Utils/SDLWrapper.cpp
  ${PROJECT_SOURCE_DIR}/Code/Utils/Logger.cpp
  ${PROJECT_SOURCE_DIR}/Code/Sprite.cpp
  ${PROJECT_SOURCE_DIR}/Code/MainGame.cpp
  ${PROJECT_SOURCE_DIR}/Code/main.cpp)

target_link_libraries(Game ${CONAN_LIBS})

