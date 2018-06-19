#ifndef _lua_signature_
#define _lua_signature_

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* Module Signature
 *
 * This file contains lua-Bindings to libgit2's Signature module.
 *
 */


/* Callable function name : luagit2_signature_default(lua_userdata luagit2_repository )
 *
 * Get the default signature for the repository.
 *
 * Params required : (lua_userdata) Repository to find the signature,
 * Returns : luagit2_signature type user_data object.
 */
int lua_git_signature_default (lua_State *L);

/* Callable function name : luagit2_signature_dup(lua_userdata luagit2_signature )
 *
 * Get the duplicate signature for given signture objects.
 *
 * Params required : (lua_userdata) luagit2 signature.
 * Returns : luagit2_signature type user_data object.
 */
int lua_git_signature_dup (lua_State *L);

/* Callable function name : luagit2_signature_from_buffer(lua_string buffer_string )
 *
 * Get signature from buffer string.
 *
 * Params required : (lua_string) buffer string.
 * Returns : luagit2_signature type user_data object.
 */
int lua_git_signature_from_buffer (lua_State *L);

/* Callable function name : luagit2_signature_now(lua_string name,lua_string email )
 *
 * Get signature from string name and stirng email.
 *
 * Params required : (lua_string) name.
                     (lua_string) email.   
 * Returns : luagit2_signature type user_data object.
 */
int lua_git_signature_now (lua_State *L);

/* Callable function name : luagit2_signature_free(lua_userdata luagit2_signature )
 *
 * Free the luagit2_signature type object.
 *
 * Params required : (lua_userdata) luagit2_signature object to free.   
 * Returns : None
 */
int lua_git_signature_free (lua_State *L);

#endif
