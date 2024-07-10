cmake_minimum_required(VERSION 3.21)
project(DB)

set(CMAKE_CXX_STANDARD 20)

if(!MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif() 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_subdirectory(src)
