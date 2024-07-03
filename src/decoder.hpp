#ifndef DECODER_HPP
#define DECODER_HPP

#include <string>
#include <opencv2/opencv.hpp>

class Decoder {
    public: 
        Decoder(); 
        std::string decode(cv::Mat& image);
};

#endif