------------------------------------------------------------------------------
--
-- luagit2's "diff" example
-- ( equivalent to git diff <file> )
--
-- Copyright (c) 2018 Satyendra Kumar Banjare
-- 
-- shows how to get the diff data for a given repo.
--
-- The user should pass a valid git repository's path as 1st argument and
-- 2nd argument as : The format of diff data it should print, any of :
-- raw, patch, name_only, name_status, patch_header
-- 
-- Note : the passed file paths must be relative to the given repository's path
--

local luagit2 = require("luagit2")

----------------------------------------------------------
-- The necessary funation call for initializing
-- Libgit2's global state & threading
----------------------------------------------------------
luagit2.init()

----------------------------------------------------------
--
-- Get the params from comand line
----------------------------------------------------------
local repo_path = arg[1]
local format_type = arg[2]

----------------------------------------------------------
--
-- Open repo using passed repository's path
----------------------------------------------------------
local repo = luagit2.repository_open(repo_path)

----------------------------------------------------------
--
-- Get the repository's current index
----------------------------------------------------------

local repo_index = luagit2.repository_index(repo)

---------------------------------------------------------
--
-- Get the diff data for current index to workdir.
local diff_options = luagit2.diff_init_options()
local diff_idx_wkdir = luagit2.diff_index_to_workdir(repo,repo_index,diff_options)

local diff_format_options = luagit2.diff_format_init(format_type)

local diff_idx_wkdir_buf = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options)
local diff_data = luagit2.buf_details(diff_idx_wkdir_buf)

--Finally Print the data.
print(diff_data)
----------------------------------------------------------
--
-- must free the used repository and index to prevent
-- memory leaks
----------------------------------------------------------

luagit2.index_free(repo_index)
luagit2.repository_free(repo)
----------------------------------------------------------
--
-- Shutdown the libgit2's threading and global state
----------------------------------------------------------
luagit2.shutdown()

