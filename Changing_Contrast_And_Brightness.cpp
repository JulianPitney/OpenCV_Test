#include<cv.h>
#include<highgui.h>
#include<iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	double contrast;
	double brightness;


	Mat inputImage = imread(argv[1], 1);

	// Create and zero output matrix (don't think this is necessary)
	Mat outputImage = Mat::zeros(inputImage.size(), inputImage.type());
	
	cout << "Enter contrast [1.0-3.0]: ";
	cin >> contrast;
	cout << "Enter brightness [0-100]: ";
	cin >> brightness;
	
	// Loop over each row, coloumn and channel of matrix
	for(int r = 0; r < inputImage.rows; r++)
	{
		for(int c = 0; c < inputImage.cols; c++)
		{
			for(int ch = 0; ch < 3; ch++)
			{
				// Assign each value of each pixel in output image to 
				// value returned by brightness + contrast formula
				outputImage.at<Vec3b>(r,c)[ch] = saturate_cast<uchar> (contrast * 
					(inputImage.at<Vec3b>(r,c)[ch] ) + brightness);
			}
		}
	}


	namedWindow("image", 1);
	imshow("image", inputImage);
	waitKey(0);
	imshow("image", outputImage);
	waitKey(0);
	

	return 0;
}
