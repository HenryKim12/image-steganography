#include "image.hpp"
#include <opencv2/opencv.hpp>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Image::Image() {}

cv::Mat Image::load_image(std::string filepath) {
    cv::Mat image = cv::imread(filepath, cv::IMREAD_COLOR);
    if (image.empty()) {
        cout << "Error: no image at given filepath" << endl;
    }
    return image;
}

vector<vector<int>> Image::pixels_to_binary(cv::Mat pixels) {
    vector<vector<int>> binary_matrix(pixels.rows, vector<int>(pixels.cols));
    for (int i = 0; i < pixels.rows; i++) {
        for (int j = 0; j < pixels.cols; j++) {
            int pixel = pixels.at<int>(i, j);
            string binary = bitset<8>(pixel).to_string(); 
            binary_matrix[i][j] = stoi(binary);
        }
    }
    return binary_matrix;
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