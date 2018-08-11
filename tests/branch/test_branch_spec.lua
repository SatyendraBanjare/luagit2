-- Luagit2's Branch module tests

local fixer = require("Fixtures.fix_repo")

describe(" Branch Methods Tests ", function()
	local luagit2 = require("luagit2")
	local luagit2_branch = require("branch.branch_cover")
	local repo
	local type_local, type_remote

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("testrepo")
		repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
		type_local = luagit2_branch.get_type_GIT_BRANCH_LOCAL()
		type_remote = luagit2_branch.get_type_GIT_BRANCH_REMOTE()
	end)

	after_each(function()
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	--[[ Output of `git branch -a` on Fixtures/testrepo

		br2
		dir
		executable
		ident
		long-file-name
		* master
		merge-conflict
		packed
		packed-test
		subtrees
		test
		testrepo-worktree

		--------------------------------------------------

		a small part of Output of `git log` on 
		master branch of Fixtures/testrepo

		commit 099fabac3a9ea935598528c27f866e34089c2eff
		Author: Ben Straub <bstraub@github.com>
		Date:   Mon Jul 16 15:23:16 2012 -0700

		    Add a symlink

		commit a65fedf39aefe402d3bb6e24df4d4f5fe4547750
		Author: Scott Chacon <schacon@gmail.com>
		Date:   Tue Aug 9 19:33:46 2011 -0700

		commit be3563ae3f795b2b4353bcce3a527ad0a4f7f644
		Merge: 9fd738e c47800c
		Author: Scott Chacon <schacon@gmail.com>
		Date:   Tue May 25 11:58:27 2010 -0700

    		Merge branch 'br2' 

	]]--

	it("Tests Branch lookup", function()
		-- Let's Check for few branches
		local master_branch = luagit2_branch.branch_lookup(repo,"master",type_local)
		local executable_branch = luagit2_branch.branch_lookup(repo,"executable",type_local)
		local dir_branch = luagit2_branch.branch_lookup(repo,"dir",type_local)
		
		-- Check their branch names
		assert.are.same("master",luagit2_branch.branch_name(master_branch))
		assert.are.same("executable",luagit2_branch.branch_name(executable_branch))
		assert.are.same("dir",luagit2_branch.branch_name(dir_branch))
	end)

	it("Tests Branch Create ", function()
		local commit_id = luagit2.oid_fromstr("099fabac3a9ea935598528c27f866e34089c2eff")
		local commit = luagit2.commit_lookup(repo,commit_id)

		-- Create a Branch
		luagit2_branch.branch_create(repo,"newly_created_branch_from_luagit2",commit,1)

		-- Lookup for the created branch in repository
		-- And check for its name. should be same as one
		-- used to create 
		local new_branch = luagit2_branch.branch_lookup(repo,"newly_created_branch_from_luagit2",type_local)
		assert.are.same("newly_created_branch_from_luagit2",luagit2_branch.branch_name(new_branch))
	end)

	it("Tests if branch is checked out",function()
		-- Create different branch refernces
		local master_branch = luagit2_branch.branch_lookup(repo,"master",type_local)
		local master_checked = luagit2_branch.branch_is_checked_out(master_branch)

		local dir_branch = luagit2_branch.branch_lookup(repo,"dir",type_local)
		local dir_checked = luagit2_branch.branch_is_checked_out(dir_branch)

		-- As can be seen , Master is Checked out
		-- Hence these values should match
		assert.are.equal(true,master_checked)
		assert.are.equal(false,dir_checked)
	end)

	it("Tests of Branch is Head",function()
		-- Create different branch refernces
		local master_branch = luagit2_branch.branch_lookup(repo,"master",type_local)
		local is_master_head = luagit2_branch.branch_is_head(master_branch)

		local dir_branch = luagit2_branch.branch_lookup(repo,"dir",type_local)
		local is_dir_head = luagit2_branch.branch_is_head(dir_branch)

		-- As can be seen , Master is being pointed by HEAD
		-- Hence these values should match
		assert.are.equal(true,is_master_head)
		assert.are.equal(false,is_dir_head)
	end)

	it("Tests Moving a branch into new one",function()
		-- lookup a branch to move
		local old_branch = luagit2_branch.branch_lookup(repo,"dir",type_local)

		-- new branch to move into
		luagit2_branch.branch_move(old_branch,"new_branch_name_for_dir",1)

		local new_branch = luagit2_branch.branch_lookup(repo,"new_branch_name_for_dir",type_local)	
		assert.are.same("new_branch_name_for_dir",luagit2_branch.branch_name(new_branch))
	end)

	it("Tests Setting and getting a branch's upstream",function()
		-- Set an Upstream for dir branch
		local dir_branch = luagit2_branch.branch_lookup(repo,"dir",type_local)
		luagit2_branch.branch_set_upstream(dir_branch,"master")

		-- Get the upstream branch
		-- Check if it matches the used to create
		-- the upstream
		local dir_upstream = luagit2_branch.branch_upstream(dir_branch)
		assert.are.same("master",luagit2_branch.branch_name(dir_upstream))
	end)

	it("Tests branch_iterator related functions ",function()
		-- currently the branch iterator
		-- should be at zeroth position
		-- Next accessed branch should be br2 (Sorted Alphabeticaly)
		-- Then dir and then executable
		local branch_iterator = luagit2_branch.branch_iterator_new(repo,type_local)
		
		local next_branch_first = luagit2_branch.branch_next(type_local,branch_iterator)
		assert.are.equal("br2",luagit2_branch.branch_name(next_branch_first))

		local next_branch_second = luagit2_branch.branch_next(type_local,branch_iterator)
		assert.are.equal("dir", luagit2_branch.branch_name(next_branch_second))

	end)
end)
