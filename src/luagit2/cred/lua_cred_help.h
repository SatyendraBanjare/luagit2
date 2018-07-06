#ifndef _lua_cred_help_h
#define _lua_cred_help_h

#include "../common/lua_common.h"

int lua_git_cred_username_details(lua_State *L);
int lua_git_cred_userpass_details(lua_State *L);
int lua_git_cred_ssh_key_from_agent_details(lua_State *L);

#endif