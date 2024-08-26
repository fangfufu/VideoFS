#include "log.hpp"

#include "config.hpp"
#include "util.hpp"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int log_level_init()
{
    char *env = getenv("VIDEOFS_LOG_LEVEL");
    if (env) {
        return atoi(env);
    }
#ifdef DEBUG
    return DEFAULT_LOG_LEVEL | debug;
#else
    return DEFAULT_LOG_LEVEL;
#endif
}

void
log_printf(LogType type, const char *file, const char *func, int line,
           const char *format, ...)
{
    if (type & CONFIG.log_type) {
        switch (type) {
        case fatal:
            fprintf(stderr, "Fatal:");
            break;
        case error:
            fprintf(stderr, "Error:");
            break;
        case warning:
            fprintf(stderr, "Warning:");
            break;
        case info:
            goto print_actual_message;
        default:
            fprintf(stderr, "Debug");
            if (type != debug) {
                fprintf(stderr, "(%x)", type);
            }
            fprintf(stderr, ":");
            break;
        }

        fprintf(stderr, "%s:%d:", file, line);

print_actual_message: {
        }
        fprintf(stderr, "%s: ", func);
        va_list args;
        va_start(args, format);
        vfprintf(stderr, format, args);
        va_end(args);

        if (type == fatal) {
            exit_failure();
        }
    }
}

void print_version()
{
    /* FUSE prints its help to stderr */
    fprintf(stderr, "VideoFS version " VERSION "\n");
}