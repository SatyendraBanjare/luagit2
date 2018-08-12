local luagit2_lib = require("luagit2")

local luagit2_tree = {}

---------------------------------------------------------------------
-- {"tree_entry_byid", lua_git_tree_entry_byid},
-- {"tree_entry_byindex", lua_git_tree_entry_byindex},
-- {"tree_entry_byname", lua_git_tree_entry_byname},
-- {"tree_entry_bypath", lua_git_tree_entry_bypath},
-- {"tree_entry_cmp", lua_git_tree_entry_cmp},
-- {"tree_entry_filemode", lua_git_tree_entry_filemode},
-- {"tree_entry_filemode_raw", lua_git_tree_entry_filemode_raw},
-- {"tree_entry_id", lua_git_tree_entry_id},
-- {"tree_entry_name", lua_git_tree_entry_name},
-- {"tree_entry_to_object", lua_git_tree_entry_to_object},
-- {"tree_entry_type", lua_git_tree_entry_type},
-- {"tree_entrycount", lua_git_tree_entrycount},
-- {"tree_id", lua_git_tree_id},
-- {"tree_lookup", lua_git_tree_lookup},
-- {"tree_lookup_prefix", lua_git_tree_lookup_prefix},
-- {"tree_owner", lua_git_tree_owner},
-- {"tree_entry_free", lua_git_tree_entry_free},
-- {"tree_free", lua_git_tree_free},
---------------------------------------------------------------------

local function tree_entry_byid(...)
	return luagit2_lib.tree_entry_byid(...)
end

local function tree_entry_byindex(...)
	return luagit2_lib.tree_entry_byindex(...)
end

local function tree_entry_byname(...)
	return luagit2_lib.tree_entry_byname(...)
end

local function tree_entry_bypath(...)
	return luagit2_lib.tree_entry_bypath(...)
end

local function tree_entry_cmp(...)
	return luagit2_lib.tree_entry_cmp(...)
end

local function tree_entry_filemode(...)
	return luagit2_lib.tree_entry_filemode(...)
end

local function tree_entry_filemode_raw(...)
	return luagit2_lib.tree_entry_filemode_raw(...)
end

local function tree_entry_id(...)
	return luagit2_lib.tree_entry_id(...)
end

local function tree_entry_name(...)
	return luagit2_lib.tree_entry_name(...)
end

local function tree_entry_to_object(...)
	return luagit2_lib.tree_entry_to_object(...)
end

local function tree_entry_type(...)
	return luagit2_lib.tree_entry_type(...)
end

local function tree_entrycount(...)
	return luagit2_lib.tree_entrycount(...)
end

local function tree_id(...)
	return luagit2_lib.tree_id(...)
end

local function tree_lookup_prefix(...)
	return luagit2_lib.tree_lookup_prefix(...)
end

local function tree_lookup(...)
	return luagit2_lib.tree_lookup(...)
end

local function tree_owner(...)
	return luagit2_lib.tree_owner(...)
end

local function tree_entry_free(...)
	return luagit2_lib.tree_entry_free(...)
end

local function tree_free(...)
	return luagit2_lib.tree_free(...)
end

luagit2_tree.tree_entry_byid = tree_entry_byid
luagit2_tree.tree_entry_byindex = tree_entry_byindex
luagit2_tree.tree_entry_byname = tree_entry_byname
luagit2_tree.tree_entry_bypath = tree_entry_bypath
luagit2_tree.tree_entry_cmp = tree_entry_cmp
luagit2_tree.tree_entry_filemode = tree_entry_filemode
luagit2_tree.tree_entry_filemode_raw = tree_entry_filemode_raw
luagit2_tree.tree_entry_id = tree_entry_id
luagit2_tree.tree_entry_name = tree_entry_name
luagit2_tree.tree_entry_to_object = tree_entry_to_object
luagit2_tree.tree_entry_type = tree_entry_type
luagit2_tree.tree_entrycount = tree_entrycount
luagit2_tree.tree_id = tree_id
luagit2_tree.tree_lookup = tree_lookup
luagit2_tree.tree_lookup_prefix = tree_lookup_prefix
luagit2_tree.tree_owner = tree_owner
luagit2_tree.tree_entry_free = tree_entry_free
luagit2_tree.tree_free = tree_free

return luagit2_tree
