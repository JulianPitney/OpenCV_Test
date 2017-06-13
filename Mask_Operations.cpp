#include<cv.h>
#include<highgui.h>


using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
	//Manual Contrast enhancement using mask matrix
	Mat inputImage;
	Mat outputImage;


	// Read image, check that it's uchar, display it and wait
	inputImage = imread(argv[1], 1);
	CV_Assert(inputImage.depth() == CV_8U);
	namedWindow("displayImage", CV_WINDOW_AUTOSIZE);
	imshow("displayImage", inputImage);
	waitKey(0);


	// Setup blank output image and get dimmensions 
	outputImage.create(inputImage.size(), inputImage.type());
	const int nChannels = outputImage.channels();
	const int nRows = outputImage.rows;


	// Loop over all rows of inputImage, grabbing previous,current and next row
	// each iteration. 
	for(int r = 1; r < nRows - 1; r++)
	{
		const uchar* previous = inputImage.ptr<uchar>(r - 1);
		const uchar* current = inputImage.ptr<uchar>(r);
		const uchar* next = inputImage.ptr<uchar>(r + 1);

		
		// Get current row of output image
		uchar* output = outputImage.ptr<uchar>(r);


		for(int c = nChannels; c < nChannels * (inputImage.cols - 1); c++)
		{
			// Apply contrast enhancement formula to each pixel of inputImage
			// and set result to corresponding pixel of outputImage
			*output++ = saturate_cast<uchar>(5 * current[c] - current[c - nChannels]				- current[c + nChannels] - previous[c] - next[c]);
		}
	}


	// There are points where the above formula is undefined (borders)
	// So we'll just set these pixels to 0
	outputImage.row(0).setTo(Scalar(0)); // top row
	outputImage.row(outputImage.rows - 1).setTo(Scalar(0)); // bottom row
	outputImage.col(0).setTo(Scalar(0)); // left border
	outputImage.col(outputImage.cols - 1).setTo(Scalar(0)); // right border
	
	imshow("displayImage",outputImage);
	waitKey(0);





	// The above method is educational and should not be used.
	// Instead, OpenCV provides the filter2D function for such
	// operations. 

	inputImage = imread(argv[1], 1);

	// Create mask/kernel for filter operation
	Mat mask = (Mat_<char>(3,3) << 0, -1,  0,
				      -1,  5, -1,
				       0, -1,  0);

	// Supply required information to filter2D()
	filter2D(inputImage,outputImage,inputImage.depth(),mask);

	imshow("displayImage",outputImage);
	waitKey(0);

	return 0;
}
