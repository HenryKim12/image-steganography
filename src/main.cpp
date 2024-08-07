#include <opencv2/opencv.hpp>
#include "encoder.hpp"
#include "decoder.hpp"
#include "./util/image.hpp"
#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char* argv[]) {
    try {
        std::__fs::filesystem::path image_filepath = argv[1];
        std::string message_to_encode = argv[2];
        std::string image_extension = image_filepath.extension();

        Image image_helper;
        cv::Mat image_matrix = image_helper.load_image(image_filepath.string());

        std::string output_filepath = "../output/encoded" + image_extension;

        Encoder encoder;
        cv::Mat encoded_img = encoder.encode(image_matrix, message_to_encode);
        image_helper.save_image(output_filepath, encoded_img);   

        cv::Mat encoded_img_pixels = image_helper.load_image(output_filepath);

        Decoder decoder;
        std::string message = decoder.decode(encoded_img_pixels);
        std::cout << "ENCODED MESSAGE: " << message << std::endl;
    } catch (...) {
        std::cout << "Unexpected error has occurred" << std::endl;
        return -1;
    }

    return 0;
}
