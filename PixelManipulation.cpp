/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */
 
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void thresholding(cv::Mat &aImage, uchar aThreshValue)
{
    // Number of Rows in Image(Height)
	int numberRows = aImage.rows;

    // Number of Cols in Image(Width)
	int numberCols = aImage.cols;

    for(int j = 0; j < numberRows; j++)
        for(int i = 0; i < numberCols; i++)
        {
            if (aImage.channels() == 1)
            {
                // gray-level image
                // Get value of individual pixel
                uchar tValue = aImage.at<uchar>(j,i);

                if(tValue > aThreshValue)
                {
                // If the pixel value is greater than threshold value then make it WHITE
                    aImage.at<uchar>(j,i)= 255;
                }
            }
            else if (aImage.channels() == 3)
            {
                // color image
                // Sum of Red, Green & Blue components of the pixel
                int tSum = aImage.at<Vec3b>(j,i)[0] + aImage.at<Vec3b>(j,i)[1] + aImage.at<Vec3b>(j,i)[2];
                uchar averageValue = static_cast<uchar>(tSum/3);

                if(averageValue > aThreshValue)
                {
                    // If average value of R,G,B components of the pixel is greater than threshold value then make that pixel WHITE
                    aImage.at<Vec3b>(j,i)[0]= 255; // Blue component
                    aImage.at<Vec3b>(j,i)[1]= 255; // Green component
                    aImage.at<Vec3b>(j,i)[2]= 255; // Red component
                }
            }
        }
}

int main()
{
    // read the image
	Mat Image=imread("./Images/Gray.png");

    // process the image
	thresholding(Image, 125);

    // display the image
	namedWindow("TestImage");
	imshow("TestImage",Image);
	waitKey(0);

	return 0;
}

