#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <string>
#include <vector>
#include <bitset>
#include <opencv2/opencv.hpp>
#include "./util/RGB.hpp"

class Encoder {
    public: 
        Encoder();
        cv::Mat encode(cv::Mat& image, std::string message);
        std::vector<int> text_to_binary(std::string message);
        void escape_encoding(cv::Mat& image, const std::vector<std::vector<RGB>>& img_rgbs, int currRow, int currCol, int currChannel);
};

#endif