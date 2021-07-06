#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>\

//still need to work on overlapping shapes and 3d.
//need to work on parallelogram, rhombus, trapezium, and other uncommon shapes

using namespace cv;
using namespace std;

void getContours(Mat imgDil, Mat img) {
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scale(0,0,255),2);
	vector<vector<Point>>conPoly(contours.size());
	vector<Rect>BoundRect(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;
		string objectType;
		
		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.008 * peri, true);
			cout << conPoly[i].size() << endl;
			BoundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4)
			{
				float aspRatio = (float)BoundRect[i].width / (float)BoundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 10) { objectType = "Circle"; }
			else if (objCor == 5) { objectType = "Pentagon"; }
			else if (objCor == 6) { objectType = "Hexagon"; }
			else if (objCor == 7) { objectType = "Heptagon"; }
			else if (objCor == 8) { objectType = "Octagon"; }
			else if (objCor == 9) { objectType = "Nanogon"; }
			else if (objCor == 10) { objectType = "Decagon"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, BoundRect[i].tl(), BoundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { BoundRect[i].x,BoundRect[i].y - 5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}

void main() {
	string path = "Resources/new.png";
	Mat img = imread(path);
	Mat imgGray, imgCanny, imgDil, imgBlur;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 1, 0);
	Canny(imgBlur, imgCanny, 100, 100);
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	imshow("Image dia", imgDil);
	waitKey(0);
}