/**
 * © Sohil Patel 2013, Some Rights Reserved
 *
 *	This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 * 
 * 
 * */
 
// Image Steganography
// opencv header files
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// namespaces declaration
using namespace cv;
using namespace std;

/*
* Steganograph any two images.
* arg1 : Front Image
* arg2 : Hidden Image
* arg3 : Output Steganographed Image
*/
void steganographMyImage(Mat& aFrontImage, Mat& aHiddenImage, Mat& aStegedImage)
{
    // check for size and type of both the given images
	if(aFrontImage.type() != aHiddenImage.type() || aFrontImage.size() != aHiddenImage.size())
	{
		printf("Given Image types are different \n");
		return;
	}
	int numberRows = aFrontImage.rows;
    // Number of Rows in Image(Height)
	int numberCols = aFrontImage.cols;
    // Number of Cols in Image(Width)
    //create output Image
	aStegedImage.create(numberRows, numberCols, aFrontImage.type());

	Mat tFront_image, tHidden_image;
	Mat front_mask(numberRows, numberCols, aFrontImage.type(), Scalar(0xF0, 0xF0, 0xF0));
	Mat hidden_mask(numberRows, numberCols,aFrontImage.type(), Scalar(0xF0, 0xF0, 0xF0));
	
	/** @Func : bitwise_and() **/
	bitwise_and(aFrontImage, front_mask, tFront_image);
	bitwise_and(aHiddenImage,hidden_mask, tHidden_image);

	for(int j = 0; j < numberRows; j++)
		for(int i = 0; i < numberCols; i++)
		{
			tHidden_image.at<Vec3b>(j,i)[0] = tHidden_image.at<Vec3b>(j,i)[0] >> 4;
			tHidden_image.at<Vec3b>(j,i)[1] = tHidden_image.at<Vec3b>(j,i)[1] >> 4;
			tHidden_image.at<Vec3b>(j,i)[2] = tHidden_image.at<Vec3b>(j,i)[2] >> 4;
		}
	bitwise_or(tFront_image, tHidden_image,aStegedImage);
}

/*
* Decode Steganoraphic images.
* arg1 : Steganograph Image
* arg2 : Front Image
* arg3 : Hidden Image
*/
void getOriginalImages(Mat& aStegedImage, Mat& aFrontImage, Mat& aHiddenImage)
{
	int numberRows = aStegedImage.rows;
    // Number of Rows in Image(Height)
	int numberCols = aStegedImage.cols;
    // Number of Cols in Image(Width)

	aFrontImage.create(numberRows,numberCols, aStegedImage.type());
	aHiddenImage.create(numberRows, numberCols, aStegedImage.type());

	Mat tFront_image,tHidden_image;
	Mat front_mask(numberRows, numberCols, aStegedImage.type(), Scalar(0xF0, 0xF0, 0xF0));
	Mat hidden_mask(numberRows, numberCols, aStegedImage.type(), Scalar(0x0F, 0x0F, 0x0F));

	bitwise_and(aStegedImage, front_mask, aFrontImage);
	bitwise_and(aStegedImage, hidden_mask, aHiddenImage);

	for(int j = 0; j < numberRows; j++)
		for(int i = 0; i < numberCols; i++)
		{
			aHiddenImage.at<Vec3b>(j,i)[0] = aHiddenImage.at<Vec3b>(j,i)[0] << 4;
			aHiddenImage.at<Vec3b>(j,i)[1] = aHiddenImage.at<Vec3b>(j,i)[1] << 4;
			aHiddenImage.at<Vec3b>(j,i)[2] = aHiddenImage.at<Vec3b>(j,i)[2] << 4;
		}
}

int main( int argc, char** argv )
{
	Mat front_image;
	Mat hidden_image;
	Mat steged_image;
    // open the image and store it in the image variable
    // Replace the path with where you have downloaded the image
	front_image = imread("./Images/lena.png");
	hidden_image = imread("./Images/baboon.jpg");

	steganographMyImage(front_image, hidden_image,steged_image);

	imshow("Steganographic Image", steged_image);

	Mat decodedFrontImage;
	Mat decodedHiddenImage;

	getOriginalImages(steged_image, decodedFrontImage, decodedHiddenImage);

	imshow("Front Image", decodedFrontImage);
	imshow("Hidden Image", decodedHiddenImage);

	waitKey(0);
	return 0;
}
