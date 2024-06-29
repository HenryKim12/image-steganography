#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <opencv2/opencv.hpp>

class Image {
    public: 
        Image();
        cv::Mat load_image(std::string filepath);
        std::vector<std::vector<int>> pixels_to_binary(cv::Mat pixels);
        cv::Mat binary_to_pixels(cv::Mat binary);
        void save_image(std::string filepath, cv::Mat image);
};

#endif