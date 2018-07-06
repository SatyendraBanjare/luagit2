#include "lua_cred_help.h"

int lua_git_cred_username_details(lua_State *L) {
	const luagit2_cred_object *lua_cred = (luagit2_cred_object *)lua_touserdata(L, 1);
	git_cred_username *c = (git_cred_username *)(lua_cred->git_cred_object);

	lua_pushstring(L, (c->username));

	return 1;
}

int lua_git_cred_userpass_details(lua_State *L) {
	const luagit2_cred_object *lua_cred = (luagit2_cred_object *)lua_touserdata(L, 1);
	git_cred_userpass_plaintext *c = (git_cred_userpass_plaintext *)(lua_cred->git_cred_object);

	lua_pushstring(L, (c->username));
	lua_pushstring(L, (c->password));

	return 2;
}

int lua_git_cred_ssh_key_from_agent_details(lua_State *L) {
	const luagit2_cred_object *lua_cred = (luagit2_cred_object *)lua_touserdata(L, 1);
	git_cred_ssh_key *c = (git_cred_ssh_key *)(lua_cred->git_cred_object);

	lua_pushstring(L, (c->username));

	return 1;
}
