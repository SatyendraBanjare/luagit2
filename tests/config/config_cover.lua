local luagit2_lib = require("luagit2")

local luagit2_config = {}

--------------------------------------------------------------------
--
-- Complete set of config module functions to test coverage for.
--
-- {"config_delete_entry", lua_git_config_delete_entry},
-- {"config_delete_multivar", lua_git_config_delete_multivar},
-- {"config_find_global", lua_git_config_find_global},
-- {"config_find_programdata", lua_git_config_find_programdata},
-- {"config_find_system", lua_git_config_find_system},
-- {"config_find_xdg", lua_git_config_find_xdg},
-- {"config_get_bool", lua_git_config_get_bool},
-- {"config_get_int32", lua_git_config_get_int32},
-- {"config_get_int64", lua_git_config_get_int64},
-- {"config_get_path", lua_git_config_get_path},
-- {"config_get_string", lua_git_config_get_string},
-- {"config_get_string_buf", lua_git_config_get_string_buf},
-- {"config_open_global", lua_git_config_open_global},
-- {"config_open_level", lua_git_config_open_level},
-- {"config_open_ondisk", lua_git_config_open_ondisk},
-- {"config_open_default ", lua_git_config_open_default},
-- {"config_parse_bool", lua_git_config_parse_bool},
-- {"config_parse_int32", lua_git_config_parse_int32},
-- {"config_parse_int64", lua_git_config_parse_int64},
-- {"config_parse_path", lua_git_config_parse_path},
-- {"config_set_bool", lua_git_config_set_bool},
-- {"config_set_int32", lua_git_config_set_int32},
-- {"config_set_int64", lua_git_config_set_int64},
-- {"config_set_multivar", lua_git_config_set_multivar},
-- {"config_set_string", lua_git_config_set_string},
-- {"config_snapshot", lua_git_config_snapshot},
-- {"config_free", lua_git_config_free},
-- {"config_add_file_ondisk",lua_git_config_add_file_ondisk},
-- {"config_new",lua_git_config_new},
-- {"config_iterator_new",lua_git_config_iterator_new},
-- {"config_entry_free",lua_git_config_entry_free},
-- {"config_get_entry",lua_git_config_get_entry},
-- {"config_next",lua_git_config_next},
-- {"config_iterator_free",lua_git_config_iterator_free}
--
-- {"config_level_program_data", lua_get_config_level_program_data},
-- {"config_level_system", lua_get_config_level_system},
-- {"config_level_global", lua_get_config_level_global},
-- {"config_level_xdg", lua_get_config_level_xdg},
-- {"config_level_local",lua_get_config_level_local},
-- {"config_entry_name",lua_get_config_entry_name},
-- {"config_entry_value",lua_get_config_entry_value},
--
--------------------------------------------------------------------

local function config_delete_entry(...)
	return luagit2_lib.config_delete_entry(...)
end

local function config_delete_multivar(...)
	return luagit2_lib.config_delete_multivar(...)
end

local function config_find_global(...)
	return luagit2_lib.config_find_global(...)
end

local function config_find_programdata(...)
	return luagit2_lib.config_find_programdata(...)
end

local function config_find_system(...)
	return luagit2_lib.config_find_system(...)
end

local function config_find_xdg(...)
	return luagit2_lib.config_find_xdg(...)
end

local function config_get_bool(...)
	return luagit2_lib.config_get_bool(...)
end

local function config_get_int32(...)
	return luagit2_lib.config_get_int32(...)
end

local function config_get_int64(...)
	return luagit2_lib.config_get_int64(...)
end

local function config_get_path(...)
	return luagit2_lib.config_get_path(...)
end

local function config_get_string(...)
	return luagit2_lib.config_get_string(...)
end

local function config_get_string_buf(...)
	return luagit2_lib.config_get_string_buf(...)
end

local function config_open_global(...)
	return luagit2_lib.config_open_global(...)
end

local function config_open_level(...)
	return luagit2_lib.config_open_level(...)
end

local function config_open_ondisk(...)
	return luagit2_lib.config_open_ondisk(...)
end

local function config_open_default(...)
	return luagit2_lib.config_open_default(...)
end

local function config_parse_bool(...)
	return luagit2_lib.config_parse_bool(...)
end

