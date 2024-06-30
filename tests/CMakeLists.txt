find_package(OpenCV REQUIRED)

add_library(Main ../src/main.cpp)
add_executable(main-tests test-main.cpp)
target_include_directories(main-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main-tests PRIVATE Main ${OpenCV_LIBS})

add_library(Image ../src/util/image.cpp)
add_executable(image-tests test-image.cpp)
target_include_directories(image-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(image-tests PRIVATE Image ${OpenCV_LIBS})

add_library(Encoder ../src/encoder.cpp)
add_executable(encoder-tests test-encoder.cpp)
target_include_directories(encoder-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(encoder-tests PRIVATE Encoder Image ${OpenCV_LIBS})

add_library(Decoder ../src/decoder.cpp)
add_executable(decoder-tests test-decoder.cpp)
target_include_directories(decoder-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(decoder-tests PRIVATE Decoder ${OpenCV_LIBS})

add_test(NAME main_tests COMMAND main-tests)
add_test(NAME image_tests COMMAND image-tests)
add_test(NAME encoder_tests COMMAND encoder-tests)
add_test(NAME tecoder_tests COMMAND decoder-tests)
