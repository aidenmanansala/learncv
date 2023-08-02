// Adding

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){

    // Blank Image
    Mat img(512,512, CV_8UC3, Scalar(255, 255, 255)); // CV_8UC3 is 8 bit unsigned (0-255) image w/ 3 color channel (BGR) 

    circle(img, Point(256, 256), 155, Scalar(255, 0, 0), 10); // you can fill the circle by stating the thickness as FILLED
    rectangle(img, Point(130, 266),  Point(382, 286), Scalar(0, 0, 0), 3);
    line(img, Point(130, 296), Point(382, 296), Scalar(0, 0, 0), 2);

    putText(img, "This is some text.", Point(137, 262), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 255));

    imshow("Image", img);
    waitKey(0);

    return 0;
}