#ifndef _lua_common_h
#define _lua_common_h

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>
#include "../lua_objects.h"

/* 
 * A simple Error check program that uses giterr_last()
 * to prints out the error and any extra message if passed
 * to the user.
 */
void check_error(int error_code, const char *action);

/* Extended version of check_error() to print extra messages.
 */
void check_error_long(int error, const char *message, const char *extra);

/* Helper function to get the userdata's metatable name.
 */
int get_userdata_name(lua_State *L);

#endif