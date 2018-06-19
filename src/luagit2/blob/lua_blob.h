#ifndef _lua_blob_h
#define _lua_blob_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* Module Blob
 *
 * This file contains lua-Bindings to libgit2's Blob module.
 * 
 */

/* Callable function name : luagit2_blob_create_fromdisk(lua_userdata luagit2_repository, lua_string path )
 *
 * Read a file from the filesystem and write its content to the Object Database as a loose blob.
 *
 * Params required : (lua_userdata) the repository to look up,
                     (lua_string) the path to file.
 * Returns : luagit2_oid type user_data object.
 */
int lua_git_blob_create_fromdisk (lua_State *L);

/* Callable function name : luagit2_blob_create_fromworkdir(lua_userdata luagit2_repository, 
                                                            lua_string relative_path )
 *
 * Read a file from the working folder of a repository
 * and write its content to the Object Database as a loose blob.
 *
 * Params required : (lua_userdata) the repository to look up,
                     (lua_string) the path to file.
 * Returns : luagit2_oid type user_data object.
 */
int lua_git_blob_create_fromworkdir (lua_State *L);

/* Callable function name : luagit2_blob_filtered_content(lua_userdata luagit2_blob, 
                                lua_string path , lua_integer check_for_binary_data )
 *
 * Get a buffer with the filtered content of a blob.
 *
 * Params required : (lua_userdata) the blob to look up to,
                     (lua_string) the path to filename.
                     (lua_integer) bool argument to check for binary data.
 * Returns : luagit2_buf type user_data object.
 */
int lua_git_blob_filtered_content (lua_State *L);

/* Callable function name : luagit2_blob_id(lua_userdata luagit2_blob)
 *
 * Get the id of a blob.
 *
 * Params required : (lua_userdata) the blob to look up to,
 * Returns : luagit2_oid type user_data object.
 */
int lua_git_blob_id (lua_State *L);

/* Callable function name : luagit2_blob_is_binary(lua_userdata luagit2_blob)
 *
 * Determine if the blob content is most certainly binary or not.
 *
 * Params required : (lua_userdata) the blob to look up to,
 * Returns : luagit2_integer , bool equivalent of whether blob is binary.
 */
int lua_git_blob_is_binary (lua_State *L);

/* Callable function name : luagit2_blob_lookup(lua_userdata luagit2_repository, lua_userdata oid)
 *
 * Lookup a blob object from a repository.
 *
 * Params required : (lua_userdata) the repo to look in,
                     (lua_userdata) the oid of object to look up.
 * Returns : luagit2_blob type user_data object.
 */
int lua_git_blob_lookup (lua_State *L);

/* Callable function name : luagit2_blob_lookup_prefix(lua_userdata luagit2_repository, 
                                                lua_userdata oid , lua_integer length)
 *
 * Lookup a blob object from a repository, given a prefix of its identifier (short id).
 *
 * Params required : (lua_userdata) the repo to look in,
                     (lua_userdata) the oid of object to look up.
                     (lua_userdata) length of oid
 * Returns : luagit2_blob type user_data object.
 */
int lua_git_blob_lookup_prefix (lua_State *L);

/* Callable function name : luagit2_blob_owner(lua_userdata luagit2_blob)
 *
 * Get the owner repository for a given blob object.
 *
 * Params required : (lua_userdata) the blob to check,
 * Returns : luagit2_repository type user_data object.
 */
int lua_git_blob_owner(lua_State *L);

/* Callable function name : luagit2_blob_rawsize(lua_userdata luagit2_blob)
 *
 * Get the size in bytes of the contents of a blob.
 *
 * Params required : (lua_userdata) the blob to check,
 * Returns : luagit2_off_t type user_data object.
 */
int lua_git_blob_rawsize(lua_State *L);

/* Callable function name : luagit2_blob_free(lua_userdata luagit2_blob)
 *
 * Stop memory leak when not using luagit2_blob anymore.
 *
 * Params required : (lua_userdata) the blob to free,
 * Returns : None.
 */
int lua_git_blob_free(lua_State *L);


#endif
