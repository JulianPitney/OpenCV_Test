#include<highgui/highgui.hpp>
#include<core/core.hpp>
#include<imgproc/imgproc.hpp>


using namespace std;
using namespace cv;



int main(int argc, char** argv)
{
	Mat inputImage = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	Mat paddedImage;
	namedWindow("display", 1);
	resizeWindow("display",1920,1080);
	imshow("display",inputImage);
	waitKey(3000);

	int optimalRows = getOptimalDFTSize(inputImage.rows);
	int optimalCols = getOptimalDFTSize(inputImage.cols);	
	copyMakeBorder(inputImage, paddedImage, 0, optimalRows - inputImage.rows, 0,
			optimalCols - inputImage.cols, BORDER_CONSTANT, Scalar::all(0));

	imshow("display",paddedImage);
	waitKey(3000);

	Mat planes[] = {Mat_<float>(paddedImage), Mat::zeros(paddedImage.size(), CV_32F)};
	Mat complexI;
	merge(planes, 2, complexI);

	imshow("display",complexI);
	
	

	return 0;
}
