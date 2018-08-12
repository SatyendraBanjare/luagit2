#include "lua_config.h"

int lua_git_config_delete_entry (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	check_error_long(git_config_delete_entry(parent_cfg->cfg, name),
	    "Unable to delete the entry from given config, entry's name", NULL);

	return 1;
}

int lua_git_config_delete_multivar (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_config,name,regex");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);
	const char *regex = luaL_checkstring(L, 3);

	check_error_long(git_config_delete_multivar(parent_cfg->cfg, name, regex),
	    "Unable to delete the entry from given config , entry's name and regex", NULL);

	return 1;
}

int lua_git_config_find_global (lua_State *L) {

	if (lua_gettop(L) != 0 ) {
        return luaL_error(L, "expecting No argument(s)");
    }

	luagit2_buf *lua_buf;

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_find_global(&local_buf),
	    "Unable to find global config ", NULL);
	lua_buf->buf  = &local_buf;
	return 1;
}

int lua_git_config_find_programdata (lua_State *L) {

	if (lua_gettop(L) != 0 ) {
        return luaL_error(L, "expecting No argument(s)");
    }

	luagit2_buf *lua_buf;

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_find_programdata(&local_buf),
	    "Unable to find locate the path to the configuration file in ProgramData", NULL);
	lua_buf->buf  = &local_buf;


	return 1;
}

int lua_git_config_find_system (lua_State *L) {

	if (lua_gettop(L) != 0 ) {
        return luaL_error(L, "expecting No argument(s)");
    }

	luagit2_buf *lua_buf;


	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_find_system(&local_buf),
	    "Unable to locate the path to the system configuration file", NULL);
	lua_buf->buf  = &local_buf;


	return 1;
}

int lua_git_config_find_xdg (lua_State *L) {

	if (lua_gettop(L) != 0 ) {
        return luaL_error(L, "expecting No argument(s)");
    }

	luagit2_buf *lua_buf;


	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_find_xdg(&local_buf),
	    "Unable to Locate the path to the global xdg compatible configuration file", NULL);
	lua_buf->buf  = &local_buf;


	return 1;
}

int lua_git_config_get_int32 (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	const luagit2_config *parent_cfg;
	int32_t out;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	check_error_long(git_config_get_int32(&out, parent_cfg->cfg, name),
	    "Unable to get integer configuration variable", NULL);

	lua_pushinteger(L, out);
	return 1;
}

int lua_git_config_get_int64 (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	const luagit2_config *parent_cfg;
	int64_t out;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	check_error_long(git_config_get_int64(&out, parent_cfg->cfg, name),
	    "Unable to get long integer configuration variable", NULL);

	lua_pushinteger(L, out);
	return 1;
}

int lua_git_config_get_bool (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	const luagit2_config *parent_cfg;
	int out;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	git_config_get_bool(&out, parent_cfg->cfg, name);

	lua_pushinteger(L, out);
	return 1;
}

int lua_git_config_get_path (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	luagit2_buf *lua_buf;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_get_path(&local_buf, parent_cfg->cfg, name),
	    "Unable to get path for the config file", NULL);
	lua_buf->buf  = &local_buf;


	return 1;
}

int lua_git_config_get_string (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	const char *value;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	git_config_get_string(&value, parent_cfg->cfg, name);

	lua_pushstring(L, value);
	return 1;
}

int lua_git_config_get_string_buf (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	luagit2_buf *lua_buf;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_get_string_buf(&local_buf, parent_cfg->cfg, name),
	    "Unable to get string buffer from the config", NULL);
	lua_buf->buf  = &local_buf;

	return 1;
}

