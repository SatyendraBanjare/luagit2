#ifndef _lua_tag_h
#define _lua_tag_h

#include "../common/lua_common.h"

int lua_git_tag_annotation_create(lua_State *L);
int lua_git_tag_create(lua_State *L);
int lua_git_tag_create_frombuffer(lua_State *L);
int lua_git_tag_create_lightweight(lua_State *L);
int lua_git_tag_delete(lua_State *L);
int lua_git_tag_free(lua_State *L);
int lua_git_tag_id(lua_State *L);
int lua_git_tag_list (lua_State *L);
int lua_git_tag_list_match (lua_State *L);
int lua_git_tag_lookup (lua_State *L);
int lua_git_tag_owner(lua_State *L);
int lua_git_tag_tagger (lua_State *L);
int lua_git_tag_target (lua_State *L);
int lua_git_tag_target_id(lua_State *L);
int lua_git_tag_target_type (lua_State *L);
int lua_git_tag_message(lua_State *L);
int lua_git_tag_name(lua_State *L);

#endif
