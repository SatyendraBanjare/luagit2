#ifndef _lua_oid_h
#define _lua_oid_h

#include "../common/lua_common.h"
/* Module OID
 * 
 * This file contains lua bindings to libgit2's OID module.
 */

/* Callable function name : luagit2_oid_fromstr(lua_string hex_string)
 *
 * converts a string to luagit2 oid.
 *
 * Params required : (lua_string) the string to convert.
 * Returns : luagit2_oid type user_data object.
 */
int lua_git_oid_fromstr (lua_State *L);

/* Callable function name : luagit2_oid_fromstrn(lua_string hex_string, lua_integer length)
 *
 * converts a n length of passed string to luagit2 oid.
 *
 * Params required : (lua_string) the string to convert.
                     (lua_integer) the length to consider.
 * Returns : luagit2_oid type user_data object.
 */
int lua_git_oid_fromstrn (lua_State *L);

/* Callable function name : luagit2_oid_cmp(lua_userdata luagit2_oid, lua_userdata luagit2_oid)
 *
 * compares the two given luagit2_oid objects.
 *
 * Params required : (lua_userdata) First luagit2_oid.
                     (lua_userdata) Second luagit2_oid.
 * Returns : integer value as : < 0 if oid_1 < oid_2, 0 ifoid_1 == oid_2, >0 if oid_1 > oid_2.
 */
int lua_git_oid_cmp (lua_State *L);

/* Callable function name : luagit2_oid_cmp(lua_userdata luagit2_oid, lua_userdata luagit2_oid, lua_integer length)
 *
 * compares the two given luagit2_oid objects for a given length.
 *
 * Params required : (lua_userdata) First luagit2_oid.
                     (lua_userdata) Second luagit2_oid.
                     (lua_integer) length to compare.
 * Returns : integer value as : < 0 if oid_1 < oid_2, 0 ifoid_1 == oid_2, >0 if oid_1 > oid_2.
 */
int lua_git_oid_ncmp (lua_State *L);

/* Callable function name : luagit2_oid_fmt(lua_userdata luagit2_oid)
 *
 * formats a luagit2_oid to hex string.
 *
 * Params required : (lua_userdata) luagit2_oid to format.
 * Returns : string value of hex string.
 */
int lua_git_oid_fmt (lua_State *L);

/* Callable function name : luagit2_oid_nfmt(lua_userdata luagit2_oid)
 *
 * formats a luagit2_oid to a given length hex string.
 *
 * Params required : (lua_userdata) luagit2_oid to format.
                     (lua_integer) length
 * Returns : string value of hex string.
 */
int lua_git_oid_nfmt (lua_State *L) ;

/* Callable function name : luagit2_oid_pathfmt(lua_userdata luagit2_oid)
 *
 * formats a luagit2_oid to path string.
 *
 * Params required : (lua_userdata) luagit2_oid to format.
 * Returns : string value of path string.
 */
int lua_git_oid_pathfmt (lua_State *L);

/* Callable function name : luagit2_oid_iszero(lua_userdata luagit2_oid)
 *
 * Check is an oid is all zeros.
 *
 * Params required : (lua_userdata) luagit2_oid check.
 * Returns : integer equivalent of bool.
 */
int lua_git_oid_iszero (lua_State *L);

/* Callable function name : luagit2_oid_iszero(lua_userdata luagit2_oid, lua_string hex_string)
 *
 * Compare an oid to an hex formatted object id's string value.
 *
 * Params required : (lua_userdata) luagit2_oid check.
                     (lua_string) the objectid's string value.   
 * Returns : integer value corresponding to 
             1 if str is not valid, < 0 if id sorts before str,
             0 if id matches str, >0 if id sorts after str.
 */
int lua_git_oid_strcmp (lua_State *L);

/* Callable function name : luagit2_oid_iszero(lua_userdata luagit2_oid)
 *
 * Format a git_oid into a buffer as a hex format string.
 *
 * Params required : (lua_userdata) luagit2_oid check.
 * Returns : corresponding string value.
 */
int lua_git_oid_tostr (lua_State *L);

/* Callable function name : luagit2_oid_iszero(lua_userdata luagit2_oid)
 *
 * Format a git_oid into a statically allocated string.
 *
 * Params required : (lua_userdata) luagit2_oid check.
 * Returns : corresponding string value.
 */
int lua_git_oid_tostr_s (lua_State *L);


#endif
