/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */

// Change Brightness & Contras of Image
// OpenCV Headers
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

double alpha; 	// < Simple contrast control 
int beta; 		// < Simple brightness control

int main( int argc, char** argv )
{
	/// Read image given by user
	Mat image = imread("./Images/lena.png");
	
	// Create image to store New Image & assign it with value Zero.
	Mat new_image = Mat::zeros( image.size(), image.type() );

	/// Initialize values
	cout << " Basic Linear Transforms " << endl;
	cout <<"-------------------------" << endl;
	cout <<"* Enter the alpha value (Float) [1.0 - 3.0]: "; cin>> alpha;
	cout <<"* Enter the beta value (Int) [0 - 100]: "; cin>> beta;

	/// Do the operation new_image(i,j) = alpha*image(i,j) + beta
	for( int y = 0; y < image.rows; y++ )
	{ 
		for( int x = 0; x < image.cols; x++ )
		{ 
			for( int c = 0; c < 3; c++ )
			{
				new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
			}
		}
	}

	/// Create Windows
	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	/// Show stuff
	imshow("Original Image", image);
	imshow("New Image", new_image);

	/// Wait until user press some key
	waitKey(0);
	return 0;
}

