#include "encoder.hpp"
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

Encoder::Encoder() {}

cv::Mat Encoder::encode(cv::Mat image, string message) {
    
}

string Encoder::text_to_binary(string text) {
    string binary = ""; 
    for (int i = 0; i < text.size(); i++) {
        char character = text[i];
        int ascii = int(character);
        string char_bin = std::bitset<8>(ascii).to_string(); 
        if (i != text.size() - 1) {
            char_bin += " ";
        }
        binary += char_bin;
    }
    return binary;
}