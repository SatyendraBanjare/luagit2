#include "lua_buf_help.h"

int lua_git_buf_details(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_buf");
    }

    // We have not used luaL_checkdata here Because it was causing errors.

	const luagit2_buf *Buffer = (luagit2_buf *)lua_touserdata(L, 1);
	const char *String_Value = (char *)((Buffer->buf)->ptr);
	lua_pushstring(L, String_Value);

	return 1;
}