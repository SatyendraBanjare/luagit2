#include "lua_buf_help.h"

int lua_git_buf_details(lua_State *L) {
	const luagit2_buf *Buffer = (luagit2_buf *)lua_touserdata(L, 1);
	const char *String_Value = (char *)((Buffer->buf)->ptr);
	lua_pushstring(L, String_Value);

	return 1;
}