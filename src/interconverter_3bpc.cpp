#include "interconverter_3bpc.hpp"

#define BRIGHTNESS_BIAS     0b00001000
#define VALID_BIT_MASK          0b11100000
#define IGNORED_BIT_COUNT   5

void byte_to_pixel_3bpc(uint8_t byte, cv::Vec3b& pixel) 
{
    for (int i = 0; i < 3; i++) {
        // Note that we want to bias the colour values by 8
        pixel[i] = (byte << (3 * i) & 0b11100000) | BRIGHTNESS_BIAS;
    }
}

uint8_t pixel_to_byte_3bpc(const cv::Vec3b& pixel) 
{
    uint8_t byte = 0;
    for (int i = 0; i < 3; i++) {
        byte |= (pixel[i] & VALID_BIT_MASK) >> (3 * i);
    }
    return byte;
}