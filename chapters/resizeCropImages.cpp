// Learning to resize and crop images

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    string path = "shapes.jpeg";
    Mat img = imread(path);
    Mat imgResize, imgScale, imgCrop;

    //cout << img.size() << endl;

    // shapes.jpeg original size is 522 x 522
    resize(img, imgResize, Size(422, 422));
    resize(img, imgScale, Size(), 0.5, 0.5);

    Rect roi(100, 100, 300, 250); // region of interest for cropping
    imgCrop = img(roi);

    imshow("Image", img);
    imshow("Image Resized", imgResize);
    imshow("Image Scaled", imgScale);
    imshow("Image Croped", imgCrop);

    waitKey(0);

    return 0;
}