int lua_git_config_open_default (lua_State *L) {

	if (lua_gettop(L) != 0 ) {
        return luaL_error(L, "expecting NO argument(s) ");
    }

	luagit2_config *lua_cfg;

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_config_open_default(&local_config),
	    "Unable to open default config", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_config_open_global (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config");
    }

	luagit2_config *lua_cfg;
	luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_config_open_global(&local_config, parent_cfg->cfg),
	    "Unable to open global configuration", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_config_open_level (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,luagit2_config_level_t");
    }

	luagit2_config *lua_cfg;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	luagit2_config_level_t *Level = (luagit2_config_level_t *)luaL_checkudata(L, 2,"luagit2_config_level_t");

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_config_open_level(&local_config, parent_cfg->cfg, Level->level),
	    "Unable to open specified configuration", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_config_open_ondisk (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : path");
    }

	luagit2_config *lua_cfg;

	const char *path = luaL_checkstring(L, 1);

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_config_open_ondisk(&local_config, path),
	    "Unable to open cifiguration file from disk", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_config_parse_bool (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : value(string)");
    }

	const char *value = luaL_checkstring(L, 1);
	int out;
	check_error_long(git_config_parse_bool(&out, value),
	    "Error parsing string as bool value", NULL);
	lua_pushinteger(L, out);

	return 1;
}

int lua_git_config_parse_int32 (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : value(string)");
    }

	const char *value = luaL_checkstring(L, 1);
	int32_t out;
	check_error_long(git_config_parse_int32(&out, value),
	    "Error parsing string as integer value", NULL);
	lua_pushinteger(L, out);

	return 1;
}

int lua_git_config_parse_int64 (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : value(string)");
    }

	const char *value = luaL_checkstring(L, 1);
	int64_t out;
	check_error_long(git_config_parse_int64(&out, value),
	    "Error parsing string as long integer value", NULL);
	lua_pushinteger(L, out);

	return 1;
}

int lua_git_config_parse_path (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : buf_value(string)");
    }

	luagit2_buf *lua_buf;
	const char *path_value = luaL_checkstring(L, 1);

	lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf  = NULL;

	luaL_newmetatable(L, "luagit2_buf");

	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);
	check_error_long(git_config_parse_path(&local_buf, path_value),
	    "Error parsing string as path value", NULL);
	lua_buf->buf  = &local_buf;

	return 1;
}

int lua_git_config_set_bool (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_config,name(string),value(int)");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);
	int value = luaL_checkinteger(L, 3);

	check_error_long(git_config_set_bool(parent_cfg->cfg, name, value),
	    "Error setting bool in config", NULL);

	return 1;
}

int lua_git_config_set_int32 (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_config,name(string),value(int)");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);
	int32_t value = luaL_checkinteger(L, 3);

	check_error_long(git_config_set_int32(parent_cfg->cfg, name, value),
	    "Error setting long integer value in config", NULL);

	return 1;
}

int lua_git_config_set_int64 (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_config,name(string),value(int)");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);
	int64_t value = luaL_checkinteger(L, 3);

	check_error_long(git_config_set_int64(parent_cfg->cfg, name, value),
	    "Error setting long integer value in config", NULL);

	return 1;
}

int lua_git_config_set_multivar (lua_State *L) {

	if (lua_gettop(L) != 4 ) {
        return luaL_error(L, "expecting 4 argument(s) : luagit2_config,name(string),regex(string),value(string)");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);
	const char *regex = luaL_checkstring(L, 3);
	const char *value = luaL_checkstring(L, 4);

	check_error_long(git_config_set_multivar(parent_cfg->cfg, name, regex, value),
	    "Error setting multivar value in config", NULL);

	return 1;
}

int lua_git_config_set_string (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_config,name(string),value(string)");
    }

	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);
	const char *value = luaL_checkstring(L, 3);

	check_error_long(git_config_set_string(parent_cfg->cfg, name, value),
	    "Error setting string value in config", NULL);

	return 1;
}

int lua_git_config_snapshot (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config");
    }

	luagit2_config *lua_cfg;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");

	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_config_snapshot(&local_config, parent_cfg->cfg),
	    "Error getting config snapshot", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_config_free (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config");
    }

	const luagit2_config *lua_cfg  = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	git_config_free(lua_cfg->cfg);
	return 1;
}

