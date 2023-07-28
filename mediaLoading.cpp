#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    // images
    string imagePath = "shapes.jpeg"; // define the path to the image file
    Mat image = imread(imagePath); // store the image data inside a matrix
    imshow("Image", image); // display the matrix, title it "Image"
    waitKey(15000); // wait 15 seconds
    destroyAllWindows(); // close window


    
    // videos
    string videoPath = "zoo.mp4"; // define the path to the video

    // VideoCapture allows us to read frames from the video and work with it frame by frame.
    VideoCapture cap(videoPath); // create a VideoCapture object named 'cap' to open and access the video

    Mat video; // Matrix for video data to be moved into frame by frame

    while(true){ // one iteration of the while loop displays one frame of the video
        cap >> video; // move the frame of the video into the matrix for display

        if(video.empty()){ // if cap put nothing into the matrix, then the video is over - break before segmentation fault.
            break;
        }

        imshow("Video", video); // display the current frame in the matrix
        waitKey(42); // play approx 24 frames per second
    }
    destroyAllWindows();

    
    // webcam
    VideoCapture cam(0); // 0 = id for built-in webcam
    Mat capture;
    
    while(true){
        cam >> capture;
        imshow("Webcam", capture); // will give a segmentation fault if proper access to camera isn't granted
        waitKey(1);
    }
    

    return 0;
}