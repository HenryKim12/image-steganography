#include "encoder.hpp"
#include "./util/image.hpp"
#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <stdexcept>

using namespace std;

Encoder::Encoder() {}

cv::Mat Encoder::encode(cv::Mat image, string message) {
    // vector<bitset<8>> binary_message = text_to_binary(message);
    // Image image_helper;
    // vector<vector<bitset<8>>> img_pixels = image_helper.pixels_to_binary(image);

    // int numPixels = img_pixels.size() * img_pixels[0].size();
    // int numMessage = binary_message.size() * 8; 
    // if (numMessage > numPixels) {
    //     cout << "Error: message is too large for image" << endl;
    //     throw invalid_argument("Error: message is too large for image");
    // }

    // int word_index = 0;
    // int character_index = 0;
    // for (int i = 0; i < img_pixels.size(); i++) {
    //     for (int j = 0; j < img_pixels[0].size(); j++) {
    //         bitset<8> curr_binary_pixel = img_pixels[i][j];
    //         // exchange lsb with 1-bit from word_index at character_index
    //         // curr_binary_pixel = curr_binary_pixel & 0xFE; 
            
    //     }
    // }
}

vector<int> Encoder::text_to_binary(string message) {
    vector<int> binaries;
    for (int i = 0; i < message.size(); i++) {
        char character = message[i];
        int ascii = int(character);
        binaries.push_back(ascii);
    }
    return binaries;
}

