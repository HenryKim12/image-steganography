#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <string>
#include <opencv2/opencv.hpp>

class Encoder {
    public: 
        Encoder();
        cv::Mat encode(cv::Mat image, std::string message);
        std::string text_to_binary(std::string text);
};

#endif