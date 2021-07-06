#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

float w = 250, h = 350;
Mat matrix, img1, img2, img3, img4;

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path); 

	Point2f src1[4] = { {529,142},{771,192},{405,395} ,{675,458} };
	Point2f dst1[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	Point2f src2[4] = { {776,106},{1018,84},{840,355},{1115,329} };
	Point2f dst2[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h } };

	Point2f src3[4] = { {742,385},{1020,437},{647,709},{967,781} };
	Point2f dst3[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	Point2f src4[4] = { {66,324},{337,279},{92,633},{402,571} };
	Point2f dst4[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src1, dst1);
	warpPerspective(img, img1, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src2, dst2);
	warpPerspective(img, img2, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src3, dst3);
	warpPerspective(img, img3, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src4, dst4);
	warpPerspective(img, img4, matrix, Point(w, h));

	imshow("Image", img);
	imshow("Image 1", img1);
	imshow("Image 2", img2);
	imshow("Image 3", img3);
	imshow("Image 4", img4);
	waitKey(0);

}