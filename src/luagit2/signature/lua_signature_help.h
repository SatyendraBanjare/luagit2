#ifndef _lua_signature_help
#define _lua_signature_help

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static void print_signature( const git_signature *sig)
{
	char sign;
	int offset, hours, minutes;

	if (!sig)
		return;

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

static int lua_get_signature_details (lua_State *L) {
	const luagit2_signature *signature_data = (luagit2_signature *)lua_touserdata(L, 1);
	int which_value = luaL_checkinteger(L,2);

	switch(which_value)
	{
		case 1:  lua_pushstring(L,signature_data->sign->name);
		    	break;
		case 2: lua_pushstring(L,signature_data->sign->email);
		    	break;
	}

    return 1;
}

static int lua_print_complete_signature_details (lua_State *L) {
	const luagit2_signature *signature_data = (luagit2_signature *)lua_touserdata(L, 1);
	print_signature(signature_data->sign);
    return 1;
}

#endif
