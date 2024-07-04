#include "encoder.hpp"
#include "./util/image.hpp"
#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <stdexcept>
#include "./util/RGB.hpp"
#include <typeinfo>

using namespace std;

Encoder::Encoder() {}

cv::Mat Encoder::encode(cv::Mat& image, string message) {
    vector<int> binary_message = text_to_binary(message);
    Image image_helper;
    vector<vector<RGB>> img_rgbs = image_helper.pixels_to_rgb(image);

    int msg_bit_length = (binary_message.size() * 8) + 8;
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
    
    bool msg_complete = false;
    int msg_index = 0; 
    for (int i = 0; i < img_rgbs.size(); i++) {
        for (int j = 0; j < img_rgbs[0].size(); j++) {
            RGB pixel_rgb = img_rgbs[i][j];
            vector<int> rgb;
            rgb.push_back(pixel_rgb.r);
            rgb.push_back(pixel_rgb.g);
            rgb.push_back(pixel_rgb.b);

            cv::Vec3b& pixel = image.at<cv::Vec3b>(i, j);
            for (int k = 0; k < 3; k++) {
                if (msg_index >= msg_bit_length) {
                    cout << "[Encoder] Reached end of message in encoding" << endl;
                    // ESC: 27 (0001 1011)
                    escape_encoding(image, img_rgbs, i, j, k);
                    msg_complete = true;
                    break;
                }
                int color = rgb[k];
                color &= 0xFE;
                color += msg_bit_list[msg_index];
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

void Encoder::escape_encoding(cv::Mat& image, const vector<vector<RGB>>& img_rgbs, int currRow, int currCol, int currChannel) {
    vector<int> ESC_binary = {1, 1, 0, 1, 1, 0, 0, 0};
    int ESC_index = 0;
    bool ESC_complete = false;
    for (int i = currRow; i < image.rows; i++) {
        for (int j = currCol; j < image.cols; j++) {
            RGB pixel_rgb = img_rgbs[i][j];
            vector<int> rgb;
            rgb.push_back(pixel_rgb.r);
            rgb.push_back(pixel_rgb.g);
            rgb.push_back(pixel_rgb.b);

            cv::Vec3b& pixel = image.at<cv::Vec3b>(i, j);
            int channelStart = 0;
            if (currChannel != 0) {
                channelStart = currChannel;
                currChannel = 0;
            }
            for (int k = channelStart; k < 3; k++) {
                if (ESC_index >= 8) {
                    ESC_complete = true;
                    break;
                }
                int color = rgb[k];
                color &= 0xFE;
                color += ESC_binary[ESC_index];
                int color_index; // in cv::Mat, cv::Vec3b order is BGR; 
                if (k == 0) {
                    color_index = 2;
                } else if (k == 1) {
                    color_index = 1;
                } else {
                    color_index = 0;
                }
                pixel[color_index] = color;
                ESC_index++;
            }
            if (ESC_complete) {
                break;
            }
        }
        if (ESC_complete) {
            break;
        }
    }
}
