#ifndef INTERCONVERTER_3BPC_H
#define INTERCONVERTER_3BPC_H
/**
 * \file interconverter_3bpc.hpp
 * \brief Byte / Pixel Converter, 3 byte per chanel
 */

#include <cstdint>

#include <opencv2/core/mat.hpp>

/**
 * \brief Convert a byte to a pixel - 3 bytes per channel
 */
void byte_to_pixel_3bpc(uint8_t byte, cv::Vec3b& pixel);

/**
 * \brief Convert a pixel to a byte - 3 bytes per channel
 */
uint8_t pixel_to_byte_3bpc(const cv::Vec3b& pixel);

#endif