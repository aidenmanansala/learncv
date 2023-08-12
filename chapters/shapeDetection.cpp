// Detecting shapes and contours

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil, Mat img) {
    vector<vector<Point>> contours; // vectors of points that stores the points found in the image
    vector<Vec4i> hierarchy; // hierarchy vector desribes the relationship between the points **************

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // Find the contours is in the dilated image and store info in the vectors

    vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	 

    for(int i = 0; i < contours.size(); i++){ // Loop through each point in the contours vector
    int area = contourArea(contours[i]); // Calculate the area of the current contour

	string objectType; // Initialize a variable to store the type of object

	if (area > 1000) // If the contour area is larger than 1000
	{
		float peri = arcLength(contours[i], true); // Calculate the perimeter of the contour
		approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true); // Approximate the contour with fewer points
		cout << conPoly[i].size() << endl; // Print the number of points in the approximated contour
		boundRect[i] = boundingRect(conPoly[i]); // Create a bounding rectangle around the approximated contour
		
		int objCor = (int)conPoly[i].size(); // Get the number of corners in the approximated contour

		if (objCor == 3) { objectType = "Tri"; } // If the contour has 3 corners, it's a triangle
		else if (objCor == 4)
		{ 
			float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height; // Calculate the aspect ratio of the bounding rectangle
			cout << aspRatio << endl; // Print the aspect ratio
			if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; } // If aspect ratio is close to 1, it's a square. Otherwise, it's a rectangle
			else { objectType = "Rect";}
		}
		else if (objCor > 4) { objectType = "Circle"; } // If the contour has more than 4 corners, it's a circle

		drawContours(img, conPoly, i, Scalar(255, 0, 255), 2); // Draw the approximated contour
		rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5); // Draw a rectangle around the object
		putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN,1, Scalar(0, 69, 255), 2); // Display the object type as text
	}
}


}

int main() {
    string path = "assets/shapes.jpeg";
    Mat img = imread(path);

    // Preprocessing
    cvtColor(img, imgGray, COLOR_BGR2GRAY); // convert image to grayscale to make it less complex
    GaussianBlur(img, imgBlur, Size(7, 7), 5, 0); // blue the image to get rid of any noise
    Canny(imgBlur, imgCanny, 50, 150); // detect the edges in the image
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel); // dilate the edges incase there are any gaps or imperfections

    getContours(imgDil, img);

    imshow("Image", img);
    waitKey(0);

    return 0;
}