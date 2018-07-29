#include "lua_oid.h"

int lua_git_oid_fromstr (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : oid_string");
	}

	luagit2_oid *obj_id;
	const char *string_value = luaL_checkstring(L, 1);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_oid_fromstr(&local_id, string_value),
	    "Error generating oid object from given string", NULL);
	obj_id->oid = local_id;

	return 1;
}

int lua_git_oid_fromstrn (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : oid_string, length");
	}

	luagit2_oid *obj_id;
	const char *string_value = luaL_checkstring(L, 1);
	size_t length = luaL_checkinteger(L, 2);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_oid_fromstrn(&local_id, string_value, length),
	    "Error generating oid object from given length of string", NULL);
	obj_id->oid = local_id;

	return 1;
}

int lua_git_oid_cmp (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_oid, luagit2_oid");
	}

	const luagit2_oid *oid_A;
	const luagit2_oid *oid_B;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	oid_B = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");
	int result = git_oid_cmp(&(oid_A->oid), &(oid_B->oid));

	lua_pushinteger(L, result);
	return 1;
}

int lua_git_oid_ncmp (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_oid, luagit2_oid, length");
	}

	const luagit2_oid *oid_A;
	const luagit2_oid *oid_B;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	oid_B = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");
	size_t length = luaL_checkinteger(L, 3);
	int result = git_oid_ncmp(&(oid_A->oid), &(oid_B->oid), length);

	lua_pushinteger(L, result);
	return 1;
}

int lua_git_oid_fmt (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_oid");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");

	char result_str[GIT_OID_HEXSZ + 1];
	result_str[GIT_OID_HEXSZ] = '\0';
	git_oid_fmt(result_str, &(oid_A->oid));

	lua_pushstring(L, result_str);
	return 1;
}

int lua_git_oid_nfmt (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_oid, length");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	size_t length = luaL_checkinteger(L, 2);
	char result_str[GIT_OID_HEXSZ + 1];
	result_str[GIT_OID_HEXSZ] = '\0';
	git_oid_nfmt(result_str, length, &(oid_A->oid));

	lua_pushstring(L, result_str);
	return 1;
}

int lua_git_oid_pathfmt (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_oid");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");

	char result_str[GIT_OID_HEXSZ + 2];
	result_str[GIT_OID_HEXSZ + 1] = '\0';
	git_oid_pathfmt(result_str, &(oid_A->oid));

	lua_pushstring(L, result_str);
	return 1;
}

int lua_git_oid_iszero (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_oid");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	int result = git_oid_iszero(&(oid_A->oid));

	lua_pushboolean(L, result);
	return 1;
}

int lua_git_oid_strcmp (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_oid, string");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	const char *string_to_compare = luaL_checkstring(L, 2);
	int result = git_oid_strcmp(&(oid_A->oid), string_to_compare);

	lua_pushinteger(L, result);

	return 1;
}

int lua_git_oid_tostr (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_oid");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	char buffer[1024] = {0};
	char *string_value = git_oid_tostr(buffer, sizeof(buffer), &(oid_A->oid));
	lua_pushstring(L, string_value);
	*buffer = NULL;
	return 1;
}

int lua_git_oid_tostr_s (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_oid");
	}

	const luagit2_oid *oid_A;

	oid_A = (luagit2_oid *)luaL_checkudata(L, 1, "luagit2_oid");
	const char *string_value = git_oid_tostr_s(&(oid_A->oid));

	lua_pushstring(L, string_value);

	return 1;
}
