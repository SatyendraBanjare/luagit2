#include "lua_buf.h"

int lua_git_buf_set_str(lua_State *L) {
	luagit2_buf *lua_buf;
	const char *string_value = luaL_checkstring(L, 1);

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL,0);
	check_error_long(git_buf_set(&local_buf, string_value, strlen(string_value)),
	    "Unable to set char in the buf", NULL);
	lua_buf->buf = &local_buf;

	return 1;
}

int lua_git_buf_free(lua_State *L) {
	luagit2_buf *buf_to_free = (luagit2_buf *)lua_touserdata(L, 1);
	git_buf_free(buf_to_free->buf);
	return 1;
}