local function config_parse_int32(...)
	return luagit2_lib.config_parse_int32(...)
end

local function config_parse_int64(...)
	return luagit2_lib.config_parse_int64(...)
end

local function config_parse_path(...)
	return luagit2_lib.config_parse_path(...)
end

local function config_set_bool(...)
	return luagit2_lib.config_set_bool(...)
end

local function config_set_int32(...)
	return luagit2_lib.config_set_int32(...)
end

local function config_set_int64(...)
	return luagit2_lib.config_set_int64(...)
end

local function config_set_multivar(...)
	return luagit2_lib.config_set_multivar(...)
end

local function config_set_string(...)
	return luagit2_lib.config_set_string(...)
end

local function config_snapshot(...)
	return luagit2_lib.config_snapshot(...)
end

local function config_free(...)
	return luagit2_lib.config_free(...)
end

local function config_add_file_ondisk(...)
	return luagit2_lib.config_add_file_ondisk(...)
end

local function config_new(...)
	return luagit2_lib.config_new(...)
end

local function config_iterator_new(...)
	return luagit2_lib.config_iterator_new(...)
end

local function config_entry_free(...)
	return luagit2_lib.config_entry_free(...)
end

local function config_get_entry(...)
	return luagit2_lib.config_get_entry(...)
end

local function config_next(...)
	return luagit2_lib.config_next(...)
end

local function config_iterator_free(...)
	return luagit2_lib.config_iterator_free(...)
end

local function config_level_program_data(...)
	return luagit2_lib.config_level_program_data(...)
end

local function config_level_system(...)
	return luagit2_lib.config_level_system(...)
end

local function config_level_global(...)
	return luagit2_lib.config_level_global(...)
end

local function config_level_xdg(...)
	return luagit2_lib.config_level_xdg(...)
end

local function config_level_local(...)
	return luagit2_lib.config_level_local(...)
end

local function config_entry_name(...)
	return luagit2_lib.config_entry_name(...)
end

local function config_entry_value(...)
	return luagit2_lib.config_entry_value(...)
end

luagit2_config.config_delete_entry = config_delete_entry
luagit2_config.config_delete_multivar = config_delete_multivar
luagit2_config.config_find_global = config_find_global
luagit2_config.config_find_programdata = config_find_programdata
luagit2_config.config_find_system = config_find_system
luagit2_config.config_find_xdg = config_find_xdg
luagit2_config.config_get_bool = config_get_bool
luagit2_config.config_get_int32 = config_get_int32
luagit2_config.config_get_int64 = config_get_int64
luagit2_config.config_get_path = config_get_path
luagit2_config.config_get_string = config_get_string
luagit2_config.config_get_string_buf = config_get_string_buf
luagit2_config.config_open_global = config_open_global
luagit2_config.config_open_level = config_open_level
luagit2_config.config_open_ondisk = config_open_ondisk
luagit2_config.config_open_default = config_open_default
luagit2_config.config_parse_bool = config_parse_bool
luagit2_config.config_parse_int32 = config_parse_int32
luagit2_config.config_parse_int64 = config_parse_int64
luagit2_config.config_parse_path = config_parse_path 
luagit2_config.config_set_bool = config_set_bool
luagit2_config.config_set_int32 = config_set_int32
luagit2_config.config_set_int64 = config_set_int64
luagit2_config.config_set_multivar = config_set_multivar
luagit2_config.config_set_string = config_set_string
luagit2_config.config_snapshot = config_snapshot
luagit2_config.config_free = config_free
luagit2_config.config_add_file_ondisk = config_add_file_ondisk
luagit2_config.config_new = config_new
luagit2_config.config_iterator_new = config_iterator_new
luagit2_config.config_entry_free = config_entry_free
luagit2_config.config_get_entry = config_get_entry
luagit2_config.config_next = config_next
luagit2_config.config_iterator_free = config_iterator_free

luagit2_config.config_level_program_data = config_level_program_data
luagit2_config.config_level_system = config_level_system
luagit2_config.config_level_global = config_level_global
luagit2_config.config_level_xdg = config_level_xdg
luagit2_config.config_level_local = config_level_local
luagit2_config.config_entry_name = config_entry_name
luagit2_config.config_entry_value = config_entry_value

return luagit2_config