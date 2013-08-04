/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */

// Image Conversion
// opencv header files
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// namespaces declaration
using namespace cv;
using namespace std;

// create a variable to store the image
Mat image;
Mat gray;
Mat hsv;

int main(int argc, char** argv )
{
    // open the image and store it in the ‘image’ variable
    // Replace the path with where you have downloaded the image
	image=imread("./Images/lena.png");
	
	/** @Func : create() **/
    // create single channel image to store output grayscale image
	gray.create(image.rows, image.cols, CV_8UC1);
	
	hsv.create(image.rows, image.cols, CV_8UC3);
	
	/** @Func : cvtColor() **/
    // convert RGB image to GrayScale
	cvtColor(image, gray, CV_BGR2GRAY);
	
	cvtColor(image, hsv, CV_BGR2HSV);

    // create a window to display the image
	namedWindow( "Color Image", CV_WINDOW_AUTOSIZE);
	namedWindow("GrayScale Image", CV_WINDOW_AUTOSIZE);
	namedWindow("HSV Image", CV_WINDOW_AUTOSIZE);

    // display the image in the window created
	imshow( "Color Image", image);
	imshow("GrayScale Image", gray);
	imshow("HSV Image", hsv);

    // wait for a keystroke
	waitKey(0);
	return 0;
}
