-- Luagit2's Object Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Object Methods Tests ", function()
	local luagit2 = require("luagit2")
	local luagit2_object = require("object.object_cover")
	local repo
	local blob_id_str = "1385f264afb75a56a5bec74243be9b367ba4ca08"
	local tree_id_str = "181037049a54a1eb5fab404658a3a250b44335d7"
	local tag_id_str = "0c37a5391bbff43c37f0d0371823a5509eed5b1d"
	local commit_id_str = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
	local blob_id, tree_id, tag_id, commit_id
	local otype_blob, otype_tree, otype_tag, otype_commit
	local obj_blob, obj_tree, obj_tag, obj_commit
	local current_directory_path = lfs.currentdir()

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
		blob_id = luagit2.oid_fromstr(blob_id_str)
		tree_id = luagit2.oid_fromstr(tree_id_str)
		tag_id = luagit2.oid_fromstr(tag_id_str)
		commit_id = luagit2.oid_fromstr(commit_id_str)
		otype_blob = luagit2_object.object_string2type("blob")
		otype_tree = luagit2_object.object_string2type("tree")
		otype_tag = luagit2_object.object_string2type("tag")
		otype_commit = luagit2_object.object_string2type("commit")
		obj_blob = luagit2_object.object_lookup(repo,blob_id,otype_blob)
		obj_tree = luagit2_object.object_lookup(repo,tree_id,otype_tree)
		obj_tag = luagit2_object.object_lookup(repo,tag_id,otype_tag)
		obj_commit = luagit2_object.object_lookup(repo,commit_id,otype_commit)
	end)

	after_each(function()
		luagit2_object.object_free(obj_blob)
		luagit2_object.object_free(obj_tree)
		luagit2_object.object_free(obj_tag)
		luagit2_object.object_free(obj_commit)
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	--[[ A part of the ` git cat-file --batch-check --batch-all-objects `
		 on tests/new_test_repo

		 for tests we have used these values

		0c37a5391bbff43c37f0d0371823a5509eed5b1d tag 144         | (for obj_tag)
		108ddee361877aa5c044d89d8dd232b8fd0f8992 commit 236      | (for obj_commit)
		1385f264afb75a56a5bec74243be9b367ba4ca08 blob 4          | (for obj_blob)
		181037049a54a1eb5fab404658a3a250b44335d7 tree 34         | (for obj_tree)
		1810dff58d8a660512d4832e740f692884338ccd tree 112
		1b49a09ae5e707b8ed48e6048aa1901138838944 tree 137
		2d2eff63372b08adf0a9eb84109ccf7d19e2f3a2 commit 163
		36060c58702ed4c2a40832c51758d5344201d89a commit 227
		418382dff1ffb8bdfba833f4d8bbcde58b1e7f47 tree 39
		41bc8c69075bbdb46c5c6f0566cc8cc5b46e8bd9 commit 230
		45b983be36b73c0788dc9cbcb76cbb80fc7bb057 blob 3
		4a202b346bb0fb0db7eff3cffeb3c70babbd2045 commit 227
		5001298e0c09ad9c34e4249bc5801c75e9754fa5 commit 182
		5b5b025afb0b4c913b4c338a42934a3863bf3644 commit 227

	]]--

	it("Tests getting object ID ",function()
		local check_blob_id = luagit2_object.object_id(obj_blob)
		local check_blob_id_str = luagit2.oid_tostr_s(check_blob_id)

		local check_tag_id = luagit2_object.object_id(obj_tag)
		local check_tag_id_str = luagit2.oid_tostr_s(check_tag_id)

		local check_tree_id = luagit2_object.object_id(obj_tree)
		local check_tree_id_str = luagit2.oid_tostr_s(check_tree_id)

		local check_commit_id = luagit2_object.object_id(obj_commit)
		local check_commit_id_str = luagit2.oid_tostr_s(check_commit_id)

		assert.are.equal(blob_id_str,check_blob_id_str)
		assert.are.equal(tag_id_str,check_tag_id_str)
		assert.are.equal(tree_id_str,check_tree_id_str)
		assert.are.equal(commit_id_str,check_commit_id_str)
	end)

	it("Checks Object Type ",function()
		local type_blob = luagit2_object.object_type(obj_blob)
		local type_tree = luagit2_object.object_type(obj_tree)
		local type_tag = luagit2_object.object_type(obj_tag)
		local type_commit = luagit2_object.object_type(obj_commit)

		assert.are.equal("blob",luagit2_object.object_type2string(type_blob))
		assert.are.equal("tree",luagit2_object.object_type2string(type_tree))
		assert.are.equal("tag",luagit2_object.object_type2string(type_tag))
		assert.are.equal("commit",luagit2_object.object_type2string(type_commit))
	end)

	it("Tests object short id",function()
		local short_id_buf = luagit2_object.object_short_id(obj_blob)
		local str_value = luagit2.buf_details(short_id_buf)
		assert.is_not_nil(string.match(blob_id_str,str_value))
	end)

	it("Tests object owner",function()
		-- Get the owner repository
		local owner_repo = luagit2_object.object_owner(obj_blob)

		-- Get the repo path for that owner repository
		local owner_repo_path = luagit2.repository_path(owner_repo)

		-- Check with absolute path 
		assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/" , owner_repo_path)
	end)
end)
