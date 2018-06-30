#include "lua_buf.h"

int lua_git_buf_set_char(lua_State *L) {
	luagit2_buf *lua_buf;
	const char *string_value = luaL_checkstring(L, 1);
	size_t data_length = luaL_checkinteger(L, 2);

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_buf;
	check_error_long(git_buf_set(&local_buf, string_value, data_length),
	    "Unable to set char in the buf", NULL);
	lua_buf->buf = &local_buf;

	return 1;
}

int lua_git_buf_free(lua_State *L) {
	luagit2_buf *buf_to_free = (luagit2_buf *)lua_touserdata(L, 1);
	git_buf_free(buf_to_free->buf);
	return 1;
}
