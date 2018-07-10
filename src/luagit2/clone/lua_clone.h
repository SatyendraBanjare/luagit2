#ifndef _lua_clone_h
#define _lua_clone_h
#define PRIuZ "zu" //for non windows system for now.

#include "../common/lua_common.h"

/* Module Clone
 *
 * This file contains lua-Bindings to libgit2's Clone module.
 * 
 */

/* Callable function name : luagit2_clone_public(lua_string Url, lua_string Path , lua_ineger should_print)
 *
 * Clone the given PUBLIC  repository.
 *
 * Params required : (lua_string) the Url to repository to clone,
                     (lua_string) Path where to save.
                     (lua_integer) integer equivalent of bool.
 * Returns : None.
 */
int lua_git_clone_public(lua_State *L);

#endif
