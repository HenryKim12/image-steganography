#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <opencv2/opencv.hpp>
#include <bitset>
#include <string>
#include "./RGB.hpp"

class Image {
    public: 
        Image();
        cv::Mat load_image(std::string filepath);
        std::vector<std::vector<RGB>> pixels_to_rgb(cv::Mat pixels);
        cv::Mat binary_to_pixels(cv::Mat binary);
        void save_image(std::string filepath, cv::Mat image);
};

#endif