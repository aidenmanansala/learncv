// Detecting colors

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "assets/shapes.jpeg";
    Mat img = imread(path);
    Mat imgHSV; // Hue Saturation Value
    Mat mask;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    int hmin = 0, smin = 50, vmin = 75; // Hue minimum, Saturation minimum, Value minimum
    int hmax = 50, smax=400, vmax=350; // Hue maximum, Saturation maximum, Value maximum 

    namedWindow("Trackbars");
    createTrackbar("Hue Min", "Trackbars", &hmin, 50); // 179 is the max position of the slider
    createTrackbar("Hue Max", "Trackbars", &hmax, 75);
    createTrackbar("Saturation Min", "Trackbars", &smin, 75);
    createTrackbar("Saturation Max", "Trackbars", &smax, 500);
    createTrackbar("Value Min", "Trackbars", &vmin, 100);
    createTrackbar("Value Max", "Trackbars", &vmax, 400);    

    while(true){ // loop the through the values, conversions, and display in real time to represent the inputted track values
        cout << hmin << " " << hmax << endl;
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);


        inRange(imgHSV, lower, upper, mask); // looking for anything in the range of color, put it in mask

        imshow("Shapes", img);
        imshow("Shapes HSV", imgHSV);
        imshow("Shapes Mask", mask);

        waitKey(1); // use a 1 millisecond delay rather than 0, otherwise loop would get stuck here infinitely
    }

    return 0;
}