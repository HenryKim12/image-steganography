#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <opencv2/opencv.hpp>

class Image {
    public: 
        Image();
        cv::Mat load_image(std::string filepath);
        void save_image(std::string filepath, cv::Mat image);
};

#endif