// Warping perspective on images

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

float w = 250, h = 350;
Mat matrix, imgWarp;

int main() {
    string path = "cards.png";
    Mat img = imread(path);

    Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {675, 457}};
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix,Point(w, h));

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
    waitKey(0);

    return 0;
}