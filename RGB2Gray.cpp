#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;

Mat RGB2Gray(Mat input)
{
	Mat gray(input.rows, input.cols, CV_8UC1);
	for (int i = 0; i < input.rows; i++)
	{
		for (int j = 0; j < input.cols; j++)
		{
			Vec3b pixel = input.at<Vec3b>(i, j);
			gray.at<uchar>(i, j) = (pixel[0] + pixel[1] + pixel[2])/3;
		}
	}
	return gray;
}

int main()
{
	Mat input_img = imread("C:/Users/raj.yadav/Documents/Python Scripts/image_processing/lane.jpg");
	Mat gray_img = RGB2Gray(input_img);
	imshow("gray_image1", gray_img);
	waitKey(0);
}