/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */
 
//Edge Detection
// opencv header files
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// namespaces declaration
using namespace cv;
using namespace std;

// create a variable to store the image
Mat image, gray, edge, cedge;
// Threshold value for canny edge detection
int edgeThresh = 25;

int main( int argc, char** argv )
{
    // open the image and store it in the ‘image’ variable
    // Replace the path with where you have downloaded the image
	image=imread("./Images/lena.png", 1);
	
	/** @Func : Mat::create() **/
	// create single channel image to store output gray image
	gray.create(image.rows, image.cols, CV_8UC1);

    // convert RGB image to GrayScale
	cvtColor(image, gray, CV_BGR2GRAY);

    // create image to store final edge detected image.
	cedge.create(gray.size(), gray.type());
	
	/** @Func : Canny() **/
    // Run the edge detector on grayscale image
	Canny(gray,edge,edgeThresh,edgeThresh*3,3);
	cedge = Scalar::all(0);
	image.copyTo(cedge, edge);

	namedWindow("Output Image", CV_WINDOW_AUTOSIZE);

    // display the image in the window created
	imshow("Output Image", cedge);
	waitKey(0);
	return 0;
}
