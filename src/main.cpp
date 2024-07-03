#include <opencv2/opencv.hpp>
#include "encoder.hpp"
#include "decoder.hpp"
#include "./util/image.hpp"
#include <iostream>

int main() {
    try {
        Image image_helper;
        cv::Mat image_matrix = image_helper.load_image("../img/mona_16x16.png");

        Encoder encoder;
        cv::Mat encoded_img = encoder.encode(image_matrix, "hello world");
        image_helper.save_image("../output/encoded.png", encoded_img);   

        cv::Mat encoded_img_pixels = image_helper.load_image("../output/encoded.png");

        Decoder decoder;
        std::string message = decoder.decode(encoded_img_pixels);
        std::cout << "ENCODED MESSAGE: " << message << std::endl;

    } catch (...) {
        return -1;
    }

    return 0;
}
