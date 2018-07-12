#include "lua_tree.h"

int lua_git_tree_entry_byid(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_tree,luagit2_oid");
	}

	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1, "luagit2_tree");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");

	luagit2_tree_entry *lua_tree_entry;

	lua_tree_entry = (luagit2_tree_entry *)lua_newuserdata(L, sizeof(*lua_tree_entry));
	lua_tree_entry->tree_entry = NULL;

	luaL_newmetatable(L, "luagit2_tree_entry");
	lua_setmetatable(L, -2);

	lua_tree_entry->tree_entry = git_tree_entry_byid(Tree->tree, &(obj_id->oid));

	return 1;
}

int lua_git_tree_entry_byindex(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_tree,index");
	}

	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");
	size_t index = luaL_checkinteger(L, 2);

	luagit2_tree_entry *lua_tree_entry;

	lua_tree_entry = (luagit2_tree_entry *)lua_newuserdata(L, sizeof(*lua_tree_entry));
	lua_tree_entry->tree_entry = NULL;

	luaL_newmetatable(L, "luagit2_tree_entry");
	lua_setmetatable(L, -2);

	lua_tree_entry->tree_entry = git_tree_entry_byindex(Tree->tree, index);

	return 1;
}

int lua_git_tree_entry_byname(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_tree,filename");
	}

	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");
	const char *filename = luaL_checkstring(L, 2);

	luagit2_tree_entry *lua_tree_entry;

	lua_tree_entry = (luagit2_tree_entry *)lua_newuserdata(L, sizeof(*lua_tree_entry));
	lua_tree_entry->tree_entry = NULL;

	luaL_newmetatable(L, "luagit2_tree_entry");
	lua_setmetatable(L, -2);

	lua_tree_entry->tree_entry = git_tree_entry_byname(Tree->tree, filename);

	return 1;
}

int lua_git_tree_entry_bypath(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_tree,path");
	}

	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");
	const char *path = luaL_checkstring(L, 2);

	luagit2_tree_entry *lua_tree_entry;

	lua_tree_entry = (luagit2_tree_entry *)lua_newuserdata(L, sizeof(*lua_tree_entry));
	lua_tree_entry->tree_entry = NULL;

	luaL_newmetatable(L, "luagit2_tree_entry");
	lua_setmetatable(L, -2);

	git_tree_entry *local_tree_entry;
	check_error_long(git_tree_entry_bypath(&local_tree_entry, Tree->tree, path),
	    "Error in getting tree entry by given file path", NULL);
	lua_tree_entry->tree_entry = local_tree_entry;

	return 1;
}


int lua_git_tree_entry_cmp(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_tree,luagit2_tree");
	}

	const luagit2_tree_entry *Tree_entry1 = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");
	const luagit2_tree_entry *Tree_entry2 = (luagit2_tree_entry *)luaL_checkudata(L, 2,"luagit2_tree_entry");

	int result = git_tree_entry_cmp(Tree_entry1->tree_entry, Tree_entry2->tree_entry);
	lua_pushinteger(L, result);
	return 1;
}

int lua_git_tree_entry_filemode(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree_entry");
	}

	luagit2_filemode *File_Mode;
	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");

	File_Mode = (luagit2_filemode *)lua_newuserdata(L, sizeof(*File_Mode));

	luaL_newmetatable(L, "luagit2_filemode");
	lua_setmetatable(L, -2);
	File_Mode->filemode = git_tree_entry_filemode(Tree_entry->tree_entry);

	return 1;
}

int lua_git_tree_entry_filemode_raw(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree_entry");
	}

	luagit2_filemode *File_Mode;
	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");

	File_Mode = (luagit2_filemode *)lua_newuserdata(L, sizeof(*File_Mode));

	luaL_newmetatable(L, "luagit2_filemode");
	lua_setmetatable(L, -2);
	File_Mode->filemode = git_tree_entry_filemode_raw(Tree_entry->tree_entry);

	return 1;
}

