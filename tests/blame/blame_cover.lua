local luagit2_lib = require("luagit2")

local luagit2_blame = {}

---------------------------------------------------------------
--
-- Complete set of blame functions to test lua coverage for.
--
-- {"blame_buffer", lua_git_blame_buffer},
-- {"blame_file", lua_git_blame_file},
-- {"blame_get_hunk_byindex", lua_git_blame_get_hunk_byindex},
-- {"blame_get_hunk_byline", lua_git_blame_get_hunk_byline},
-- {"blame_get_hunk_count", lua_git_blame_get_hunk_count},
-- {"blame_free", lua_git_blame_free},
--
-- {"blame_hunk_commit_id",lua_blame_hunk_commit_id},
-- {"blame_hunk_signature",lua_blame_hunk_signature},
-----------------------------------------------------------------

local function blame_buffer(...)
	return luagit2_lib.blame_buffer(...)
end

local function blame_file(...)
	return luagit2_lib.blame_file(...)
end

local function blame_get_hunk_byindex(...)
	return luagit2_lib.blame_get_hunk_byindex(...)
end

local function blame_get_hunk_byline(...)
	return luagit2_lib.blame_get_hunk_byline(...)
end

local function blame_get_hunk_count(...)
	return luagit2_lib.blame_get_hunk_count(...)
end

local function blame_free(...)
	return luagit2_lib.blame_free(...)
end

local function blame_hunk_commit_id(...)
	return luagit2_lib.blame_hunk_commit_id(...)
end

local function blame_hunk_signature(...)
	return luagit2_lib.blame_hunk_signature(...)
end

luagit2_blame.blame_buffer = blame_buffer
luagit2_blame.blame_file = blame_file
luagit2_blame.blame_get_hunk_byindex = blame_get_hunk_byindex
luagit2_blame.blame_get_hunk_byline = blame_get_hunk_byline
luagit2_blame.blame_get_hunk_count = blame_get_hunk_count
luagit2_blame.blame_free = blame_free
luagit2_blame.blame_hunk_commit_id = blame_hunk_commit_id
luagit2_blame.blame_hunk_signature = blame_hunk_signature

return luagit2_blame
