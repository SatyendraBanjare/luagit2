#ifndef _lua_common_h
#define _lua_common_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* 
 *A simple Error check program that uses giterr_last()
 * to prints out the error and any extra message if passed
 * to the user.
 */
void check_error(int error_code, const char *action);

/* Extended version of check_error() to print extra messages.
 */
void check_error_long(int error, const char *message, const char *extra);

#endif