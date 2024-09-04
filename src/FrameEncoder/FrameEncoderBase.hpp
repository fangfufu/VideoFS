#ifndef FRAMEENCODERBASE_HPP
#define FRAMEENCODERBASE_HPP

#include <cstddef>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class FrameEncoderBase {
public:
    FrameEncoderBase(const std::string& filename,
                        int video_width, 
                        int video_height, 
                        int fps, 
                        int macroblock_size) : 
                        filename(filename),
                        video_height(video_height),
                        video_width(video_width),
                        fps(fps),
                        macroblock_size(macroblock_size),
                        frame_height(video_height/macroblock_size),
                        frame_width(video_width/macroblock_size),
                        frame_size(frame_height * frame_width) {
        if(!video_writer.open(filename, 
            cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 
            fps, 
            cv::Size(frame_width, frame_height), 
            true)) {
                throw std::runtime_error(
                    "Error: Could not open the video file for writing.");
            }
    }

    /**
     * \brief Destructor
     * \details Closes the video writer if it is open
     */
    virtual ~FrameEncoderBase() {
        if (video_writer.isOpened()) {
            video_writer.release();
        }
    }

    const std::string filename;
    const unsigned int video_width;
    const unsigned int video_height;
    const unsigned int fps;
    const unsigned int macroblock_size;
    const unsigned int frame_width;
    const unsigned int frame_height;
    const unsigned int frame_size;

    /**
     * \brief Write data to the frame encoder
     */
    virtual size_t write(const void *ptr, size_t size, size_t nmemb) = 0;
    

protected:
    // Protected members and functions here

private:
     cv::VideoWriter video_writer;
};
#endif