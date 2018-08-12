#include "lua_blame_help.h"

int lua_blame_hunk_signature(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_blame_hunk");
	}

	luagit2_signature *lua_sign;
	const luagit2_blame_hunk *lua_blame_hunk = (luagit2_blame_hunk *)luaL_checkudata(L, 1, "luagit2_blame_hunk");

	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	lua_sign->sign = (lua_blame_hunk->blame_hunk)->final_signature ;
	
	return 1;
}

int lua_blame_hunk_commit_id(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_blame_hunk");
	}

	luagit2_oid *obj_id;
	const luagit2_blame_hunk *lua_blame_hunk = (luagit2_blame_hunk *)luaL_checkudata(L, 1, "luagit2_blame_hunk");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	
	obj_id->oid = (lua_blame_hunk->blame_hunk)->final_commit_id;
	return 1;
}
