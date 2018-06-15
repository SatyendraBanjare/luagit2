#ifndef _lua_libgit2_h
#define _lua_libgit2_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* Module Libgit2
 *
 * This file contains methods to access, view and set
 * Global variables for the working of luagit2.
 */


/* Callable function name : luagit2_init()
 *
 * This function must be called before any other luagit2 function in order
 * to set up global state and threading.
 *
 * Params required : None
 * Returns : None
 */
int lua_git_libgit2_init (lua_State *L);

/* Callable function name : luagit2_shutdown()
 *
 * Clean up the global state and threading context after calling it as many times
 * as luagit2_init() was called.
 *
 * Params required : None
 * Returns : None
 */
int lua_git_libgit2_shutdown (lua_State *L);

/* Callable function name : luagit2_features().
 *
 * Params required : None
 * Returns : Integer value for Query compile time options for libgit2.
 */
int lua_git_libgit2_features (lua_State *L);

/* Callable function name : luagit2_version().
 *
 * Params required : None
 * Returns : A `libgit_version_data` type Userdata object.
 */
int lua_git_libgit2_version (lua_State *L);

/* Callable function name : luagit2_GET_MWINDOW_SIZE().
 *
 * Params required : None
 * Returns : an Integer valued maximum mmap window size.
 */
int lua_GIT_OPT_GET_MWINDOW_SIZE(lua_State *L);

/* Callable function name : luagit2_SET_MWINDOW_SIZE( lua_integer Size).
 *
 * Sets the maximum mmap window size.
 *
 * Params required : (Integer) an integer value.
 * Returns : None.
 */
int lua_GIT_OPT_SET_MWINDOW_SIZE(lua_State *L);

/* Callable function name : luagit2_GET_MWINDOW_MAPPED_LIMIT().
 *
 * Params required : None
 * Returns : Integer value of the maximum memory that will be
 *           mapped in total by the library.
 */
int lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT(lua_State *L);

/* Callable function name : luagit2_SET_MWINDOW_MAPPED_LIMIT( lua_integer Size).
 * Sets the maximum memory that	will be mapped by library.
 *
 * Params required : (Integer) an integer value.
 * Returns : None.
 */
int lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT(lua_State *L);

/* Callable function name : luagit2_GET_SEARCH_PATH( lua_integer Option_Number).
 *
 * Params required : (Integer) Integer option number.
 					1 -> GIT_CONFIG_LEVEL_SYSTEM
 					2 -> GIT_CONFIG_LEVEL_GLOBAL
 					3 -> GIT_CONFIG_LEVEL_XDG
 					4 -> GIT_CONFIG_LEVEL_PROGRAMDATA
 * Returns : String value of search path for a selected level for a config data.
 */
int lua_GIT_OPT_GET_SEARCH_PATH(lua_State *L);

/* Callable function name : luagit2_SET_SEARCH_PATH( lua_integer Option_Number , lua_string path).
 *
 * Params required : (String) string value of path ,(Integer) Integer option number.
 					1 -> GIT_CONFIG_LEVEL_SYSTEM
 					2 -> GIT_CONFIG_LEVEL_GLOBAL
 					3 -> GIT_CONFIG_LEVEL_XDG
 					4 -> GIT_CONFIG_LEVEL_PROGRAMDATA
 * Returns : None.
 */
int lua_GIT_OPT_SET_SEARCH_PATH(lua_State *L);

/* Callable function name : luagit2_GET_CACHED_MEMORY(lua_integer option_number)
 * Get the current bytes in cache and the maximum that would be  allowed in the cache.
 *
 * Params required : (Integer) option number. 1 -> current value, 2 -> allowed value
 * Returns : cache byte value according to selected option number.
 */
int lua_GIT_OPT_GET_CACHED_MEMORY(lua_State *L);

/* Callable function name : luagit2_SET_CACHE_OBJECT_LIMIT(lua_integer size)
 * Sets the cache object memory limit.
 *
 * Params required : (Integer) integer value of size.
 * Returns : None.
 */
int lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT(lua_State *L);

