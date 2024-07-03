#include "decoder.hpp"
#include <string>
#include <vector>
#include "./util/image.hpp"
#include "./util/RGB.hpp"

using namespace std;

Decoder::Decoder() {}

string Decoder::decode(cv::Mat& image) {
    Image image_helper;
    vector<vector<RGB>> pixels = image_helper.pixels_to_rgb(image);
    vector<int> msg_bits;
    for (int i = 0; i < pixels.size(); i++) {
        for (int j = 0; j < pixels[0].size(); j++) {
            RGB pixel = pixels[i][j];
            msg_bits.push_back(pixel.r % 2);
            msg_bits.push_back(pixel.g % 2);
            msg_bits.push_back(pixel.b % 2);
        }
    }

    vector<int> msg_characters_decimal;
    int value = 0;
    for (int i = 0; i < msg_bits.size(); i++) {
        if (i % 8 == 0 && i != 0) {
            msg_characters_decimal.push_back(value);
            value = 0;
        }
        value |= msg_bits[i] << (i % 8);
    }

    string message = "";
    for (int character : msg_characters_decimal) {
        char c = char(character);
        message += c;
    }

    return message;
}

// string Decoder::binary_to_text(string binary) {
//     return "";
// }
