#include <iostream>
#include <opencv2/opencv.hpp>
#include "fpdw_detector.h"


int main(int argc, char **argv)
{
    cv::Mat image = cv::imread(argv[2]);
    fpdw::detector::FPDWDetector detector(argv[1], 0.);
    
    detector.process(image);
    std::vector<cv::Rect> rect = detector.getBBoxes();

    for(const auto &i : rect)
    {
        cv::rectangle(image, i, cv::Scalar(255, 0, 0), 2);
    }
    
    cv::imshow("image", image);
    cv::waitKey(0);
    return 0;
}
