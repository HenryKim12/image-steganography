#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <string>
#include <vector>
#include <bitset>
#include <opencv2/opencv.hpp>

class Encoder {
    public: 
        Encoder();
        cv::Mat encode(cv::Mat image, std::string message);
        std::vector<std::bitset<8>> text_to_binary(std::string message);
};

#endif