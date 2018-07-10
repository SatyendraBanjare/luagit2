#ifndef _lua_blame_h
#define _lua_blame_h

#include "../common/lua_common.h"

/* Module Blame
 *
 * This file contains lua-Bindings to libgit2's Blame module.
 * 
 */

/* Callable function name : luagit2_blame_buffer(lua_userdata luagit2_blame, lua_string buffer
 *                                              , lua_integer length)
 *
 * Get blame data for a file that has been modified in memory.
 *
 * Params required : (lua_userdata) the reference luagit2_blame,
                     (lua_string) the buffer string
                     (lua_integer) the length of buffer string.
 * Returns : luagit2_blame type user_data object.
 */
int lua_git_blame_buffer (lua_State *L);

/* Callable function name : luagit2_blame_file(lua_userdata luagit2_repository, lua_string path_to_file)
 *
 * Get blame data for a single file.
 *
 * Params required : (lua_userdata) the repository to look into,
                     (lua_string) the path to file.
 * Returns : luagit2_blame type user_data object.
 */
int lua_git_blame_file (lua_State *L);

/* Callable function name : luagit2_blame_get_hunk_byindex(lua_userdata luagit2_blame, lua_integer index)
 *
 * Gets the blame hunk at the given index.
 *
 * Params required : (lua_userdata) the reference luagit2_blame,
                     (lua_string) the index number
                     .
 * Returns : luagit2_blame type user_data object.
 */
int lua_git_blame_get_hunk_byindex (lua_State *L);

/* Callable function name : luagit2_blame_get_hunk_byline(lua_userdata luagit2_blame, lua_integer line_number)
 *
 * Gets the blame hunk at the given line number.
 *
 * Params required : (lua_userdata) the reference luagit2_blame,
                     (lua_string) the line number
                     .
 * Returns : luagit2_blame type user_data object.
 */
int lua_git_blame_get_hunk_byline (lua_State *L);

/* Callable function name : luagit2_blame_get_hunk_count(lua_userdata luagit2_blame)
 *
 * Gets the blame hunk at the given line number.
 *
 * Params required : (lua_userdata) the reference luagit2_blame,
 * Returns : Hunk count for given luagit2_blame.
 */
int lua_git_blame_get_hunk_count (lua_State *L);

/* Callable function name : luagit2_blame_free(lua_userdata luagit2_blame)
 *
 * Free memory allocated by luagit2_blame_file or luagit2_blame_buffer.
 *
 * Params required : (lua_userdata) the reference luagit2_blame,
 * Returns : None.
 */
int lua_git_blame_free (lua_State *L);

#endif
