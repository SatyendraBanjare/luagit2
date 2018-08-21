------------------------------------------------------------------------------
--
-- luagit2's "clone" example
-- ( equivalent to git clone <repo_url> <path_where_to_clone> )
--
-- Copyright (c) 2018 Satyendra Kumar Banjare
-- 
-- shows how clone only a public repository
--
-- The user should pass a valid git repository's remote url as 1st argument.
-- and pass the directory path where to clone.
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
if (#arg ~= 2) then
	print("2 arguments required <repo_url> <path_where_to_clone> ")
	return
end

local remote_url = arg[1]
local clone_location = arg[2]

----------------------------------------------------------
-- do the cloning clone
--
-- passed 1 to show clone progress.
-- pass 0 to prevent show clone progress.
----------------------------------------------------------
luagit2.clone_public(remote_url,clone_location,1)

----------------------------------------------------------
--
-- Shutdown the libgit2's threading and global state
----------------------------------------------------------
luagit2.shutdown()

