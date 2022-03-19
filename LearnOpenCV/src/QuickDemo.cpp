#include <QuickDemo.h>

void QuickDemo::QuickDemoPix(cv::InputArray input)
{
	cv::Mat mat = cv::Mat::zeros(cv::Size(8, 8), CV_8UC3);
	std::cout << mat << std::endl;
	//mat = cv::Scalar(0, 0, 255);//g-b-r
	cv::imshow("quick", mat);
	cv::waitKey(0);
}

