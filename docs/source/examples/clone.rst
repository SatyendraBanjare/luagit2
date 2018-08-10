Clone Public Repo
=================

luagit2's "clone" example
( equivalent to git clone <repo_url> <path_where_to_clone> )
 
shows how clone only a public repository

The user should pass a valid git repository's remote url as 1st argument.
and pass the directory path where to clone.


.. code-block:: lua

	local luagit2 = require("luagit2")
	luagit2.init()

	if (#arg ~= 2) then
		print("2 arguments required <repo_url> <path_where_to_clone> ")
		return
	end

	local remote_url = arg[1]
	local clone_location = arg[2]
	
	luagit2.clone_public(remote_url,clone_location,1) -- passing 1 to print clone print progress.
                                                      -- pass 0 to not print clone progress.
	luagit2.shutdown()