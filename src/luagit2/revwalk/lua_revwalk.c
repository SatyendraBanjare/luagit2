#include "lua_revwalk.h"

int lua_git_revwalk_new(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_repository");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");

	luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)lua_newuserdata(L, sizeof(*lua_revwalk));
	lua_revwalk->revwalk = NULL;

	luaL_newmetatable(L, "luagit2_revwalk");
	lua_setmetatable(L, -2);

	git_revwalk *local_revwalk ;
	check_error_long(git_revwalk_new(&local_revwalk, Repository->repo),
	    "Error getting a revwalk object for given repo", NULL);

	lua_revwalk->revwalk  = local_revwalk;

	return 1;
}

int lua_git_revwalk_next (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_revwalk");
	}

	const luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");

	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_revwalk_next(&local_id, lua_revwalk->revwalk),
	    "Error getting next commit from revision walk", NULL);
	obj_id->oid = local_id;

	return 1;
}

int lua_git_revwalk_push (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_revwalk, luagit2_oid");
	}

	luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");
	const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");

	check_error_long(git_revwalk_push(lua_revwalk->revwalk, &(lua_oid->oid)),
	    "Error pushing a commit to revision walker", NULL);

	return 1;
}

int lua_git_revwalk_push_ref (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_revwalk, (string)ref_name");
	}

	luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");
	const char *ref_name = luaL_checkstring(L, 2);

	check_error_long(git_revwalk_push_ref(lua_revwalk->revwalk, ref_name),
	    "Error pushing reference to revision walker", NULL);

	return 1;
}

int lua_git_revwalk_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_revwalk");
	}

	const luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");
	git_revwalk_free(lua_revwalk->revwalk);

	return 1;
}

int lua_git_revwalk_reset (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_revwalk");
	}

	const luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");
	git_revwalk_reset(lua_revwalk->revwalk);

	return 1;
}

int lua_git_revwalk_push_head (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_revwalk");
	}

	const luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");
	git_revwalk_push_head(lua_revwalk->revwalk);

	return 1;
}

int lua_git_revwalk_repository (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_revwalk");
	}

	const luagit2_revwalk *lua_revwalk = (luagit2_revwalk *)luaL_checkudata(L, 1, "luagit2_revwalk");

	luagit2_repository *lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	lua_repo->repo = git_revwalk_repository(lua_revwalk->revwalk);

	return 1;
}

