-- Luagit2's Tree Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Tree Methods Tests ", function()
	local lib = require("luagit2")
	local repo_path = "Fixtures/WORKON_REPO"
	local tree_oid_string = "619f9935957e010c419cb9d15621916ddfcc0b96"
	local README_oid_string = "1385f264afb75a56a5bec74243be9b367ba4ca08"
	local tree_oid, tree , README_oid
	local current_directory_path = lfs.currentdir()

	setup(function()
		lib.luagit2_init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = lib.luagit2_repository_open(repo_path)
		tree_oid = lib.luagit2_oid_fromstr(tree_oid_string)
		README_oid = lib.luagit2_oid_fromstr(README_oid_string)
		tree = lib.luagit2_tree_lookup(repo,tree_oid)
	end)

	after_each(function()
		lib.luagit2_tree_free(tree)
		lib.luagit2_repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		lib.luagit2_shutdown()
	end)

	--[[ A simple output of `git cat-file -p HEAD^{tree}`
		 on Fixtures/new_test_repo

		100644 blob 1385f264afb75a56a5bec74243be9b367ba4ca08	README
		100644 blob ce013625030ba8dba906f756967f9e9ca394464a	abc.txt
		100644 blob fa49b077972391ad58037050f2a75f74e3671e92	new.txt
		040000 tree 619f9935957e010c419cb9d15621916ddfcc0b96	subdir <--------|
																				|
		---------------------------------------------------------------         |
																				|
		An output of                                                            | 
		-$ git ls-tree 619f9935957e010c419cb9d15621916ddfc  <-------------------|

		100644 blob 1385f264afb75a56a5bec74243be9b367ba4ca08	README
		100644 blob fa49b077972391ad58037050f2a75f74e3671e92	new.txt
		040000 tree f60079018b664e4e79329a7ef9559c8d9e0378d1	subdir2
	]]--

	it("Tests Tree id",function()
		-- It tests that id of tree generated
		-- acually matches one used for creation

		local tree_id_check = lib.luagit2_tree_id(tree)
		local tree_id_str_check = lib.luagit2_oid_tostr_s(tree_id_check)
		assert.are.equal(tree_oid_string,tree_id_str_check)

	end)

	it("Tests Tree owner repository",function()
		local owner_repo = lib.luagit2_tree_owner(tree)
		local owner_repo_path = lib.luagit2_repository_path(owner_repo)

		-- Check with absolute path 
		assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/" , owner_repo_path)
	end)

	it("Tests tree lookup by prefix",function()
		-- Lookup using first 5 chars of oid
		local tree_by_prefix = lib.luagit2_tree_lookup_prefix(repo,tree_oid,5)

		-- Check for returned oid value
		-- Must match with original value
		local tree_id_check = lib.luagit2_tree_id(tree_by_prefix)
		local tree_id_str_check = lib.luagit2_oid_tostr_s(tree_id_check)
		assert.are.equal(tree_oid_string,tree_id_str_check)
	end)

	it("Tests Tree entry count",function()
		--
		-- Get th entries count
		-- It should be equal to '3'
		-- As seen in the output of git ls-tree
		--
		local count = lib.luagit2_tree_entrycount(tree)
		assert.are.equal(3,count)
	end)

	it("Tests getting Tree entries ",function()
		--
		-- Here we retrieve trww entries by different
		-- available methods. Then we check for their
		-- Values.
		--
		-- By oid of README
		local README_entry_by_id = lib.luagit2_tree_entry_byid(tree,README_oid)

		-- Since README is the first in tree, its index value is 0
		local README_entry_byindex = lib.luagit2_tree_entry_byindex(tree,0)

		-- Make sure this object does exist in tree by
		-- given name. 
		local README_entry_byname = lib.luagit2_tree_entry_byname(tree,"README")

		-- README is in the current path pointed 
		-- by tree object. Hence simply passing the name 
		-- would work.
		local README_entry_bypath = lib.luagit2_tree_entry_bypath(tree,"README")


		-- Get ids for each tree entry
		local entry_oid_byid = lib.luagit2_tree_entry_id(README_entry_by_id)
		local entry_oid_byindex = lib.luagit2_tree_entry_id(README_entry_byindex)
		local entry_oid_byname = lib.luagit2_tree_entry_id(README_entry_byname)
		local entry_oid_bypath = lib.luagit2_tree_entry_id(README_entry_bypath)

		-- Get the names for different Entries
		local entry_name_byid = lib.luagit2_tree_entry_name(README_entry_by_id)
		local entry_name_byindex = lib.luagit2_tree_entry_name(README_entry_by_id)
		local entry_name_byname = lib.luagit2_tree_entry_name(README_entry_by_id)
		local entry_name_bypath = lib.luagit2_tree_entry_name(README_entry_by_id)

		-- Check for the values of oids
		-- They all must be consistent with readme's oid string value
		assert.are.equal(README_oid_string,lib.luagit2_oid_tostr_s(entry_oid_byid))
		assert.are.equal(README_oid_string,lib.luagit2_oid_tostr_s(entry_oid_byindex))
		assert.are.equal(README_oid_string,lib.luagit2_oid_tostr_s(entry_oid_byname))
		assert.are.equal(README_oid_string,lib.luagit2_oid_tostr_s(entry_oid_bypath))

		-- Check for the values of entry names 
		-- They all must be README .
		assert.are.equal("README",entry_name_byid)
		assert.are.equal("README",entry_name_byindex)
		assert.are.equal("README",entry_name_byname)
		assert.are.equal("README",entry_name_bypath)

	end)

	it("Tests tree entry's object type",function()
		local README_entry_by_id = lib.luagit2_tree_entry_byid(tree,README_oid)
		local entry_type = lib.luagit2_tree_entry_type(README_entry_by_id)

		local type_value = lib.luagit2_object_type2string(entry_type)
		assert.are.equal("blob",type_value)
	end)

end)