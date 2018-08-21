#include "lua_diff_help.h"

int lua_diff_format_init(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : (string)option");
	}

	const char *option = luaL_checkstring(L, 1);
	git_diff_format_t diff_format_t = -1; // bad value , it will raise error

	if ((diff_format_t = (strcasecmp(option, "patch") == 0 ? GIT_DIFF_FORMAT_PATCH : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_format_t = (strcasecmp(option, "patch_header") == 0 ? GIT_DIFF_FORMAT_PATCH_HEADER : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_format_t = (strcasecmp(option, "raw") == 0 ? GIT_DIFF_FORMAT_RAW : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_format_t = (strcasecmp(option, "name_only") == 0 ? GIT_DIFF_FORMAT_NAME_ONLY : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_format_t = (strcasecmp(option, "name_status") == 0 ? GIT_DIFF_FORMAT_NAME_STATUS : -1)) != -1 ) {
		goto set_val;
	}

set_val : {

		luagit2_diff_format *lua_diff_format = (luagit2_diff_format *)lua_newuserdata(L, sizeof(*lua_diff_format));

		luaL_newmetatable(L, "luagit2_diff_format");
		lua_setmetatable(L, -2);

		lua_diff_format->diff_format = diff_format_t;
		return 1;
	}

	luaL_error(L, "Unsupported option, must be one of : patch,patch_header,raw,name_only,name_status");
	return 0;

}

int lua_diff_stats_format_init(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : (string)option");
	}

	const char *option = luaL_checkstring(L, 1);
	git_diff_stats_format_t diff_stats_format_t = -1; // bad value , it will raise error

	if ((diff_stats_format_t = (strcasecmp(option, "none") == 0 ? GIT_DIFF_STATS_NONE : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_stats_format_t = (strcasecmp(option, "full") == 0 ? GIT_DIFF_STATS_FULL : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_stats_format_t = (strcasecmp(option, "short") == 0 ? GIT_DIFF_STATS_SHORT : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_stats_format_t = (strcasecmp(option, "number") == 0 ? GIT_DIFF_STATS_NUMBER : -1)) != -1 ) {
		goto set_val;
	}
	if ((diff_stats_format_t = (strcasecmp(option, "summary") == 0 ? GIT_DIFF_STATS_INCLUDE_SUMMARY : -1)) != -1 ) {
		goto set_val;
	}

set_val : {

		luagit2_diff_stats_format *lua_diff_stats_format = (luagit2_diff_stats_format *)lua_newuserdata(L, sizeof(*lua_diff_stats_format));

		luaL_newmetatable(L, "luagit2_diff_stats_format");
		lua_setmetatable(L, -2);

		lua_diff_stats_format->stats_format = diff_stats_format_t;
		return 1;
	}

	luaL_error(L, "Unsupported option, must be one of : none, full, short, number, summary");
	return 0;

}

