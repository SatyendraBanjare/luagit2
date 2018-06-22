#ifndef _lua_tree_h
#define _lua_tree_h

#include "../common/lua_common.h"

/* Module Tree
 *
 * This file contains lua-Bindings to libgit2's Tree module.
 *
 */


/* Callable function name : luagit2_tree_entry_byid(lua_userdata luagit2_tree, lua_userdata luagit2_oid )
 *
 * Lookup a tree entry by SHA value of luagit2_oid.
 *
 * Params required : (lua_userdata) Tree to look in,
                     (lua_userdata) the object id to look for.
 * Returns : luagit2_tree_entry type user_data object.
 */
int lua_git_tree_entry_byid(lua_State *L);

/* Callable function name : luagit2_tree_entry_byindex(lua_userdata luagit2_tree, lua_integer index )
 *
 * Lookup a tree entry by it's index number.
 *
 * Params required : (lua_userdata) Tree to look in,
                     (lua_integer) the index number.
 * Returns : luagit2_tree_entry type user_data object.
 */
int lua_git_tree_entry_byindex(lua_State *L);

/* Callable function name : luagit2_tree_entry_byname(lua_userdata luagit2_tree, lua_string filename )
 *
 * Lookup a tree entry by the filename.
 *
 * Params required : (lua_userdata) Tree to look in,
                     (lua_string) the name of filename
 * Returns : luagit2_tree_entry type user_data object.
 */
int lua_git_tree_entry_byname(lua_State *L);

/* Callable function name : luagit2_tree_entry_bypath(lua_userdata luagit2_tree, lua_string path )
 *
 * Lookup a tree entry by the name.
 *
 * Params required : (lua_userdata) Tree to look in,
                     (lua_string) the path to file.
 * Returns : luagit2_tree_entry type user_data object.
 */
int lua_git_tree_entry_bypath(lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_cmp(lua_userdata luagit2_tree_entry, lua_userdata luagit2_tree_entry )
 *
 * Compare two tree entries.
 *
 * Params required : (lua_userdata) 1st tree entry,
                     (lua_userdata) 2nd tree entry.
 * Returns : integer value , < 0 if entry1 is before entry2, 0 if entry1 == entry2, >0 if entry1 is after entry2 .
 */
int lua_git_tree_entry_cmp(lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_filemode(lua_userdata luagit2_tree_entry )
 *
 * Params required : (lua_userdata) tree entry,
 * Returns : luagit2_filemode for the tree entry .
 */
int lua_git_tree_entry_filemode(lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_filemode_raw(lua_userdata luagit2_tree_entry )
 *
 * Params required : (lua_userdata) tree entry,
 * Returns : luagit2_filemode for the raw file's tree entry .
 */
int lua_git_tree_entry_filemode_raw(lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_id(lua_userdata luagit2_tree_entry )
 *
 * Params required : (lua_userdata) tree entry,
 * Returns : luagit2_oid type user data object .
 */
int lua_git_tree_entry_id(lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_name(lua_userdata luagit2_tree_entry )
 *
 * Params required : (lua_userdata) tree entry,
 * Returns : name of the file .
 */
int lua_git_tree_entry_name (lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_to_object(lua_userdata luagit2_tree_entry )
 *
 * Convert a tree entry to the git_object it points to.
 *
 * Params required : (lua_userdata) tree entry,
 * Returns : luagit2_object tyoe user data.
 */
int lua_git_tree_entry_to_object (lua_State *L);

/* Callable function name : luagit2_tree_tree_entry_type(lua_userdata luagit2_tree_entry )
 *
 * Get the type of the object pointed by the entry.
 *
 * Params required : (lua_userdata) tree entry,
 * Returns : luagit2_otype type user data.
 */
int lua_git_tree_entry_type(lua_State *L);

/* Callable function name : luagit2_tree_tree_entrycount(lua_userdata luagit2_tree)
 *
 * Get the number of entries enlisted in a tree.
 *
 * Params required : (lua_userdata) tree ,
 * Returns : integer number of enlisted entries.
 */
int lua_git_tree_entrycount(lua_State *L);

/* Callable function name : luagit2_tree_tree_id(lua_userdata luagit2_tree)
 *
 * Params required : (lua_userdata) tree ,
 * Returns : the luagit2_oid type object for the id of the tree.
 */
int lua_git_tree_id(lua_State *L);

/* Callable function name : luagit2_tree_tree_entrycount(lua_userdata luagit2_repository, lua_userdata luagit2_oid)
 *
 * Lookup for a tree id in a repository.
 *
 * Params required : (lua_userdata) Repository to look into ,
                     (lua_userdata) luagit2_oid of tree.
 * Returns : luagit2_tree type user data object.
 */
int lua_git_tree_lookup (lua_State *L);

/* Callable function name : luagit2_tree_tree_entrycount(lua_userdata luagit2_repository, lua_userdata luagit2_oid , lua_integer length)
 *
 * Lookup for a tree id in a repository using prefix..
 *
 * Params required : (lua_userdata) Repository to look into ,
                     (lua_userdata) luagit2_oid of tree.
                     (lua_integer) length of prefix oid.
 * Returns : luagit2_tree type user data object.
 */
int lua_git_tree_lookup_prefix (lua_State *L);

/* Callable function name : luagit2_tree_owner(lua_userdata luagit2_tree)
 *
 * Params required : (lua_userdata) tree ,
 * Returns : the owner repository of the given tree.
 */
int lua_git_tree_owner(lua_State *L);

/* Callable function name : luagit2_tree_entry_free(lua_userdata luagit2_tree_entry)
 *
 * Frees the luagit2_tree_entry object.
 *
 * Params required : (lua_userdata) tree entry ,
 * Returns : None.
 */
int lua_git_tree_entry_free (lua_State *L);

/* Callable function name : luagit2_tree_free(lua_userdata luagit2_tree)
 *
 * Frees the luagit2_tree object.
 *
 * Params required : (lua_userdata) tree ,
 * Returns : None.
 */
int lua_git_tree_free (lua_State *L);

#endif
