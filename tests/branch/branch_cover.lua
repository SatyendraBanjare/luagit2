local luagit2_lib = require("luagit2")

local luagit2_branch = {}

----------------------------------------------------------------------------
--
-- Complete set of functions to test coverage for.
--
-- {"branch_create", lua_git_branch_create},
-- {"branch_create_from_annotated", lua_git_branch_create_from_annotated},
-- {"branch_delete", lua_git_branch_delete},
-- {"branch_is_checked_out", lua_git_branch_is_checked_out},
-- {"branch_is_head", lua_git_branch_is_head},
-- {"branch_iterator_new", lua_git_branch_iterator_new},
-- {"branch_lookup", lua_git_branch_lookup},
-- {"branch_move", lua_git_branch_move},
-- {"branch_name", lua_git_branch_name},
-- {"branch_next", lua_git_branch_next},
-- {"branch_set_upstream", lua_git_branch_set_upstream},
-- {"branch_upstream", lua_git_branch_upstream},
--
-- {"get_type_GIT_BRANCH_LOCAL", get_type_GIT_BRANCH_LOCAL},
-- {"get_type_GIT_BRANCH_REMOTE", get_type_GIT_BRANCH_REMOTE},
------------------------------------------------------------------------------

local function branch_create(...)
	return luagit2_lib.branch_create(...)
end

local function branch_create_from_annotated(...)
	return luagit2_lib.branch_create_from_annotated(...)
end

local function branch_delete(...)
	return luagit2_lib.branch_delete(...)
end

local function branch_is_checked_out(...)
	return luagit2_lib.branch_is_checked_out(...)
end

local function branch_is_head(...)
	return luagit2_lib.branch_is_head(...)
end

local function branch_iterator_new(...)
	return luagit2_lib.branch_iterator_new(...)
end

local function branch_lookup(...)
	return luagit2_lib.branch_lookup(...)
end

local function branch_move(...)
	return luagit2_lib.branch_move(...)
end

local function branch_name(...)
	return luagit2_lib.branch_name(...)
end

local function branch_next(...)
	return luagit2_lib.branch_next(...)
end

local function branch_set_upstream(...)
	return luagit2_lib.branch_set_upstream(...)
end

local function branch_upstream(...)
	return luagit2_lib.branch_upstream(...)
end

local function get_type_GIT_BRANCH_LOCAL(...)
	return luagit2_lib.get_type_GIT_BRANCH_LOCAL(...)
end

local function get_type_GIT_BRANCH_REMOTE(...)
	return luagit2_lib.get_type_GIT_BRANCH_REMOTE(...)
end


luagit2_branch.branch_create = branch_create
luagit2_branch.branch_create_from_annotated = branch_create_from_annotated
luagit2_branch.branch_delete = branch_delete
luagit2_branch.branch_is_checked_out = branch_is_checked_out
luagit2_branch.branch_is_head = branch_is_head
luagit2_branch.branch_iterator_new = branch_iterator_new
luagit2_branch.branch_lookup = branch_lookup
luagit2_branch.branch_move = branch_move
luagit2_branch.branch_name = branch_name
luagit2_branch.branch_next = branch_next
luagit2_branch.branch_set_upstream = branch_set_upstream
luagit2_branch.branch_upstream = branch_upstream
luagit2_branch.get_type_GIT_BRANCH_LOCAL = get_type_GIT_BRANCH_LOCAL
luagit2_branch.get_type_GIT_BRANCH_REMOTE = get_type_GIT_BRANCH_REMOTE

return luagit2_branch

