-- Tests for luagit2's Blob module functions

local fixer = require("Fixtures.fix_repo")


describe(" Blob Methods Tests ", function()
	local luagit2 = require("luagit2")
	local repo_path = "Fixtures/WORKON_REPO"
	local README_oid_string = "1385f264afb75a56a5bec74243be9b367ba4ca08"
	local abc_txt_oid_string = "ce013625030ba8dba906f756967f9e9ca394464a"
	local README_blob_oid ,  abc_txt_blob_oid
	local README_blob , abc_txt_blob
	local current_directory_path = lfs.currentdir()

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = luagit2.repository_open(repo_path)
		README_blob_oid = luagit2.blob_create_fromdisk(repo,repo_path .. "/README")
		abc_txt_blob_oid = luagit2.blob_create_fromdisk(repo,repo_path .. "/abc.txt")
		README_blob = luagit2.blob_lookup(repo,README_blob_oid)
		abc_txt_blob = luagit2.blob_lookup(repo,abc_txt_blob_oid)
	end)

	after_each(function()
		luagit2.blob_free(README_blob)
		luagit2.blob_free(abc_txt_blob)
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	--[[ A simple output of `git cat-file -p HEAD^{tree}`
		 on Fixtures/new_test_repo

		100644 blob 1385f264afb75a56a5bec74243be9b367ba4ca08	README
		100644 blob ce013625030ba8dba906f756967f9e9ca394464a	abc.txt
		100644 blob fa49b077972391ad58037050f2a75f74e3671e92	new.txt
		040000 tree 619f9935957e010c419cb9d15621916ddfcc0b96	subdir

	]]--

	it("Tests if blob ID matches", function()
		-- Tests if received blob oid strings actually exists
		assert.are.equal(README_oid_string,luagit2.oid_tostr_s(README_blob_oid))
		assert.are.equal(abc_txt_oid_string,luagit2.oid_tostr_s(abc_txt_blob_oid))
	end)

	it("Tests loking up blob in the repo",function()
		-- Checks that the looked up blob in
		-- repository has same oid as original
		local README_id = luagit2.blob_id(README_blob)
		assert.are.equal(README_oid_string,luagit2.oid_tostr_s(README_id))

		local blob_id = luagit2.blob_id(abc_txt_blob)
		assert.are.equal(abc_txt_oid_string,luagit2.oid_tostr_s(blob_id))
	end)

	it("Tests Creating Blob oid from workdir",function()
		-- create the blob oid
		-- Be careful that to pass only
		-- the name of file from the root of 
		-- used git repository 
		local workdir_blob_id = luagit2.blob_create_fromworkdir(repo,"README")
		-- Check if it is correct
		assert.are.equal(README_oid_string,luagit2.oid_tostr_s(workdir_blob_id))
	end)

	it("Tests Blob lookup prefix",function()
		-- Looks up for blob object using
		-- n lengthed prefix
		local readme_lookup_prefix = luagit2.blob_lookup_prefix(repo,README_blob_oid,5)
		local readme_lookup_prefix_oid = luagit2.blob_id(readme_lookup_prefix)
		assert.are.equal(README_oid_string,luagit2.oid_tostr_s(readme_lookup_prefix_oid))
		luagit2.blob_free(readme_lookup_prefix)
	end)

	it("Tests Blob Owner Repository",function()
		-- Get the owner repository
		local owner_repo = luagit2.blob_owner(README_blob)

		-- Get the repo path for that owner repository
		local owner_repo_path = luagit2.repository_path(owner_repo)

		-- Check with absolute path 
		assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/" , owner_repo_path)
	end)

	it("Tests if Blob is binary",function()
		-- As can be seen, the README is not a binary file
		-- So it should return 0.
		assert.are.equal(0,luagit2.blob_is_binary(README_blob))
	end)

end)
