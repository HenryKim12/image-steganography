#include "image.hpp"
#include <opencv2/opencv.hpp>

Image::Image() {}

cv::Mat Image::load_image(std::string filepath) {
    cv::Mat image = cv::imread(filepath, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cout << "Error: no image at given filepath" << std::endl;
    }
    return image;
}

void Image::save_image(std::string filepath, cv::Mat image) {
    bool result = cv::imwrite(filepath, image);
    if (!result) {
        std::cout << "Error: image was not saved." << std::endl;
    }
    std::cout << "Saved image to " + filepath << std::endl;
}