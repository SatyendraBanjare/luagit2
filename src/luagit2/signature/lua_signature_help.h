#ifndef _lua_signature_help
#define _lua_signature_help

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* This file contains some helper methods to luagit2's signature module
 * functions.
 */

/* Callable function name : luagit2_get_signature_details(lua_userdata luagit2_signature, 
																lua_integer option_number)
 *
 * get the signature detail value.
 *
 * Params required : (lua_userdata) the signature,
                     (lua_string) the option number : 1 -> name , 2 -> email
                     .
 * Returns : string value as requested in option number.
 */
int lua_get_signature_details (lua_State *L);

/* Callable function name : luagit2_print_complete_signature_details(lua_userdata luagit2_signature)
 *
 * print the complete signature details.
 *
 * Params required : (lua_userdata) the signature,                    .
 * Returns : None.
 */
int lua_print_complete_signature_details (lua_State *L);

#endif
