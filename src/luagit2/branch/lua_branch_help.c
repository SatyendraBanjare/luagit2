#include "lua_branch_help.h"

int get_type_GIT_BRANCH_LOCAL(lua_State *L){

	if (lua_gettop(L) != 0) {
        return luaL_error(L, "expecting No argument ");
    }

	luagit2_branch_type *Branch_type;
	Branch_type = (luagit2_branch_type *)lua_newuserdata(L, sizeof(*Branch_type));

	luaL_newmetatable(L, "luagit2_branch_type");
	lua_setmetatable(L, -2);

	Branch_type->branch_type = GIT_BRANCH_LOCAL;

	return 1;
}

int get_type_GIT_BRANCH_REMOTE(lua_State *L){

	if (lua_gettop(L) != 0) {
        return luaL_error(L, "expecting No argument ");
    }

	luagit2_branch_type *Branch_type;
	Branch_type = (luagit2_branch_type *)lua_newuserdata(L, sizeof(*Branch_type));

	luaL_newmetatable(L, "luagit2_branch_type");
	lua_setmetatable(L, -2);

	Branch_type->branch_type = GIT_BRANCH_REMOTE;

	return 1;
}
