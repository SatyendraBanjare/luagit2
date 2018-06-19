#ifndef _lua_cred_h
#define _lua_cred_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include "../common/lua_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

int lua_git_cred_default_new (lua_State *L);
int lua_git_cred_ssh_key_from_agent (lua_State *L);
int lua_git_cred_ssh_key_memory_new (lua_State *L) ;
int lua_git_cred_ssh_key_new (lua_State *L);
int lua_git_cred_username_new (lua_State *L);
int lua_git_cred_userpass_plaintext_new (lua_State *L);
int lua_git_cred_free (lua_State *L);

#endif
