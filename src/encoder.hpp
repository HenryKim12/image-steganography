#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using std::vector;
using std::string;

class Encoder {
    public: 
        Encoder();
        cv::Mat encode(cv::Mat & image, string message);

    private:
        string text_to_binary(string& text);
};

#endif