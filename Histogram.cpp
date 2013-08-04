/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/**
 * main Function
 */
int main( int argc, char** argv )
{
	Mat src, dst;

	/// Load image
	src = imread("./Images/lena.png", 1);

	if( !src.data )
	{ 
		cout << "Image is Empty!!!" << endl;
		return -1; 
	}

	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	
	/** @Func : split() **/
	// Split image channels. 
	split( src, bgr_planes );

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 } ;
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;
	
	/** @Func : calcHist() **/
	/// Compute the histograms:
	calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound( (double) hist_w/histSize );

	Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
	
	/** @Func : normalize() **/
	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

	/// Draw for each channel
	for( int i = 1; i < histSize; i++ )
	{
	  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
					   Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
					   Scalar( 255, 0, 0), 2, 8, 0  );
	  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
					   Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
					   Scalar( 0, 255, 0), 2, 8, 0  );
	  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
					   Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
					   Scalar( 0, 0, 255), 2, 8, 0  );
	}
	
	// create a window to display the image
	namedWindow( "Color Image", CV_WINDOW_AUTOSIZE);
	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );	
	
	/// Display
	imshow("calcHist Demo", histImage );
	imshow( "Color Image", src);

	waitKey(0);

	return 0;
}
