#include "lua_annotated.h"

int lua_git_annotated_commit_from_ref (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,luagit2_reference");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_reference *lua_ref = (luagit2_reference *)luaL_checkudata(L, 2, "luagit2_reference");

	luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)lua_newuserdata(L, sizeof(*lua_annotated_commit));
	lua_annotated_commit->annotated_commit  = NULL;

	luaL_newmetatable(L, "luagit2_annotated_commit");
	lua_setmetatable(L, -2);

	git_annotated_commit *local_annotated_commit;
	check_error_long(git_annotated_commit_from_ref(&local_annotated_commit, Repo->repo, lua_ref->reference),
	    "Error create an annotated commit from given reference", NULL);

	lua_annotated_commit->annotated_commit  = local_annotated_commit;

	return 1;
}

int lua_git_annotated_commit_from_revspec (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,string_revspec");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *revspec = luaL_checkstring(L, 2);

	luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)lua_newuserdata(L, sizeof(*lua_annotated_commit));
	lua_annotated_commit->annotated_commit  = NULL;

	luaL_newmetatable(L, "luagit2_annotated_commit");
	lua_setmetatable(L, -2);

	git_annotated_commit *local_annotated_commit;
	check_error_long(git_annotated_commit_from_revspec(&local_annotated_commit, Repo->repo, revspec),
	    "Error create an annotated commit from given refspec string", NULL);

	lua_annotated_commit->annotated_commit  = local_annotated_commit;

	return 1;
}

int lua_git_annotated_commit_lookup (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,luagit2_oid");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");

	luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)lua_newuserdata(L, sizeof(*lua_annotated_commit));
	lua_annotated_commit->annotated_commit  = NULL;

	luaL_newmetatable(L, "luagit2_annotated_commit");
	lua_setmetatable(L, -2);

	git_annotated_commit *local_annotated_commit;
	check_error_long(git_annotated_commit_lookup(&local_annotated_commit, Repo->repo, &(lua_oid->oid)),
	    "Error create an annotated commit from given object id", NULL);

	lua_annotated_commit->annotated_commit  = local_annotated_commit;

	return 1;
}

int lua_git_annotated_commit_from_fetchhead (lua_State *L) {

	if (lua_gettop(L) != 4) {
		return luaL_error(L, "expecting exactly 4 arguments : luagit2_repository,(string)branch_name,(string)remote_url,luagit2_oid");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *branch_name = luaL_checkstring(L, 2);
	const char *remote_url = luaL_checkstring(L, 3);
	const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 4, "luagit2_oid");

	luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)lua_newuserdata(L, sizeof(*lua_annotated_commit));
	lua_annotated_commit->annotated_commit  = NULL;

	luaL_newmetatable(L, "luagit2_annotated_commit");
	lua_setmetatable(L, -2);

	git_annotated_commit *local_annotated_commit;
	check_error_long(git_annotated_commit_from_fetchhead(&local_annotated_commit, Repo->repo, branch_name, remote_url, &(lua_oid->oid)),
	    "Error create an annotated commit from given object id", NULL);

	lua_annotated_commit->annotated_commit  = local_annotated_commit;

	return 1;
}

int lua_git_annotated_commit_id(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_annotated_commit");
	}

	const luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)luaL_checkudata(L, 1, "luagit2_annotated_commit");

	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	const git_oid *local_id = git_annotated_commit_id(lua_annotated_commit->annotated_commit);
	obj_id->oid = *local_id;

	return 1;
}

int lua_git_annotated_commit_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_annotated_commit");
	}

	const luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)luaL_checkudata(L, 1, "luagit2_annotated_commit");
	git_annotated_commit_free(lua_annotated_commit->annotated_commit);

	return 1;
}
