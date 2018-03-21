#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

typedef struct {
    git_repository *repo;
    char *repo_path;
} initialize_data;
 
static int lua_initialize(lua_State *L)
{
    initialize_data *init_data;
    const char *path;
 
    /* Check the arguments are valid. */
    path  = luaL_checkstring(L, 1);
    if (path == NULL)
        luaL_error(L, "name cannot be empty");
 
    /* Create the user data pushing it onto the stack. We also pre-initialize
     * the member of the userdata in case initialization fails in some way. If
     * that happens we want the userdata to be in a consistent state for __gc. */
    init_data = (initialize_data *)lua_newuserdata(L, sizeof(*init_data));
    init_data->repo  = NULL;
    init_data->repo_path = NULL;
 
    /* Add the metatable to the stack. */
    luaL_getmetatable(L, "initialize_repo_data");
    /* Set the metatable on the userdata. */
    lua_setmetatable(L, -2);
 
    /* Create the data that comprises the userdata (the counter). */

    git_repository *Repository  = NULL;
    git_repository_open(&Repository,path);

    init_data->repo   = Repository ;
    init_data->repo_path = strdup(path);
 
    return 1;
}

static int lua_get_initial_repo_path(lua_State *L)
{
    initialize_data *init_data;
 
    init_data = (initialize_data  *)lua_touserdata(L, 1);
    lua_pushstring(L, init_data->repo_path);
 
    return 1;
}
 
