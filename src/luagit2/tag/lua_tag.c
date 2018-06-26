#include "lua_tag.h"

int lua_git_tag_annotation_create(lua_State *L) {
	luagit2_oid *obj_id;
	const luagit2_repository *Repository = (luagit2_repository *)lua_touserdata(L, 1);
	const char *tag_name = luaL_checkstring(L, 2);
	const luagit2_object *target_obj = (luagit2_object *)lua_touserdata(L, 3);
	const luagit2_signature *tagger = (luagit2_signature *)lua_touserdata(L, 4);
	const char *tag_message = luaL_checkstring(L, 5);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	check_error_long(git_tag_annotation_create(&(obj_id->oid), Repository->repo, tag_name, target_obj->object,
	        tagger->sign, tag_message), "Error creating tag for given object", NULL);

	return 1;
}

int lua_git_tag_create(lua_State *L) {
	luagit2_oid *obj_id;
	const luagit2_repository *Repository = (luagit2_repository *)lua_touserdata(L, 1);
	const char *tag_name = luaL_checkstring(L, 2);
	const luagit2_object *target_obj = (luagit2_object *)lua_touserdata(L, 3);
	const luagit2_signature *tagger = (luagit2_signature *)lua_touserdata(L, 4);
	const char *tag_message = luaL_checkstring(L, 5);
	const int force = luaL_checkinteger(L, 6);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	check_error_long(git_tag_create(&(obj_id->oid), Repository->repo, tag_name, target_obj->object,
	        tagger->sign, tag_message), "Error creating tag for given object", NULL);

	return 1;
}

int lua_git_tag_create_frombuffer(lua_State *L) {
	luagit2_oid *obj_id;
	const luagit2_repository *Repository = (luagit2_repository *)lua_touserdata(L, 1);
	const char *buffer = luaL_checkstring(L, 2);
	const int force = luaL_checkinteger(L, 3);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	check_error_long(git_tag_create_frombuffer(&(obj_id->oid), Repository->repo
	        , buffer, force), "Error creating tag using given buffer", NULL);

	return 1;
}

int lua_git_tag_create_lightweight(lua_State *L) {
	luagit2_oid *obj_id;
	const luagit2_repository *Repository = (luagit2_repository *)lua_touserdata(L, 1);
	const char *tag_name = luaL_checkstring(L, 2);
	const luagit2_object *target_obj = (luagit2_object *)lua_touserdata(L, 3);
	const int force = luaL_checkinteger(L, 4);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	check_error_long(git_tag_create_lightweight(&(obj_id->oid), Repository->repo, tag_name,
	        target_obj->object, force), "Error creating lightweight tag for given object", NULL);

	return 1;
}

int lua_git_tag_delete(lua_State *L) {
	const luagit2_repository *Repository = (luagit2_repository *)lua_touserdata(L, 1);
	const char *tag_name = luaL_checkstring(L, 2);

	check_error_long(git_tag_delete( Repository->repo, tag_name),
	    "Error deleting tag from given tag name", NULL);

	return 1;
}

int lua_git_tag_free(lua_State *L) {
	const luagit2_tag *Tag = (luagit2_tag *)lua_touserdata(L, 1);
	git_tag_free( Tag->tag);

	return 1;
}

int lua_git_tag_id(lua_State *L) {
	luagit2_oid *obj_id;
	const luagit2_tag *Tag = (luagit2_tag *)lua_touserdata(L, 1);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *(git_tag_id(Tag->tag));

	return 1;
}

int lua_git_tag_list (lua_State *L) {
	luagit2_strarray *lua_array;
	const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);

	lua_array = (luagit2_strarray *)lua_newuserdata(L, sizeof(*lua_array));
	luaL_newmetatable(L, "luagit2_strarray");
	lua_setmetatable(L, -2);

	git_strarray local_strarray;
	check_error_long(git_tag_list(&local_strarray, lua_repo->repo),
	    "Error getting a tag list", NULL);
	lua_array->array  = local_strarray;
	return 1;
}

int lua_git_tag_list_match (lua_State *L) {
	luagit2_strarray *lua_array;
	const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
	const char *pattern = luaL_checkstring(L, 2);

	lua_array = (luagit2_strarray *)lua_newuserdata(L, sizeof(*lua_array));
	luaL_newmetatable(L, "luagit2_strarray");
	lua_setmetatable(L, -2);

	git_strarray local_strarray;
	check_error_long(git_tag_list_match(&local_strarray, pattern, lua_repo->repo),
	    "Error getting a tag list matching given pattern", NULL);
	lua_array->array  = local_strarray;
	return 1;
}

