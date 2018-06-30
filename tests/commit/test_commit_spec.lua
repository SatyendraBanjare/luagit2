-- Tests for lugit2's Commit module functions

local fixer = require("Fixtures.fix_repo")

describe(" Commit Methods Tests ", function()
	local lib = require("luagit2")
	local repo
	local Commit_Id_A_string = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
	local Commit_Id_B_string = "36060c58702ed4c2a40832c51758d5344201d89a"
	local Commit_Id_A, Commit_Id_B
	local Commit_A , Commit_B
	local Author_Sign_A, Author_Sign_B , Commmitter_Sign_A , Commmitter_Sign_B
	local current_write_tree_id = "1b49a09ae5e707b8ed48e6048aa1901138838944"

	setup(function()
		lib = require("luagit2")
		lib.luagit2_init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = lib.luagit2_repository_open("Fixtures/WORKON_REPO/.git")
		Commit_Id_A = lib.luagit2_oid_fromstr(Commit_Id_A_string)
		Commit_Id_B = lib.luagit2_oid_fromstr(Commit_Id_B_string)
		Commit_A = lib.luagit2_commit_lookup(repo,Commit_Id_A)
		Commit_B = lib.luagit2_commit_lookup(repo,Commit_Id_B)
		Author_Sign_A = lib.luagit2_commit_author(Commit_A)
		Author_Sign_B = lib.luagit2_commit_author(Commit_B)
		Commmitter_Sign_A = lib.luagit2_commit_committer(Commit_A)
		Commmitter_Sign_B = lib.luagit2_commit_committer(Commit_B)
	end)

	after_each(function()
		lib.luagit2_commit_free(Commit_A)
		lib.luagit2_commit_free(Commit_B)
		lib.luagit2_repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		lib.luagit2_shutdown()
	end)

	--[[ A simple output of 'git log' on Fixtures/new_test_repo 
		 Before Creating any other Commit in the tests below.
	
		commit 108ddee361877aa5c044d89d8dd232b8fd0f8992
		Author: test_user <test@example.com>
		Date:   Sat Jun 30 19:20:49 2018 +0530

		    Added File
		    
		    Commit message body

		commit 36060c58702ed4c2a40832c51758d5344201d89a
		Author: Scott Chacon <schacon@gmail.com>
		Date:   Tue Oct 26 15:44:21 2010 -0200

		    subdirectories

		commit 5b5b025afb0b4c913b4c338a42934a3863bf3644
		Author: Scott Chacon <schacon@gmail.com>
		Date:   Tue May 11 13:38:42 2010 -0700

		    another commit

		commit 8496071c1b46c854b31185ea97743be6a8774479
		Author: Scott Chacon <schacon@gmail.com>
		Date:   Sat May 8 16:13:06 2010 -0700

		    testing


		----------------------------------------------------------
		
		Output of 'git write-tree' on Fixtures/new_test_repo
		
		1b49a09ae5e707b8ed48e6048aa1901138838944

		This is the current tree id.

	]]--

	it("Tests the user data type",function()
		assert.are.equal("luagit2_oid",lib.get_userdata_name(Commit_Id_A))
		assert.are.equal("luagit2_oid",lib.get_userdata_name(Commit_Id_B))

		assert.are.equal("luagit2_commit",lib.get_userdata_name(Commit_A))
		assert.are.equal("luagit2_commit",lib.get_userdata_name(Commit_B))

		assert.are.equal("luagit2_signature",lib.get_userdata_name(Author_Sign_A))
		assert.are.equal("luagit2_signature",lib.get_userdata_name(Author_Sign_B))

		assert.are.equal("luagit2_signature",lib.get_userdata_name(Commmitter_Sign_A))
		assert.are.equal("luagit2_signature",lib.get_userdata_name(Commmitter_Sign_B))
	end)

	it("Tests Commit Author",function()
		assert.are.equal("test_user",lib.luagit2_get_signature_details(Author_Sign_A,1))
		assert.are.equal("test@example.com",lib.luagit2_get_signature_details(Author_Sign_A,2))

		assert.are.equal("Scott Chacon",lib.luagit2_get_signature_details(Author_Sign_B,1))
		assert.are.equal("schacon@gmail.com",lib.luagit2_get_signature_details(Author_Sign_B,2))
	end)

	it("Tests Commit Commmitter",function()
		assert.are.equal("test_user",lib.luagit2_get_signature_details(Commmitter_Sign_A,1))
		assert.are.equal("test@example.com",lib.luagit2_get_signature_details(Commmitter_Sign_A,2))

		assert.are.equal("Scott Chacon",lib.luagit2_get_signature_details(Commmitter_Sign_B,1))
		assert.are.equal("schacon@gmail.com",lib.luagit2_get_signature_details(Commmitter_Sign_B,2))
	end)

	it("Tests commit Body",function()
		assert.are.equal("Commit message body",lib.luagit2_commit_body(Commit_A))
		assert.is_nil(lib.luagit2_commit_body(Commit_B))
	end)

	it("Tests extract commit Header Field ", function()
		-- Parent for Commit_A is Commit_B
		-- So the commit id of Commit_B 
		-- Should be received
		local parent_buf = lib.luagit2_commit_header_field(Commit_A,"parent")
		assert.are.equal(Commit_Id_B_string, lib.luagit2_buf_details(parent_buf))

		-- We should get the current write-tree id
		local tree_buf = lib.luagit2_commit_header_field(Commit_A,"tree")
		assert.are.equal(current_write_tree_id, lib.luagit2_buf_details(tree_buf))
	end)

	it("Tests commit lookup using prefix", function()
		-- Create a simple commit object
		local Commit_test = lib.luagit2_commit_lookup(repo,Commit_Id_A,2)

		-- If this commit is valid , it should
		-- be same as Commit_A. Lets check for
		-- its id.

		local Commit_test_id = lib.luagit2_commit_id(Commit_test)
		assert.are.equal(Commit_Id_A_string, lib.luagit2_oid_tostr_s(Commit_test_id))
		lib.luagit2_commit_free(Commit_test)
	end)

	it("Tests commit Message",function()
		local message = lib.luagit2_commit_message(Commit_B)
		assert.are.same("subdirectories\n",message)
	end)
	
	it("Tests commit Message encoding ",function()
		-- Currently the messages are not encoded at all
		-- we therefore receive a nil
		local message_encoding = lib.luagit2_commit_message_encoding(Commit_A)
		assert.are.same(nil,message)
	end)

	it("Tests Commit Message Raw", function()
		local message_raw = lib.luagit2_commit_message(Commit_B)
		assert.are.same("subdirectories\n",message_raw)
	end)

	it("Tests Commit Nth generation parent",function()
		-- Zero generation ancestor means the commit itself
		local commit_gen_zero = lib.luagit2_commit_nth_gen_ancestor(Commit_A,0)
		-- Check if we got the same commit or not
		local commit_gen_zero_id = lib.luagit2_commit_id(commit_gen_zero)
		assert.are.equal(Commit_Id_A_string, lib.luagit2_oid_tostr_s(commit_gen_zero_id))

		-- generation one means immediate parent commit
		local commit_gen_one = lib.luagit2_commit_nth_gen_ancestor(Commit_A,1)
		-- Check for values
		local commit_gen_one_id = lib.luagit2_commit_id(commit_gen_one)
		assert.are.equal(Commit_Id_B_string, lib.luagit2_oid_tostr_s(commit_gen_one_id))
		lib.luagit2_commit_free(commit_gen_zero)
		lib.luagit2_commit_free(commit_gen_one)
	end)

	it("Tests Commit Parent",function()
		-- Since parent Commit for commit A is Commit B
		-- the values should match accordingly
		-- the param value of 0 means we want 
		-- just immediate before value of commit.
		local parent_commit_one = lib.luagit2_commit_parent(Commit_A,0)

		local parent_commit_id = lib.luagit2_commit_id(parent_commit_one)
		assert.are.equal(Commit_Id_B_string, lib.luagit2_oid_tostr_s(parent_commit_id))
		lib.luagit2_commit_free(parent_commit_one)
	end)

	it("Tests commit Parent ID",function()
		-- Since parent Commit for commit A is Commit B
		-- the values should match accordingly
		-- the param value of 0 means we want 
		-- just immediate before value of commit.
		local parent_commit_id = lib.luagit2_commit_parent_id(Commit_A,0)
		assert.are.equal(Commit_Id_B_string, lib.luagit2_oid_tostr_s(parent_commit_id))
	end)

	it("Tests parent count",function()
		-- Since the commit A has been create using
		-- only one parent commit, We should get 1 as
		-- its parent count 
		local parent_count = lib.luagit2_commit_parentcount(Commit_A)
		assert.are.equal(1,parent_count)
	end)

	it("Tests Raw Commit Header",function()
		local Header = "tree 1b49a09ae5e707b8ed48e6048aa1901138838944\n"..
						"parent 36060c58702ed4c2a40832c51758d5344201d89a\n" ..
						"author test_user <test@example.com> 1530366649 +0530\n" .. 
						"committer test_user <test@example.com> 1530366649 +0530\n"
		local Header_A = lib.luagit2_commit_raw_header(Commit_A)
		assert.are.equal(Header,Header_A)
	end)

	it("Tests Commit Summary", function()
		local Commit_A_summary = lib.luagit2_commit_summary(Commit_A)
		assert.are.equal("Added File",Commit_A_summary)
	end)

	it("Tests Commit Tree", function()
		local Commit_A_tree = lib.luagit2_commit_tree(Commit_A)
		local tree_id = lib.luagit2_tree_id(Commit_A_tree)

		assert.are.equal(current_write_tree_id, lib.luagit2_oid_tostr_s(tree_id))
		lib.luagit2_tree_free(Commit_A_tree)
	end)

	it("Tests Commit Tree Id",function()
		-- Please refer libgit2's original documentation for this
		local tree_id = lib.luagit2_tree_id(Commit_A)
		assert.are.equal(Commit_Id_A_string, lib.luagit2_oid_tostr_s(tree_id))
	end)

	it("Tests Creating a Commmit and update head ",function ()
		-- Get parent from most recent commit
		local parent_tree_id = lib.luagit2_oid_fromstr("1b49a09ae5e707b8ed48e6048aa1901138838944")
		local parent_tree = lib.luagit2_tree_lookup(repo,parent_tree_id)

		-- Create a new Commit and get commit Id
		local new_commit_id =  lib.luagit2_commit_create_update_head(repo,Author_Sign_A,
			Commmitter_Sign_A,"New Commit From luagit2",parent_tree,Commit_A)

		print("\n New Commit Id : " .. lib.luagit2_oid_tostr_s(new_commit_id) .. "\n")

		local new_commit_string = lib.luagit2_oid_tostr_s(new_commit_id)
		
		-- Try to lookup that Id in repo
		-- A test of whether the commit was actually created or not
		local new_commit = lib.luagit2_commit_lookup(repo,new_commit_id)
		-- Check the lookedup Commit is the one that we created
		local lookedup_commit_id = lib.luagit2_commit_id(new_commit)

		assert.are.equal(new_commit_string,lib.luagit2_oid_tostr_s(lookedup_commit_id))

	end)

	it("Tests Creating a Commmit and update none ",function ()
		-- Get parent from most recent commit
		local parent_tree_id = lib.luagit2_oid_fromstr("1b49a09ae5e707b8ed48e6048aa1901138838944")
		local parent_tree = lib.luagit2_tree_lookup(repo,parent_tree_id)

		-- Create a new Commit and get commit Id
		local new_commit_id =  lib.luagit2_commit_create_update_none(repo,Author_Sign_A,
			Commmitter_Sign_A,"New Commit From luagit2",parent_tree,Commit_A)

		print("\n New Commit Id : " .. lib.luagit2_oid_tostr_s(new_commit_id) .. "\n")

		local new_commit_string = lib.luagit2_oid_tostr_s(new_commit_id)
		
		-- Try to lookup that Id in repo
		-- A test of whether the commit was actually created or not
		local new_commit = lib.luagit2_commit_lookup(repo,new_commit_id)
		-- Check the lookedup Commit is the one that we created
		local lookedup_commit_id = lib.luagit2_commit_id(new_commit)

		assert.are.equal(new_commit_string,lib.luagit2_oid_tostr_s(lookedup_commit_id))

	end)

	pending(" Tests extract commit signature ", function()
		local sign_buf = lib.luagit2_commit_extract_signature(repo,Commit_Id_A)
		print(lib.luagit2_buf_details(sign_buf))
	end)

	pending("Tests commit time",function()
	end)

end)
