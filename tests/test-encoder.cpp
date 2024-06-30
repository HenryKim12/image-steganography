#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <bitset>
#include "../src/encoder.hpp"

TEST_CASE("Text to Binary: char", "[encoder]") {
    Encoder encoder;
    std::vector<int> binaries = encoder.text_to_binary("A");

    // std::bitset<8> A_bits(65);
    // std::vector<std::bitset<8>> answer = {A_bits};

    // std::cout << "answer " << answer[0] << " binaries " << binaries[0] << std::endl;
    // REQUIRE(binaries[0] == answer[0]);
}

TEST_CASE("Text to Binary: string", "[encoder]") {
    Encoder encoder;
    std::vector<int> binaries = encoder.text_to_binary("ABC");

    // std::bitset<8> A_bits(65);
    // std::bitset<8> B_bits(66);
    // std::bitset<8> C_bits(67);
    // std::vector<std::bitset<8>> answer = {A_bits, B_bits, C_bits};
    // for (int i = 0; i < binaries.size(); i++) {
    //     REQUIRE(binaries[i] == answer[i]);
    // }
}