#include<cv.h>
#include<highgui.h>
#include<iostream>


using namespace std;
using namespace cv;


int main(int argc, char** argv)
{

	double alpha = 0.5; double beta; double input;
	Mat input1, input2, output;

	
	cout << "Enter alpha [0-1]: ";
	cin >> input;

	if( input  >= 0.0 && input <= 1.0)
	{
		alpha = input;
	}
	else
	{
		cout << "Invalid alpha input \n";
		return -1;
	}

	// Load 2 source images for blending (note they must be same size and type)
	input1 = imread(argv[1], 1);
	input2= imread(argv[2], 1);
	
	if(!input1.data || !input2.data)
	{
		cout << "Error loading input images...\n";
		return -1;	
	}

	namedWindow("linearBlend",1);

	beta = (1.0 - alpha);
	
	// Produces a weighted average of each pixel in the source images
	// and places the result in the output image
	addWeighted(input1, alpha, input2, beta, 0.0, output);
	
	imshow("linearBlend", output);
	waitKey(0);

	return 0;
}
