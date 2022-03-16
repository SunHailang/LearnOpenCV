<<<<<<< HEAD
ï»¿#include <iostream>
//#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <cmath>

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

#define INPUT_VIDEO "nvcamtest_17723_s00_00000.mp4"
#define OUT_VIDEO "nvcamtest_out.mp4"

void rescaleFrame(cv::InputArray src, cv::OutputArray dst, float scale = 0.75)
{
	cv::resize(src, dst, cv::Size(0, 0), scale, scale);
}
=======
#include <iostream>
//#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2



int main(int argc, char** argv)
{
	std::cout << "OpenCV Hello World!" << std::endl;
<<<<<<< HEAD

	cv::Mat mat = cv::imread("0116.jpg");
	cv::VideoCapture inVideo = cv::VideoCapture(INPUT_VIDEO);
	double frame_num = inVideo.get(cv::CAP_PROP_FRAME_COUNT);
	double video_width = inVideo.get(cv::CAP_PROP_FRAME_WIDTH);
	double video_height = inVideo.get(cv::CAP_PROP_FRAME_HEIGHT);
	double fourcc = inVideo.get(cv::CAP_PROP_FOURCC);
	double fps = inVideo.get(cv::CAP_PROP_FPS);

	std::cout << "width:" << video_width << " - height:" << video_height << " - fourcc:" << fourcc << " - fps:" << fps << std::endl;

	cv::VideoWriter outVideo = cv::VideoWriter(OUT_VIDEO, int(fourcc), fps/4, cv::Size(1920,1080));

	//cv::Mat
	cv::Scalar lower_blue = cv::Scalar(0, 43, 46);
	cv::Scalar upper_blue = cv::Scalar(10, 255, 255);
	cv::Mat kernel1 = cv::Mat::ones(cv::Size(13, 13), CV_8UC1);
	cv::Mat kernel2 = cv::Mat::ones(cv::Size(7, 7), CV_8UC1);
	cv::Mat kernel3 = cv::Mat::ones(cv::Size(37, 37), CV_8UC1);
	// è®°å½• run_time è¿è¡Œæ—¶é—´
	//clock_t begin_time, end_time;
	int index = 0;
	while (true)
	{
		cv::Mat frame;
		if (inVideo.read(frame))
		{

			cv::Mat gray;
			cv::cvtColor(frame, gray, cv::COLOR_RGB2GRAY);
			cv::Mat blur;
			cv::GaussianBlur(gray, blur, cv::Size(5, 5), 0);
			cv::Mat canny;
			cv::Canny(blur, canny, 50, 150);
			cv::Mat result;
			rescaleFrame(blur, result, 0.5);
			cv::imshow("result", result);
			

			cv::Mat hsv;
			cv::cvtColor(frame, hsv, cv::COLOR_RGB2HSV);
			cv::Mat hsvDst;
			rescaleFrame(hsv, hsvDst, 0.5);
			cv::imshow("hsv", hsvDst);
			cv::waitKey(10);
			continue;
			cv::Mat mask;
			cv::inRange(hsv, lower_blue, upper_blue, mask);
			//cv::Mat maskDst;
			//rescaleFrame(mask, maskDst, 0.5);
			//cv::imshow("mask", maskDst);
			cv::Mat closing1;
			cv::morphologyEx(mask, closing1, cv::MORPH_CLOSE, kernel1);
			//cv::Mat closing1Dst;
			//rescaleFrame(closing1, closing1Dst, 0.5);
			//cv::imshow("closing1", closing1Dst);
			//cv::waitKey(10);
			//continue;
			cv::Mat open;
			cv::morphologyEx(closing1, open, cv::MORPH_OPEN, kernel2);
			//cv::Mat openDst;
			//rescaleFrame(open, openDst, 0.5);
			//cv::imshow("open", openDst);
			//cv::waitKey(10);
			//continue;
			cv::Mat closing2;
			cv::morphologyEx(open, closing2, cv::MORPH_CLOSE, kernel3);
			//cv::Mat closing2Dst;
			//rescaleFrame(closing2, closing2Dst, 0.5);
			//cv::imshow("closing2", closing2Dst);
			//cv::waitKey(10);
			//continue;
			cv::Mat dilation;
			cv::dilate(closing2, dilation, kernel2);
			cv::Mat roi = closing2(cv::Rect(0, 580, 1920, 500));
			cv::Mat roiDst;
			rescaleFrame(roi, roiDst, 0.5);
			cv::imshow("roi", roiDst);
			cv::line(frame, cv::Point(0, 1000), cv::Point(1920, 1000), cv::Scalar(0, 255, 0), 2);
			std::vector<std::vector<cv::Point>> contours;
			std::vector<cv::Vec4i> hierarchy;
			cv::findContours(roi, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
			if (contours.size() > 0)
			{
				std::vector<cv::Point> cnt = contours.at(0);
				cv::Rect rect = cv::boundingRect(cnt);
				cv::line(frame, cv::Point(rect.x + int(rect.width / 2), 980),
					cv::Point(rect.x + int(rect.width / 2), 1020),
					cv::Scalar(0, 255, 0), 2);
				int p = rect.x + int(rect.width / 2);

				cv::putText(frame, cv::String("index:" + p), cv::Point(rect.x + int(rect.width / 2) + 1, 999),
					cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);
			}

			cv::namedWindow("frame", cv::WINDOW_FREERATIO);
			cv::imshow("frame", frame);
			outVideo.write(frame);
			cv::waitKey(10);
		}
		else
		{
			break;
		}
	}
	outVideo.release();
	cv::destroyAllWindows();
	return 0;
}


=======
	
	cv::Mat mat = cv::imread("Ëïº£ÀË+2021.09.22.png");

	cv::namedWindow("ÈËÎï");

	cv::imshow("ÈËÎï",mat);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2
