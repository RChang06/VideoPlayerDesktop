cmake_minimum_required(VERSION 3.10)
project(FFmpegDesktop)

# 1. Setup YOUR project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# 2. Setup FFmpeg headers (Inside the folder you moved to external)
include_directories(${CMAKE_SOURCE_DIR}/external/ffmpeg/include)

# 3. Setup FFmpeg libraries
link_directories(${CMAKE_SOURCE_DIR}/external/ffmpeg/lib)

# 4. Your Source Files
# Make sure main.cpp is in the root or 'src/' folder!
add_executable(FFmpegTest src/main.cpp src/VideoReader.cpp)

# 5. Link FFmpeg Muscles
target_link_libraries(FFmpegTest 
    avformat 
    avcodec 
    avutil 
    swscale
)