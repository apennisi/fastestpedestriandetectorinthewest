#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <opencv2/video/video.hpp>

#include "fpdw_detector.h"

#include <media.hpp>

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        std::cout << "Usage:\n";
        std::cout << "./fpdw /path/to/detector/xml /path/to/image/or/video/file\n";
        return EXIT_FAILURE;
    }

    media::MediaWrapper::Ptr media;
    try{
        media = media::MediaFactory::Create(argv[2]);
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    fpdw::detector::FPDWDetector detector(argv[1], 0.0);

    cv::Mat image;
    bool nextImageAvailable = true;
    while(nextImageAvailable)
    {
        nextImageAvailable = media->getImage(image);

        detector.process(image);
        std::vector<cv::Rect> rect = detector.getBBoxes();

        for(const auto &i : rect)
        {
            cv::rectangle(image, i, cv::Scalar(255, 0, 0), 2);
        }

        cv::imshow("image", image);
        media->waitKey();
    }

    return 0;
}
