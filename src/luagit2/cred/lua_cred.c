#include "lua_cred.h"

int lua_git_cred_default_new (lua_State *L) {
	luagit2_cred_object *cred_obj;

	cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
	cred_obj->git_cred_object  = NULL;

	luaL_newmetatable(L, "luagit2_cred_object");

	lua_setmetatable(L, -2);

	git_cred *out;
	check_error_long(git_cred_default_new(&out),
	    "Error creating a default luagit2_cred object", NULL);

	cred_obj->git_cred_object  = out;
	git_cred_free(out);
	return 1;

}

int lua_git_cred_ssh_key_from_agent (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L, 1);

	cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
	cred_obj->git_cred_object  = NULL;

	luaL_newmetatable(L, "luagit2_cred_object");

	lua_setmetatable(L, -2);

	git_cred *out;
	check_error_long(git_cred_ssh_key_from_agent(&out, username),
	    "Error creating SSH key credential from agent name", NULL);

	cred_obj->git_cred_object  = out;
	git_cred_free(out);
	return 1;

}

int lua_git_cred_ssh_key_memory_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L, 1);
	const char *publickey = luaL_checkstring(L, 2);
	const char *privatekey = luaL_checkstring(L, 3);
	const char *passphrase = luaL_checkstring(L, 4);

	cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
	cred_obj->git_cred_object  = NULL;

	luaL_newmetatable(L, "luagit2_cred_object");

	lua_setmetatable(L, -2);

	git_cred *out;
	check_error_long(git_cred_ssh_key_memory_new(&out, username, publickey, privatekey, passphrase),
	    "Error creating in memory SSH key credentials from given details", NULL);

	cred_obj->git_cred_object  = out;
	git_cred_free(out);
	return 1;

}

int lua_git_cred_ssh_key_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L, 1);
	const char *publickey = luaL_checkstring(L, 2);
	const char *privatekey = luaL_checkstring(L, 3);
	const char *passphrase = luaL_checkstring(L, 4);

	cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
	cred_obj->git_cred_object  = NULL;

	luaL_newmetatable(L, "luagit2_cred_object");

	lua_setmetatable(L, -2);

	git_cred *out;
	check_error_long(git_cred_ssh_key_new(&out, username, publickey, privatekey, passphrase),
	    "Error creating SSH key credentials from given details", NULL);

	cred_obj->git_cred_object  = out;
	git_cred_free(out);
	return 1;

}

int lua_git_cred_username_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L, 1);

	cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
	cred_obj->git_cred_object  = NULL;

	luaL_newmetatable(L, "luagit2_cred_object");

	lua_setmetatable(L, -2);

	git_cred *out;
	check_error_long(git_cred_username_new(&out, username),
	    "Error generating credentials from given user name", NULL);

	cred_obj->git_cred_object  = out;
	git_cred_free(out);
	return 1;

}

int lua_git_cred_userpass_plaintext_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L, 1);
	const char *password = luaL_checkstring(L, 2);

	cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
	cred_obj->git_cred_object  = NULL;

	luaL_newmetatable(L, "luagit2_cred_object");

	lua_setmetatable(L, -2);

	git_cred *out;
	check_error_long(git_cred_userpass_plaintext_new(&out, username, password),
	    "Error generating credentials from given username and password ", NULL);

	cred_obj->git_cred_object  = out;
	git_cred_free(out);
	return 1;

}

int lua_git_cred_free (lua_State *L) {
	const luagit2_cred_object *cred_obj = (luagit2_cred_object *)lua_touserdata(L, 1);
	git_cred_free(cred_obj->git_cred_object);
	return 1;

}
