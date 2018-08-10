Init a blank repo and make an initial commit
============================================

luagit2's "init" example

( equivalent to git init [path] [--bare] )
 
shows how to init a bare or non bare repository

Pass the path where to create a new repo.
should be in form : <folder_name/.git>

.. code-block:: lua

	local luagit2 = require("luagit2")
	luagit2.init()

	local repo_path = arg[1]
	local is_bare = arg[2]
	local repo

	if is_bare == "--bare" then
		repo = luagit2.repository_init(repo_path,1)
		
		else repo = luagit2.repository_init(repo_path,0)
	end 
	 
	-- Create an initial commit.
	--
	-- initializing parameters.

	local repo_index = luagit2.repository_index(repo)
	local index_write_tree_oid = luagit2.index_write_tree(repo_index)
	local tree = luagit2.tree_lookup(repo,index_write_tree_oid)
	local author_sign = luagit2.signature_default(repo)
	local committer_sign = luagit2.signature_default(repo)

	--
	-- Creating an initial commit is different as there is no parent commit 
	-- present so, use commit_create_initial() to make an initial commit.

	local new_commit_id = luagit2.commit_create_initial(repo,author_sign,
				committer_sign,"Initial commit",tree) 

	local new_commit_str = luagit2.oid_tostr(new_commit_id)
	print("Newly created commit's id : " .. new_commit_str)

	-- at this point, if you run a git log in the new created
	-- repo, you should see a complete log for initial commit.


	luagit2.tree_free(tree)
	luagit2.index_free(repo_index)
	luagit2.repository_free(repo)

	luagit2.shutdown()

