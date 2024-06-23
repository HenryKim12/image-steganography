#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <opencv2/opencv.hpp>
#include <string>

using std::string;

class Image {
    public: 
        Image();
        cv::Mat load_image(string& filepath);
        void save_image(string& filepath, cv::Mat image);
};

#endif