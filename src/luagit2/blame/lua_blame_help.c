#include "lua_blame_help.h"

int lua_blame_hunk_signature(lua_State *L) {

	luagit2_signature *lua_sign;
	const luagit2_blame_hunk *lua_blame_hunk = (luagit2_blame_hunk *)luaL_checkudata(L, 1, "luagit2_blame_hunk");

	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	lua_sign->sign = (lua_blame_hunk->blame_hunk)->final_signature ;
	
	return 1;
}