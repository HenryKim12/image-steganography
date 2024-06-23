#include <opencv2/opencv.hpp>
#include "encoder.hpp"
#include "decoder.hpp"
#include "./util/image.hpp"

using namespace std;

int main() {
    Encoder *encoder = new Encoder();
    encoder->encode();


    cout << "hello world" << endl;
    return 0;
}
