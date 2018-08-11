-- Tests for lugit2's Commit module functions

local fixer = require("Fixtures.fix_repo")

describe(" Commit Methods Tests ", function()
	local luagit2 = require("luagit2")
	local luagit2_commit = require("commit.commit_cover")
	local repo
	local commit_id_a_string = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
	local commit_id_b_string = "36060c58702ed4c2a40832c51758d5344201d89a"
	local commit_id_a, commit_id_b
	local commit_a , commit_b
	local author_sign_a, author_sign_b , committer_sign_a , committer_sign_b
	local current_write_tree_id = "1b49a09ae5e707b8ed48e6048aa1901138838944"

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
		commit_id_a = luagit2.oid_fromstr(commit_id_a_string)
		commit_id_b = luagit2.oid_fromstr(commit_id_b_string)
		commit_a = luagit2_commit.commit_lookup(repo,commit_id_a)
		commit_b = luagit2_commit.commit_lookup(repo,commit_id_b)
		author_sign_a = luagit2_commit.commit_author(commit_a)
		author_sign_b = luagit2_commit.commit_author(commit_b)
		committer_sign_a = luagit2_commit.commit_committer(commit_a)
		committer_sign_b = luagit2_commit.commit_committer(commit_b)
	end)

	after_each(function()
		luagit2_commit.commit_free(commit_a)
		luagit2_commit.commit_free(commit_b)
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
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
		assert.are.equal("luagit2_oid",luagit2.get_userdata_name(commit_id_a))
		assert.are.equal("luagit2_oid",luagit2.get_userdata_name(commit_id_b))

		assert.are.equal("luagit2_commit",luagit2.get_userdata_name(commit_a))
		assert.are.equal("luagit2_commit",luagit2.get_userdata_name(commit_b))

		assert.are.equal("luagit2_signature",luagit2.get_userdata_name(author_sign_a))
		assert.are.equal("luagit2_signature",luagit2.get_userdata_name(author_sign_b))

		assert.are.equal("luagit2_signature",luagit2.get_userdata_name(committer_sign_a))
		assert.are.equal("luagit2_signature",luagit2.get_userdata_name(committer_sign_b))
	end)

	it("Tests Commit Author",function()
		local name_a, email_a = luagit2.get_signature_details(author_sign_a)

		assert.are.equal("test_user",name_a)
		assert.are.equal("test@example.com",email_a)

		local name_b, email_b = luagit2.get_signature_details(author_sign_b)

		assert.are.equal("Scott Chacon",name_b)
		assert.are.equal("schacon@gmail.com",email_b)
	end)

	it("Tests Commit Commmitter",function()
		local name_a, email_a = luagit2.get_signature_details(committer_sign_a)

		assert.are.equal("test_user",name_a)
		assert.are.equal("test@example.com",email_a)

		local name_b, email_b = luagit2.get_signature_details(committer_sign_b)

		assert.are.equal("Scott Chacon",name_b)
		assert.are.equal("schacon@gmail.com",email_b)
	end)

	it("Tests commit Body",function()
		assert.are.equal("Commit message body",luagit2_commit.commit_body(commit_a))
		assert.is_nil(luagit2_commit.commit_body(commit_b))
	end)

	it("Tests extract commit Header Field ", function()
		-- Parent for commit_a is commit_b
		-- So the commit id of commit_b 
		-- Should be received
		local parent_buf = luagit2_commit.commit_header_field(commit_a,"parent")
		assert.are.equal(commit_id_b_string, luagit2.buf_details(parent_buf))

		-- We should get the current write-tree id
		local tree_buf = luagit2_commit.commit_header_field(commit_a,"tree")
		assert.are.equal(current_write_tree_id, luagit2.buf_details(tree_buf))
	end)

	it("Tests commit lookup using prefix", function()
		-- Create a simple commit object
		local Commit_test = luagit2_commit.commit_lookup(repo,commit_id_a)

		-- If this commit is valid , it should
		-- be same as commit_a. Lets check for
		-- its id.

		local Commit_test_id = luagit2_commit.commit_id(Commit_test)
		assert.are.equal(commit_id_a_string, luagit2.oid_tostr_s(Commit_test_id))
		luagit2_commit.commit_free(Commit_test)
	end)

	it("Tests commit Message",function()
		local message = luagit2_commit.commit_message(commit_b)
		assert.are.same("subdirectories\n",message)
	end)
	
	it("Tests commit Message encoding ",function()
		-- Currently the messages are not encoded at all
		-- we therefore receive a nil
		local message_encoding = luagit2_commit.commit_message_encoding(commit_a)
		assert.are.same(nil,message)
	end)

	it("Tests Commit Message Raw", function()
		local message_raw = luagit2_commit.commit_message(commit_b)
		assert.are.same("subdirectories\n",message_raw)
	end)

	it("Tests Commit Nth generation parent",function()
		-- Zero generation ancestor means the commit itself
		local commit_gen_zero = luagit2_commit.commit_nth_gen_ancestor(commit_a,0)
		-- Check if we got the same commit or not
		local commit_gen_zero_id = luagit2_commit.commit_id(commit_gen_zero)
		assert.are.equal(commit_id_a_string, luagit2.oid_tostr_s(commit_gen_zero_id))

		-- generation one means immediate parent commit
		local commit_gen_one = luagit2_commit.commit_nth_gen_ancestor(commit_a,1)
		-- Check for values
		local commit_gen_one_id = luagit2_commit.commit_id(commit_gen_one)
		assert.are.equal(commit_id_b_string, luagit2.oid_tostr_s(commit_gen_one_id))
		luagit2_commit.commit_free(commit_gen_zero)
		luagit2_commit.commit_free(commit_gen_one)
	end)

	it("Tests Commit Parent",function()
		-- Since parent Commit for commit A is Commit B
		-- the values should match accordingly
		-- the param value of 0 means we want 
		-- just immediate before value of commit.
		local parent_commit_one = luagit2_commit.commit_parent(commit_a,0)

		local parent_commit_id = luagit2_commit.commit_id(parent_commit_one)
		assert.are.equal(commit_id_b_string, luagit2.oid_tostr_s(parent_commit_id))
		luagit2_commit.commit_free(parent_commit_one)
	end)

	it("Tests commit Parent ID",function()
		-- Since parent Commit for commit A is Commit B
		-- the values should match accordingly
		-- the param value of 0 means we want 
		-- just immediate before value of commit.
		local parent_commit_id = luagit2_commit.commit_parent_id(commit_a,0)
		assert.are.equal(commit_id_b_string, luagit2.oid_tostr_s(parent_commit_id))
	end)

	it("Tests parent count",function()
		-- Since the commit A has been create using
		-- only one parent commit, We should get 1 as
		-- its parent count 
		local parent_count = luagit2_commit.commit_parentcount(commit_a)
		assert.are.equal(1,parent_count)
	end)

	it("Tests Raw Commit Header",function()
		local Header = "tree 1b49a09ae5e707b8ed48e6048aa1901138838944\n"..
						"parent 36060c58702ed4c2a40832c51758d5344201d89a\n" ..
						"author test_user <test@example.com> 1530366649 +0530\n" .. 
						"committer test_user <test@example.com> 1530366649 +0530\n"
		local Header_A = luagit2_commit.commit_raw_header(commit_a)
		assert.are.equal(Header,Header_A)
	end)

	it("Tests Commit Summary", function()
		local commit_a_summary = luagit2_commit.commit_summary(commit_a)
		assert.are.equal("Added File",commit_a_summary)
	end)

	it("Tests Commit Tree", function()
		local commit_a_tree = luagit2_commit.commit_tree(commit_a)
		local tree_id = luagit2.tree_id(commit_a_tree)

		assert.are.equal(current_write_tree_id, luagit2.oid_tostr_s(tree_id))
		luagit2.tree_free(commit_a_tree)
	end)

	it("Tests Commit Tree Id",function()
		-- Please refer luagit2.it2's original documentation for this
		local tree_id = luagit2_commit.commit_tree_id(commit_a)
		assert.are.equal(current_write_tree_id, luagit2.oid_tostr_s(tree_id))
	end)

	it("Tests Creating a Commmit and update head ",function ()
		-- Get parent from most recent commit
		local parent_tree_id = luagit2.oid_fromstr("1b49a09ae5e707b8ed48e6048aa1901138838944")
		local parent_tree = luagit2.tree_lookup(repo,parent_tree_id)

		-- Create a new Commit and get commit Id
		local new_commit_id =  luagit2_commit.commit_create_update_head(repo,author_sign_a,
			committer_sign_a,"New Commit From luagit2",parent_tree,commit_a)

		local new_commit_string = luagit2.oid_tostr_s(new_commit_id)
		
		-- Try to lookup that Id in repo
		-- A test of whether the commit was actually created or not
		local new_commit = luagit2_commit.commit_lookup(repo,new_commit_id)
		-- Check the lookedup Commit is the one that we created
		local lookedup_commit_id = luagit2_commit.commit_id(new_commit)

		assert.are.equal(new_commit_string,luagit2.oid_tostr_s(lookedup_commit_id))

	end)

	it("Tests Creating a Commmit and update none ",function ()
		-- Get parent from most recent commit
		local parent_tree_id = luagit2.oid_fromstr("1b49a09ae5e707b8ed48e6048aa1901138838944")
		local parent_tree = luagit2.tree_lookup(repo,parent_tree_id)

		-- Create a new Commit and get commit Id
		local new_commit_id =  luagit2_commit.commit_create_update_none(repo,author_sign_a,
			committer_sign_a,"New Commit From luagit2",parent_tree,commit_a)

		local new_commit_string = luagit2.oid_tostr_s(new_commit_id)
		
		-- Try to lookup that Id in repo
		-- A test of whether the commit was actually created or not
		local new_commit = luagit2_commit.commit_lookup(repo,new_commit_id)
		-- Check the lookedup Commit is the one that we created
		local lookedup_commit_id = luagit2_commit.commit_id(new_commit)

		assert.are.equal(new_commit_string,luagit2.oid_tostr_s(lookedup_commit_id))

	end)

	it(" Tests create a signed commit and extract commit signature ", function()

		local gpgsig = "-----BEGIN PGP SIGNATURE-----\n\
		Version: GnuPG v1.4.12 (Darwin)\n\
		\n\
		iQIcBAABAgAGBQJQ+FMIAAoJEH+LfPdZDSs1e3EQAJMjhqjWF+WkGLHju7pTw2al\n\
		o6IoMAhv0Z/LHlWhzBd9e7JeCnanRt12bAU7yvYp9+Z+z+dbwqLwDoFp8LVuigl8\n\
		JGLcnwiUW3rSvhjdCp9irdb4+bhKUnKUzSdsR2CK4/hC0N2i/HOvMYX+BRsvqweq\n\
		AsAkA6dAWh+gAfedrBUkCTGhlNYoetjdakWqlGL1TiKAefEZrtA1TpPkGn92vbLq\n\
		SphFRUY9hVn1ZBWrT3hEpvAIcZag3rTOiRVT1X1flj8B2vGCEr3RrcwOIZikpdaW\n\
		who/X3xh/DGbI2RbuxmmJpxxP/8dsVchRJJzBwG+yhwU/iN3MlV2c5D69tls/Dok\n\
		6VbyU4lm/ae0y3yR83D9dUlkycOnmmlBAHKIZ9qUts9X7mWJf0+yy2QxJVpjaTGG\n\
		cmnQKKPeNIhGJk2ENnnnzjEve7L7YJQF6itbx5VCOcsGh3Ocb3YR7DMdWjt7f8pu\n\
		c6j+q1rP7EpE2afUN/geSlp5i3x8aXZPDj67jImbVCE/Q1X9voCtyzGJH7MXR0N9\n\
		ZpRF8yzveRfMH8bwAJjSOGAFF5XkcR/RNY95o+J+QcgBLdX48h+ZdNmUf6jqlu3J\n\
		7KmTXXQcOVpN6dD3CmRFsbjq+x6RHwa8u1iGn+oIkX908r97ckfB/kHKH7ZdXIJc\n\
		cpxtDQQMGYFpXK/71stq\n\
		=ozeK\n\
		-----END PGP SIGNATURE-----";

		local data =  "tree 1b49a09ae5e707b8ed48e6048aa1901138838944\n\
		parent 108ddee361877aa5c044d89d8dd232b8fd0f8992\n\
		author Test_user <test@example.com> 1358451456 -0800\n\
		committer Test_user <test@example.com> 1358451456 -0800\n\
		\n\
		a simple commit which works\n";

		local new_commit_id = luagit2_commit.commit_create_with_signature(repo,data,gpgsig)
		local sign_buf, extra_buf = luagit2_commit.commit_extract_signature(repo,new_commit_id)

		assert.are.equal(gpgsig,luagit2.buf_details(sign_buf))
	end)

	it("Tests commit time",function()
		local time_str = luagit2_commit.commit_time(commit_a)
		assert.is_not_nil(time_str)
		assert.is_string(time_str)
	end)

end)
