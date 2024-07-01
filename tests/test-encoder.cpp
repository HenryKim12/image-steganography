#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <bitset>
#include "../src/encoder.hpp"
#include "../src/util/image.hpp"

TEST_CASE("Text to Binary: char", "[encoder]") {
    Encoder encoder;
    std::vector<int> binaries = encoder.text_to_binary("A");
    int A_ascii = int('A');
    std::vector<int> answer = { A_ascii };
    REQUIRE(binaries[0] == answer[0]);
}

TEST_CASE("Text to Binary: string", "[encoder]") {
    Encoder encoder;
    std::vector<int> binaries = encoder.text_to_binary("ABC");
    int A_ascii = int('A');
    int B_ascii = int('B');
    int C_ascii = int('C');
    std::vector<int> answer = { A_ascii, B_ascii, C_ascii };
    for (int i = 0; i < binaries.size(); i++) {
        REQUIRE(binaries[i] == answer[i]);
    }
}

std::string MONA_8x8_PATH = "../../img/mona_8x8.png";

TEST_CASE("Encode", "[encoder]") {
    Image image_helper;
    cv::Mat pixels = image_helper.load_image(MONA_8x8_PATH);

    Encoder encoder;
    cv::Mat encoded_matrix = encoder.encode(pixels, "hello");

    REQUIRE(1 == 1);
}