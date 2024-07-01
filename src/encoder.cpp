#include "encoder.hpp"
#include "./util/image.hpp"
#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <stdexcept>
#include "./util/RGB.hpp"

using namespace std;

Encoder::Encoder() {}

cv::Mat Encoder::encode(cv::Mat image, string message) {
    vector<int> binary_message = text_to_binary(message);
    Image image_helper;
    vector<vector<RGB>> img_rgbs = image_helper.pixels_to_rgb(image);

    int msg_bit_length = binary_message.size() * 8;
    int img_bit_length = img_rgbs.size() * img_rgbs[0].size() * 3;
    if (msg_bit_length > img_bit_length) {
        cout << "Error (Encoder::encode): message is too large to encode into image" << endl;
        throw invalid_argument("Error (Encoder::encode): message is too large to encode into image");
    }

    vector<int> msg_bit_list(msg_bit_length);
    for (int i = 0; i < binary_message.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (binary_message[i] >> j) & 1;
            msg_bit_list.push_back(bit);
        }
    }

    // TODO: implement lsb

    return image;
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

