#ifndef _lua_branch_h
#define _lua_branch_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

/* Module Branch
 *
 * This file contains lua-Bindings to libgit2's Branch module.
 * 
 */

/* Callable function name : luagit2_branch_create(lua_userdata luagit2_repository, lua_string branch_name,
                                                lua_userdata luagit2_commit , lua_integer force )
 *
 * Create a new branch pointing at a target commit
 *
 * Params required : (lua_userdata) the repository,
                     (lua_string) new branch name.
                     (lua_userdata) luagit2_commit the target commit.
                     (lua_integer) integer equivalent of bool.
 * Returns : luagit2_reference type user_data object.
 */
int lua_git_branch_create (lua_State *L);

/* Callable function name : luagit2_branch_create_from_annotated(lua_userdata luagit2_repository,
                        lua_string branch_name, lua_userdata luagit2_annotated_commit , lua_integer force )
 *
 * Create a new branch pointing at a target annotated commit.
 *
 * Params required : (lua_userdata) the repository,
                     (lua_string) new branch name.
                     (lua_userdata) luagit2_annotated_commit the target annotated commit.
                     (lua_integer) integer equivalent of bool.
 * Returns : luagit2_reference type user_data object.
 */
int lua_git_branch_create_from_annotated (lua_State *L);

/* Callable function name : luagit2_branch_delete(lua_userdata luagit2_reference )
 *
 * Delete an existing branch reference.
 *
 * Params required : (lua_userdata) the luagit2_reference , the reference object for the branch,
 * Returns : None.
 */
int lua_git_branch_delete (lua_State *L);

/* Callable function name : luagit2_branch_is_checked_out(lua_userdata luagit2_reference )
 *
 * check if an existing branch reference is checked out.
 *
 * Params required : (lua_userdata) the luagit2_reference , the reference object for the branch,
 * Returns : Integer equivalent of bool, true / false.
 */
int lua_git_branch_is_checked_out (lua_State *L);

/* Callable function name : luagit2_branch_is_head(lua_userdata luagit2_reference )
 *
 * check if an existing branch reference is being pointed by head.
 *
 * Params required : (lua_userdata) the luagit2_reference , the reference object for the branch,
 * Returns : Integer equivalent of bool, true / false.
 */
int lua_git_branch_is_head (lua_State *L);

/* Callable function name : luagit2_branch_iterator_new(lua_userdata luagit2_repository ,
                                                        lua_userdata luagit2_branch_type )
 *
 * Create an iterator which loops over the requested branches.
 *
 * Params required : (lua_userdata) the luagit2_repository ,
                     (lua_userdata) luagit2_branch_type
 * Returns : luagit2_branch_iterator type user data.
 */
int lua_git_branch_iterator_new (lua_State *L);

/* Callable function name : luagit2_branch_lookup(lua_userdata luagit2_repository ,
                            lua_string branch_name, lua_userdata luagit2_branch_type )
 *
 * Lookup a branch by its name in a repository.
 *
 * Params required : (lua_userdata) the luagit2_repository ,
                     (lua_string) branch name,
                     (lua_userdata) luagit2_branch_type
 * Returns : luagit2_reference type user data for the branch.
 */
int lua_git_branch_lookup (lua_State *L);

/* Callable function name : luagit2_branch_lookup(lua_userdata luagit2_reference ,
                            lua_string new_branch_name, lua_integer force )
 *
 * Move/rename an existing local branch reference..
 *
 * Params required : (lua_userdata) the luagit2_reference for the branch,
                     (lua_string) new branch name,
                     (lua_integer) integer equivalent for the bool.
 * Returns : luagit2_reference type user data for the newed branch.
 */
int lua_git_branch_move (lua_State *L);

/* Callable function name : luagit2_branch_name(lua_userdata luagit2_reference )
 *
 * get the name for the local branch reference.
 *
 * Params required : (lua_userdata) the luagit2_reference for the branch.
 * Returns : luagit2_string name of branch.
 */
int lua_git_branch_name (lua_State *L);

/* Callable function name : luagit2_branch_next(lua_userdata luagit2_branch_type,
                                                lua_userdata luagit2_branch_iterator )
 *
 * get the next branch in the luagit2_iterator.
 *
 * Params required : (lua_userdata) the luagit2_branch type.
                     (lua_userdata) the luagit2 branch iterator to do the iteration.
 * Returns : luagit2_reference type user data for the next branch.
 */
int lua_git_branch_next (lua_State *L);

/* Callable function name : luagit2_branch_next(lua_userdata luagit2_reference,
                                                lua_string upstream_name )
 *
 * Set the upstream configuration for a given local branch.
 *
 * Params required : (lua_userdata) the luagit2_reference object for the branch .
                     (lua_string) the the upstream name.
 * Returns : None.
 */
int lua_git_branch_set_upstream (lua_State *L);

/* Callable function name : luagit2_branch_next(lua_userdata luagit2_reference)
 *
 * get the upstream refernce , given a local branch reference.
 *
 * Params required : (lua_userdata) the luagit2_reference reference branch.
 * Returns : luagit2_reference type user data for upstream.
 */
int lua_git_branch_upstream (lua_State *L);

#endif
