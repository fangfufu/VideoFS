/**
 * \file VideoWriter.cpp
 * \brief VideoWriter class implementation
 * \author Fufu Fang
 * \date 2024
 * \copyright SPDX-License-Identifier:  GPL-3.0-or-later
 */

#ifndef VideoWriter_HPP
#define VideoWriter_HPP

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class VideoWriter {
public:
    VideoWriter(const std::string& filename,
        int video_width,
        int video_height,
        int fps,
        int macroblock_size,
        int frame_repeat);

    ~VideoWriter();

    const std::string filename;
    const unsigned int video_width;
    const unsigned int video_height;
    const unsigned int fps;
    const unsigned int macroblock_size;
    const unsigned int frame_repeat;

    /**
     * \brief Write data to the frame encoder
     */
    size_t write(const void* ptr, size_t size, size_t nmemb);

protected:
    // Protected members and functions here

private:
    cv::VideoWriter video_writer;
};
#endif