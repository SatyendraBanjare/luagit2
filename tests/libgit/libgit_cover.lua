local luagit2_lib = require("luagit2")

local luagit2_libgit = {}


-------------------------------------------------------------------------------------
-- {"init", lua_git_libgit2_init },
-- {"shutdown", lua_git_libgit2_shutdown},
-- {"libgit2_features", lua_git_libgit2_features},
-- {"libgit2_version", lua_git_libgit2_version},
-- {"get_mwindow_size", lua_GIT_OPT_GET_MWINDOW_SIZE},
-- {"set_mwindow_size", lua_GIT_OPT_SET_MWINDOW_SIZE},
-- {"get_mwindow_mapped_limit", lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT},
-- {"set_mwindow_mapped_limit", lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT},
-- {"get_search_path", lua_GIT_OPT_GET_SEARCH_PATH},
-- {"set_search_path", lua_GIT_OPT_SET_SEARCH_PATH},
-- {"get_cached_memory", lua_GIT_OPT_GET_CACHED_MEMORY},
-- {"set_cache_object_limit", lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT},
-- {"set_cache_max_size", lua_GIT_OPT_SET_CACHE_MAX_SIZE},
-- {"enable_caching", lua_GIT_OPT_ENABLE_CACHING},
-- {"get_template_path", lua_GIT_OPT_GET_TEMPLATE_PATH},
-- {"set_template_path", lua_GIT_OPT_SET_TEMPLATE_PATH},
-- {"set_user_agent", lua_GIT_OPT_SET_USER_AGENT},
-- {"get_windows_sharemode", lua_GIT_OPT_GET_WINDOWS_SHAREMODE},
-- {"set_windows_sharemode", lua_GIT_OPT_SET_WINDOWS_SHAREMODE},
-- {"enable_strict_object_creation", lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION},
-- {"enable_strict_symbolic_ref_creation", lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION},
-- {"set_ssl_ciphers", lua_GIT_OPT_SET_SSL_CIPHERS},
-- {"enable_ofs_delta", lua_GIT_OPT_ENABLE_OFS_DELTA},
-- {"enable_fsync_gitdir", lua_GIT_OPT_ENABLE_FSYNC_GITDIR},
-- {"enable_strict_hash_verification", lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION},
-------------------------------------------------------------------------------------

local function init(...)
	return luagit2_lib.init(...)
end

local function shutdown(...)
	return luagit2_lib.shutdown(...)
end

local function libgit2_features(...)
	return luagit2_lib.libgit2_features(...)
end

local function libgit2_version(...)
	return luagit2_lib.libgit2_version(...)
end

local function get_mwindow_size(...)
	return luagit2_lib.get_mwindow_size(...)
end

local function set_mwindow_size(...)
	return luagit2_lib.set_mwindow_size(...)
end

local function get_mwindow_mapped_limit(...)
	return luagit2_lib.get_mwindow_mapped_limit(...)
end

local function set_mwindow_mapped_limit(...)
	return luagit2_lib.set_mwindow_mapped_limit(...)
end

local function get_search_path(...)
	return luagit2_lib.get_search_path(...)
end

local function set_search_path(...)
	return luagit2_lib.set_search_path(...)
end

local function get_cached_memory(...)
	return luagit2_lib.get_cached_memory(...)
end

local function set_cache_object_limit(...)
	return luagit2_lib.set_cache_object_limit(...)
end

local function set_cache_max_size(...)
	return luagit2_lib.set_cache_max_size(...)
end

local function enable_caching(...)
	return luagit2_lib.enable_caching(...)
end

local function get_template_path(...)
	return luagit2_lib.get_template_path(...)
end

local function set_template_path(...)
	return luagit2_lib.set_template_path(...)
end

local function set_user_agent(...)
	return luagit2_lib.set_user_agent(...)
end

local function get_windows_sharemode(...)
	return luagit2_lib.get_windows_sharemode(...)
end

local function set_windows_sharemode(...)
	return luagit2_lib.set_windows_sharemode(...)
end

local function enable_strict_object_creation(...)
	return luagit2_lib.enable_strict_object_creation(...)
end

local function enable_strict_symbolic_ref_creation(...)
	return luagit2_lib.enable_strict_symbolic_ref_creation(...)
end

local function set_ssl_ciphers(...)
	return luagit2_lib.set_ssl_ciphers(...)
end

local function enable_ofs_delta(...)
	return luagit2_lib.enable_ofs_delta(...)
end

local function enable_fsync_gitdir(...)
	return luagit2_lib.enable_fsync_gitdir(...)
end

local function enable_strict_hash_verification(...)
	return luagit2_lib.enable_strict_hash_verification(...)
end

luagit2_libgit.init = init
luagit2_libgit.shutdown = shutdown
luagit2_libgit.libgit2_features = libgit2_features
luagit2_libgit.libgit2_version = libgit2_version
luagit2_libgit.get_mwindow_size = get_mwindow_size
luagit2_libgit.set_mwindow_size = set_mwindow_size
luagit2_libgit.get_mwindow_mapped_limit = get_mwindow_mapped_limit
luagit2_libgit.set_mwindow_mapped_limit = set_mwindow_mapped_limit
luagit2_libgit.get_search_path = get_search_path
luagit2_libgit.set_search_path = set_search_path
luagit2_libgit.get_cached_memory = get_cached_memory
luagit2_libgit.set_cache_object_limit = set_cache_object_limit
luagit2_libgit.set_cache_max_size = set_cache_max_size
luagit2_libgit.enable_caching = enable_caching
luagit2_libgit.get_template_path = get_template_path
luagit2_libgit.set_template_path = set_template_path
luagit2_libgit.set_user_agent = set_user_agent
luagit2_libgit.get_windows_sharemode = get_windows_sharemode
luagit2_libgit.set_windows_sharemode = set_windows_sharemode
luagit2_libgit.enable_strict_object_creation = enable_strict_object_creation
luagit2_libgit.enable_strict_symbolic_ref_creation = enable_strict_symbolic_ref_creation
luagit2_libgit.set_ssl_ciphers = set_ssl_ciphers
luagit2_libgit.enable_ofs_delta = enable_ofs_delta
luagit2_libgit.enable_fsync_gitdir = enable_fsync_gitdir
luagit2_libgit.enable_strict_hash_verification = enable_strict_hash_verification

return luagit2_libgit

