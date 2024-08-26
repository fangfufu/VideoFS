#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Define the parameters for the video
    int frameWidth = 1920; // Frame width (you can change this to your desired resolution)
    int frameHeight = 1080; // Frame height
    int fps = 30; // Frames per second
    int durationInSeconds = 5; // Duration in seconds

    // Calculate the total number of frames needed
    int totalFrames = fps * durationInSeconds;

    // Create a video writer object
    cv::VideoWriter video("black_video.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(frameWidth, frameHeight), false);

    if (!video.isOpened()) {
        std::cerr << "Error: Could not open the video file for writing." << std::endl;
        return -1;
    }

    // Create a black frame (all pixels set to zero)
    cv::Mat blackFrame = cv::Mat::zeros(frameHeight, frameWidth, CV_8UC1);

    // Write the black frames to the video file
    for (int i = 0; i < totalFrames; ++i) {
        video.write(blackFrame);
    }

    // Release the video writer
    video.release();

    std::cout << "Black video generated successfully!" << std::endl;

    return 0;
}