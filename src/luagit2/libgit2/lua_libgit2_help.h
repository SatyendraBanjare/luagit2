#ifndef _lua_libgit_help
#define _lua_libgit_help

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* Module Libgit2_helper
 *
 * These are helper methods to ease the user in accessing
 * the libgit2.
 */

/* Callable function name : luagit2_print_version_data(lua_userdata version_data, lua_integer option)
 *
 * Helper function to help in printing libgit2's version details.
 *
 * Params required : (lua_userdata) libgit_version_data , (lua_integer) option number.
 * 					 1 -> Major version number
 					 2 -> Minor version number
 					 3 -> Rev version number
 * Returns : None
 */
int lua_git_libgit2_print_version_data (lua_State *L);

#endif
