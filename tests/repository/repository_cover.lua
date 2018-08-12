local luagit2_lib = require("luagit2")

local luagit2_repository = {}

------------------------------------------------------------------------------------
-- {"repository_commondir", lua_git_repository_commondir},
-- {"repository_config", lua_git_repository_config},
-- {"repository_config_snapshot", lua_git_repository_config_snapshot},
-- {"repository_detach_head", lua_git_repository_detach_head},
-- {"repository_get_namespace", lua_git_repository_get_namespace},
-- {"repository_head", lua_git_repository_head},
-- {"repository_head_detached", lua_git_repository_head_detached},
-- {"repository_head_for_worktree", lua_git_repository_head_for_worktree},
-- {"repository_head_unborn", lua_git_repository_head_unborn},
-- {"repository_ident", lua_git_repository_ident},
-- {"repository_index", lua_git_repository_index},
-- {"repository_init", lua_git_repository_init},
-- {"repository_is_bare", lua_git_repository_is_bare},
-- {"repository_is_empty", lua_git_repository_is_empty},
-- {"repository_is_shallow", lua_git_repository_is_shallow},
-- {"repository_is_worktree", lua_git_repository_is_worktree},
-- {"repository_message", lua_git_repository_message},
-- {"repository_message_remove", lua_git_repository_message_remove},
-- {"repository_odb", lua_git_repository_odb},
-- {"repository_open", lua_git_repository_open},
-- {"repository_open_bare", lua_git_repository_open_bare},
-- {"repository_open_from_worktree", lua_git_repository_open_from_worktree},
-- {"repository_path", lua_git_repository_path},
-- {"repository_refdb", lua_git_repository_refdb},
-- {"repository_set_head", lua_git_repository_set_head},
-- {"repository_set_head_detached", lua_git_repository_set_head_detached},
-- {"repository_set_ident", lua_git_repository_set_ident},
-- {"repository_set_namespace", lua_git_repository_set_namespace},
-- {"repository_set_workdir", lua_git_repository_set_workdir},
-- {"repository_state", lua_git_repository_state},
-- {"repository_state_cleanup", lua_git_repository_state_cleanup},
-- {"repository_workdir", lua_git_repository_workdir},
-- {"repository_free", lua_git_repository_free},
-- {"repository_submodule_cache_all",lua_git_repository_submodule_cache_all},
-- {"repository_submodule_cache_clear",lua_git_repository_submodule_cache_clear},
-- {"repository_set_index",lua_git_repository_set_index},
-- {"repository_set_bare",lua_git_repository_set_bare},
-- {"repository_set_config",lua_git_repository_set_config},
-- {"repository_set_odb",lua_git_repository_set_odb},
-- {"repository_cleanup",lua_git_repository__cleanup},
------------------------------------------------------------------------------------

local function repository_commondir(...)
	return luagit2_lib.repository_commondir(...)
end

local function repository_config_snapshot(...)
	return luagit2_lib.repository_config_snapshot(...)
end

local function repository_config(...)
	return luagit2_lib.repository_config(...)
end

local function repository_detach_head(...)
	return luagit2_lib.repository_detach_head(...)
end

local function repository_get_namespace(...)
	return luagit2_lib.repository_get_namespace(...)
end

local function repository_head(...)
	return luagit2_lib.repository_head(...)
end

local function repository_head_detached(...)
	return luagit2_lib.repository_head_detached(...)
end

local function repository_head_for_worktree(...)
	return luagit2_lib.repository_head_for_worktree(...)
end

local function repository_head_unborn(...)
	return luagit2_lib.repository_head_unborn(...)
end

local function repository_ident(...)
	return luagit2_lib.repository_ident(...)
end

local function repository_index(...)
	return luagit2_lib.repository_index(...)
end

local function repository_init(...)
	return luagit2_lib.repository_init(...)
end

local function repository_is_bare(...)
	return luagit2_lib.repository_is_bare(...)
end

local function repository_is_empty(...)
	return luagit2_lib.repository_is_empty(...)
end

local function repository_is_shallow(...)
	return luagit2_lib.repository_is_shallow(...)
end

local function repository_is_worktree(...)
	return luagit2_lib.repository_is_worktree(...)
end

local function repository_message(...)
	return luagit2_lib.repository_message(...)
end

local function repository_message_remove(...)
	return luagit2_lib.repository_message_remove(...)
end

