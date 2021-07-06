#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std; 

void main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErod;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	
	Canny(img, imgCanny, 100, 100);

	dilate(imgCanny, imgDil, kernel);

	erode(imgDil, imgErod, kernel);
	
	imshow("Image", imgGray);
	imshow("ImageBlur", imgBlur);
	imshow("ImageCanny", imgCanny);
	imshow("ImageDia", imgDil);
	imshow("ImageErod", imgErod);
	waitKey(0);
}