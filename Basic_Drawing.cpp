#include<cv.h>
#include<highgui.h>
#include<iostream>




using namespace std;
using namespace cv;

void DrawEllipse(Mat inputImg, double angle)
{
	int thickness = 2;
	int lineType = 0;
	
	ellipse(inputImg,
		Point( 1920/2.0, 1080/2.0),
		Size(1920/4.0, 1080/16.0),
		angle,
		0,
		360,
		Scalar(255,0,0),
		thickness,
		lineType);
}


void DrawCircle(Mat inputImg, Point center)
{
	int thickness = -1;
	int lineType = 0;
	
	circle(inputImg, center, 1920/32.0,Scalar(0,0,255), thickness, lineType);
	
}

int main(int argc, char** argv)
{
	Mat image1 = Mat::zeros(1080,1920,CV_8UC3);
	Mat image2 = Mat::zeros(1920,1080,CV_8UC3);

	DrawEllipse(image1,90);
	DrawEllipse(image1,0);
	DrawEllipse(image1,45);
	DrawEllipse(image1,-45);

	Point center;
	center.x=1920/2.0;
	center.y=1080/2.0;
	DrawCircle(image1, center);
	
	namedWindow("output",1);
	imshow("output",image1);
	waitKey(0);

	return 0;
}
