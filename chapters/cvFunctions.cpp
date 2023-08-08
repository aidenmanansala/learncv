// Getting familiar with some of the fundamental openCV functions

// Learning to load media for use w/ openCV

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "shapes.jpeg";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    // openCV uses BGR rather than RGB
    cvtColor(img, imgGray, COLOR_BGR2GRAY); // take img, cvt color to gray, put it in imgGray matrix
    GaussianBlur(img, imgBlur, Size(7, 7), 5, 0); // Gaussian kernal size, Gaussian deviation
    Canny(imgBlur, imgCanny, 50, 150); // 50 & 150 are the hysteresis edge thresholds (Canny = edge detection algo.)

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); // creates a kernel for dilation
    dilate(imgCanny, imgDil, kernel); // dilate edge lines from the canny algo (can be applied to anything)
    erode(imgDil, imgErode, kernel); // erode the dilated edges

    imshow("image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDil);
    imshow("Image Erosion", imgErode);
    waitKey(0);
} 