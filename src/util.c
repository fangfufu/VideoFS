/**
 * \file util.c
 * @author Fufu Fang (fangfufu2003@gmail.com)
 * @copyright Copyright (c) 2023
 */

#include "util.h"
#include "log.h"

#include <errno.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * \brief Backtrace buffer size
 */
#define BT_BUF_SIZE 100

void PTHREAD_MUTEX_UNLOCK(pthread_mutex_t *x)
{
    int i;
    i = pthread_mutex_unlock(x);
    if (i) {
        lprintf(fatal,
                "thread %x: %d, %s\n", pthread_self(), i, strerror(i));
    }
}

void PTHREAD_MUTEX_LOCK(pthread_mutex_t *x)
{
    int i;
    i = pthread_mutex_lock(x);
    if (i) {
        lprintf(fatal,
                "thread %x: %d, %s\n", pthread_self(), i, strerror(i));
    }
}

void *CALLOC(size_t nmemb, size_t size)
{
    void *ptr = calloc(nmemb, size);
    if (!ptr) {
        lprintf(fatal, "%s!\n", strerror(errno));
    }
    return ptr;
}

void *MALLOC(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr) {
        lprintf(fatal, "%s!\n", strerror(errno));
    }
    return ptr;
}

void FREE(void *ptr)
{
    if (ptr) {
        free(ptr);
    } else {
        lprintf(fatal, "attempted to free NULL ptr!\n");
    }/**
 * \brief Backtrace buffer size
 */
#define BT_BUF_SIZE 100
}

void exit_failure(void)
{
    int nptrs;
    void *buffer[BT_BUF_SIZE];

    nptrs = backtrace(buffer, BT_BUF_SIZE);
    fprintf(stderr, "\nOops! HTTPDirFS crashed! :(\n");
    fprintf(stderr, "backtrace() returned the following %d addresses:\n",
            nptrs);
    backtrace_symbols_fd(buffer, nptrs, STDERR_FILENO);

    exit(EXIT_FAILURE);
}