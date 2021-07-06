#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void main() {
	Mat img(512, 512, CV_8UC3, Scalar(500, 500, 500));
	circle(img, Point(256, 256), 200, Scalar(200, 0, 200), FILLED);
	rectangle(img, Point(150, 200), Point(400, 250), Scalar(0, 0, 300), FILLED);
	line(img, Point(150, 240), Point(400, 240), Scalar(0, 0, 300), 2);

	putText(img, "Satvik Learning OPENCV", Point(160, 230), FONT_HERSHEY_PLAIN, 1, Scalar(200, 200, 200));

	imshow("Image", img);

	waitKey(0);
}