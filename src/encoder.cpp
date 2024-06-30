#include "encoder.hpp"
#include "./util/image.hpp"
#include <string>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

Encoder::Encoder() {}

cv::Mat Encoder::encode(cv::Mat image, string message) {
    // string binary_message = text_to_binary(message);
    // Image image_helper;
    // vector<vector<int>> img_pixels = image_helper.pixels_to_binary(image);
}

vector<bitset<8>> Encoder::text_to_binary(string message) {
    vector<bitset<8>> binaries;
    for (int i = 0; i < message.size(); i++) {
        char character = message[i];
        int ascii = int(character);
        bitset<8> char_binary(ascii);
        binaries.push_back(char_binary);
    }
    return binaries;
}

