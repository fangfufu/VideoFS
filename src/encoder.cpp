#include <opencv2/opencv.hpp>
#include <iostream>

#include "interconverter_3bpc.hpp"

int main(int argc, char** argv) {

    (void)argc;
    (void)argv;

    // Define the parameters for the video
    int frameWidth = 1024; // Frame width (you can change this to your desired resolution)
    int frameHeight = 1024; // Frame height
    int fps = 30; // Frames per second
    int durationInSeconds = 30; // Duration in seconds

    // Calculate the total number of frames needed
    int totalFrames = fps * durationInSeconds;

    // Create a video writer object
    cv::VideoWriter video("black_video.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(frameWidth, frameHeight), true);

    if (!video.isOpened()) {
        std::cerr << "Error: Could not open the video file for writing." << std::endl;
        return -1;
    }

    // Create a black frame (all pixels set to zero)
    cv::Mat frame = cv::Mat::zeros(16, 16, CV_8UC3);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            cv::Vec3b& pixel = frame.at<cv::Vec3b>(i, j);
            uint8_t value = i*16 + j;
            printf("value: %u\n", value);
            byte_to_pixel_3bpc(value, pixel);
        }
    }

    cv::Size newSize(1024, 1024);

    // Resize the image using nearest neighbor interpolation
    cv::Mat resizedImage;
    cv::resize(frame, resizedImage, newSize, 0, 0, cv::INTER_NEAREST);

    // Write the black frames to the video file
    for (int i = 0; i < totalFrames; ++i) {
        video.write(resizedImage);
    }

    // Release the video writer
    video.release();

    std::cout << "Black video generated successfully!" << std::endl;

    return 0;
}