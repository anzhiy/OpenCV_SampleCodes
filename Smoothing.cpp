/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */
 
// Smoothing of Image
#include <iostream>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"

using namespace std;
using namespace cv;

/// Global Variables
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
char window_name[] = "Smoothing Demo";

/// Function headers
int display_caption( char* caption );
int display_dst( int delay );


/**
 * function main
 */
int main( int argc, char** argv )
{
	namedWindow( window_name, CV_WINDOW_AUTOSIZE );

	/// Load the source image
	src = imread( "./Images/lena.png", 1 );

	if( display_caption( "Original Image" ) != 0 ) 
	{ 
		return 0; 
	}

	dst = src.clone();
	if( display_dst( DELAY_CAPTION ) != 0 ) 
	{ 
		return 0; 
	}

	/// Applying Homogeneous blur
	if( display_caption( "Homogeneous Blur" ) != 0 ) 
	{ 
		return 0; 
	}

	for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
	{ 
		/** @Func : blur() **/
		blur( src, dst, Size( i, i ), Point(-1,-1) );
		
		// Display Blured Image.
		if( display_dst( DELAY_BLUR ) != 0 ) 
		{ 
			return 0; 
		} 
	}

	/// Applying Bilateral Filter
	if( display_caption( "Bilateral Blur" ) != 0 ) 
	{ 
		return 0; 
	}

	for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
	{ 
		/** @Func : bilateralFilter() **/
		bilateralFilter( src, dst, i, i*2, i/2 );
		
		// Display Blured Image.
		if( display_dst( DELAY_BLUR ) != 0 ) 
		{ 
			return 0; 
		} 
	}

	/// Wait until user press a key
	display_caption( "End: Press a key!" );

	waitKey(0);

	return 0;
}

/**
 * display_caption
 */
int display_caption( char* caption )
{
	dst = Mat::zeros( src.size(), src.type() );
	putText( dst, caption,
		   Point( src.cols/4, src.rows/2),
		   CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );
	
	// Show Caption
	imshow( window_name, dst );
	int c = waitKey( DELAY_CAPTION );
	if( c >= 0 ) 
	{ 
		return -1; 
	}
	return 0;
}

/**
 * display_dst
 */
int display_dst( int delay )
{
	// Show destination Image.
	imshow( window_name, dst );
	int c = waitKey ( delay );
	if( c >= 0 ) 
	{ 
		if(c == 'p')
		{
			c = 0;
			while( c != 'm')
			{
				c = waitKey(25);
			}
		}
	}
	return 0;
}
