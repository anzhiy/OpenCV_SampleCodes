/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */

// opencv header files
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

// namespaces declaration
using namespace cv;
using namespace std;

// create a variable to store the image
Mat image;

int main( int argc, char** argv )
{
    // open the image and store it in the ‘image’ variable
    // Replace the path with where you have downloaded the image
    image = imread("./Images/lena.png");
	
	// Display Image Properties.
	cout << "Height of Image : " << image.rows << endl;         					// Number of rows
	cout << "Width of Image : " << image.cols << endl;         						// Number of cols
	cout << "Size of Matrix : " << image.size() << endl;       						// Size of the matrix: Size(cols, rows)
	cout << "Type of Matrix : " << image.type() << endl;							// Type of Matrix
	cout << "Total Number of Channles in Image : " << image.channels() << endl;   	// Number of channels
	cout << "Depth of Matrix Element : " << image.depth() << endl;      			// Depth of matrix element: CV_8U, CV_32F, etc
	cout << "Total number of pixels : " << image.total() << endl;      				// Total number of array elements/pixels

    // create a window to display the image
    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
    
	// display the image in the window created
    imshow( "Display window", image );
    
	// wait for a keystroke
    waitKey(0);
    
	return 0;
}
