#include <opencv2/opencv.hpp>
#include <iostream>

#include "frame_encoder/interconverter_3bpc.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // Path to the video file
    std::string videoPath = "../resources/sample.mkv";

    // Create a VideoCapture object
    cv::VideoCapture cap(videoPath);

    // Check if the video file was opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video." << std::endl;
        return -1;
    }

    // Loop through the video frame by frame
    while (true) {
        cv::Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame was not retrieved, we have reached the end of the video
        if (frame.empty()) {
            std::cout << "End of video." << std::endl;
            break;
        }

        // Display the current frame
        cv::imshow("Frame", frame);

        // Press 'q' on the keyboard to exit the loop
        if (cv::waitKey(25) == 'q') {
            break;
        }

        if (cv::waitKey(25) == 'p') {
            printf("Start: \n");
            int k = 0;
            for (int i = 22; i < 720; i += 45) {
                for (int j = 22; j < 720; j += 45) {
                    cv::Vec3b &pixel = frame.at<cv::Vec3b>(i, j);
                    uint8_t value = pixel_to_byte_3bpc(pixel);
                    printf("%02x, ", value);
                    if (k != value) {
                        printf("Error: %x, %x\n", k, value);
                    }
                    k++;
                }
                printf("\n");
            }
            printf("End.\n");
        }
    }

    // Release the video capture object and close display windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}