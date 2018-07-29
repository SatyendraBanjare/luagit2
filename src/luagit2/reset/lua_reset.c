#include "lua_reset.h"

int lua_git_reset(lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,luagit2_object,(string) option");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_object *lua_obj = (luagit2_object *)luaL_checkudata(L, 2, "luagit2_object");
	const char *option = luaL_checkstring(L, 3);
	git_checkout_options local_checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;

	git_reset_t reset_t = 0; //bad value, it should create error

	if ((reset_t = (strcasecmp(option, "soft") == 0 ? GIT_RESET_SOFT : 0)) != 0 ) {
		goto set_val;
	}
	if ((reset_t = (strcasecmp(option, "mixed") == 0 ? GIT_RESET_MIXED : 0)) != 0 ) {
		goto set_val;
	}
	if ((reset_t = (strcasecmp(option, "hard") == 0 ? GIT_RESET_HARD : 0)) != 0 ) {
		goto set_val;
	}

set_val: {

		check_error_long(git_reset(Repository->repo, lua_obj->object, reset_t, &local_checkout_opts),
		    "Error doing a git reset ", NULL);

		return 0;
	}

	luaL_error(L, "Unsupported option, must be one of : soft,mixed,hard");
	return 0;
}