int lua_git_tag_lookup (lua_State *L) {
	luagit2_tag *lua_tag;
	const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
	const luagit2_oid *lua_oid = (luagit2_oid *)lua_touserdata(L, 2);

	lua_tag = (luagit2_tag *)lua_newuserdata(L, sizeof(*lua_tag));
	lua_tag->tag  = NULL;

	luaL_newmetatable(L, "luagit2_tag");

	lua_setmetatable(L, -2);

	git_tag *local_tag;
	check_error_long(git_tag_lookup(&local_tag, lua_repo->repo, lua_oid->oid),
	    "Error looking up the tag in the given repo", NULL);
	lua_tag->tag  = local_tag;
	git_tag_free(local_tag);
	return 1;
}

int lua_git_tag_lookup_prefix (lua_State *L) {
	luagit2_tag *lua_tag;
	const luagit2_repository *lua_repo = (luagit2_repository *)lua_touserdata(L, 1);
	const luagit2_oid *lua_oid = (luagit2_oid *)lua_touserdata(L, 2);
	const size_t length = luaL_checkinteger(L, 3);

	lua_tag = (luagit2_tag *)lua_newuserdata(L, sizeof(*lua_tag));
	lua_tag->tag  = NULL;

	luaL_newmetatable(L, "luagit2_tag");

	lua_setmetatable(L, -2);

	git_tag *local_tag;
	check_error_long(git_tag_lookup_prefix(&local_tag, lua_repo->repo, lua_oid->oid, length),
	    "Error looking up the tag in the given repo using prefix", NULL);
	lua_tag->tag  = local_tag;
	git_tag_free(local_tag);
	return 1;
}

int lua_git_tag_message(lua_State *L) {
	const luagit2_tag *Tag = (luagit2_tag *)lua_touserdata(L, 1);
	const char *tag_message = git_tag_message( Tag->tag);

	lua_pushstring(L, tag_message);

	return 1;
}

int lua_git_tag_name(lua_State *L) {
	const luagit2_tag *Tag = (luagit2_tag *)lua_touserdata(L, 1);
	const char *tag_name = git_tag_name( Tag->tag);

	lua_pushstring(L, tag_name);

	return 1;
}

int lua_git_tag_owner(lua_State *L) {
	luagit2_repository *lua_repo;
	const luagit2_tag *lua_tag = (luagit2_tag *)lua_touserdata(L, 1);

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	lua_repo->repo = git_tag_owner(lua_tag->tag);

	return 1;
}

int lua_git_tag_tagger (lua_State *L) {
	const luagit2_tag *lua_tag = (luagit2_tag *)lua_touserdata(L, 1);

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	lua_sign->sign = git_tag_tagger(lua_tag->tag);

	return 1;
}

int lua_git_tag_target (lua_State *L) {
	luagit2_object *lua_git_obj;
	const luagit2_tag *lua_tag = (luagit2_tag *)lua_touserdata(L, 1);

	lua_git_obj = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_git_obj));
	lua_git_obj->object  = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	git_object *local_git_obj;
	check_error_long(git_tag_target(&local_git_obj, lua_tag->tag),
	    "Unable to find target object for the given tag", NULL);
	lua_git_obj->object = local_git_obj;
	git_object_free(local_git_obj);
	return 1;
}

int lua_git_tag_target_id(lua_State *L) {
	luagit2_oid *obj_id;
	const luagit2_tag *Tag = (luagit2_tag *)lua_touserdata(L, 1);

	obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	obj_id->oid = *(git_tag_target_id(Tag->tag));

	return 1;
}

int lua_git_tag_target_type (lua_State *L) {
	luagit2_otype *target_type;
	const luagit2_tag *lua_tag = (luagit2_tag *)lua_touserdata(L, 1);

	target_type = (luagit2_otype *)lua_newuserdata(L, sizeof(*target_type));

	luaL_newmetatable(L, "luagit2_otype");
	lua_setmetatable(L, -2);

	target_type->otype = git_tag_target_type(lua_tag->tag);
	return 1;
}
