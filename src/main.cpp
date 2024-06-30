#include <opencv2/opencv.hpp>
#include "encoder.hpp"
#include "decoder.hpp"
#include "./util/image.hpp"
#include <iostream>

int main() {
    try {
        Image image_helper;
        cv::Mat image_matrix = image_helper.load_image("../img/mona_8x8.png");

        /*
        remove lsb from each pixel in image data
        
        */


        std::cout << "hello world";
        
    } catch (...) {
        std::cout << "Error" << std::endl;
        return -1;
    }

    return 0;
}
