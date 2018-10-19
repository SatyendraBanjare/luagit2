#include "lua_repository.h"

int lua_git_repository_commondir(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *path = git_repository_commondir(lua_repo->repo);
	lua_pushstring(L, path);
	return 1;
}

int lua_git_repository_config (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_config *lua_cfg;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_repository_config(&local_config, lua_repo->repo),
	    "Error getting config file for given repo", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_repository_config_snapshot (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_config *lua_cfg;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_repository_config_snapshot(&local_config, lua_repo->repo),
	    "Error getting config snapshot for the file", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_repository_detach_head (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	git_repository_detach_head(lua_repo->repo);
	return 1;
}

int lua_git_repository_get_namespace(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *name_space = git_repository_get_namespace(lua_repo->repo);
	lua_pushstring(L, name_space);
	return 1;
}

int lua_git_repository_head (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_reference *lua_ref;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	git_repository_head(&local_ref, lua_repo->repo);
	lua_ref->reference  = local_ref;


	return 1;
}

int lua_git_repository_head_detached (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_head_detached(lua_repo->repo);
	lua_pushboolean(L, result);
	return 1;
}

int lua_git_repository_head_for_worktree (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,name");
    }

	luagit2_reference *lua_ref;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *name = luaL_checkstring(L, 2);

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_repository_head_for_worktree(&local_ref, lua_repo->repo, name),
	    "Error retrieving Head for worktree", NULL);
	lua_ref->reference  = local_ref;

	return 1;
}

int lua_git_repository_head_unborn (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_head_unborn(lua_repo->repo);
	lua_pushboolean(L, result);
	return 1;
}

int lua_git_repository_ident (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *name;
	const char *email;
	git_repository_ident(&name, &email, lua_repo->repo);
	lua_pushstring(L, name);
	lua_pushstring(L, email);
	return 2;
}

int lua_git_repository_index(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_index *lua_index;

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_index = (luagit2_index *)lua_newuserdata(L, sizeof(*lua_index));
	lua_index->index  = NULL;

	luaL_newmetatable(L, "luagit2_index");
	lua_setmetatable(L, -2);

	git_index *local_index  = NULL;
	check_error_long(git_repository_index(&local_index, lua_repo->repo),
	    "Error getting INdex for given repo", NULL);

	lua_index->index  = local_index;

	return 1;
}

int lua_git_repository_init (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 1 argument(s) : path,is_bare(int)");
    }

	luagit2_repository *lua_repo;
	const char *path;

	path  = luaL_checkstring(L, 1);
	if (path == NULL) {
		luaL_error(L, "path cannot be empty");
	}

	int is_bare = luaL_checkinteger(L, 2);

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	git_repository *local_repository  = NULL;
	check_error_long(git_repository_init(&local_repository, path, is_bare),
	    "Error initializing repository", NULL);

	lua_repo->repo = local_repository ;

	return 1;
}

int lua_git_repository_is_bare (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_is_bare(lua_repo->repo);
	lua_pushboolean(L, result);
	return 1;
}

int lua_git_repository_is_empty (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }
	
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_is_empty(lua_repo->repo);
	lua_pushboolean(L, result);
	return 1;
}

int lua_git_repository_is_shallow (lua_State *L) {

if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }
	
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_is_shallow(lua_repo->repo);
	lua_pushboolean(L, result);
	return 1;
}

int lua_git_repository_is_worktree (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }
	
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_is_worktree(lua_repo->repo);
	lua_pushboolean(L, result);
	return 1;
}

int lua_git_repository_message (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_buf *lua_buf;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_repository_message(&local_buf, lua_repo->repo),
	    "Error getting repository message", NULL);
	lua_buf->buf  = &local_buf;

	return 1;
}

int lua_git_repository_message_remove (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int success = git_repository_message_remove(lua_repo->repo);
	lua_pushinteger(L, success);
	return 1;
}

int lua_git_repository_odb (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_odb *lua_odb;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_odb = (luagit2_odb *)lua_newuserdata(L, sizeof(*lua_odb));
	lua_odb->odb  = NULL;

	luaL_newmetatable(L, "luagit2_odb");

	lua_setmetatable(L, -2);

	git_odb *local_odb;
	check_error_long(git_repository_odb(&local_odb, lua_repo->repo),
	    "Error Getting Object databse for the given repo", NULL);
	lua_odb->odb  = local_odb;

	return 1;
}

int lua_git_repository_open(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : path");
    }

	luagit2_repository *lua_repo;
	const char *path;

	path  = luaL_checkstring(L, 1);
	if (path == NULL) {
		luaL_error(L, "path cannot be empty");
	}

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	git_repository *Repository  = NULL;
	check_error_long(git_repository_open(&Repository, path),
	    "Error opening the given repo from given path", NULL);

	lua_repo->repo = Repository ;

	return 1;
}

