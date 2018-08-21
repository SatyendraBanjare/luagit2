#include "lua_index_help.h"

int lua_git_index_entry_get_path(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		lua_pushstring(L, (Index_entry->index_entry)->path);
		return 1;
	} else {
		luaL_error(L, null_err);
	}
}

int lua_git_index_entry_get_filemode(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		lua_pushinteger(L, (int)(Index_entry->index_entry)->mode);
		return 1;
	} else {
		luaL_error(L, null_err);
	}
}

int lua_git_index_entry_get_filesize(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		lua_pushinteger(L, (int)(Index_entry->index_entry)->file_size);
		return 1;
	} else {
		luaL_error(L, null_err);
	}
}

int lua_git_index_entry_get_stage(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		lua_pushinteger(L, git_index_entry_stage(Index_entry->index_entry));
		return 1;
	} else {
		luaL_error(L, null_err);
	}
}

int lua_git_index_entry_get_oid_str(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		char out[GIT_OID_HEXSZ + 1];
		out[GIT_OID_HEXSZ] = '\0';
		git_oid_fmt(out, &(Index_entry->index_entry)->id);
		lua_pushstring(L, out);
		return 1;
	} else {
		luaL_error(L, null_err);
	}
}

int lua_git_index_entry_get_dev_inode(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		lua_pushinteger(L, (Index_entry->index_entry)->dev);
		lua_pushinteger(L, (Index_entry->index_entry)->ino);
		return 2;
	} else {
		luaL_error(L, null_err);
	}
}

int lua_git_index_entry_get_UID_GID(lua_State *L) {
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");
	if ((Index_entry->index_entry) != NULL) {
		lua_pushinteger(L, (Index_entry->index_entry)->uid);
		lua_pushinteger(L, (Index_entry->index_entry)->gid);
		return 2;
	} else {
		luaL_error(L, null_err);
	}
}