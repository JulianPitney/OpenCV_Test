#include<cv.h>
#include<highgui.h>
#include<iostream>

using namespace std;
using namespace cv;


int main(int argc, char* argv[]){


	// Load image from input path
	Mat image;
	image = imread( argv[1], 1);

	if (argc != 2 || !image.data)
	{
		cout << "No image data \n";
		return -1;
	}

	// Display image
	namedWindow("Before Image", CV_WINDOW_AUTOSIZE);
	imshow("Before Image", image);

	waitKey(0);


	// Setup lookup table for colour reduction of image
	uchar table[256];
	int reductionSize = 70;
	for (int i = 0; i < 256; i++)
	{
		table[i] = (uchar)(reductionSize * (i/reductionSize)); // Reduced value for each colour and store in table
	}
		
	int channels = image.channels();
	int rows = image.rows;
	int cols = image.cols * channels;
	
	uchar* p; // Data pointer
	p = image.data; // The "data" member of Mat holds a pointer to the first row, first column of the image data

	// Loop across rows and columns and set each pixel to appropriate value from the lookup table
	// Note: Don't actually use the below method to perform lookup table transforms on arrays,
	//	instead use the OpenCV LUT() function.
	for (int i = 0; i < rows; i++)
	{
		p = image.ptr<uchar>(i); // Set data pointer
		for(int x = 0; x < cols; x++)
		{
			p[x] = table[p[x]];
		}

		cout << endl << endl;
	}


	cout << image.isContinuous() << endl; // Check if rows of image matrix are stored successively in memory
	namedWindow("Reduced Image", CV_WINDOW_AUTOSIZE);
	imshow("Reduced Image", image);
	waitKey(0);


	// LUT() method for lookup table array transform.
	// Use this for lookup table array transforms (it's way faster and multithreaded)
	Mat LUTtable(1, 256, CV_8U); // Setup LUT lookup table
	Mat output;
	LUT(image, LUTtable, output); 

	cout << output.isContinuous() << endl; // Check if rows of image matrix are stored successively in memory
	namedWindow("LUTReduced Image", CV_WINDOW_AUTOSIZE);
	imshow("LUTReduced Image", output);



	waitKey(0);







	return 0;
}
