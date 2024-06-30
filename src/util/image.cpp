#include "image.hpp"
#include <opencv2/opencv.hpp>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include "./RGB.hpp"

using namespace std;

Image::Image() {}

cv::Mat Image::load_image(std::string filepath) {
    cv::Mat image = cv::imread(filepath, cv::IMREAD_COLOR);
    if (image.empty()) {
        cout << "Error: no image at given filepath" << endl;
    }
    return image;
}

vector<vector<RGB>> Image::pixels_to_rgb(cv::Mat pixels) {
    vector<vector<RGB>> pixel_b_matrix(pixels.rows, vector<RGB>(pixels.cols));
    for (int i = 0; i < pixels.rows; i++) {
        for (int j = 0; j < pixels.cols; j++) {
            cv::Vec3b pixel = pixels.at<cv::Vec3b>(i, j);
            RGB pixel_rgb;
            pixel_rgb.r = pixel[2];
            pixel_rgb.g = pixel[1];
            pixel_rgb.b = pixel[0];
            pixel_b_matrix[i][j] = pixel_rgb;
        }
    }
    return pixel_b_matrix;
    // vector<vector<bitset<8>>> binary_matrix(pixels.rows, vector<bitset<8>>(pixels.cols));
    // for (int i = 0; i < pixels.rows; i++) {
    //     for (int j = 0; j < pixels.cols; j++) {

    //         int B = pixels.at<cv::Vec3b>(i, j)[0];
    //         int G = pixels.at<cv::Vec3b>(i, j)[1];
    //         int R = pixels.at<cv::Vec3b>(i, j)[2];
    //         cout << "[RGB at " << pixels.at<cv::Vec3b>(i, j) << "] " << "R: " << R << ", " << "G: " << G  << ", " << "B: " << B << endl;

    //         int pixel = pixels.at<int>(i, j);
    //         bitset<8> binary = bitset<8>(pixel); 
    //         binary_matrix[i][j] = binary;
    //     }
    // }
    // return binary_matrix;
}

cv::Mat Image::binary_to_pixels(cv::Mat binary) {
    
}

void Image::save_image(std::string filepath, cv::Mat image) {
    bool result = cv::imwrite(filepath, image);
    if (!result) {
        cout << "Error: image was not saved." << endl;
        return;
    }
    cout << "Saved image to " + filepath << endl;
    return;
}