#include "lua_odb.h"

int lua_git_odb_exists(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_odb,luagit2_oid");
	}

	const luagit2_odb *lua_odb = (luagit2_odb *)luaL_checkudata(L, 1, "luagit2_odb");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");

	int result = git_odb_exists(lua_odb->odb, &(obj_id->oid));

	lua_pushboolean(L, result);

	return 1;
}

int lua_git_odb_free(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_odb");
	}

	const luagit2_odb *lua_odb = (luagit2_odb *)luaL_checkudata(L, 1, "luagit2_odb");
	git_odb_free(lua_odb->odb);

	return 1;
}

int lua_git_odb_hash(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : (string)data,luagit2_otype");
	}

	const char *string_value = luaL_checkstring(L, 1);
	const luagit2_otype *lua_otype = (luagit2_otype *)luaL_checkudata(L, 2, "luagit2_otype");
	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_odb_hash(&local_id, (void *)string_value, strlen(string_value), lua_otype->otype),
	    "Error generating hash for given string", NULL);

	obj_id->oid = local_id;

	return 1;
}

int lua_git_odb_hashfile(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : (string)path,luagit2_otype");
	}

	const char *path = luaL_checkstring(L, 1);
	const luagit2_otype *lua_otype = (luagit2_otype *)luaL_checkudata(L, 2, "luagit2_otype");
	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_odb_hashfile(&local_id, path, lua_otype->otype),
	    "Error generating hash for given file", NULL);

	obj_id->oid = local_id;

	return 1;
}

int lua_git_odb_object_free(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_odb_object");
	}

	const luagit2_odb_object *lua_odb_obj = (luagit2_odb_object *)luaL_checkudata(L, 1, "luagit2_odb_object");
	git_odb_object_free(lua_odb_obj->odb_object);

	return 1;
}

int lua_git_odb_object_id(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_odb_object");
	}

	const luagit2_odb_object *lua_odb_obj = (luagit2_odb_object *)luaL_checkudata(L, 1, "luagit2_odb_object");
	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *(git_odb_object_id(lua_odb_obj->odb_object));

	return 1;
}

int lua_git_odb_object_size(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_odb_object");
	}

	const luagit2_odb_object *lua_odb_obj = (luagit2_odb_object *)luaL_checkudata(L, 1, "luagit2_odb_object");

	size_t size = git_odb_object_size(lua_odb_obj->odb_object);
	lua_pushnumber(L, size);

	return 1;
}

int lua_git_odb_object_type(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_odb_object");
	}

	const luagit2_odb_object *lua_odb_obj = (luagit2_odb_object *)luaL_checkudata(L, 1, "luagit2_odb_object");

	luagit2_otype *obj_type = (luagit2_otype *)lua_newuserdata(L, sizeof(*obj_type));

	luaL_newmetatable(L, "luagit2_otype");
	lua_setmetatable(L, -2);

	obj_type->otype = git_odb_object_type(lua_odb_obj->odb_object);

	return 1;
}

int lua_git_odb_open(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : (string)path");
	}

	const char *path = luaL_checkstring(L, 1);

	luagit2_odb *lua_odb = (luagit2_odb *)lua_newuserdata(L, sizeof(*lua_odb));
	lua_odb->odb = NULL;

	luaL_newmetatable(L, "luagit2_odb");
	lua_setmetatable(L, -2);

	git_odb *local_odb;
	check_error_long(git_odb_open(&local_odb, path),
	    "Error opening odb from given path", NULL);

	lua_odb->odb = local_odb;

	return 1;
}

int lua_git_odb_read(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_odb,luagit2_oid");
	}

	const luagit2_odb *lua_odb = (luagit2_odb *)luaL_checkudata(L, 1, "luagit2_odb");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 2, "luagit2_oid");

	luagit2_odb_object *lua_odb_obj = (luagit2_odb_object *)lua_newuserdata(L, sizeof(*lua_odb_obj));
	lua_odb_obj->odb_object = NULL;

	luaL_newmetatable(L, "luagit2_odb_object");
	lua_setmetatable(L, -2);

	git_odb_object *local_odb_object;
	check_error_long(git_odb_read(&local_odb_object, lua_odb->odb, &(obj_id->oid)),
	    "Error looking up the object id in the repo", NULL);

	lua_odb_obj->odb_object = local_odb_object;

	return 1;
}

int lua_git_odb_refresh(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_odb");
	}

	const luagit2_odb *lua_odb = (luagit2_odb *)luaL_checkudata(L, 1, "luagit2_odb");
	check_error_long(git_odb_refresh(lua_odb->odb), "Error refreshing odb", NULL);

	return 1;
}

int lua_git_odb_write(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 argument : luagit2_odb,(string)buffer,luagit2_otype");
	}

	const luagit2_odb *lua_odb = (luagit2_odb *)luaL_checkudata(L, 1, "luagit2_odb");
	const char *buffer = luaL_checkstring(L, 2);
	const luagit2_otype *lua_otype = (luagit2_otype *)luaL_checkudata(L, 3, "luagit2_otype");
	luagit2_oid *obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_id;
	check_error_long(git_odb_write(&local_id, lua_odb->odb, (void *)buffer, strlen(buffer), lua_otype->otype),
	    "Error generating hash for given file", NULL);

	obj_id->oid = local_id;

	return 1;
}
