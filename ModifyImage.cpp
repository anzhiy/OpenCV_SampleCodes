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
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

// namespaces declaration
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    // create variables to store the images
    Mat org, resized,saved;

    // open the image and store it in the ‘org’ variable
    // Replace the path with where you have downloaded the image
    org = imread("./Images/lena.png");

    //Create a window to display the image
    namedWindow("Original Image",CV_WINDOW_AUTOSIZE);

    //display original image
    imshow("Original Image",org);
	
	/** @Func : resize() **/
    //resize the image
    resize(org, resized, Size(),0.7,0.8,INTER_NEAREST);
    
	// Display Resized Image
	namedWindow("Resized Image",CV_WINDOW_AUTOSIZE);
    imshow("Resized Image",resized);
	
	/** @Func : imwrite() **/
    //save the image
    //Replace <path> with your desired location
    imwrite("./Images/saved.png",resized);
    namedWindow("Image saved",CV_WINDOW_AUTOSIZE);
    
	// Read already Saved Image
	saved = imread("./Images/saved.png");

	// Display Saved Image
    imshow("Image saved",saved);

    //wait for a keystroke
    waitKey(0);
    return 0;
}
