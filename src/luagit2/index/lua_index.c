#include "lua_index.h"

int lua_git_index_add(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index, luagit2_index_entry");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 2, "luagit2_index_entry");

	check_error_long(git_index_add(Index->index, Index_entry->index_entry),
	    "Unable to add/update index entry", NULL);

	return 1;

}

int lua_git_index_add_bypath(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index, (string)path");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *path = luaL_checkstring(L, 2);

	check_error_long(git_index_add_bypath(Index->index, path),
	    "Unable to add/update from file pointed by given path", NULL);

	return 1;

}

int lua_git_index_caps(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	int values = git_index_caps(Index->index);
	lua_pushinteger(L, values);

	return 1;

}

int lua_git_index_checksum(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_oid *obj_id;
	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *(git_index_checksum(Index->index));

	return 1;

}

int lua_git_index_conflict_add(lua_State *L) {

	if (lua_gettop(L) != 4) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index,(luagit2_index_entry)ancestor,\
			(luagit2_index_entry)ours,(luagit2_index_entry)theirs");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const luagit2_index_entry *Index_ancestor_entry = (luagit2_index_entry *)luaL_checkudata(L, 2, "luagit2_index_entry");
	const luagit2_index_entry *Index_our_entry = (luagit2_index_entry *)luaL_checkudata(L, 3, "luagit2_index_entry");
	const luagit2_index_entry *Index_their_entry = (luagit2_index_entry *)luaL_checkudata(L, 4, "luagit2_index_entry");

	check_error_long(git_index_conflict_add(Index->index, Index_ancestor_entry->index_entry
	        , Index_our_entry->index_entry, Index_their_entry->index_entry),
	    "Error in adding index entries to represent a conflict", NULL);

	return 1;

}

int lua_git_index_conflict_cleanup(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	git_index_conflict_cleanup(Index->index);

	return 1;

}

int lua_git_index_entry_is_conflict(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index_entry");
	}

	luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");

	int is_conflict = git_index_entry_is_conflict(Index_entry->index_entry);
	lua_pushboolean(L, is_conflict);

	return 1;

}

int lua_git_index_entry_stage(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index_entry");
	}

	luagit2_index_entry *Index_entry = (luagit2_index_entry *)luaL_checkudata(L, 1, "luagit2_index_entry");

	int stage_value = git_index_entry_stage(Index_entry->index_entry);
	lua_pushinteger(L, stage_value);

	return 1;

}

int lua_git_index_entrycount(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	int index_entry_count = git_index_entrycount(Index->index);
	lua_pushinteger(L, index_entry_count);

	return 1;

}

int lua_git_index_find(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,(string)path");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *path = luaL_checkstring(L, 2);

	size_t at_pos;
	git_index_find(&at_pos, Index->index, path);
	lua_pushinteger(L, at_pos);

	return 1;

}

int lua_git_index_find_prefix(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,(string)prefix");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *prefix = luaL_checkstring(L, 2);

	size_t at_pos;
	git_index_find_prefix(&at_pos, Index->index, prefix);
	lua_pushinteger(L, at_pos);

	return 1;

}

int lua_git_index_get_byindex(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,(integer)index_value");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	size_t n = luaL_checkinteger(L, 2);

	luagit2_index_entry *Index_entry;
	Index_entry = (luagit2_index_entry *)lua_newuserdata(L, sizeof(*Index_entry));

	luaL_newmetatable(L, "luagit2_index_entry");
	lua_setmetatable(L, -2);


	Index_entry->index_entry = git_index_get_byindex(Index->index, n);

	return 1;
}

int lua_git_index_get_bypath(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_index,(string)path,(integer)stage_value");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *path = luaL_checkstring(L, 2);
	int stage = luaL_checkinteger(L, 3);

	luagit2_index_entry *Index_entry;
	Index_entry = (luagit2_index_entry *)lua_newuserdata(L, sizeof(*Index_entry));

	luaL_newmetatable(L, "luagit2_index_entry");
	lua_setmetatable(L, -2);


	Index_entry->index_entry = git_index_get_bypath(Index->index, path, stage);

	return 1;
}

