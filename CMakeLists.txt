cmake_minimum_required(VERSION 3.10)
project(img-sg)

set(CMAKE_CXX_STANDARD 11)

# opencv
set(OpenCV_DIR "/opt/homebrew/Cellar/opencv/4.9.0_10/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR})

add_executable(img-sg src/main.cpp src/encoder.cpp src/decoder.cpp src/util/image.cpp)
target_link_libraries(img-sg ${OpenCV_LIBS})

# tests
enable_testing()
include_directories(lib)
add_subdirectory(tests)

