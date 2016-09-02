//
// Created by yildirim on 02.09.16.
//

#ifndef FPDW_MEDIA_H
#define FPDW_MEDIA_H

#include <fstream>
#include <stdexcept>

namespace media {

    class ExtensionFactory
    {
    public:
        static std::vector<std::string> GetImageExtensions()
        {
            std::vector<std::string> extensions{ "jpg", "bmp", "jpeg", "tiff", "png", "tif" };
            return extensions;
        }
    };

    bool isAmongSetOfStrings(const char *extension, std::vector<std::string> str_array) {
        return std::find(str_array.begin(), str_array.end(), extension) != str_array.end();
    }

    bool file_exists(const std::string& name)
    {
        std::ifstream f(name.c_str());
        if (f.good()) {
            f.close();
            return true;
        } else {
            f.close();
            return false;
        }
    }

    bool isImageFile(const char *filename) {
        std::string str_filename(filename);
        size_t index = str_filename.find_last_of(".");

        if (index == std::string::npos) {
            return false;
        }

        std::string ext = str_filename.substr(index + 1, 4);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        if (!isAmongSetOfStrings(ext.c_str(), ExtensionFactory::GetImageExtensions()))
            return false;

        return true;
    }

    class MediaWrapper {
    public:
        virtual bool getImage(cv::Mat& image) = 0;
        virtual bool waitKey() = 0;

    public:
        typedef std::shared_ptr<MediaWrapper> Ptr;
    };

    class VideoMedia : public MediaWrapper {
    public:
        VideoMedia(const char *filename) {
            if(!cap.open(filename))
                throw std::runtime_error("Cannot start video stream!");
        }

        bool getImage(cv::Mat& image) {
            cap >> image;
            return !image.empty();
        }

        bool waitKey()
        {
            cv::waitKey(20);
        }

    private:
        cv::VideoCapture cap;

    public:
        typedef std::shared_ptr<VideoMedia> Ptr;
    };

    class ImageMedia : public MediaWrapper {
    public:
        ImageMedia(const char *filename) : filename(filename){
            if(!file_exists(filename))
                throw std::runtime_error("Image file does not exist");
        }

        bool getImage(cv::Mat& image) {
            image = cv::imread(filename);
            return false;
        }

        bool waitKey()
        {
            cv::waitKey(0);
        }

    private:
        const char* filename;

    public:
        typedef std::shared_ptr<ImageMedia> Ptr;
    };

    class MediaFactory {
    public:
        static MediaWrapper::Ptr Create(const char *filename) {
            bool isImage = isImageFile(filename);
            if (isImage)
                return std::make_shared<ImageMedia>(filename);
            else
                return std::make_shared<VideoMedia>(filename);
        }
    };
}

#endif //FPDW_MEDIA_H