int lua_git_index_has_conflicts(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	int has_conflicts = git_index_has_conflicts(Index->index);
	lua_pushboolean(L, has_conflicts);

	return 1;

}

int lua_git_index_open(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : (string)index_file_path");
	}

	const char *path = luaL_checkstring(L, 1);

	luagit2_index *lua_index;
	lua_index = (luagit2_index *)lua_newuserdata(L, sizeof(*lua_index));
	lua_index->index = NULL;

	luaL_newmetatable(L, "luagit2_index");
	lua_setmetatable(L, -2);

	git_index *local_index;
	check_error_long(git_index_open(&local_index, path),
	    "Unable to create git object of index type from file at given path", NULL);
	lua_index->index = local_index;
	return 1;
}

int lua_git_index_owner (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_repository *lua_repo;
	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	lua_repo->repo = git_index_owner(Index->index);
	return 1;
}

int lua_git_index_path(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	char *index_path = git_index_path(Index->index);
	lua_pushstring(L, index_path);

	return 1;

}

int lua_git_index_read(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_index,(integer)force");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	int force = luaL_checkinteger(L, 2);
	check_error_long(git_index_read(Index->index, force),
	    "Unable to read from hard disk to update index", NULL);

	return 1;

}

int lua_git_index_read_tree(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,luagit2_tree");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 2, "luagit2_tree");
	check_error_long(git_index_read_tree(Index->index, Tree->tree),
	    "Unable to read a tree into index file", NULL);

	return 1;

}

int lua_git_index_remove(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_index,(string)path,(integer)stage_value");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *path = luaL_checkstring(L, 2);
	int stage = luaL_checkinteger(L, 3);

	check_error_long(git_index_remove(Index->index, path, stage),
	    "Unable to remove entry from index", NULL);

	return 1;
}

int lua_git_index_remove_bypath(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,(string)path");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *path = luaL_checkstring(L, 2);

	check_error_long(git_index_remove_bypath(Index->index, path),
	    "Unable to remove entry from index that corresponds to file path provided", NULL);

	return 1;
}

int lua_git_index_remove_directory(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_index,(string)path,(integer)stage_value");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const char *dir_path = luaL_checkstring(L, 2);
	int stage = luaL_checkinteger(L, 3);

	check_error_long(git_index_remove_directory(Index->index, dir_path, stage),
	    "Unable to remove all entries at given directory path", NULL);

	return 1;
}

int lua_git_index_set_caps(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,(integer)caps");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	int caps = luaL_checkinteger(L, 2);

	check_error_long(git_index_set_caps(Index->index, caps),
	    "Unable to set caps for the given index", NULL);

	return 1;
}


int lua_git_index_set_version(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_index,(integer)version");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	unsigned int version = luaL_checkinteger(L, 2);

	check_error_long(git_index_set_version(Index->index, version),
	    "Unable to set the index version", NULL);

	return 1;
}

int lua_git_index_version(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	unsigned int version_number = git_index_version(Index->index);
	lua_pushnumber(L, version_number);

	return 1;
}

int lua_git_index_write(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	check_error_long(git_index_write(Index->index),
	    "Unable to write to given index", NULL);

	return 1;
}

int lua_git_index_write_tree(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_oid *obj_id;
	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_index_write_tree(&local_id, Index->index),
	    "Unable to write tree to index", NULL);
	obj_id->oid = local_id;

	return 1;

}

int lua_git_index_write_tree_to(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository");
	}

	luagit2_oid *obj_id;
	const luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 2, "luagit2_repository");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_index_write_tree_to(&local_id, Index->index, Repo->repo),
	    "Unable to write the index as a tree to the given repository", NULL);
	obj_id->oid = local_id;

	return 1;

}

int lua_git_index_free(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_index");
	}

	luagit2_index *Index = (luagit2_index *)luaL_checkudata(L, 1, "luagit2_index");
	git_index_free( Index->index);

	return 1;
};
