#include "lua_libgit2_help.h"

int lua_git_libgit2_print_version_data (lua_State *L) {
	const libgit_version_data *version_data = (libgit_version_data *)lua_touserdata(L, 1);
	int which_version = luaL_checkinteger(L,2);

	switch(which_version)
	{
		case 1:  lua_pushinteger(L,version_data->major);
		    	break;
		case 2: lua_pushinteger(L,version_data->minor);
		    	break;
		case 3: lua_pushinteger(L,version_data->major);
		    	break;
	}

    return 1;
}