int lua_git_repository_open_bare(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : path");
    }

	luagit2_repository *lua_repo;
	const char *bare_path;

	bare_path  = luaL_checkstring(L, 1);
	if (bare_path == NULL) {
		luaL_error(L, "path cannot be empty");
	}

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	git_repository *Repository  = NULL;
	check_error_long(git_repository_open_bare(&Repository, bare_path),
	    "Error Opening bare repository", NULL);

	lua_repo->repo = Repository ;

	return 1;
}

int lua_git_repository_open_from_worktree (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_worktree");
    }

	luagit2_repository *lua_repo;
	luagit2_worktree *lua_worktree = (luagit2_worktree *)luaL_checkudata(L, 1,"luagit2_worktree");

	lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
	lua_repo->repo  = NULL;

	luaL_newmetatable(L, "luagit2_repository");
	lua_setmetatable(L, -2);

	git_repository *Repository  = NULL;
	check_error_long(git_repository_open_from_worktree(&Repository, lua_worktree->worktree),
	    "Error Opening repository from worktree", NULL);

	lua_repo->repo = Repository ;

	return 1;
}

int lua_git_repository_path (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *path = git_repository_path(lua_repo->repo);
	lua_pushstring(L, path);
	return 1;
}

int lua_git_repository_refdb (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	luagit2_refdb *lua_refdb;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");

	lua_refdb = (luagit2_refdb *)lua_newuserdata(L, sizeof(*lua_refdb));
	lua_refdb->refdb  = NULL;

	luaL_newmetatable(L, "luagit2_refdb");

	lua_setmetatable(L, -2);

	git_refdb *local_refdb;
	check_error_long(git_repository_refdb(&local_refdb, lua_repo->repo),
	    "Unable to get refdb for repository", NULL);
	lua_refdb->refdb  = local_refdb;

	return 1;
}

int lua_git_repository_set_head (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,refname");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *refname = luaL_checkstring(L, 2);
	git_repository_set_head(lua_repo->repo, refname);
	return 1;
}

int lua_git_repository_set_head_detached (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_oid");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	check_error_long(git_repository_set_head_detached(lua_repo->repo, &(lua_oid->oid)),
	    "Unable to set HEAD", NULL);
	return 1;
}

int lua_git_repository_set_ident (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_repository,name,email");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *name = luaL_checkstring(L, 2);
	const char *email = luaL_checkstring(L, 3);
	check_error_long(git_repository_set_ident(lua_repo->repo, name, email),
	    "Unable to set Identity variables ", NULL);
	return 1;
}

int lua_git_repository_set_namespace (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,name_space");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *name_space = luaL_checkstring(L, 2);
	check_error_long(git_repository_set_namespace(lua_repo->repo, name_space),
	    "Unable to set name space", NULL);
	return 1;
}

int lua_git_repository_set_workdir (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_repository,workdir,update_gitlink(int)");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *work_dir = luaL_checkstring(L, 2);
	int update_gitlink = luaL_checkinteger(L, 3);
	check_error_long(git_repository_set_workdir(lua_repo->repo, work_dir, update_gitlink),
	    "Unable to set the workdir path", NULL);
	return 1;
}

int lua_git_repository_state (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_state(lua_repo->repo);
	lua_pushinteger(L, result);
	return 1;
}

int lua_git_repository_state_cleanup (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	int result = git_repository_state_cleanup(lua_repo->repo);
	lua_pushinteger(L, result);
	return 1;
}

int lua_git_repository_workdir (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *wkdir = git_repository_workdir(lua_repo->repo);
	lua_pushstring(L, wkdir);
	return 1;
}

int lua_git_repository_free (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	git_repository_free(lua_repo->repo);
	return 1;
}

int lua_git_repository_submodule_cache_all (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	check_error_long( git_repository_submodule_cache_all(lua_repo->repo),
	    "Error in doing repository cache all", NULL);
	return 1;
}

int lua_git_repository_submodule_cache_clear (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	check_error_long( git_repository_submodule_cache_clear(lua_repo->repo),
	    "Error in clearing sublodule cache clear", NULL);
	return 1;
}

int lua_git_repository_set_index (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_index");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_index *lua_index = (luagit2_index *)luaL_checkudata(L, 2,"luagit2_index");
	git_repository_set_index(lua_repo->repo, lua_index->index);
	return 1;
}

int lua_git_repository_set_bare (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");	check_error_long( git_repository_set_bare(lua_repo->repo),
	    "Error in setting repository bare", NULL);
	return 1;
}

int lua_git_repository_set_config (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_config");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_config *lua_cfg = (luagit2_config *)luaL_checkudata(L, 2,"luagit2_config");
	git_repository_set_config(lua_repo->repo, lua_cfg->cfg);
	return 1;
}

int lua_git_repository_set_odb (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_odb");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_odb *lua_odb = (luagit2_odb *)luaL_checkudata(L, 2,"luagit2_odb");
	git_repository_set_odb(lua_repo->repo, lua_odb->odb) ;
	return 1;
}

int lua_git_repository__cleanup(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_repository");
    }

	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	git_repository__cleanup(lua_repo->repo);
	return 1;
}