int lua_git_tree_entry_id(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree_entry");
	}

	luagit2_oid *obj_id;
	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	const git_oid *local_id = git_tree_entry_id(Tree_entry->tree_entry);
	obj_id->oid = *local_id;

	return 1;
}

int lua_git_tree_entry_name (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree_entry");
	}

	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");

	const char *entry_name = git_tree_entry_name(Tree_entry->tree_entry);
	lua_pushstring(L, entry_name);
	return 1;
}

int lua_git_tree_entry_to_object (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_repository,luagit2_tree_entry");
	}

	luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 2,"luagit2_tree_entry");

	luagit2_object *lua_obj;

	lua_obj = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_obj));
	lua_obj->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	git_object *local_obj;
	check_error_long(git_tree_entry_to_object(&local_obj, Repo->repo, Tree_entry->tree_entry),
	    "Error getting the object pointed by given tree entry", NULL);

	lua_obj->object  = local_obj;

	return 1;
}

int lua_git_tree_entry_type(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree_entry");
	}

	luagit2_otype *obj_type;
	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");

	obj_type = (luagit2_otype *)lua_newuserdata(L, sizeof(*obj_type));

	luaL_newmetatable(L, "luagit2_otype");
	lua_setmetatable(L, -2);

	obj_type->otype = git_tree_entry_type(Tree_entry->tree_entry);

	return 1;
}

int lua_git_tree_entrycount(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree");
	}

	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");

	size_t result = git_tree_entrycount(Tree->tree);
	lua_pushinteger(L, result);
	return 1;
}

int lua_git_tree_id(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree");
	}

	luagit2_oid *obj_id;
	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	const git_oid *local_id = git_tree_id(Tree->tree);
	obj_id->oid = *local_id;
	return 1;
}

int lua_git_tree_lookup (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository, luagit2_oid");
	}

	luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *Tree_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");

	luagit2_tree *lua_tree;

	lua_tree = (luagit2_tree *)lua_newuserdata(L, sizeof(*lua_tree));
	lua_tree->tree = NULL;

	luaL_newmetatable(L, "luagit2_tree");
	lua_setmetatable(L, -2);

	git_tree *local_tree_obj;
	check_error_long(git_tree_lookup(&local_tree_obj, Repo->repo, &(Tree_id->oid)),
	    "Error looking up the tree id in the given repository", NULL);

	lua_tree->tree  = local_tree_obj;

	return 1;
}

int lua_git_tree_lookup_prefix (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,luagit2_oid,length");
	}

	luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *Tree_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	size_t length = luaL_checkinteger(L, 3);

	luagit2_tree *lua_tree;

	lua_tree = (luagit2_tree *)lua_newuserdata(L, sizeof(*lua_tree));
	lua_tree->tree = NULL;

	luaL_newmetatable(L, "luagit2_tree");
	lua_setmetatable(L, -2);

	git_tree *local_tree_obj;
	check_error_long(git_tree_lookup_prefix(&local_tree_obj, Repo->repo, &(Tree_id->oid), length),
	    "Error looking up the tree id in the given repository using its prefix", NULL);

	lua_tree->tree  = local_tree_obj;

	return 1;
}

int lua_git_tree_owner(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree");
	}

	luagit2_repository *lua_repo;
	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	git_repository *Repository  = git_tree_owner(Tree->tree);
	lua_repo->repo = Repository ;
	return 1;
}

int lua_git_tree_entry_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree_entry");
	}

	const luagit2_tree_entry *Tree_entry = (luagit2_tree_entry *)luaL_checkudata(L, 1,"luagit2_tree_entry");
	git_tree_entry_free( Tree_entry->tree_entry);
	return 1;
}

int lua_git_tree_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_tree");
	}

	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 1,"luagit2_tree");
	git_tree_free( Tree->tree);
	return 1;
}
