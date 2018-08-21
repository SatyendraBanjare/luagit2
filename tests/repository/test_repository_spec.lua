-- Luagit2's Repisitory module tests

local fixer = require("Fixtures.fix_repo")
local lfs = require("lfs")

describe(" Repository Methods Tests ", function()
	local luagit2 = require("luagit2")
	local repo
	local current_directory_path = lfs.currentdir()

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("testrepo")
		repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
	end)

	after_each(function()
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	--[[
		A simple output of `git config -l` on Fixtures/testrepo
		After the repo has been fixed for testing , that is user.email
		and user.name have been set (see fixer.set_repo())

		user.name=Satyendra_Kumar_Banjare
		user.email=satyendrabanjare99@gmail.com
		user.email=satyendrabanjare99@gmail.com
		user.name=Satyendra_Kumar_Banjare
		core.repositoryformatversion=0
		core.filemode=true
		core.bare=false
		core.logallrefupdates=true
		remote.test.url=git://github.com/libgit2/libgit2
		remote.test.fetch=+refs/heads/*:refs/remotes/test/*
		user.name=TEST_USER
		user.email=testusernoreply@github.com
		
	]]--

	it("Tests Repository Commondir",function()
		-- Checks the common dir of repository
		local common_dir = luagit2.repository_commondir(repo)
		assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/" , common_dir)
	end)

	it("Tests Repository Config & Repository Config Snapshot",function()
		-- Get the config for the repository
		local Config = luagit2.repository_config(repo)
		-- Create a Snapshot to read the existing values 
		local Config_Snapshot = luagit2.repository_config_snapshot(repo)

		-- Get the username & useremail values and match
		local old_name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local old_email = luagit2.config_get_string(Config_Snapshot,"user.email")

		assert.are.equal("TEST_USER",old_name)
		assert.are.equal("testusernoreply@github.com",old_email)

		-- Free the old config snapshot
		luagit2.config_free(Config_Snapshot)

		-- Set the Values on test repository's config
		luagit2.config_set_string(Config,"user.email","newemail@example.com")
		luagit2.config_set_string(Config,"user.name","NEW_NAME_TEST_USER")

		-- Create a Snapshot to read the existing values 
		local Config_Snapshot = luagit2.repository_config_snapshot(repo)

		-- Get the username & useremail values and match
		local new_name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local new_email = luagit2.config_get_string(Config_Snapshot,"user.email")

		assert.are.equal("NEW_NAME_TEST_USER",new_name)
		assert.are.equal("newemail@example.com",new_email)

		-- Free the new config snapshot
		luagit2.config_free(Config_Snapshot)
		-- Finally free the used config
		luagit2.config_free(Config)
	end)

	it("Tests detach head",function()
		-- Check originally that the HEAD
		-- of used test repository is not detached
		local is_head_detached = luagit2.repository_head_detached(repo)
		assert.are.equal(false,is_head_detached)

		-- Detach the HEAD for the test repo
		luagit2.repository_detach_head(repo)

		-- Check again if HEAD is detached
		is_head_detached = luagit2.repository_head_detached(repo)
		assert.are.equal(true,is_head_detached)
	end)

	it("Tests repository namespace",function()
		-- Currently in the test repo,
		-- No used namespaces are used
		-- Therefore it should return nil.
		local namespace = luagit2.repository_get_namespace(repo)
		assert.is_nil(namespace)

		-- Lets Set the namespace for repo and check again
		luagit2.repository_set_namespace(repo,"SOME_EXAMPLE_NAMESPACE")
		local namespace_new = luagit2.repository_get_namespace(repo)
		assert.are.equal("SOME_EXAMPLE_NAMESPACE",namespace_new)
	end)

	it("Tests getting Repository HEAD",function()
		-- Get repository HEAD refernce
		-- and Check its name value
		local repo_HEAD_ref = luagit2.repository_head(repo)
		local ref_name = luagit2.reference_name(repo_HEAD_ref)
		assert.are.equal("refs/heads/master",ref_name)
	end)
	
	it("Tests Head unborn",function()
		-- Since there is HEAD present in the current repo
		-- this should value to 0
		local is_head_unborn = luagit2.repository_head_unborn(repo)
		assert.are.equal(false,is_head_unborn)

		-- Lets Create an initial repo and check if it has head unborn
		--
		-- Create an empty non bare repository 
		local repo_init = luagit2.repository_init("Fixtures/WORKON_REPO_INIT",0)
		-- Check if head is unborn or not
		local is_initialized_repo_head_unborn = luagit2.repository_head_unborn(repo_init)
		assert.are.equal(true,is_initialized_repo_head_unborn)

		-- Free used repo && remove the files
		luagit2.repository_free(repo_init)
		os.execute('cd Fixtures && rm -rf WORKON_REPO_INIT')
	end)

	it("Tests Repository index", function()
		-- Get the index for the current repo
		local index = luagit2.repository_index(repo)

		-- Get the owner repo of index and check
		-- For the owner repo's path it should be equal to 
		-- original rest repo's path
		local owner_repo = luagit2.index_owner(index)
		local owner_repo_path = luagit2.repository_path(owner_repo)
		assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/" , owner_repo_path)
	end)

	it("Tests Repository identity",function()
		-- initially the identity values for the 
		-- taken test repo are not set, we should therefore
		-- get nil values.
		local old_name, old_email  = luagit2.repository_ident(repo)
		assert.is_nil(old_name)
		assert.is_nil(old_email)


		-- Lets set the identity values & check again
		luagit2.repository_set_ident(repo,"EXAMPLE_NAME","something@something.com")
		local new_name,new_email  = luagit2.repository_ident(repo)

		assert.are.equal("something@something.com",new_email)
	end)

	it("Tests repository bare methods",function()
		-- Check if initially the repo is bare or not 
		local is_bare = luagit2.repository_is_bare(repo)
		assert.are.equal(false,is_bare)

		-- set the repository to bare
		luagit2.repository_set_bare(repo)
		-- Check again
		is_bare = luagit2.repository_is_bare(repo)
		assert.are.equal(true,is_bare)
	end)

	it("Tests check-repository is_empty, is_shallow, is_worktree methods",function()
		-- Clearly the repository is not empty,
		-- nor shallow and also does not have a worktree
		local is_empty = luagit2.repository_is_empty(repo)
		assert.are.equal(false,is_empty)

		local is_shallow = luagit2.repository_is_shallow(repo)
		assert.are.equal(false,is_shallow)
		
		local is_worktree = luagit2.repository_is_worktree(repo)
		assert.are.equal(false,is_worktree)
	end)

	it("Tests repositoy odb",function()
		-- improve this test later
		local repo_odb = luagit2.repository_odb(repo)
		assert.is_not_nil(repo_odb)
	end)

	it("Tests open repository as bare",function()
		-- open a repo in bare form 
		local bare_repo = luagit2.repository_open_bare("Fixtures/WORKON_REPO/.git")
		-- Check if the opened repo is bare or not
		local repo_is_bare = luagit2.repository_is_bare(bare_repo)
		assert.are.equal(true,repo_is_bare)

		-- Free used repo
		luagit2.repository_free(bare_repo)
	end)

	it("Tests set repository Head",function()
		-- Set the HEAD to another branch
		-- The branch must be present at the refs/heads

		luagit2.repository_set_head(repo,"refs/heads/executable")
		local repo_HEAD_ref = luagit2.repository_head(repo)
		local ref_name = luagit2.reference_name(repo_HEAD_ref)
		assert.are.equal("refs/heads/executable",ref_name)
	end)

	it("Tests repository submodule related methods",function()
		luagit2.repository_submodule_cache_all(repo)
		luagit2.repository_submodule_cache_clear(repo)
	end)

	it("Tests repo cleanup",function()
		luagit2.repository_cleanup(repo)
	end)
end)
