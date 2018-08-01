-- Tests for lugit2's Reference module functions

local fixer = require("Fixtures.fix_repo")

describe(" Reference Methods Tests ", function()
	local luagit2 = require("luagit2")
	local repo
	local ref_dir, ref_point_to_blob
	local ref_dir_str = "144344043ba4d4a405da03de3844aa829ae8be0e"

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("testrepo")
		repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
		ref_dir = luagit2.reference_lookup(repo,"refs/heads/dir")
		ref_point_to_blob = luagit2.reference_lookup(repo,"refs/tags/point_to_blob")
	end)

	after_each(function()
		luagit2.reference_free(ref_dir)
		luagit2.reference_free(ref_point_to_blob)
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	--[[ An example output of git show-ref on testrepo
		
		a4a7dce85cf63874e984719f4fdd239f5145052f refs/heads/br2
		144344043ba4d4a405da03de3844aa829ae8be0e refs/heads/dir
		f9ed4af42472941da45a3ce44458455ed227a6be refs/heads/executable
		6fd5c7dd2ab27b48c493023f794be09861e9045f refs/heads/ident
		6b377958d8c6a4906e8573b53672a1a23a4e8ce6 refs/heads/long-file-name
		099fabac3a9ea935598528c27f866e34089c2eff refs/heads/master
		a38d028f71eaa590febb7d716b1ca32350cf70da refs/heads/merge-conflict
		41bc8c69075bbdb46c5c6f0566cc8cc5b46e8bd9 refs/heads/packed
		4a202b346bb0fb0db7eff3cffeb3c70babbd2045 refs/heads/packed-test
		763d71aadf09a7951596c9746c024e7eece7c7af refs/heads/subtrees
		e90810b8df3e80c413d903f631643c716887138d refs/heads/test
		099fabac3a9ea935598528c27f866e34089c2eff refs/heads/testrepo-worktree
		7b4384978d2493e851f9cca7858815fac9b10980 refs/tags/e90810b
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/foo/bar
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/foo/foo/bar
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/packed-tag
		1385f264afb75a56a5bec74243be9b367ba4ca08 refs/tags/point_to_blob
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/test

	]]--

	it("Checks the reference, if it is branch | note | remote | tag ",function()
		-- Get the different bool values.
		local is_branch_A = luagit2.reference_is_branch(ref_dir)
		local is_branch_B = luagit2.reference_is_branch(ref_point_to_blob)

		local is_note_A = luagit2.reference_is_note(ref_dir)
		local is_note_B = luagit2.reference_is_note(ref_point_to_blob)

		local is_remote_A = luagit2.reference_is_remote(ref_dir)
		local is_remote_B = luagit2.reference_is_remote(ref_point_to_blob)

		local is_tag_A = luagit2.reference_is_tag(ref_dir)
		local is_tag_B = luagit2.reference_is_tag(ref_point_to_blob)

		-- Check for the values
		assert.are.equal(1,is_branch_A)
		assert.are.equal(0,is_branch_B)

		assert.are.equal(0,is_note_A)
		assert.are.equal(0,is_note_B)

		assert.are.equal(0,is_remote_A)
		assert.are.equal(0,is_remote_B)

		assert.are.equal(0,is_tag_A)
		assert.are.equal(1,is_tag_B)
	end)

	it("Checks for a valid name",function()
		-- libgit2's documentation says :
		--  You must avoid the characters '~', '^', ':', '\', '?', 
		-- '[', and '*', and the sequences ".." and "@{" which have special meaning to revparse.
		local is_valid_name_A = luagit2.reference_is_valid_name("refs/tags/packed-tag")
		local is_valid_name_B = luagit2.reference_is_valid_name("refs/tags/alpha@{beta")

		assert.are.equal(1,is_valid_name_A)
		assert.are.equal(0,is_valid_name_B)
	end)

	it("Checks for reference name and its oid",function()
		local ref_name = luagit2.reference_name(ref_dir)
		assert.are.equal("refs/heads/dir",ref_name)

		local ref_oid = luagit2.reference_name_to_id(repo,"refs/heads/dir")
		local ref_oid_str = luagit2.oid_tostr_s(ref_oid)
		assert.are.equal(ref_dir_str,ref_oid_str)
	end)

	it("Tests reference remove",function()
		-- lets try looking up a ref
		local ref_executable = luagit2.reference_lookup(repo,"refs/heads/executable")
		local ref_name = luagit2.reference_name(ref_executable)
		assert.are.equal("refs/heads/executable",ref_name)

		-- Lets remove that reference from repo.
		luagit2.reference_remove(repo,"refs/heads/executable")

		-- At this point if you try looking up the refs/heads/executable
		-- using refernce_lookup, you will get an error that object is not found.
		--
		-- try running this
		-- ref_executable = luagit2.reference_lookup(repo,"refs/heads/executable"
	end)

	it("Tests reference rename ",function()
		-- lets try looking up a ref
		local ref_executable = luagit2.reference_lookup(repo,"refs/heads/executable")
		local ref_name = luagit2.reference_name(ref_executable)
		assert.are.equal("refs/heads/executable",ref_name)

		-- rename the ref
		luagit2.reference_rename(ref_executable,"refs/heads/new_name_for_executable",1,"changed name refs/heads/executable")

		-- Lets lookup for the reference with changed name.
		ref_executable = luagit2.reference_lookup(repo,"refs/heads/new_name_for_executable")
		ref_name = luagit2.reference_name(ref_executable)
		assert.are.equal("refs/heads/new_name_for_executable",ref_name)
	end)

	it("Tests reference target related functions",function()
		-- Get the old target of ref_dir
		local target_id = luagit2.reference_target(ref_dir)
		local target_id_str = luagit2.oid_tostr_s(target_id)
		assert.are.equal(ref_dir_str,target_id_str)

		-- change the target for that reference.
		-- get the oid for new target.
		local new_target_oid_str = "6fd5c7dd2ab27b48c493023f794be09861e9045f"
		local new_target_oid = luagit2.oid_fromstr(new_target_oid_str)
		-- Get the new changed refernce
		local new_target_ref = luagit2.reference_set_target(ref_dir,new_target_oid,"Reset target of ref_dir")

		-- check for the target the reference points at.
		local target_id_check = luagit2.reference_target(new_target_ref)
		local target_id_str_check = luagit2.oid_tostr_s(target_id_check)
		assert.are.equal(new_target_oid_str,target_id_str_check)

		-- check for the reference's name
		local ref_name = luagit2.reference_name(new_target_ref)
		assert.are.equal("refs/heads/dir",ref_name)
		-- See that the name of original refernce is not changed. 
		-- But the target it points to is changed.
	end)

	it("Tests reference iterator related functions",function()
		-- Get a reference iterator for the repository.
		local ref_iterator = luagit2.reference_iterator_new(repo)

		-- Get the next reference and check its name
		local next_ref_first = luagit2.reference_next(ref_iterator)
		local name = luagit2.reference_name(next_ref_first)
		assert.are.equal("refs/heads/br2",name)

		local next_ref_second = luagit2.reference_next_name(ref_iterator)
		assert.are.equal("refs/heads/dir",next_ref_second)
		-- and so on we can get next reference
		-- or simply its name.
	end)

	it("Tests reference Create",function()
		-- Create a new reference that
		-- targets to "ref/heads/dir"
		local target_oid = luagit2.oid_fromstr(ref_dir_str)
		local ref_create = luagit2.reference_create(repo,"refs/heads/a_new_ref",target_oid,1,"created new reference")

		-- Check the name and target of created reference.
		local ref_name = luagit2.reference_name(ref_create)
		assert.are.equal("refs/heads/a_new_ref",ref_name)

		local target_id = luagit2.reference_target(ref_create)
		local target_id_str = luagit2.oid_tostr_s(target_id)
		assert.are.equal(ref_dir_str,target_id_str)

		-- Free the used reference
		luagit2.reference_free(ref_create)
	end)

	it("Tests reference Create matching",function()
		-- Create a new reference that
		-- targets to "ref/heads/dir"
		-- and is matching to `ref/tags/point_to_blob`
		local target_oid = luagit2.oid_fromstr(ref_dir_str)
		local matching_reference_oid = luagit2.reference_name_to_id(repo,"refs/tags/point_to_blob")

		local ref_create_matching = luagit2.reference_create_matching(repo,"refs/tags/point_to_blob",target_oid,1,
			matching_reference_oid,"created new reference")

		-- Check the name and target of created reference.
		local ref_name = luagit2.reference_name(ref_create_matching)
		assert.are.equal("refs/tags/point_to_blob",ref_name)

		local target_id = luagit2.reference_target(ref_create_matching)
		local target_id_str = luagit2.oid_tostr_s(target_id)
		assert.are.equal(ref_dir_str,target_id_str)

		luagit2.reference_free(ref_create_matching)
	end)

	it("Tests reference symbolic Create",function()
		-- Create a new reference that
		-- targets to "ref/heads/dir"
		local ref_create_sym = luagit2.reference_symbolic_create(repo,"refs/heads/a_new_ref","ref/heads/dir",
			1,"created new reference")

		-- Check the name of created reference.
		local ref_name = luagit2.reference_name(ref_create_sym)
		assert.are.equal("refs/heads/a_new_ref",ref_name)

		luagit2.reference_free(ref_create_sym)
	end)

end)