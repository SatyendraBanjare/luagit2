#ifndef _lua_clone_h
#define _lua_clone_h
#define PRIuZ "zu" //for non windows system for now.

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

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