/* Callable function name : luagit2_SET_CACHE_MAX_SIZE(lua_integer size)
 * Set the maximum total data size that will be cached in memory
 * across all repositories before libgit2 starts evicting objects
 * from the cache.
 *
 * Params required : (Integer) integer value of size.
 * Returns : None.
 */
int lua_GIT_OPT_SET_CACHE_MAX_SIZE(lua_State *L);

/* Callable function name : luagit2_ENABLE_CACHING(lua_integer is_enabled)
 * Enable or disable caching completely.
 *
 * Params required : (Integer) integer equivalent of bool. 0 -> disabled , >0 -> enabled
 * Returns : None.
 */
int lua_GIT_OPT_ENABLE_CACHING(lua_State *L);

/* Callable function name : luagit2_GET_TEMPLATE_PATH()
 *
 * Params required : None.
 * Returns : String value of default template path.
 */
int lua_GIT_OPT_GET_TEMPLATE_PATH(lua_State *L);

/* Callable function name : luagit2_SET_TEMPLATE_PATH(lua_string path)
 * Set the default template path.
 *
 * Params required : (String) path value .
 * Returns : None.
 */
int lua_GIT_OPT_SET_TEMPLATE_PATH(lua_State *L);

/* Callable function name : luagit2_SET_USER_AGENT(lua_string user_agent)
 * Set the user agent.
 *
 * Params required : (String) string value of user_agent .
 * Returns : None.
 */
int lua_GIT_OPT_SET_USER_AGENT(lua_State *L);

/* Callable function name : luagit2_GET_WINDOWS_SHAREMODE()
 * Get the share mode used when opening files on Windows
 *
 * Params required : None .
 * Returns : Integer value of share mode.
 */
int lua_GIT_OPT_GET_WINDOWS_SHAREMODE(lua_State *L);

/* Callable function name : luagit2_SET_WINDOWS_SHAREMODE(lua_number value)
 * Set the share mode on windows.
 *
 * Params required : (lua_Number) a long integer equivalent number .
 * Returns : None.
 */
int lua_GIT_OPT_SET_WINDOWS_SHAREMODE(lua_State *L);

/* Callable function name : luagit2_ENABLE_STRICT_OBJECT_CREATION(lua_integer is_enabled)
 * enable or disable creation of objects strictly.
 *
 * Params required : (Integer) integer equivalent of bool. 0 -> disabled , >0 -> enabled.
 * Returns : None.
 */
int lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION(lua_State *L);

/* Callable function name : luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION(lua_integer is_enabled)
 * enable or disable creation of symbolic reference strictly.
 *
 * Params required : (Integer) integer equivalent of bool. 0 -> disabled , >0 -> enabled.
 * Returns : None.
 */
int lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION(lua_State *L);

/* Callable function name : luagit2_SET_SSL_CIPHERS(lua_string ssl_cipher)
 * Set the SSL ciphers use for HTTPS connections.
 * `ssl_cipher_name` is the list of ciphers that are eanbled.
 *
 * Params required : (String) SSL_cipher.
 * Returns : None.
 */
int lua_GIT_OPT_SET_SSL_CIPHERS(lua_State *L);

/* Callable function name : luagit2_ENABLE_OFS_DELTA(lua_integer is_enabled)
 * Enable or disable the use of "offset deltas" when creating packfiles.
 *
 * Params required : (Integer) integer equivalent of bool. 0 -> disabled , >0 -> enabled.
 * Returns : None.
 */
int lua_GIT_OPT_ENABLE_OFS_DELTA(lua_State *L);

/* Callable function name : luagit2_ENABLE_FSYNC_GITDIR(lua_integer is_enabled)
 * Enable synchronized writes of files in the gitdir using `fsync`.
 *
 * Params required : (Integer) integer equivalent of bool. 0 -> disabled , >0 -> enabled.
 * Returns : None.
 */
int lua_GIT_OPT_ENABLE_FSYNC_GITDIR(lua_State *L);

/* Callable function name : luagit2_ENABLE_STRICT_HASH_VERIFICATION(lua_integer is_enabled)
 * Enable strict verification of object hashsums when reading objects from disk.
 *
 * Params required : (Integer) integer equivalent of bool. 0 -> disabled , >0 -> enabled.
 * Returns : None.
 */
int lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION(lua_State *L);

#endif
