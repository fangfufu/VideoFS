/**
 * \file InterConverter.hpp
 * \brief Byte / Pixel Converter, 3 byte per chanel
 * \author Fufu Fang
 * \date 2024
 * \copyright SPDX-License-Identifier:  GPL-3.0-or-later
 */

#ifndef INTERCONVERTER_H
#define INTERCONVERTER_H

#include <cstdint>

#include <opencv2/core/mat.hpp>

/**
 * \brief Convert a byte to a pixel - 3 bytes per channel
 */
void byte_to_pixel(uint8_t byte, cv::Vec3b& pixel);

/**
 * \brief Convert a pixel to a byte - 3 bytes per channel
 */
uint8_t pixel_to_byte(const cv::Vec3b& pixel);

#endif