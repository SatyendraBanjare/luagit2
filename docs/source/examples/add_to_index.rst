Add Files to Index
==================

**luagit2's "add" example**

( equivalent to git add <file> )

It shows how to modify the index

The user should pass a valid git repository's path as 1st argument.
and can pass as many file path to add to the current index as he/she wishes.

.. note:: The passed file paths must be relative to the given repository's path

This file can be executed directly with some arguments.

.. code-block:: lua

	local luagit2 = require("luagit2")
	
	luagit2.init() -- initialize libgit2's threading and global state.
	
	local repo_path = arg[1] -- Get the repository's path
	local num_files = (#arg) -- Count total number of arguments
	
	local repo = luagit2.repository_open(repo_path)    -- open repository
	local repo_index = luagit2.repository_index(repo)  -- open repository's index

	for i=2,num_files do
		luagit2.index_add_bypath(repo_index,arg[i])    -- Add files to index
	end

	luagit2.index_write(repo_index)   -- Write added files to git index.

	luagit2.index_free(repo_index)    -- Free the used index
	luagit2.repository_free(repo)     -- Free used repository.

	luagit2.shutdown() -- Shutdown libgit threading and global state.

