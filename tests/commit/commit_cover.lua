local luagit2_lib = require("luagit2")

local luagit2_commit = {}

-----------------------------------------------------------------
-- Complete set of functions to test coverage for.
--
-- {"commit_author", lua_git_commit_author},
-- {"commit_body", lua_git_commit_body},
-- {"commit_committer", lua_git_commit_committer},
-- {"commit_extract_signature", lua_git_commit_extract_signature},
-- {"commit_header_field", lua_git_commit_header_field},
-- {"commit_lookup", lua_git_commit_lookup},
-- {"commit_lookup_prefix", lua_git_commit_lookup_prefix},
-- {"commit_message", lua_git_commit_message},
-- {"commit_message_encoding = commit_message_encoding", lua_git_commit_message_encoding},
-- {"commit_message_raw", lua_git_commit_message_raw},
-- {"commit_nth_gen_ancestor", lua_git_commit_nth_gen_ancestor},
-- {"commit_parent", lua_git_commit_parent},
-- {"commit_parent_id", lua_git_commit_parent_id},
-- {"commit_parentcount", lua_git_commit_parentcount},
-- {"commit_raw_header", lua_git_commit_raw_header},
-- {"commit_summary", lua_git_commit_summary},
-- {"commit_time", lua_git_commit_time},
-- {"commit_tree", lua_git_commit_tree},
-- {"commit_tree_id", lua_git_commit_tree_id},
-- {"commit_free", lua_git_commit_free},
-- {"commit_id", lua_git_commit_id},
-- {"commit_create_update_head", lua_git_commit_create_update_head},
-- {"commit_create_update_none", lua_git_commit_create_update_none},
-- {"commit_create_with_signature",lua_git_commit_create_with_signature},
-- {"commit_create_initial",lua_git_commit_create_initial},
-----------------------------------------------------------------

local function commit_author(...)
	return luagit2_lib.commit_author(...)
end

local function commit_body(...)
	return luagit2_lib.commit_body(...)
end

local function commit_committer(...)
	return luagit2_lib.commit_committer(...)
end

local function commit_extract_signature(...)
	return luagit2_lib.commit_extract_signature(...)
end

local function commit_header_field(...)
	return luagit2_lib.commit_header_field(...)
end

local function commit_lookup(...)
	return luagit2_lib.commit_lookup(...)
end

local function commit_lookup_prefix(...)
	return luagit2_lib.commit_lookup_prefix(...)
end

local function commit_message(...)
	return luagit2_lib.commit_message(...)
end

local function commit_message_encoding(...)
	return luagit2_lib.commit_message_encoding(...)
end

local function commit_message_raw(...)
	return luagit2_lib.commit_message_raw(...)
end

local function commit_nth_gen_ancestor(...)
	return luagit2_lib.commit_nth_gen_ancestor(...)
end

local function commit_parent(...)
	return luagit2_lib.commit_parent(...)
end

local function commit_parent_id(...)
	return luagit2_lib.commit_parent_id(...)
end

local function commit_parentcount(...)
	return luagit2_lib.commit_parentcount(...)
end

local function commit_raw_header(...)
	return luagit2_lib.commit_raw_header(...)
end

local function commit_time(...)
	return luagit2_lib.commit_time(...)
end

local function commit_tree(...)
	return luagit2_lib.commit_tree(...)
end

local function commit_tree_id(...)
	return luagit2_lib.commit_tree_id(...)
end

local function commit_free(...)
	return luagit2_lib.commit_free(...)
end

local function commit_id(...)
	return luagit2_lib.commit_id(...)
end

local function commit_create_update_head(...)
	return luagit2_lib.commit_create_update_head(...)
end

local function commit_create_update_none(...)
	return luagit2_lib.commit_create_update_none(...)
end

local function commit_create_with_signature(...)
	return luagit2_lib.commit_create_with_signature(...)
end

local function commit_create_initial(...)
	return luagit2_lib.commit_create_initial(...)
end

local function commit_summary(...)
	return luagit2_lib.commit_summary(...)
end

luagit2_commit.commit_author = commit_author
luagit2_commit.commit_body = commit_body
luagit2_commit.commit_committer = commit_committer
luagit2_commit.commit_extract_signature = commit_extract_signature
luagit2_commit.commit_header_field = commit_header_field
luagit2_commit.commit_lookup = commit_lookup
luagit2_commit.commit_lookup_prefix = commit_lookup_prefix
luagit2_commit.commit_message = commit_message
luagit2_commit.commit_message_encoding = commit_message_encoding
luagit2_commit.commit_message_raw = commit_message_raw
luagit2_commit.commit_nth_gen_ancestor = commit_nth_gen_ancestor
luagit2_commit.commit_parent = commit_parent
luagit2_commit.commit_parent_id = commit_parent_id
luagit2_commit.commit_parentcount = commit_parentcount
luagit2_commit.commit_raw_header = commit_raw_header
luagit2_commit.commit_summary = commit_summary
luagit2_commit.commit_time = commit_time
luagit2_commit.commit_tree = commit_tree
luagit2_commit.commit_tree_id = commit_tree_id
luagit2_commit.commit_free = commit_free
luagit2_commit.commit_id = commit_id
luagit2_commit.commit_create_update_head = commit_create_update_head
luagit2_commit.commit_create_update_none = commit_create_update_none
luagit2_commit.commit_create_with_signature = commit_create_with_signature
luagit2_commit.commit_create_initial = commit_create_initial

return luagit2_commit
