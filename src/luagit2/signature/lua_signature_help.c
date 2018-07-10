#include "lua_signature_help.h"

static void print_signature( const git_signature *sig) {
	char sign;
	int offset, hours, minutes;

	if (!sig) {
		return;
	}

	offset = sig->when.offset;
	if (offset < 0) {
		sign = '-';
		offset = -offset;
	} else {
		sign = '+';
	}

	hours   = offset / 60;
	minutes = offset % 60;

	printf("%s <%s> %ld %c%02d%02d\n",
	    sig->name, sig->email, (long)sig->when.time,
	    sign, hours, minutes);
}

int lua_get_signature_details (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_signature");
	}

	const luagit2_signature *signature_data = (luagit2_signature *)luaL_checkudata(L, 1, "luagit2_signature");

	if (signature_data->sign != NULL) {
		lua_pushstring(L, signature_data->sign->name);
		lua_pushstring(L, signature_data->sign->email);
		return 2;
	} else {
		return luaL_error(L, null_err);
	}

}

int lua_print_complete_signature_details (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_signature");
	}

	const luagit2_signature *signature_data = (luagit2_signature *)luaL_checkudata(L, 1, "luagit2_signature");

	if (signature_data->sign != NULL) {
		print_signature(signature_data->sign);
		return 1;
	} else {
		return luaL_error(L, null_err);
	}

}
