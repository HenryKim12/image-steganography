add_executable(main-tests test-main.cpp)
target_include_directories(main-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(image-tests test-image.cpp)
target_include_directories(image-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(encoder-tests test-encoder.cpp)
target_include_directories(encoder-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(decoder-tests test-decoder.cpp)
target_include_directories(decoder-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME Main_Tests COMMAND main-tests)
add_test(NAME Image_Tests COMMAND image-tests)
add_test(NAME Encoder_Tests COMMAND encoder-tests)
add_test(NAME Decoder_Tests COMMAND decoder-tests)
