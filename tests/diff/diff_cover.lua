local luagit2_lib = require("luagit2")

local luagit2_diff = {}

------------------------------------------------------------------------------
-- {"diff_init_options",lua_git_diff_init_options},
-- {"diff_get_stats",lua_git_diff_get_stats},
-- {"diff_index_to_index",lua_git_diff_index_to_index},
-- {"diff_index_to_workdir",lua_git_diff_index_to_workdir},
-- {"diff_is_sorted_icase",lua_git_diff_is_sorted_icase},
-- {"diff_merge",lua_git_diff_merge},
-- {"diff_num_deltas",lua_git_diff_num_deltas},
-- {"diff_stats_deletions",lua_git_diff_stats_deletions},
-- {"diff_stats_files_changed",lua_git_diff_stats_files_changed},
-- {"diff_stats_insertions",lua_git_diff_stats_insertions},
-- {"diff_stats_to_buf",lua_git_diff_stats_to_buf},
-- {"diff_to_buf",lua_git_diff_to_buf},
-- {"diff_tree_to_index",lua_git_diff_tree_to_index},
-- {"diff_tree_to_tree",lua_git_diff_tree_to_tree},
-- {"diff_tree_to_workdir",lua_git_diff_tree_to_workdir},
-- {"diff_tree_to_workdir_with_index",lua_git_diff_tree_to_workdir_with_index},
--
-- {"diff_format_init",lua_diff_format_init},
-- {"diff_stats_format_init",lua_diff_stats_format_init},
--------------------------------------------------------------------------------

local function diff_init_options(...)
	return luagit2_lib.diff_init_options(...)
end

local function diff_get_stats(...)
	return luagit2_lib.diff_get_stats(...)
end

local function diff_index_to_index(...)
	return luagit2_lib.diff_index_to_index(...)
end

local function diff_index_to_workdir(...)
	return luagit2_lib.diff_index_to_workdir(...)
end

local function diff_is_sorted_icase(...)
	return luagit2_lib.diff_is_sorted_icase(...)
end

local function diff_merge(...)
	return luagit2_lib.diff_merge(...)
end

local function diff_num_deltas(...)
	return luagit2_lib.diff_num_deltas(...)
end

local function diff_stats_deletions(...)
	return luagit2_lib.diff_stats_deletions(...)
end

local function diff_stats_files_changed(...)
	return luagit2_lib.diff_stats_files_changed(...)
end

local function diff_stats_insertions(...)
	return luagit2_lib.diff_stats_insertions(...)
end

local function diff_stats_to_buf(...)
	return luagit2_lib.diff_stats_to_buf(...)
end

local function diff_to_buf(...)
	return luagit2_lib.diff_to_buf(...)
end

local function diff_tree_to_index(...)
	return luagit2_lib.diff_tree_to_index(...)
end

local function diff_tree_to_tree(...)
	return luagit2_lib.diff_tree_to_tree(...)
end

local function diff_tree_to_workdir(...)
	return luagit2_lib.diff_tree_to_workdir(...)
end

local function diff_tree_to_workdir_with_index(...)
	return luagit2_lib.diff_tree_to_workdir_with_index(...)
end

local function diff_format_init(...)
	return luagit2_lib.diff_format_init(...)
end

local function diff_stats_format_init(...)
	return luagit2_lib.diff_stats_format_init(...)
end

luagit2_diff.diff_init_options = diff_init_options
luagit2_diff.diff_get_stats = diff_get_stats
luagit2_diff.diff_index_to_index = diff_index_to_index
luagit2_diff.diff_index_to_workdir = diff_index_to_workdir
luagit2_diff.diff_is_sorted_icase = diff_is_sorted_icase
luagit2_diff.diff_merge = diff_merge
luagit2_diff.diff_num_deltas = diff_num_deltas
luagit2_diff.diff_stats_deletions = diff_stats_deletions
luagit2_diff.diff_stats_files_changed = diff_stats_files_changed
luagit2_diff.diff_stats_insertions = diff_stats_insertions
luagit2_diff.diff_stats_to_buf = diff_stats_to_buf
luagit2_diff.diff_to_buf = diff_to_buf
luagit2_diff.diff_tree_to_index = diff_tree_to_index
luagit2_diff.diff_tree_to_tree = diff_tree_to_tree
luagit2_diff.diff_tree_to_workdir = diff_tree_to_workdir
luagit2_diff.diff_tree_to_workdir_with_index = diff_tree_to_workdir_with_index
luagit2_diff.diff_format_init = diff_format_init
luagit2_diff.diff_stats_format_init = diff_stats_format_init

return luagit2_diff
