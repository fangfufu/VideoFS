#ifndef LOG_H
#define LOG_H

/**
 * \brief Log types
 */
typedef enum {
    fatal = 1 << 0,
    error = 1 << 1,
    warning = 1 << 2,
    info = 1 << 3,
    debug = 1 << 4,
} LogType;

/**
 * \brief The default log level
 */
#define DEFAULT_LOG_LEVEL fatal | error | warning | info | debug

/**
 * \brief Get the log level from the environment.
 */
int log_level_init();

/**
 * \brief Log printf
 * \details This is for printing nice log messages
 */
void log_printf(LogType type, const char *file, const char *func, int line,
                const char *format, ...);

/**
 * \brief Log type printf
 * \details This macro automatically prints out the filename and line number
 */
#define lprintf(type, ...) \
    log_printf(type, __FILE__, __func__, __LINE__, __VA_ARGS__);
#endif

/**
 * \brief Print the version information for Video
 */
void print_version();
