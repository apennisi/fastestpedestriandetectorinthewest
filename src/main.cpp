#include <iostream>
#include <opencv2/opencv.hpp>
#include "fpdw_detector.h"
#include <QVector>
#include <QtXml>

int main(int argc, char **argv)
{
    bool failure=false;

    if(argc!=4)
    {failure=true;}

    if(!failure)
    {
        cv::Mat image = cv::imread(argv[2]);

        fpdw::detector::FPDWDetector detector(argv[1], QString(argv[3]).toDouble());

        detector.process(image);
        std::vector<cv::Rect> result = detector.getBBoxes();


        QDomDocument outputXML;
        QDomElement objects = outputXML.createElement("Result");
        outputXML.appendChild(objects);
        for(int i = 0; i < result.size(); i++)
        {
            QDomElement boundingBox = outputXML.createElement("Rectangle");
            boundingBox.setAttribute("x", QString::number(result.at(i).x));
            boundingBox.setAttribute("y", QString::number(result.at(i).y));
            boundingBox.setAttribute("w", QString::number(result.at(i).width));
            boundingBox.setAttribute("h", QString::number(result.at(i).height));
            objects.appendChild(boundingBox);
        }

        std::cout<<outputXML.toString().toStdString();
    }
    else
    {
        std::cout<<"wrong arg list. given:\n";
        for(int i=0;i<argc;i++)
        {std::cout<<argv[i];}
        std::cout<<"\nShould be program image detector";
    }

    return 0;
}
