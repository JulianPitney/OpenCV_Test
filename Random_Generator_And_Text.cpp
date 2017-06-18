#include<core/core.hpp>
#include<imgproc/imgproc.hpp>
#include<highgui/highgui.hpp>
#include<stdio.h>

using namespace cv;



int delay = 5;


static Scalar randomColor(RNG* rng)
{
	int icolor = (unsigned)rng->next();
	return Scalar(icolor&255, (icolor>>8)&255,(icolor>>16)&255);
}

void DrawRandomLines(Mat image, char* windowName, RNG* rng, int cycleLength, int windowHeight, int windowWidth)
{
	int lineType = 8;
	Point pt1, pt2;
	
	for(int i = 0; i < cycleLength; i++)
	{
		pt1.x = rng->uniform(0,windowWidth+1);
		pt1.y = rng->uniform(0,windowHeight+1);
		pt2.x = rng->uniform(0,windowWidth+1);
		pt2.y = rng->uniform(0,windowHeight+1);
	
		line(image, pt1, pt2, randomColor(rng), rng->uniform(1,10), lineType);
		imshow(windowName,image);
		waitKey(delay);
	}

}

void DrawRandomCircles(Mat image, char* windowName, RNG* rng, int cycleLength, int windowHeight, int windowWidth)
{

	for(int i = 0; i < cycleLength; i++)
	{
		Point center;
		center.x = rng->uniform(0,windowWidth+1);
		center.y= rng->uniform(0,windowHeight+1);

		int radius = rng->uniform(1, windowWidth/3);
	
		circle(image, center, radius, randomColor(rng), rng->uniform(-5,6), 8, 0);
		imshow(windowName, image);
		waitKey(delay);
	}
}


int main(int argc, char** argv)
{
	// OpenCV's rng class
	RNG rng (0xFFFFFFFF);
	char* windowName = "Display";
	int windowHeight = 1440;
	int windowWidth = 3400;
	int cycleLength = 100;

	Mat image = Mat::zeros(windowHeight, windowWidth, CV_8UC3);	
	namedWindow(windowName, 1);
	resizeWindow(windowName, windowHeight, windowWidth);
	imshow(windowName, image);
	waitKey(5000);

	DrawRandomLines(image, windowName, &rng, cycleLength,windowHeight, windowWidth);
	DrawRandomCircles(image, windowName, &rng, cycleLength, windowHeight, windowWidth);
	return 0;
}
