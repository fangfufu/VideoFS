#ifndef UTIL_H
#define UTIL_H

/**
 * \file util.h
 * \author Fufu Fang (fangfufu2003@gmail.com)
 * \brief Useful utility functions
 * @copyright Copyright (c) 2023
 */

#include <pthread.h>

/**
 * \brief wrapper for calloc(), with error handling
 */
void *CALLOC(size_t nmemb, size_t size);

/**
 * \brief wrapper for free(), but the pointer is set to NULL afterwards.
 */
void FREE(void *ptr);

/**
 * \brief wrapper for pthread_mutex_lock(), with error handling
 */
void PTHREAD_MUTEX_LOCK(pthread_mutex_t *x);

/**
 * \brief wrapper for pthread_mutex_unlock(), with error handling
 */
void PTHREAD_MUTEX_UNLOCK(pthread_mutex_t *x);

/**
 * \brief wrapper for exit(EXIT_FAILURE), with error handling
 */
void exit_failure(void);

#endif  // UTIL_H