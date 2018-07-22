#ifndef _lua_libgit_help
#define _lua_libgit_help

#include "../common/lua_common.h"

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
