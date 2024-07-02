#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <bitset>
#include "../src/encoder.hpp"
#include "../src/util/image.hpp"

// TEST_CASE("Text to Binary: char", "[encoder]") {
//     Encoder encoder;
//     std::vector<int> binaries = encoder.text_to_binary("A");
//     int A_ascii = int('A');
//     std::vector<int> answer = { A_ascii };
//     REQUIRE(binaries[0] == answer[0]);
// }

// TEST_CASE("Text to Binary: string", "[encoder]") {
//     Encoder encoder;
//     std::vector<int> binaries = encoder.text_to_binary("ABC");
//     int A_ascii = int('A');
//     int B_ascii = int('B');
//     int C_ascii = int('C');
//     std::vector<int> answer = { A_ascii, B_ascii, C_ascii };
//     for (int i = 0; i < binaries.size(); i++) {
//         REQUIRE(binaries[i] == answer[i]);
//     }
// }

std::string MONA_8x8_PATH = "../../img/mona_8x8.png";

TEST_CASE("Encode", "[encoder]") {
    Image image_helper;
    cv::Mat pixels = image_helper.load_image(MONA_8x8_PATH);

    Encoder encoder;
    cv::Mat encoded_matrix = encoder.encode(pixels, "hi");

    std::vector<int> binary_message = encoder.text_to_binary("hi");
    std::vector<int> msg_bit_list;
    for (int i = 0; i < binary_message.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (binary_message[i] >> j) & 1;
            msg_bit_list.push_back(bit);
        }
    }

    // for (int i = 0; i < encoded_matrix.rows; i++) {
    //     for (int j = 0; j < encoded_matrix.cols; j++) {
    //         std::cout << "ORIGINAL" << std::endl;
    //         cv::Vec3b pixel = pixels.at<cv::Vec3b>(i, j);
    //         std::cout << "R: " << (int) pixel[2] << ", " << "G: " << (int) pixel[1] << ", " << "B: " << (int) pixel[0] << std::endl;

    //         std::cout << "ENCODED" << std::endl;
    //         cv::Vec3b pixel1 = encoded_matrix.at<cv::Vec3b>(i, j);
    //         std::cout << "R: " << (int) pixel1[2] << ", " << "G: " << (int) pixel1[1] << ", " << "B: " << (int) pixel1[0] << std::endl;
    //         std::cout << "\n" << std::endl;
    //     }
    // }

    int msg_index = 0;
    for (int i = 0; i < encoded_matrix.rows; i++) {
        for (int j = 0; j < encoded_matrix.cols; j++) {
            if (msg_index == 8) {
                std::cout << "Reached end of message" << std::endl;
                REQUIRE(1 == 1);
            }
            cv::Vec3b rgb = encoded_matrix.at<cv::Vec3b>(i, j);

            int r_val = rgb[2] & 0x01;
            std::cout << r_val << std::endl;
            REQUIRE(r_val == msg_bit_list[msg_index]);
            msg_index++;

            int g_val = rgb[1] & 0x01;
            REQUIRE(g_val == msg_bit_list[msg_index]);
            msg_index++;

            int b_val = rgb[0] & 0x01;
            REQUIRE(b_val == msg_bit_list[msg_index]);
            msg_index++;
        }
    }
    REQUIRE(1 == 1);
}