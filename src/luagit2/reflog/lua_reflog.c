#include "lua_reflog.h"

int lua_git_reflog_read(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository, (string) name");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *name = luaL_checkstring(L, 2);

	luagit2_reflog *lua_reflog = (luagit2_reflog *)lua_newuserdata(L, sizeof(*lua_reflog));
	lua_reflog->reflog = NULL;

	luaL_newmetatable(L, "luagit2_reflog");
	lua_setmetatable(L, -2);

	git_reflog *local_reflog;
	check_error_long(git_reflog_read(&local_reflog, Repository->repo, name),
	    "Error getting reflog for given reference ", NULL);

	lua_reflog->reflog = local_reflog;

	return 1;
}

int lua_git_reflog_entrycount(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: luagit2_reflog");
	}

	const luagit2_reflog *lua_reflog = (luagit2_reflog *)luaL_checkudata(L, 1, "luagit2_reflog");

	size_t entry_count = git_reflog_entrycount(lua_reflog->reflog);
	lua_pushnumber(L, entry_count);

	return 1;
}

int lua_git_reflog_free(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: luagit2_reflog");
	}

	const luagit2_reflog *lua_reflog = (luagit2_reflog *)luaL_checkudata(L, 1, "luagit2_reflog");

	git_reflog_free(lua_reflog->reflog);

	return 1;
}

int lua_git_reflog_entry_byindex(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments: luagit2_reflog,(number)index");
	}

	const luagit2_reflog *lua_reflog = (luagit2_reflog *)luaL_checkudata(L, 1, "luagit2_reflog");
	const size_t index = luaL_checknumber(L, 2);

	luagit2_reflog_entry *lua_reflog_entry = (luagit2_reflog_entry *)lua_newuserdata(L, sizeof(*lua_reflog_entry));
	lua_reflog_entry->reflog_entry = NULL;

	luaL_newmetatable(L, "luagit2_reflog_entry");
	lua_setmetatable(L, -2);

	lua_reflog_entry->reflog_entry = git_reflog_entry_byindex(lua_reflog->reflog, index);

	return 1;
}

int lua_git_reflog_entry_committer(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: luagit2_reflog_entry");
	}

	const luagit2_reflog_entry *lua_reflog_entry = (luagit2_reflog_entry *)luaL_checkudata(L, 1, "luagit2_reflog_entry");

	luagit2_signature *lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign  = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	lua_sign->sign = git_reflog_entry_committer(lua_reflog_entry->reflog_entry);

	return 1;
}

int lua_git_reflog_entry_message(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: luagit2_reflog_entry");
	}

	const luagit2_reflog_entry *lua_reflog_entry = (luagit2_reflog_entry *)luaL_checkudata(L, 1, "luagit2_reflog_entry");
	const char *message = git_reflog_entry_message(lua_reflog_entry->reflog_entry);

	lua_pushstring(L, message);

	return 1;
}

int lua_git_reflog_entry_id_new (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: luagit2_reflog_entry");
	}

	const luagit2_reflog_entry *lua_reflog_entry = (luagit2_reflog_entry *)luaL_checkudata(L, 1, "luagit2_reflog_entry");
	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *git_reflog_entry_id_new(lua_reflog_entry->reflog_entry);

	return 1;
}

int lua_git_reflog_entry_id_old (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: luagit2_reflog_entry");
	}

	const luagit2_reflog_entry *lua_reflog_entry = (luagit2_reflog_entry *)luaL_checkudata(L, 1, "luagit2_reflog_entry");
	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *git_reflog_entry_id_old(lua_reflog_entry->reflog_entry);

	return 1;
}

int lua_git_reflog_delete(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository, (string) name");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *name = luaL_checkstring(L, 2);

	check_error_long(git_reflog_delete(Repository->repo, name),
	    "Error deleting reflog ", NULL);

	return 1;
}

int lua_git_reflog_drop(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 2 arguments: luagit2_reflog,(number)index,(integer)should_rewrite");
	}

	const luagit2_reflog *lua_reflog = (luagit2_reflog *)luaL_checkudata(L, 1, "luagit2_reflog");
	const size_t index = luaL_checknumber(L, 2);
	const int rewrite = luaL_checkinteger(L, 3);

	check_error_long(git_reflog_drop(lua_reflog->reflog, index, rewrite),
	    "Error dropping reflog entry at given index position", NULL);

	return 1;
}

int lua_git_reflog_append(lua_State *L) {

	if (lua_gettop(L) != 4) {
		return luaL_error(L, "expecting exactly 4 arguments: luagit2_reflog,luagit2_oid,luagit2_signature,(string)message");
	}

	const luagit2_reflog *lua_reflog = (luagit2_reflog *)luaL_checkudata(L, 1, "luagit2_reflog");
	const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");
	const luagit2_signature *lua_sign = (luagit2_signature *)luaL_checkudata(L, 3, "luagit2_signature");
	const char *message = luaL_checkstring(L, 4);

	check_error_long(git_reflog_append(lua_reflog->reflog, &(lua_oid->oid), lua_sign->sign, message),
	    "Error ammending new reflog entry", NULL);

	return 1;
}


