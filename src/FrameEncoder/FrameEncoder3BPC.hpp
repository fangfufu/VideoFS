#ifndef FRAMEENCODER3BPC_HPP
#define FRAMEENCODER3BPC_HPP

/**
 * \file FrameEncoder3BPC.hpp
 * \author 2024 Fufu Fang
 * \copyright SPDX-License-Identifier:  GPL-3.0-or-later
 */

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class FrameEncoder3BPC {
public:
    FrameEncoder3BPC(const std::string& filename,
                        int video_width, 
                        int video_height, 
                        int fps, 
                        int macroblock_size,
                        int frame_repeat);

    ~FrameEncoder3BPC();

    const std::string filename;
    const unsigned int video_width;
    const unsigned int video_height;
    const unsigned int fps;
    const unsigned int macroblock_size;
    const unsigned int frame_width;
    const unsigned int frame_height;
    const unsigned int frame_size;
    const unsigned int frame_repeat;

    /**
     * \brief Write data to the frame encoder
     */
    size_t write(const void *ptr, size_t size, size_t nmemb);
    

protected:
    // Protected members and functions here

private:
     cv::VideoWriter video_writer;
};
#endif