int lua_git_config_add_file_ondisk (lua_State *L) {

	if (lua_gettop(L) != 5 ) {
        return luaL_error(L, "expecting 5 argument(s) : luagit2_config,path,luagit2_config_level_t,luagit2_repository\
        	force(int)");
    }

	const luagit2_config *Config_to_write = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *path = luaL_checkstring(L, 2);
	const luagit2_config_level_t *cfg_lvl = (luagit2_config_level_t *)luaL_checkudata(L, 3,"luagit2_config_level_t");
	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 4,"luagit2_repository");
	const int force = luaL_checkinteger(L, 5);

	check_error_long(git_config_add_file_ondisk(Config_to_write->cfg,
	        path, cfg_lvl->level, Repository->repo, force), "Unable to add file ondisk", NULL);
	return 1;
}

int lua_git_config_new(lua_State *L) {

	if (lua_gettop(L) != 0 ) {
        return luaL_error(L, "expecting No argument(s)");
    }

	luagit2_config *lua_cfg;

	lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
	lua_cfg->cfg  = NULL;

	luaL_newmetatable(L, "luagit2_config");
	lua_setmetatable(L, -2);

	git_config *local_config;
	check_error_long(git_config_new(&local_config),
	    "Error creating new config", NULL);
	lua_cfg->cfg  = local_config;

	return 1;
}

int lua_git_config_iterator_new(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config");
    }

	luagit2_config_iterator *lua_cfg_itr;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");

	lua_cfg_itr = (luagit2_config_iterator *)lua_newuserdata(L, sizeof(*lua_cfg_itr));
	lua_cfg_itr->config_iterator  = NULL;

	luaL_newmetatable(L, "luagit2_config_iterator");
	lua_setmetatable(L, -2);

	git_config_iterator *local_config_itr;
	check_error_long(git_config_iterator_new(&local_config_itr, parent_cfg->cfg),
	    "Error creating new iterator", NULL);
	lua_cfg_itr->config_iterator  = local_config_itr;

	return 1;
}

int lua_git_config_entry_free(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config_entry");
    }

	luagit2_config_entry *cfg_entry = (luagit2_config_entry *)luaL_checkudata(L, 1,"luagit2_config_entry");
	git_config_entry_free(cfg_entry->config_entry);
	return 1;
}

int lua_git_config_get_entry(lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_config,name");
    }

	luagit2_config_entry *lua_cfg_entry;
	const luagit2_config *parent_cfg;

	parent_cfg = (luagit2_config *)luaL_checkudata(L, 1,"luagit2_config");
	const char *name = luaL_checkstring(L, 2);

	lua_cfg_entry = (luagit2_config_entry *)lua_newuserdata(L, sizeof(*lua_cfg_entry));
	lua_cfg_entry->config_entry  = NULL;

	luaL_newmetatable(L, "luagit2_config_entry");
	lua_setmetatable(L, -2);

	git_config_entry *local_config_entry;
	check_error_long(git_config_get_entry(&local_config_entry, parent_cfg->cfg, name),
	    "Unable to get the entry", NULL);
	lua_cfg_entry->config_entry  = local_config_entry;
	return 1;
}

int lua_git_config_next(lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config_iterator");
    }

	luagit2_config_entry *lua_cfg_entry;
	const luagit2_config_iterator *cfg_itr = (luagit2_config_iterator *)luaL_checkudata(L, 1,"luagit2_config_iterator");

	lua_cfg_entry = (luagit2_config_entry *)lua_newuserdata(L, sizeof(*lua_cfg_entry));
	lua_cfg_entry->config_entry  = NULL;

	luaL_newmetatable(L, "luagit2_config_entry");
	lua_setmetatable(L, -2);

	git_config_entry *local_config_entry;
	check_error_long(git_config_next(&local_config_entry, cfg_itr->config_iterator),
	    "Unable to get next entry", NULL);
	lua_cfg_entry->config_entry  = local_config_entry;

	return 1;
}

int lua_git_config_iterator_free(lua_State *L){

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_config_iterator");
    }

	luagit2_config_iterator *cfg_itr = (luagit2_config_iterator *)luaL_checkudata(L,1,"luagit2_config_iterator");
	git_config_iterator_free(cfg_itr->config_iterator);
	return 1;
}