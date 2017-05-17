#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "fpdw_detector.h"
#include "imagemanager.h"


int main(int argc, char **argv)
{
    cv::Mat image;
    //= cv::imread(argv[2]);
    ImageManager img(argv[2]);
    fpdw::detector::FPDWDetector detector(argv[1], 30.);
    std::ofstream myfile ("detection.txt");
    
    for(uint i = 0; i < img.getEnd(); ++i)
    {
      image = cv::imread(img.next(1));
      cv::resize(image, image, cv::Size(image.cols * 1.5, image.rows * 1.5));
      detector.process(image);
      std::vector<cv::Rect> rect = detector.getBBoxes();
      myfile << (i+1) << "," << rect.size() << ",";
      uint j = 0;
      for(const auto &r : rect)
      {
	cv::rectangle(image, r, cv::Scalar(255, 0, 0), 2);
	myfile << cvRound(r.x / 1.5) << "," << cvRound(r.y / 1.5) << "," << cvRound(r.width / 1.5) << "," << cvRound(r.height / 1.5);
	if(j != rect.size() - 1)
	  myfile << ",";
	++j;
      }
      myfile << std::endl;
      cv::resize(image, image, cv::Size(image.cols / 1.5, image.rows / 1.5));
      cv::imshow("image", image);
      cv::waitKey(30);
    }
    
    myfile.close();
    return 0;
}
