#include "lua_graph.h"

int lua_git_graph_ahead_behind(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,(local)luagit2_oid,(upstream)luagit2_oid");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *local_oid = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	const luagit2_oid *upstream_oid = (luagit2_oid *)luaL_checkudata(L, 3,"luagit2_oid");

	size_t ahead, behind;

	check_error_long(git_graph_ahead_behind(&ahead,&behind,Repository->repo,&(local_oid->oid),&(upstream_oid->oid)),
		"Error getting graph details between given commits",NULL);

	lua_pushnumber(L,ahead);
	lua_pushnumber(L,behind);

	return 2;
}

int lua_git_graph_descendant_of(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,(commit)luagit2_oid,(ancestor_commit)luagit2_oid");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *commit_oid = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	const luagit2_oid *ancestor_oid = (luagit2_oid *)luaL_checkudata(L, 3,"luagit2_oid");

	int is_descendent = git_graph_descendant_of(Repository->repo,&(commit_oid->oid),&(ancestor_oid->oid));
	lua_pushboolean(L,is_descendent);

	return 1;
}
