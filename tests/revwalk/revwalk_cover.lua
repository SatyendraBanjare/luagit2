local luagit2_lib = require("luagit2")

local luagit2_revwalk = {}

-------------------------------------------------------------------------
-- {"revwalk_new",lua_git_revwalk_new},
-- {"revwalk_next",lua_git_revwalk_next},
-- {"revwalk_push",lua_git_revwalk_push},
-- {"revwalk_push_ref",lua_git_revwalk_push_ref},
-- {"revwalk_free",lua_git_revwalk_free},
-- {"revwalk_reset",lua_git_revwalk_reset},
-- {"revwalk_push_head",lua_git_revwalk_push_head},
-- {"revwalk_repository",lua_git_revwalk_repository},
-------------------------------------------------------------------------

local function revwalk_new(...)
	return luagit2_lib.revwalk_new(...)
end

local function revwalk_next(...)
	return luagit2_lib.revwalk_next(...)
end

local function revwalk_push(...)
	return luagit2_lib.revwalk_push(...)
end

local function revwalk_push_ref(...)
	return luagit2_lib.revwalk_push_ref(...)
end

local function revwalk_free(...)
	return luagit2_lib.revwalk_free(...)
end

local function revwalk_reset(...)
	return luagit2_lib.revwalk_reset(...)
end

local function revwalk_push_head(...)
	return luagit2_lib.revwalk_push_head(...)
end

local function revwalk_repository(...)
	return luagit2_lib.revwalk_repository(...)
end

luagit2_revwalk.revwalk_new = revwalk_new
luagit2_revwalk.revwalk_next = revwalk_next
luagit2_revwalk.revwalk_push = revwalk_push
luagit2_revwalk.revwalk_push_ref = revwalk_push_ref
luagit2_revwalk.revwalk_free = revwalk_free
luagit2_revwalk.revwalk_reset = revwalk_reset
luagit2_revwalk.revwalk_push_head = revwalk_push_head
luagit2_revwalk.revwalk_repository = revwalk_repository

return luagit2_revwalk
