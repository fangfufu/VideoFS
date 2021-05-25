#include "log.h"

#include "util.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int log_level_init(void)
{
    /* TODO: Set application level default log level */
    char *env = getenv("VIDEOFS_LOG_LEVEL");
    if (env) {
        return atoi(env);
    }
    return DEFAULT_LOG_LEVEL;
}

void
log_printf(LogType type, const char *file, const char *func, int line,
           const char *format, ...)
{
    /* TODO: Set application level default log level */
    if (type) {
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
            fprintf(stderr, "Debug(%x):", type);
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

void print_version(void)
{
    /* FUSE prints its help to stderr */
    fprintf(stderr, "VideoFS version " VERSION "\n");
}
