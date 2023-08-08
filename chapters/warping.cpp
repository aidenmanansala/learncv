// Warping perspective on images
// Taking images at an angle, and making them have a "birds eye view" perspective

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// it is possible that the dimensions/coordinates will be different across other OS's and software
float w = 140, h = 190;
Mat matrix, imgWarp;

int main() {
    string path = "assets/cards.png";
    Mat img = imread(path);

    Point2f src[4] = {{299, 77}, {444, 110}, {225, 225}, {391, 263}};
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix,Point(w, h));

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
    waitKey(0);

    return 0;
}