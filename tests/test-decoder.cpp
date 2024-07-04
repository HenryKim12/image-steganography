#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <string>
#include <iostream>
#include "../src/decoder.hpp"
#include "../src/util/image.hpp"

std::string ENCODED_IMG_PATH = "../../output/encoded.jpg";

TEST_CASE("Decode image", "[decoder]") {
    Image image_helper;
    cv::Mat pixels = image_helper.load_image(ENCODED_IMG_PATH);

    cv::Mat pixelst = image_helper.load_image()

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << pixels.at<cv::Vec3b>(i, j) << std::endl;
        }
    }

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << pixels.at<cv::Vec3b>(i, j) << std::endl;
        }
    }

    Decoder decoder;
    std::string message = decoder.decode(pixels);

    REQUIRE(message == "hello world");
}