cmake_minimum_required(VERSION 3.10)
project(img-sg)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(img-sg src/main.cpp src/encoder.cpp src/decoder.cpp src/util/image.cpp)
target_link_libraries(img-sg ${OpenCV_LIBS})
