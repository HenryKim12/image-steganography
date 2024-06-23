#ifndef DECODER_HPP
#define DECODER_HPP

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using std::vector;
using std::string;

class Decoder {
    public: 
        Decoder(); 
        string decode(cv::Mat& image);

    private:
        string binary_to_text(string& binary);
};

#endif