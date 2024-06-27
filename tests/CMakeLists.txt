add_executable(tests
    test-main.cpp
    test-image.cpp
    test-encoder.cpp
    test-decoder.cpp)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})