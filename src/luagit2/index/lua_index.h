#ifndef _lua_index_h
#define _lua_index_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_index_write_tree(lua_State *L) {
    luagit2_oid *obj_id;
    const luagit2_index *Index = (luagit2_index *)lua_touserdata(L, 1);
	
    obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

    luaL_getmetatable(L, "luagit2_oid");
    lua_setmetatable(L, -2);
    
    git_oid local_id;
    git_index_write_tree(&local_id,Index->index); 
   	obj_id->oid = local_id;
 
}

#endif
