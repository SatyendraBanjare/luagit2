#include "lua_signature.h"

int lua_git_signature_default (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_repository");
	}

	luagit2_signature *lua_sign;
	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");

	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");

	lua_setmetatable(L, -2);

	git_signature *local_sign_obj;
	check_error_long(git_signature_default(&local_sign_obj, Repo->repo),
	    "Error getting default signature details for the given repository", NULL);

	lua_sign->sign  = local_sign_obj;
	return 1;
}

int lua_git_signature_dup (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_signature");
	}

	luagit2_signature *lua_sign;
	const luagit2_signature *source_sign = (luagit2_signature *)luaL_checkudata(L, 1, "luagit2_signature");

	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");

	lua_setmetatable(L, -2);

	git_signature *local_sign_obj;
	check_error_long(git_signature_dup(&local_sign_obj, source_sign->sign),
	    "Error generating duplicate signature", NULL);

	lua_sign->sign  = local_sign_obj;

	return 1;
}

int lua_git_signature_from_buffer (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : string");
	}

	luagit2_signature *lua_sign;
	const char *buf_string = luaL_checkstring(L, 1);

	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");

	lua_setmetatable(L, -2);

	git_signature *local_sign_obj;
	check_error_long(git_signature_from_buffer(&local_sign_obj, buf_string),
	    "Error generating signature from buffer string", NULL);

	lua_sign->sign  = local_sign_obj;

	return 1;
}

int lua_git_signature_now (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : name_string,email_string");
	}

	luagit2_signature *lua_sign;
	const char *name = luaL_checkstring(L, 1);
	const char *email = luaL_checkstring(L, 2);

	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");

	lua_setmetatable(L, -2);

	git_signature *local_sign_obj;
	check_error_long(git_signature_now(&local_sign_obj, name, email),
	    "Error generating signature from given user and email details", NULL);

	lua_sign->sign  = local_sign_obj;

	return 1;
}

int lua_git_signature_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_signature");
	}

	const luagit2_signature *lua_sign = (luagit2_signature *)luaL_checkudata(L, 1, "luagit2_signature");
	git_signature_free(lua_sign->sign);
	return 1;
}
