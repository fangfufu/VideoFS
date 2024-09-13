/**
 * \file VideoWriter.cpp
 * \brief VideoWriter class implementation
 * \author 2024 Fufu Fang
 * \copyright SPDX-License-Identifier:  GPL-3.0-or-later
 */
#include "VideoWriter.hpp"

VideoWriter::VideoWriter(const std::string& filename,
                    int video_width,
                    int video_height,
                    int fps,
                    int macroblock_size,
                    int frame_repeat) :
                    filename(filename),
                    video_height(video_height),
                    video_width(video_width),
                    fps(fps),
                    frame_repeat(frame_repeat),
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

VideoWriter::~VideoWriter() {
        if (video_writer.isOpened()) {
            video_writer.release();
        }
    }