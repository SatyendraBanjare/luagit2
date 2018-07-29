-- Luagit2's Tag Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Tag Methods Tests ", function()
    local luagit2 = require("luagit2")
    local repo
    local tag_str = "0c37a5391bbff43c37f0d0371823a5509eed5b1d"
    local tag_oid, tag
    local target_commit_id_str = "5b5b025afb0b4c913b4c338a42934a3863bf3644"
    local current_directory_path = lfs.currentdir()
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
        tag_oid = luagit2.oid_fromstr(tag_str)
        tag = luagit2.tag_lookup(repo, tag_oid)
    end)
    
    after_each(function()
        luagit2.tag_free(tag)
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)

    --[[ Output of ` git show-ref --tags ` on Fixtures/new_test_repo
		 gives this output

		 We have used these values for tests
		
		5b5b025afb0b4c913b4c338a42934a3863bf3644 refs/tags/v0.9  <:========================|
    	0c37a5391bbff43c37f0d0371823a5509eed5b1d refs/tags/v1.0	 <:=================================|
																						   |		|
		------------------------------------------------------------------------------	   |		|
																						   |		|
		Part of Output of ` git show 5b5b025afb0b4c913b4c338a42934a3863bf3644 `	<:=========|		|
																									|
		It shows it is a lightweight commit, Hence it won't show up in odb.							|
		It cannot be therefore looked up. 															|
																									|
		commit 5b5b025afb0b4c913b4c338a42934a3863bf3644												|
		Author: Scott Chacon <schacon@gmail.com>													|
		Date:   Tue May 11 13:38:42 2010 -0700														|
																									|
		    another commit 																			|
																									|
		...																							|
																									|
		-------------------------------------------------------------------------------				|
																									|
		Part of Output of ` git show 0c37a5391bbff43c37f0d0371823a5509eed5b1d ` <:==================|
		
		It shows a annotated Commit.

		tag v1.0
		Tagger: Scott Chacon <schacon@gmail.com>
		Date:   Tue Oct 26 15:33:03 2010 -0200

		test tag message

		commit 5b5b025afb0b4c913b4c338a42934a3863bf3644
		Author: Scott Chacon <schacon@gmail.com>
		Date:   Tue May 11 13:38:42 2010 -0700

		    another commit

		...

		--------------------------------------------------------------------------------------------
	]]--

    it("Tests tag id", function()
        -- Check for the tag id, it should
        -- match one used to create it
        local tag_id = luagit2.tag_id(tag)
        local tag_id_str = luagit2.oid_tostr(tag_id)
        assert.are.equal(tag_str, tag_id_str)
    end)
    
    it("Tests tag message", function()
        -- Checks the tag message value
        local tag_message = luagit2.tag_message(tag)
        assert.are.equal("test tag message\n", tag_message)
    end)
    
    it("Tests tag name", function()
        -- Checks the tag name value
        local tag_name = luagit2.tag_name(tag)
        assert.are.equal("v1.0", tag_name)
    end)
    
    it("Tests Target related functions", function()
        -- Get the target object
        local target_obj = luagit2.tag_target(tag)
        local target_obj_id = luagit2.object_id(target_obj)
        local target_obj_id_str = luagit2.oid_tostr(target_obj_id)
        
        -- Check if the obj_id matches the commit id
        -- it should point at
        assert.are.equal(target_commit_id_str, target_obj_id_str)
        -- Free the used object
        luagit2.object_free(target_obj)
        
        -- Alternatively target's id can be retrieved
        -- using :
        local target_id = luagit2.tag_target_id(tag)
        local test_target_str = luagit2.oid_tostr(target_id)
        assert.are.equal(target_commit_id_str, test_target_str)
        
        -- Check the object type, Must be commit
        local target_obj_type = luagit2.tag_target_type(tag)
        local type_str = luagit2.object_type2string(target_obj_type)
        assert.are.equal("commit", type_str)
    end)
    
    it("Tests the tagger signature", function()
        local tagger = luagit2.tag_tagger(tag)
        local user_name, user_email = luagit2.get_signature_details(tagger)
        assert.are.equal("Scott Chacon", user_name)
        assert.are.equal("schacon@gmail.com", user_email)
    end)
    
    it("Tests tag owner", function()
        -- Get the owner repository
        local owner_repo = luagit2.tag_owner(tag)
        
        -- Get the repo path for that owner repository
        local owner_repo_path = luagit2.repository_path(owner_repo)
        
        -- Check with absolute path
        assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/", owner_repo_path)
    end)
    
    it("Tests Tag create", function()
        -- Lets Create a new Tag for the same target
        -- commit
        --
        -- Build up params to create a new tag
        local commit_oid = luagit2.oid_fromstr(target_commit_id_str)
        local otype_commit = luagit2.object_string2type("commit")
        local target_commit_obj = luagit2.object_lookup(repo, commit_oid, otype_commit)
        local signature = luagit2.signature_now("user_name", "something@example.com")
        local tag_message = "Testing_new_tag_create"
        local tag_name = "new_tag"
        
        -- Create a tag
        local new_tag_id = luagit2.tag_create(repo, tag_name, target_commit_obj, signature, tag_message, 1)
        assert.is_not_nil(new_tag_id)
        -- Lookup for the tag in repo,
        -- this ensures that the tag object
        -- has been successfuly created and stored in odb
        local new_tag = luagit2.tag_lookup(repo, new_tag_id)
        local new_tag_target_id = luagit2.tag_target_id(new_tag)
        -- Check that the target object is same
        assert.are.equal(target_commit_id_str, luagit2.oid_tostr(new_tag_target_id))
        -- Check if tagger is same
        local tagger = luagit2.tag_tagger(new_tag)
        local user_name, user_email = luagit2.get_signature_details(tagger)
        assert.are.equal("user_name", user_name)
        assert.are.equal("something@example.com", user_email)
        
        -- Check if the tag message and name are same
        local new_tag_message = luagit2.tag_message(new_tag)
        assert.are.equal(tag_message, new_tag_message)
        
        local new_tag_name = luagit2.tag_name(new_tag)
        assert.are.equal(tag_name, new_tag_name)
        
        -- Delete the tag from repository
        luagit2.tag_delete(repo, tag_name)
        
        -- Free the used tag objects
        luagit2.tag_free(new_tag)
    end)
    
end)
