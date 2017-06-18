#include<cv.h>
#include<highgui.h>
#include<iostream>


using namespace std;
using namespace cv;


int main( int argc, char** argv)
{
	VideoCapture cap( argv[1]);
	if (!cap.isOpened())
	{
		cout << "Failed to open file input: " << argv[1] << endl;
		return -1;
	}		

	Mat frame;
	for(;;)
	{
		if(!cap.read(frame))
			break;
		
		imshow("window",frame);

		char key = cvWaitKey(10);
		if (key == 27)
			break;
	}

	return 0;
}
