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

// namespaces declaration
using namespace cv;
using namespace std;

// create a variable to store the image
Mat image;

int main( int argc, char** argv )
{
    // open the image and store it in the ‘image’ variable
    // Replace the path with where you have downloaded the image
	/** @Func : imread() **/
    image = imread("./Images/lena.png");
	
	/** @Func : namedWindow() **/
    // create a window to display the image
    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
    
	/** @Func : imshow() **/
	// display the image in the window created
    imshow( "Display window", image );
    
	/** @Func : waitKey() **/
	// wait for a keystroke
    waitKey(0);
    
	return 0;
}
