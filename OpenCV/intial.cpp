#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv; 

void main() {

	VideoCapture cap(0);	
	Mat img;

	while (true) {
		cap.read(img);
		imshow("Webcam", img);
		waitKey(1);
	}
}