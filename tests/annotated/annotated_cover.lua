local luagit2_lib = require("luagit2")

local luagit2_annotated = {}
-------------------------------------------------------------------------------
--
-- Functions of annotated module to test coverage for.
--
-- {"annotated_commit_from_ref",lua_git_annotated_commit_from_ref},
-- {"annotated_commit_from_revspec",lua_git_annotated_commit_from_revspec},
-- {"annotated_commit_lookup",lua_git_annotated_commit_lookup},
-- {"annotated_commit_from_fetchhead",lua_git_annotated_commit_from_fetchhead},
-- {"annotated_commit_id",lua_git_annotated_commit_id},
-- {"annotated_commit_free",lua_git_annotated_commit_free},
--------------------------------------------------------------------------------

local function annotated_commit_from_ref(...)
	return luagit2_lib.annotated_commit_from_ref(...)
end

local function annotated_commit_from_revspec(...)
	return luagit2_lib.annotated_commit_from_revspec(...)
end

local function annotated_commit_lookup(...)
	return luagit2_lib.annotated_commit_lookup(...)
end

local function annotated_commit_from_fetchhead(...)
	return luagit2_lib.annotated_commit_from_fetchhead(...)
end

local function annotated_commit_id(...)
	return luagit2_lib.annotated_commit_id(...)
end

local function annotated_commit_free(...)
	return luagit2_lib.annotated_commit_free(...)
end

luagit2_annotated.annotated_commit_from_ref = annotated_commit_from_ref
luagit2_annotated.annotated_commit_from_revspec = annotated_commit_from_revspec
luagit2_annotated.annotated_commit_lookup = annotated_commit_lookup
luagit2_annotated.annotated_commit_from_fetchhead = annotated_commit_from_fetchhead
luagit2_annotated.annotated_commit_id = annotated_commit_id
luagit2_annotated.annotated_commit_free = annotated_commit_free

return luagit2_annotated

