#include "lua_status.h"

int lua_git_status_list_new(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_repository");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");

	luagit2_status_list *lua_status_list = (luagit2_status_list *)lua_newuserdata(L, sizeof(*lua_status_list));
	lua_status_list->status_list = NULL;

	luaL_newmetatable(L, "luagit2_status_list");
	lua_setmetatable(L, -2);

	git_status_options status_opt = GIT_STATUS_OPTIONS_INIT ;

	git_status_list *local_status_list ;
	check_error_long(git_status_list_new(&local_status_list, Repository->repo, &status_opt),
	    "Error getting status list for given repo", NULL);

	lua_status_list->status_list  = local_status_list;

	return 1;
}

int lua_git_status_list_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_status_list");
	}

	const luagit2_status_list *lua_status_list = (luagit2_status_list *)luaL_checkudata(L, 1, "luagit2_status_list");
	git_status_list_free(lua_status_list->status_list);

	return 1;
}

int lua_git_status_list_entrycount (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_status_list");
	}

	const luagit2_status_list *lua_status_list = (luagit2_status_list *)luaL_checkudata(L, 1, "luagit2_status_list");
	size_t count = git_status_list_entrycount(lua_status_list->status_list);

	lua_pushnumber(L,count);
	return 1;
}

int lua_git_status_byindex(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_status_list,(number)index_number");
	}

	const luagit2_status_list *lua_status_list = (luagit2_status_list *)luaL_checkudata(L, 1, "luagit2_status_list");
	const size_t index_number = luaL_checkinteger(L, 2);

	luagit2_status_entry *lua_status_entry = (luagit2_status_entry *)lua_newuserdata(L, sizeof(*lua_status_entry));
	lua_status_entry->status_entry = NULL;

	luaL_newmetatable(L, "luagit2_status_entry");
	lua_setmetatable(L, -2);

	git_status_options status_opt = GIT_STATUS_OPTIONS_INIT ;

	lua_status_entry->status_entry  = git_status_byindex(lua_status_list->status_list, index_number);

	return 1;
}

