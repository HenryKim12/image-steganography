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

    vector<int> msg_bit_list;
    for (int i = 0; i < binary_message.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (binary_message[i] >> j) & 1;
            msg_bit_list.push_back(bit);
        }
    }

    cv::Mat encoded = image.clone();

    bool msg_complete = false;
    int msg_index = 0; 
    for (int i = 0; i < img_rgbs.size(); i++) {
        for (int j = 0; j < img_rgbs[0].size(); j++) {
            RGB pixel_rgb = img_rgbs[i][j];
            vector<int> rgb(3);
            rgb.push_back((int) pixel_rgb.r);
            rgb.push_back((int) pixel_rgb.g);
            rgb.push_back((int) pixel_rgb.b);

            cv::Vec3b &pixel = encoded.at<cv::Vec3b>(i, j);
            for (int k = 0; k < 3; k++) {
                if (msg_index >= msg_bit_length) {
                    cout << "Reached end of message in encoding" << endl;
                    msg_complete = true;
                    // return encoded; 
                }

                int color = rgb[k];
                color = color & 0xFE;
                color = color + msg_bit_list[msg_index];

                int color_index; // in cv::Mat, cv::Vec3b order is BGR; 
                if (k == 0) {
                    color_index = 2;
                } else if (k == 1) {
                    color_index = 1;
                } else {
                    color_index = 0;
                }
                pixel[color_index] = color;
                msg_index++;
            }
            if (msg_complete) {
                break;
            }
        }
        if (msg_complete) {
            break;
        }
    }


    cout << "HERE" << endl;
    return encoded;
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

