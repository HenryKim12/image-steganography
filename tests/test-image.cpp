#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include "../src/util/image.hpp"

// relative path is from /build/tests folder
std::string RAW_IMG_RELATIVE_PATH = "../../img/mona_raw.jpg";
std::string ENCODED_IMG_RELATIVE_PATH = "../../output/mona_encoded.jpg";

TEST_CASE("Load and Save image: 1788x1200", "[image]") {
    Image image_helper;
    cv::Mat pixels = image_helper.load_image(RAW_IMG_RELATIVE_PATH);
    REQUIRE(pixels.rows == 1788);
    REQUIRE(pixels.cols == 1200);

    image_helper.save_image(ENCODED_IMG_RELATIVE_PATH, pixels);
    REQUIRE(std::__fs::filesystem::exists(ENCODED_IMG_RELATIVE_PATH));
}