local function repository_odb(...)
	return luagit2_lib.repository_odb(...)
end

local function repository_open(...)
	return luagit2_lib.repository_open(...)
end

local function repository_open_bare(...)
	return luagit2_lib.repository_open_bare(...)
end

local function repository_open_from_worktree(...)
	return luagit2_lib.repository_open_from_worktree(...)
end

local function repository_path(...)
	return luagit2_lib.repository_path(...)
end

local function repository_refdb(...)
	return luagit2_lib.repository_refdb(...)
end

local function repository_set_head(...)
	return luagit2_lib.repository_set_head(...)
end

local function repository_set_head_detached(...)
	return luagit2_lib.repository_set_head_detached(...)
end

local function repository_set_ident(...)
	return luagit2_lib.repository_set_ident(...)
end

local function repository_set_namespace(...)
	return luagit2_lib.repository_set_namespace(...)
end

local function repository_set_workdir(...)
	return luagit2_lib.repository_set_workdir(...)
end

local function repository_state(...)
	return luagit2_lib.repository_state(...)
end

local function repository_state_cleanup(...)
	return luagit2_lib.repository_state_cleanup(...)
end

local function repository_workdir(...)
	return luagit2_lib.repository_workdir(...)
end

local function repository_free(...)
	return luagit2_lib.repository_free(...)
end

local function repository_submodule_cache_all(...)
	return luagit2_lib.repository_submodule_cache_all(...)
end

local function repository_submodule_cache_clear(...)
	return luagit2_lib.repository_submodule_cache_clear(...)
end

local function repository_set_index(...)
	return luagit2_lib.repository_set_index(...)
end

local function repository_set_bare(...)
	return luagit2_lib.repository_set_bare(...)
end

local function repository_set_config(...)
	return luagit2_lib.repository_set_config(...)
end

local function repository_set_odb(...)
	return luagit2_lib.repository_set_odb(...)
end

local function repository_cleanup(...)
	return luagit2_lib.repository_cleanup(...)
end

luagit2_repository.repository_commondir = repository_commondir
luagit2_repository.repository_config = repository_config
luagit2_repository.repository_config_snapshot = repository_config_snapshot
luagit2_repository.repository_detach_head = repository_detach_head
luagit2_repository.repository_get_namespace = repository_get_namespace
luagit2_repository.repository_head = repository_head
luagit2_repository.repository_head_detached = repository_head_detached
luagit2_repository.repository_head_for_worktree = repository_head_for_worktree
luagit2_repository.repository_head_unborn = repository_head_unborn
luagit2_repository.repository_ident = repository_ident
luagit2_repository.repository_index = repository_index
luagit2_repository.repository_init = repository_init
luagit2_repository.repository_is_bare = repository_is_bare
luagit2_repository.repository_is_empty = repository_is_empty
luagit2_repository.repository_is_shallow = repository_is_shallow
luagit2_repository.repository_is_worktree = repository_is_worktree
luagit2_repository.repository_message = repository_message
luagit2_repository.repository_message_remove = repository_message_remove
luagit2_repository.repository_odb = repository_odb
luagit2_repository.repository_open = repository_open
luagit2_repository.repository_open_bare = repository_open_bare
luagit2_repository.repository_open_from_worktree = repository_open_from_worktree
luagit2_repository.repository_path = repository_path
luagit2_repository.repository_refdb = repository_refdb
luagit2_repository.repository_set_head = repository_set_head
luagit2_repository.repository_set_head_detached = repository_set_head_detached
luagit2_repository.repository_set_ident = repository_set_ident
luagit2_repository.repository_set_namespace = repository_set_namespace
luagit2_repository.repository_set_workdir = repository_set_workdir
luagit2_repository.repository_state = repository_state
luagit2_repository.repository_state_cleanup = repository_state_cleanup
luagit2_repository.repository_workdir = repository_workdir
luagit2_repository.repository_free = repository_free
luagit2_repository.repository_submodule_cache_all = repository_submodule_cache_all
luagit2_repository.repository_submodule_cache_clear = repository_submodule_cache_clear
luagit2_repository.repository_set_index = repository_set_index
luagit2_repository.repository_set_bare = repository_set_bare
luagit2_repository.repository_set_config = repository_set_config
luagit2_repository.repository_set_odb = repository_set_odb
luagit2_repository.repository_cleanup = repository_cleanup


return luagit2_repository
