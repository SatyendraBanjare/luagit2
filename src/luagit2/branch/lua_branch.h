#ifndef _lua_branch_h
#define _lua_branch_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_branch_create (lua_State *L) {
    luagit2_reference *lua_ref;
    const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
    const char *branch_name = luaL_checkstring(L,2);
    const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L,3);
    const int force = luaL_checkinteger(L,4);

    lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
    lua_ref->reference  = NULL;
 
    luaL_getmetatable(L, "luagit2_reference");
    
    lua_setmetatable(L, -2);
    
    git_reference *local_ref;
    git_branch_create(&local_ref,lua_repo->repo,branch_name,lua_commit->commit,force); 
    lua_ref->reference  = local_ref;
    return 1;
}

static int lua_git_branch_create_from_annotated (lua_State *L) {
    luagit2_reference *lua_ref;
    const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
    const char *branch_name = luaL_checkstring(L,2);
    const luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)lua_touserdata(L,3);
    const int force = luaL_checkinteger(L,4);

    lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
    lua_ref->reference  = NULL;
 
    luaL_getmetatable(L, "luagit2_reference");
    
    lua_setmetatable(L, -2);
    
    git_reference *local_ref;
    git_branch_create_from_annotated(&local_ref,lua_repo->repo,branch_name,
    				lua_annotated_commit->annotated_commit,force); 
    lua_ref->reference  = local_ref;
    return 1;
}

static int lua_git_branch_delete (lua_State *L) {
    const luagit2_reference *lua_ref_branch = (luagit2_reference *)lua_touserdata(L, 1);
    git_branch_delete(lua_ref_branch->reference); 
    return 1;
}

static int lua_git_branch_is_checked_out (lua_State *L) {
    const luagit2_reference *lua_ref_branch = (luagit2_reference *)lua_touserdata(L, 1);
    int is_checked_out = git_branch_is_checked_out(lua_ref_branch->reference);
    lua_pushinteger(L,is_checked_out);
    return 1;
}

static int lua_git_branch_is_head (lua_State *L) {
    const luagit2_reference *lua_ref_branch = (luagit2_reference *)lua_touserdata(L, 1);
    int is_head = git_branch_is_head(lua_ref_branch->reference);
    lua_pushinteger(L,is_head);
    return 1;
}

static int lua_git_branch_iterator_new (lua_State *L) {
    luagit2_branch_iterator *lua_branch_iterator;
    const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
    const luagit2_branch_type *list_flags = (luagit2_branch_type *)lua_touserdata(L,2);

    lua_branch_iterator = (luagit2_branch_iterator *)lua_newuserdata(L, sizeof(*lua_branch_iterator));
    lua_branch_iterator->branch_iterator  = NULL;
 
    luaL_getmetatable(L, "luagit2_branch_iterator");
    
    lua_setmetatable(L, -2);
    
    git_branch_iterator *local_branch_iter;
    git_branch_iterator_new(&local_branch_iter,lua_repo->repo,list_flags->branch_type); 
    lua_branch_iterator->branch_iterator  = local_branch_iter;
    return 1;
}

static int lua_git_branch_lookup (lua_State *L) {
    luagit2_reference *lua_ref;
    const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
    const char *branch_name = luaL_checkstring(L,2);
    const luagit2_branch_type *lua_branch_type = (luagit2_branch_type *)lua_touserdata(L,3);

    lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
    lua_ref->reference  = NULL;
 
    luaL_getmetatable(L, "luagit2_reference");
    
    lua_setmetatable(L, -2);
    
    git_reference *local_ref;
    git_branch_lookup(&local_ref,lua_repo->repo,branch_name,lua_branch_type->branch_type); 
    lua_ref->reference  = local_ref;
    return 1;
}

static int lua_git_branch_move (lua_State *L) {
    luagit2_reference *lua_ref;
    const luagit2_reference *lua_branch_from = (luagit2_reference *)lua_touserdata(L, 1);
    const char *new_branch_name = luaL_checkstring(L,2);
    const int force = luaL_checkinteger(L,3);

    lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
    lua_ref->reference  = NULL;
 
    luaL_getmetatable(L, "luagit2_reference");
    
    lua_setmetatable(L, -2);
    
    git_reference *local_ref;
    git_branch_move(&local_ref,lua_branch_from->reference,new_branch_name,force); 
    lua_ref->reference  = local_ref;
    return 1;
}

static int lua_git_branch_name (lua_State *L) {
    const luagit2_reference *lua_branch_from = (luagit2_reference *)lua_touserdata(L, 1);
    const char *branch_name;
    git_branch_name(&branch_name,lua_branch_from->reference); 
    lua_pushstring(L,branch_name);
    return 1;
}

static int lua_git_branch_next (lua_State *L) {
    luagit2_reference *lua_ref;
    luagit2_branch_type *lua_branch_t = (luagit2_branch_type *)lua_touserdata(L, 1);
    luagit2_branch_iterator *lua_branch_iterator = (luagit2_branch_iterator *)lua_touserdata(L,3);

    lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
    lua_ref->reference  = NULL;
 
    luaL_getmetatable(L, "luagit2_reference");
    
    lua_setmetatable(L, -2);
    
    git_reference *local_ref;
    git_branch_next(&local_ref,&(lua_branch_t->branch_type),lua_branch_iterator->branch_iterator); 
    lua_ref->reference  = local_ref;
    return 1;
}

static int lua_git_branch_set_upstream (lua_State *L) {
    const luagit2_reference *lua_branch_from = (luagit2_reference *)lua_touserdata(L, 1);
    const char *upstream_name = luaL_checkstring(L,2);
    git_branch_set_upstream(lua_branch_from->reference,upstream_name);
    return 1;
}

static int lua_git_branch_upstream (lua_State *L) {
    luagit2_reference *lua_ref;
    const luagit2_reference *lua_branch_base = (luagit2_reference *)lua_touserdata(L, 1);

    lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
    lua_ref->reference  = NULL;
 
    luaL_getmetatable(L, "luagit2_reference");
    
    lua_setmetatable(L, -2);
    
    git_reference *local_ref;
    git_branch_upstream(&local_ref,lua_branch_base->reference); 
    lua_ref->reference  = local_ref;
    return 1;
}
#endif
