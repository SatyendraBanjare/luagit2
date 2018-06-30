#include "lua_buf_help.h"

int lua_git_buf_details(lua_State *L) {
	const luagit2_buf *Buffer = (luagit2_buf *)lua_touserdata(L, 1);

	lua_pushstring(L, (*(Buffer->buf)).ptr);

	return 1;
}