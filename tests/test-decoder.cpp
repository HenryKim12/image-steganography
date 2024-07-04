#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <string>
#include <iostream>
#include "../src/decoder.hpp"
#include "../src/util/image.hpp"
#include "../src/encoder.hpp"

std::string RAW_IMG_PATH = "../../img/mona.png";
std::string ENCODED_IMG_PATH = "../../output/encoded.png";

TEST_CASE("Decode image", "[decoder]") {
    Image image_helper;
    cv::Mat raw = image_helper.load_image(RAW_IMG_PATH);

    Encoder encoder;
    cv::Mat encoded_img = encoder.encode(raw, "hello world");
    image_helper.save_image(ENCODED_IMG_PATH, encoded_img);

    cv::Mat pixels = image_helper.load_image(ENCODED_IMG_PATH);

    Decoder decoder;
    std::string message = decoder.decode(pixels);

    REQUIRE(message == "hello world");
}