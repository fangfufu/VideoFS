/**
 * \file FrameGenerator.hpp
 * \brief Byte / Pixel Converter, 3 byte per chanel
 * \author Fufu Fang
 * \date 2024
 * \copyright SPDX-License-Identifier:  GPL-3.0-or-later
 */

#include <opencv2/core.hpp>

class FrameGenerator {
public:
    FrameGenerator(int frame_width,
        int frame_height int macroblock_size);

    ~FrameGenerator();

    const unsigned int frame_width;
    const unsigned int frame_height;
    const unsigned int macroblock_size;
    const unsigned int array_width;
    const unsigned int array_height;

    /**
     * \brief Write data to the frame generator
     */
    size_t write(const void* ptr, size_t size, size_t nmemb);
}