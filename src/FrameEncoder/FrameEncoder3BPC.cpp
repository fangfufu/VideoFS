/**
 * \file FrameEncoder3BPC.cpp
 * \brief FrameEncoder3BPC class implementation
 */
#include "FrameEncoder3BPC.hpp"


FrameEncoder3BPC::FrameEncoder3BPC(const std::string& filename,
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

FrameEncoder3BPC::~FrameEncoder3BPC() {
        if (video_writer.isOpened()) {
            video_writer.release();
        }
    }