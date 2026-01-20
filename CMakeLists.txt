cmake_minimum_required(VERSION 3.10)
project(FFmpegDesktop)

# 1. Look for headers here
include_directories(${CMAKE_SOURCE_DIR}/include)

# 2. Look for .lib files here
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(FFmpegTest main.cpp)

# 3. Link the specific muscles
target_link_libraries(FFmpegTest avutil avformat)
