/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */
 
// Video Processing
// opencv header files
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// namespaces declaration
using namespace cv;
using namespace std;

Mat Image;
Mat gray;

void help()
{
	printf("Video Capture Device Test:\n");
	printf("Press q: to quite the program\n");
}

int main( int argc, char** argv )
{
	char key = 0;
	
	/** @Func : VideoCapture() **/
    // check for failure
	VideoCapture capture(0);
	if (!capture.isOpened()) {
		printf("Failed to open a video device or video file!\n");
		return 1;
	}

    // Set Capture device properties.
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

	namedWindow("Camera Video", CV_WINDOW_AUTOSIZE);
	namedWindow("Processed Video", CV_WINDOW_AUTOSIZE);

	while( key != 'q')
	{
		capture >> Image;
		
		cvtColor(Image, gray, CV_BGR2GRAY);
		
		imshow("Camera Video",Image);
		imshow("Processed Video", gray);
		
		key = waitKey(25);
	}
	return 0;
}
