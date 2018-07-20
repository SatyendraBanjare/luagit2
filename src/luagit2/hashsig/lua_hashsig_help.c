#include "lua_hashsig_help.h"

int lua_hashsig_option_init(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : (string)option");
	}

	const char *option = luaL_checkstring(L, 1);
	git_hashsig_option_t hashsig_option_t = -1; // bad value , it will raise error

	if ((hashsig_option_t = (strcasecmp(option, "normal") == 0 ? GIT_HASHSIG_NORMAL : -1)) != -1 ) {
		goto set_val;
	}
	if ((hashsig_option_t = (strcasecmp(option, "ignore_whitespace") == 0 ? GIT_HASHSIG_IGNORE_WHITESPACE : -1)) != -1 ) {
		goto set_val;
	}
	if ((hashsig_option_t = (strcasecmp(option, "smart_whitespace") == 0 ? GIT_HASHSIG_SMART_WHITESPACE : -1)) != -1 ) {
		goto set_val;
	}
	if ((hashsig_option_t = (strcasecmp(option, "allow_small") == 0 ? GIT_HASHSIG_ALLOW_SMALL_FILES : -1)) != -1 ) {
		goto set_val;
	}

set_val : {

		luagit2_hashsig_options *lua_hashsig_opts = (luagit2_hashsig_options *)lua_newuserdata(L, sizeof(*lua_hashsig_opts));

		luaL_newmetatable(L, "luagit2_hashsig_options");
		lua_setmetatable(L, -2);

		lua_hashsig_opts->hashsig_options = hashsig_option_t;
		return 1;
	}

	luaL_error(L, "Unsupported option, must be one of : normal,ignore_whitespace,smart_whitespace,allow_small");
	return 0;

}