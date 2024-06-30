#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include "../src/util/image.hpp"
#include <iostream>
#include <bitset>
#include "../src/util/RGB.hpp"

// relative path is from /build/tests folder
std::string RAW_IMG_RELATIVE_PATH_V1 = "../../img/mona_1788x1200.jpg";
std::string ENCODED_IMG_RELATIVE_PATH_V1 = "../../output/mona_encoded.jpg";

TEST_CASE("Load and Save image: 1788x1200", "[image]") {
    Image image_helper;
    cv::Mat pixels = image_helper.load_image(RAW_IMG_RELATIVE_PATH_V1);
    REQUIRE(pixels.rows == 1788);
    REQUIRE(pixels.cols == 1200);

    image_helper.save_image(ENCODED_IMG_RELATIVE_PATH_V1, pixels);
    REQUIRE(std::__fs::filesystem::exists(ENCODED_IMG_RELATIVE_PATH_V1));
}

std::string RAW_IMG_RELATIVE_PATH_V2 = "../../img/charmeleon_236x236.jpg";
std::string ENCODED_IMG_RELATIVE_PATH_V2 = "../../output/charmeleon236x236.jpg";

TEST_CASE("Pixels to Binary", "[image]") {
    Image image_helper;
    cv::Mat pixels = image_helper.load_image(RAW_IMG_RELATIVE_PATH_V2);
    REQUIRE(pixels.rows == 236);
    REQUIRE(pixels.cols == 236);

    std::vector<std::vector<RGB>> binaries = image_helper.pixels_to_rgb(pixels);
    for (int i = 0; i < binaries.size(); i++) {
        for (int j = 0; j < binaries[0].size(); j++) {
            cv::Vec3b pixel = pixels.at<cv::Vec3b>(i, j);
            REQUIRE(binaries[i][j].r == pixel[2]);
            REQUIRE(binaries[i][j].g == pixel[1]);
            REQUIRE(binaries[i][j].b == pixel[0]);
        }
    }
}