#ifndef CONFIG_H
#define CONFIG_H

#define VIDEO_WIDTH         3840
#define VIDEO_HEIGHT        2160
#define MACROBLOCK_SIZE     16
#define FRAME_WIDTH         (VIDEO_WIDTH / MACROBLOCK_SIZE) // 240
#define FRAME_HEIGHT        (VIDEO_HEIGHT / MACROBLOCK_SIZE) // 135

/**
 * \brief The Configuration data structure
 */
struct {
    /** \brief Current log level */
    int log_type;
} CONFIG;

#endif // CONFIG_H