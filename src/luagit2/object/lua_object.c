#include "lua_object.h"

int lua_git_object__size(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_otype");
    }

	const luagit2_otype *Type = (luagit2_otype *)luaL_checkudata(L, 1,"luagit2_otype");
	size_t size = git_object__size( Type->otype);

	lua_pushinteger(L, size);

	return 1;
}

int lua_git_object_free(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_object");
    }

	luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 1,"luagit2_object");
	git_object_free( lua_object->object);

	return 1;
}

int lua_git_object_id(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_object");
    }

	luagit2_oid *obj_id;
	const luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 1,"luagit2_object");

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *(git_object_id(lua_object->object));

	return 1;
}

int lua_git_object_lookup(lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_repository,luagit2_oid,luagit2_otype");
    }

	luagit2_object *lua_object;
	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *object_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	const luagit2_otype *Type = (luagit2_otype *)luaL_checkudata(L, 3,"luagit2_otype");

	lua_object = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_object));
	lua_object->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	git_object *local_obj;
	check_error_long(git_object_lookup(&local_obj, Repository->repo, &(object_id->oid), Type->otype)
	    , "Error looking up the object in given repo", NULL);
	lua_object->object = local_obj;

	return 1;
}

int lua_git_object_lookup_bypath(lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_object,path,luagit2_otype");
    }

	luagit2_object *lua_object;
	const luagit2_object *treeish = (luagit2_object *)luaL_checkudata(L, 1,"luagit2_object");
	const char *path = luaL_checkstring(L, 2);
	const luagit2_otype *Type = (luagit2_otype *)luaL_checkudata(L, 3,"luagit2_otype");

	lua_object = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_object));
	lua_object->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	git_object *local_obj;
	check_error_long(git_object_lookup_bypath(&local_obj, treeish->object, path, Type->otype)
	    , "Error looking up the object in given repo by its path", NULL);
	lua_object->object = local_obj;

	return 1;
}

int lua_git_object_lookup_prefix(lua_State *L) {

	if (lua_gettop(L) != 4 ) {
        return luaL_error(L, "expecting 4 argument(s) : luagit2_repository,luagit2_oid,length(int),luagit2_otype");
    }

	luagit2_object *lua_object;
	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *object_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	size_t length = luaL_checkinteger(L, 3);
	const luagit2_otype *Type = (luagit2_otype *)luaL_checkudata(L, 4,"luagit2_otype");

	lua_object = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_object));
	lua_object->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	git_object *local_obj;
	check_error_long(git_object_lookup_prefix(&local_obj, Repository->repo, &(object_id->oid), length,
	        Type->otype), "Error looking up the object in given repo for given length prefix", NULL);
	lua_object->object = local_obj;

	return 1;
}

int lua_git_object_owner(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_object");
    }

	luagit2_repository *lua_repo;
	const luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 1,"luagit2_object");

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	lua_repo->repo = git_object_owner(lua_object->object);

	return 1;
}

int lua_git_object_short_id (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_object");
    }

	const luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 1,"luagit2_object");
	luagit2_buf *lua_out_buf;

	lua_out_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_out_buf));
	lua_out_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL,0);
	check_error_long(git_object_short_id(&local_buf, lua_object->object),
	    "Unable to get abbreviated OID", NULL);

	lua_out_buf->buf  = &local_buf;
	return 1;
}

int lua_git_object_string2type(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : type_name");
    }

	const char *type_name = luaL_checkstring(L, 1);
	luagit2_otype *obj_type;

	obj_type = (luagit2_otype *)lua_newuserdata(L, sizeof(*obj_type));

	luaL_newmetatable(L, "luagit2_otype");
	lua_setmetatable(L, -2);

	obj_type->otype = git_object_string2type(type_name);

	return 1;
}

int lua_git_object_type(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_object");
    }

	const luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 1,"luagit2_object");
	luagit2_otype *obj_type;

	obj_type = (luagit2_otype *)lua_newuserdata(L, sizeof(*obj_type));

	luaL_newmetatable(L, "luagit2_otype");
	lua_setmetatable(L, -2);

	obj_type->otype = git_object_type(lua_object->object);

	return 1;
}

int lua_git_object_type2string(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_otype");
    }

	const luagit2_otype *Type = (luagit2_otype *)luaL_checkudata(L, 1,"luagit2_otype");
	const char *type_name = git_object_type2string( Type->otype);

	lua_pushstring(L, type_name);

	return 1;
}

int lua_git_object_typeisloose(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_otype");
    }

	const luagit2_otype *Type = (luagit2_otype *)luaL_checkudata(L, 1,"luagit2_otype");
	int is_loose = git_object_typeisloose( Type->otype);

	lua_pushboolean(L, is_loose);

	return 1;
}
