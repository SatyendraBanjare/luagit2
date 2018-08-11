local luagit2_lib = require("luagit2")

local luagit2_index = {}

---------------------------------------------------------------
-- {"index_add", lua_git_index_add},
-- {"index_add_bypath", lua_git_index_add_bypath},
-- {"index_caps", lua_git_index_caps},
-- {"index_checksum", lua_git_index_checksum},
-- {"index_conflict_add", lua_git_index_conflict_add},
-- {"index_conflict_cleanup", lua_git_index_conflict_cleanup},
-- {"index_entry_is_conflict", lua_git_index_entry_is_conflict},
-- {"index_entry_stage", lua_git_index_entry_stage},
-- {"index_entrycount", lua_git_index_entrycount},
-- {"index_find", lua_git_index_find},
-- {"index_find_prefix", lua_git_index_find_prefix},
-- {"index_get_byindex", lua_git_index_get_byindex},
-- {"index_get_bypath", lua_git_index_get_bypath},
-- {"index_has_conflicts", lua_git_index_has_conflicts},
-- {"index_open", lua_git_index_open},
-- {"index_owner", lua_git_index_owner},
-- {"index_path", lua_git_index_path},
-- {"index_read", lua_git_index_read},
-- {"index_read_tree", lua_git_index_read_tree},
-- {"index_remove", lua_git_index_remove},
-- {"index_remove_bypath", lua_git_index_remove_bypath},
-- {"index_remove_directory", lua_git_index_remove_directory},
-- {"index_set_caps", lua_git_index_set_caps},
-- {"index_set_version", lua_git_index_set_version},
-- {"index_version", lua_git_index_version},
-- {"index_write", lua_git_index_write},
-- {"index_write_tree", lua_git_index_write_tree},
-- {"index_write_tree_to", lua_git_index_write_tree_to},
-- {"index_free", lua_git_index_free},
--
-- {"index_entry_get_path",lua_git_index_entry_get_path},
-- {"index_entry_get_filemode",lua_git_index_entry_get_filemode},
-- {"index_entry_get_filesize",lua_git_index_entry_get_filesize},
-- {"index_entry_get_stage",lua_git_index_entry_get_stage},
-- {"index_entry_get_oid_str",lua_git_index_entry_get_oid_str},
-- {"index_entry_get_dev_inode",lua_git_index_entry_get_dev_inode},
-- {"index_entry_get_UID_GID",lua_git_index_entry_get_UID_GID},
------------------------------------------------------------------

local function index_add( ... )
	return luagit2_lib.index_add(...)
end

local function index_add_bypath(...)
	return luagit2_lib.index_add_bypath(...)
end

local function index_caps(...)
	return luagit2_lib.index_caps(...)
end

local function index_checksum(...)
	return luagit2_lib.index_checksum(...)
end

local function index_conflict_add(...)
	return luagit2_lib.index_conflict_add(...)
end

local function index_conflict_cleanup(...)
	return luagit2_lib.index_conflict_cleanup(...)
end

local function index_entry_is_conflict(...)
	return luagit2_lib.index_entry_is_conflict(...)
end

local function index_entry_stage(...)
	return luagit2_lib.index_entry_stage(...)
end

local function index_entrycount(...)
	return luagit2_lib.index_entrycount(...)
end

local function index_find(...)
	return luagit2_lib.index_find(...)
end

local function index_find_prefix(...)
	return luagit2_lib.index_find_prefix(...)
end

local function index_get_byindex(...)
	return luagit2_lib.index_get_byindex(...)
end

local function index_get_bypath(...)
	return luagit2_lib.index_get_bypath(...)
end

local function index_has_conflicts(...)
	return luagit2_lib.index_has_conflicts(...)
end

local function index_owner(...)
	return luagit2_lib.index_owner(...)
end

local function index_path(...)
	return luagit2_lib.index_path(...)
end

local function index_read(...)
	return luagit2_lib.index_read(...)
end

local function index_read_tree(...)
	return luagit2_lib.index_read_tree(...)
end

local function index_remove(...)
	return luagit2_lib.index_remove(...)
end

local function index_remove_bypath(...)
	return luagit2_lib.index_remove_bypath(...)
end

local function index_remove_directory(...)
	return luagit2_lib.index_remove_directory(...)
end

local function index_set_caps(...)
	return luagit2_lib.index_set_caps(...)
end

local function index_set_version(...)
	return luagit2_lib.index_set_version(...)
end

local function index_version(...)
	return luagit2_lib.index_version(...)
end

local function index_write(...)
	return luagit2_lib.index_write(...)
end

local function index_write_tree(...)
	return luagit2_lib.index_write_tree(...)
end

local function index_write_tree_to(...)
	return luagit2_lib.index_write_tree_to(...)
end

local function index_free(...)
	return luagit2_lib.index_free(...)
end

local function index_entry_get_path(...)
	return luagit2_lib.index_entry_get_path(...)
end

local function index_entry_get_filemode(...)
	return luagit2_lib.index_entry_get_filemode(...)
end

local function index_entry_get_filesize(...)
	return luagit2_lib.index_entry_get_filesize(...)
end

local function index_entry_get_stage(...)
	return luagit2_lib.index_entry_get_stage(...)
end

local function index_entry_get_oid_str(...)
	return luagit2_lib.index_entry_get_oid_str(...)
end

local function index_entry_get_dev_inode(...)
	return luagit2_lib.index_entry_get_dev_inode(...)
end

local function index_entry_get_UID_GID(...)
	return luagit2_lib.index_entry_get_UID_GID(...)
end

local function index_open(...)
	return luagit2_lib.index_open(...)
end

luagit2_index.index_add = index_add
luagit2_index.index_add_bypath = index_add_bypath
luagit2_index.index_caps = index_caps
luagit2_index.index_checksum = index_checksum
luagit2_index.index_conflict_add = index_conflict_add
luagit2_index.index_conflict_cleanup = index_conflict_cleanup
luagit2_index.index_entry_is_conflict = index_entry_is_conflict
luagit2_index.index_entry_stage = index_entry_stage
luagit2_index.index_entrycount = index_entrycount
luagit2_index.index_find = index_find
luagit2_index.index_find_prefix = index_find_prefix
luagit2_index.index_get_byindex = index_get_byindex
luagit2_index.index_get_bypath = index_get_bypath
luagit2_index.index_has_conflicts = index_has_conflicts
luagit2_index.index_open = index_open
luagit2_index.index_owner = index_owner
luagit2_index.index_path = index_path
luagit2_index.index_read = index_read
luagit2_index.index_read_tree = index_read_tree
luagit2_index.index_remove = index_remove
luagit2_index.index_remove_bypath = index_remove_bypath
luagit2_index.index_remove_directory = index_remove_directory
luagit2_index.index_set_caps = index_set_caps
luagit2_index.index_set_version = index_set_version
luagit2_index.index_version = index_version
luagit2_index.index_write = index_write
luagit2_index.index_write_tree = index_write_tree
luagit2_index.index_write_tree_to = index_write_tree_to
luagit2_index.index_free = index_free
luagit2_index.index_entry_get_path = index_entry_get_path
luagit2_index.index_entry_get_filemode = index_entry_get_filemode
luagit2_index.index_entry_get_filesize = index_entry_get_filesize
luagit2_index.index_entry_get_stage = index_entry_get_stage
luagit2_index.index_entry_get_oid_str = index_entry_get_oid_str
luagit2_index.index_entry_get_dev_inode = index_entry_get_dev_inode
luagit2_index.index_entry_get_UID_GID = index_entry_get_UID_GID

return luagit2_index
