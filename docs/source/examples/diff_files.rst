Get Diff for files in index
===========================

luagit2's "diff" example

( equivalent to git diff <file> )

shows how to get the diff data for a given repo.

The user should pass a valid git repository's path as 1st argument and
2nd argument as : The format of diff data it should print, any of :
raw, patch, name_only, name_status, patch_header
 
Note : the passed file paths must be relative to the given repository's path

.. code-block:: lua

	local luagit2 = require("luagit2")
	luagit2.init()

	local repo_path = arg[1]
	local format_type = arg[2]

	local repo = luagit2.repository_open(repo_path)
	local repo_index = luagit2.repository_index(repo)

	-- Get the diff data for current index to workdir.
	local diff_options = luagit2.diff_init_options()
	local diff_idx_wkdir = luagit2.diff_index_to_workdir(repo,repo_index,diff_options)

	local diff_format_options = luagit2.diff_format_init(format_type)

	local diff_idx_wkdir_buf = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options)
	local diff_data = luagit2.buf_details(diff_idx_wkdir_buf)

	--Finally Print the data.
	print(diff_data)

	luagit2.index_free(repo_index)
	luagit2.repository_free(repo)

	luagit2.shutdown()

