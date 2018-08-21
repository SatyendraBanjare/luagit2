------------------------------------------------------------------------------
--
-- luagit2's "add" example
-- ( equivalent to git add <file> )
--
-- Copyright (c) 2018 Satyendra Kumar Banjare
-- 
-- shows how to modify the index
--
-- The user should pass a valid git repository's path as 1st argument.
-- and can pass as many file path to add to the current index as he/she wishes.
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
local num_files = (#arg)

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

----------------------------------------------------------
--
-- Add the files to current index
----------------------------------------------------------
for i=2,num_files do
	luagit2.index_add_bypath(repo_index,arg[i])
end

----------------------------------------------------------
-- Finally write the added files onto the disk
----------------------------------------------------------
luagit2.index_write(repo_index)

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

