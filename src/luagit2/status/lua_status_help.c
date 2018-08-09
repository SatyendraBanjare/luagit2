#include "lua_status_help.h"

int lua_git_status_type(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_status_entry");
	}

	const luagit2_status_entry *lua_status_entry = (luagit2_status_entry *)luaL_checkudata(L, 1, "luagit2_status_entry");

	if ((lua_status_entry->status_entry) == NULL) {
		return luaL_error(L, null_err);
	}
	/*-----------------------------------------------------------------------------*/
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_CURRENT ) {
		lua_pushstring(L, "STATUS_CURRENT");
		return 1;
	}
	/*-----------------------------------------------------------------------------*/
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_INDEX_NEW ) {
		lua_pushstring(L, "STATUS_INDEX_NEW");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_INDEX_MODIFIED ) {
		lua_pushstring(L, "STATUS_INDEX_MODIFIED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_INDEX_DELETED ) {
		lua_pushstring(L, "STATUS_INDEX_DELETED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_INDEX_RENAMED ) {
		lua_pushstring(L, "STATUS_INDEX_RENAMED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_INDEX_TYPECHANGE ) {
		lua_pushstring(L, "STATUS_INDEX_TYPECHANGE");
		return 1;
	}
	/*-----------------------------------------------------------------------------*/
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_WT_NEW ) {
		lua_pushstring(L, "STATUS_WT_NEW");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_WT_MODIFIED ) {
		lua_pushstring(L, "STATUS_WT_MODIFIED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_WT_DELETED ) {
		lua_pushstring(L, "STATUS_WT_DELETED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_WT_TYPECHANGE ) {
		lua_pushstring(L, "STATUS_WT_TYPECHANGE");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_WT_RENAMED ) {
		lua_pushstring(L, "STATUS_WT_RENAMED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_WT_UNREADABLE ) {
		lua_pushstring(L, "STATUS_WT_UNREADABLE");
		return 1;
	}
	/*-----------------------------------------------------------------------------*/
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_IGNORED ) {
		lua_pushstring(L, "STATUS_IGNORED");
		return 1;
	}
	if ((lua_status_entry->status_entry)->status == GIT_STATUS_CONFLICTED ) {
		lua_pushstring(L, "STATUS_CONFLICTED");
		return 1;
	}

}

int lua_get_status_wkdir_file_paths( lua_State *L){
	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_status_entry");
	}

	const luagit2_status_entry *lua_status_entry = (luagit2_status_entry *)luaL_checkudata(L, 1, "luagit2_status_entry");

	if ((lua_status_entry->status_entry) == NULL) {
		return luaL_error(L, null_err);
	}

	const char *old_file_path = (lua_status_entry->status_entry)->index_to_workdir->old_file.path ? (lua_status_entry->status_entry)->index_to_workdir->old_file.path : "NULL" ;
	const char *new_file_path = (lua_status_entry->status_entry)->index_to_workdir->new_file.path ? (lua_status_entry->status_entry)->index_to_workdir->new_file.path :"NULL" ;

	lua_pushstring(L,old_file_path);
	lua_pushstring(L,new_file_path);

	return 2;
}

int lua_get_status_index_file_paths( lua_State *L){
	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_status_entry");
	}

	const luagit2_status_entry *lua_status_entry = (luagit2_status_entry *)luaL_checkudata(L, 1, "luagit2_status_entry");

	if ((lua_status_entry->status_entry) == NULL) {
		return luaL_error(L, null_err);
	}

	const char *old_file_path = (lua_status_entry->status_entry)->head_to_index->old_file.path ? (lua_status_entry->status_entry)->head_to_index->old_file.path : "NULL" ;
	const char *new_file_path = (lua_status_entry->status_entry)->head_to_index->new_file.path ? (lua_status_entry->status_entry)->head_to_index->new_file.path :"NULL" ;

	lua_pushstring(L,old_file_path);
	lua_pushstring(L,new_file_path);

	return 2;
}
