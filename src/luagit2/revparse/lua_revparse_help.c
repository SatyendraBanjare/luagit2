#include "lua_revparse_help.h"

int lua_git_revspec_from(lua_State *L) {
	luagit2_object *lua_object;
	const luagit2_revspec *lua_revspec = (luagit2_revspec *)luaL_checkudata(L, 1, "luagit2_revspec");

	lua_object = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_object));
	lua_object->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	lua_object->object = (lua_revspec->revspec)->from ;

	return 1;
}

int lua_git_revspec_to(lua_State *L) {
	luagit2_object *lua_object;
	const luagit2_revspec *lua_revspec = (luagit2_revspec *)luaL_checkudata(L, 1, "luagit2_revspec");

	lua_object = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_object));
	lua_object->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	lua_object->object = (lua_revspec->revspec)->to ;

	return 1;
}
