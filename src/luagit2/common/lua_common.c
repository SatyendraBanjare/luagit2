#include "lua_common.h"

void check_error(int error_code, const char *action) {
	// Get the last error and print it.
	const git_error *error = giterr_last();
	if (!error_code) {
		return;
	}

	printf("Error %d %s - %s\n", error_code, action,
	    (error && error->message) ? error->message : "???");

	exit(1);
}

void check_error_long(int error, const char *message, const char *extra) {
	const git_error *lg2err;
	const char *lg2msg = "", *lg2spacer = "";

	if (!error) {
		return;
	}
	// Get the last error and print it with extra comments.
	if ((lg2err = giterr_last()) != NULL && lg2err->message != NULL) {
		lg2msg = lg2err->message;
		lg2spacer = " - ";
	}

	if (extra)
		printf( "%s '%s' [%d]%s%s\n",
		    message, extra, error, lg2spacer, lg2msg);
	else
		printf( "%s [%d]%s%s\n",
		    message, error, lg2spacer, lg2msg);

	exit(1);
}

int get_userdata_name(lua_State *L) {
	void *user_data = (void *)lua_touserdata(L, 1);

	lua_getmetatable(L, 1);
	lua_pushstring(L, "__name");
	lua_rawget(L, 2);

	return 1;
}
