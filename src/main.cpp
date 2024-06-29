#include <opencv2/opencv.hpp>
#include "encoder.hpp"
#include "decoder.hpp"
#include "./util/image.hpp"

int main() {
    Image *image_helper = new Image();
    cv::Mat image_matrix = image_helper->load_image("../img/squirtle.jpeg");

   /*
   remove lsb from each pixel in image data
   
   */


    std::cout << "hello world";
    return 0;
}
