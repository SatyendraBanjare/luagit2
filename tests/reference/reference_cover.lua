local luagit2_lib = require("luagit2")

local luagit2_reference = {}

--------------------------------------------------------------------------------------
-- {"reference_create", lua_git_reference_create},
-- {"reference_create_matching", lua_git_reference_create_matching},
-- {"reference_dup", lua_git_reference_dup},
-- {"reference_dwim", lua_git_reference_dwim},
-- {"reference_ensure_log", lua_git_reference_ensure_log},
-- {"reference_has_log", lua_git_reference_has_log},
-- {"reference_is_branch", lua_git_reference_is_branch},
-- {"reference_is_note", lua_git_reference_is_note},
-- {"reference_is_remote", lua_git_reference_is_remote},
-- {"reference_is_tag", lua_git_reference_is_tag},
-- {"reference_is_valid_name", lua_git_reference_is_valid_name},
-- {"reference_iterator_glob_new", lua_git_reference_iterator_glob_new},
-- {"reference_iterator_new", lua_git_reference_iterator_new},
-- {"reference_list", lua_git_reference_list},
-- {"reference_lookup", lua_git_reference_lookup},
-- {"reference_name", lua_git_reference_name},
-- {"reference_name_to_id", lua_git_reference_name_to_id},
-- {"reference_next", lua_git_reference_next},
-- {"reference_next_name", lua_git_reference_next_name},
-- {"reference_owner", lua_git_reference_owner},
-- {"reference_peel", lua_git_reference_peel},
-- {"reference_remove", lua_git_reference_remove},
-- {"reference_rename", lua_git_reference_rename},
-- {"reference_resolve", lua_git_reference_resolve},
-- {"reference_set_target", lua_git_reference_set_target},
-- {"reference_symbolic_create", lua_git_reference_symbolic_create},
-- {"reference_symbolic_create_matching", lua_git_reference_symbolic_create_matching},
-- {"reference_symbolic_set_target", lua_git_reference_symbolic_set_target},
-- {"reference_symbolic_target", lua_git_reference_symbolic_target},
-- {"reference_target", lua_git_reference_target},
-- {"reference_target_peel", lua_git_reference_target_peel},
-- {"reference_type", lua_git_reference_type},
-- {"reference_free", lua_git_reference_free},
-- {"reference_iterator_free", lua_git_reference_iterator_free},
--------------------------------------------------------------------------------------

local function reference_create(...)
	return luagit2_lib.reference_create(...)
end

local function reference_create_matching(...)
	return luagit2_lib.reference_create_matching(...)
end

local function reference_dup(...)
	return luagit2_lib.reference_dup(...)
end

local function reference_dwim(...)
	return luagit2_lib.reference_dwim(...)
end

local function reference_ensure_log(...)
	return luagit2_lib.reference_ensure_log(...)
end

local function reference_has_log(...)
	return luagit2_lib.reference_has_log(...)
end

local function reference_is_branch(...)
	return luagit2_lib.reference_is_branch(...)
end

local function reference_is_note(...)
	return luagit2_lib.reference_is_note(...)
end

local function reference_is_remote(...)
	return luagit2_lib.reference_is_remote(...)
end

local function reference_is_tag(...)
	return luagit2_lib.reference_is_tag(...)
end

local function reference_is_valid_name(...)
	return luagit2_lib.reference_is_valid_name(...)
end

local function reference_iterator_glob_new(...)
	return luagit2_lib.reference_iterator_glob_new(...)
end

local function reference_iterator_new(...)
	return luagit2_lib.reference_iterator_new(...)
end

local function reference_list(...)
	return luagit2_lib.reference_list(...)
end

local function reference_lookup(...)
	return luagit2_lib.reference_lookup(...)
end

local function reference_name(...)
	return luagit2_lib.reference_name(...)
end

local function reference_next(...)
	return luagit2_lib.reference_next(...)
end

local function reference_name_to_id(...)
	return luagit2_lib.reference_name_to_id(...)
end

local function reference_next_name(...)
	return luagit2_lib.reference_next_name(...)
end

local function reference_owner(...)
	return luagit2_lib.reference_owner(...)
end

local function reference_peel(...)
	return luagit2_lib.reference_peel(...)
end

local function reference_remove(...)
	return luagit2_lib.reference_remove(...)
end

local function reference_rename(...)
	return luagit2_lib.reference_rename(...)
end

local function reference_resolve(...)
	return luagit2_lib.reference_resolve(...)
end

local function reference_set_target(...)
	return luagit2_lib.reference_set_target(...)
end

local function reference_symbolic_create(...)
	return luagit2_lib.reference_symbolic_create(...)
end

local function reference_symbolic_create_matching(...)
	return luagit2_lib.reference_symbolic_create_matching(...)
end

local function reference_symbolic_set_target(...)
	return luagit2_lib.reference_symbolic_set_target(...)
end

local function reference_symbolic_target(...)
	return luagit2_lib.reference_symbolic_target(...)
end

local function reference_target(...)
	return luagit2_lib.reference_target(...)
end

local function reference_target_peel(...)
	return luagit2_lib.reference_target_peel(...)
end

local function reference_type(...)
	return luagit2_lib.reference_type(...)
end

local function reference_free(...)
	return luagit2_lib.reference_free(...)
end

local function reference_iterator_free(...)
	return luagit2_lib.reference_iterator_free(...)
end

luagit2_reference.reference_create = reference_create
luagit2_reference.reference_create_matching = reference_create_matching
luagit2_reference.reference_dup = reference_dup
luagit2_reference.reference_dwim = reference_dwim
luagit2_reference.reference_ensure_log = reference_ensure_log
luagit2_reference.reference_has_log = reference_has_log
luagit2_reference.reference_is_branch = reference_is_branch
luagit2_reference.reference_is_note = reference_is_note
luagit2_reference.reference_is_remote = reference_is_remote
luagit2_reference.reference_is_tag = reference_is_tag
luagit2_reference.reference_is_valid_name = reference_is_valid_name
luagit2_reference.reference_iterator_glob_new = reference_iterator_glob_new
luagit2_reference.reference_iterator_new = reference_iterator_new
luagit2_reference.reference_list = reference_list
luagit2_reference.reference_lookup = reference_lookup
luagit2_reference.reference_name = reference_name
luagit2_reference.reference_name_to_id = reference_name_to_id
luagit2_reference.reference_next = reference_next
luagit2_reference.reference_next_name = reference_next_name
luagit2_reference.reference_owner = reference_owner
luagit2_reference.reference_peel = reference_peel
luagit2_reference.reference_remove = reference_remove
luagit2_reference.reference_rename = reference_rename
luagit2_reference.reference_resolve = reference_resolve
luagit2_reference.reference_set_target = reference_set_target
luagit2_reference.reference_symbolic_create = reference_symbolic_create
luagit2_reference.reference_symbolic_create_matching = reference_symbolic_create_matching
luagit2_reference.reference_symbolic_set_target = reference_symbolic_set_target
luagit2_reference.reference_symbolic_target = reference_symbolic_target
luagit2_reference.reference_target = reference_target
luagit2_reference.reference_target_peel = reference_target_peel
luagit2_reference.reference_type = reference_type
luagit2_reference.reference_free = reference_free
luagit2_reference.reference_iterator_free = reference_iterator_free

return luagit2_reference
