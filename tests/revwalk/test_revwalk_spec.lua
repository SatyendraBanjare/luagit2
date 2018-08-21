-- Luagit2's Revwalk Module Tests

local fixer = require("Fixtures.fix_repo")
local lfs = require("lfs")

describe(" Revwalk Methods Tests ", function()
    local luagit2 = require("luagit2")
    local repo_path = "Fixtures/WORKON_REPO"
    local current_directory_path = lfs.currentdir()
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open(repo_path)
    end)
    
    after_each(function()
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)

    it("tests revwalker functions",function()
    	local revwalk = luagit2.revwalk_new(repo)
    	-- now our revwalk is not set.
    	-- lets set it to list the values for our
    	-- repository's HEAD. like the one used in
    	-- git rev-list 
    	--
    	-- using revwalk without setting it will give errors.
    	luagit2.revwalk_push_head(revwalk)
    	
    	local first_revwalk_oid = luagit2.revwalk_next(revwalk)
    	assert.is_string(luagit2.oid_tostr_s(first_revwalk_oid))

    	local second_revwalk_oid = luagit2.revwalk_next(revwalk)
    	assert.is_string(luagit2.oid_tostr_s(second_revwalk_oid))
    	
    	-- Later check the existance of these string
    	-- after odb module is completed.

    	-- free used revwalk
    	luagit2.revwalk_free(revwalk)
    end)
    
    pending("check if oid exists in odb",function() end)

    it("tests push ref",function()
    	local revwalk = luagit2.revwalk_new(repo)
    	-- this will make revwalk list changes, objects in specified reference. 
    	assert.has_no_errors(function() luagit2.revwalk_push_ref(revwalk,"refs/heads/master") end)

    	-- free used revwalk
    	luagit2.revwalk_free(revwalk)
    end)

    it("tests revwalk repository & reseting it",function()
    	local revwalk = luagit2.revwalk_new(repo)
    	-- set the revwalk
    	luagit2.revwalk_push_head(revwalk)

    	-- reset the revwalk
    	luagit2.revwalk_reset(revwalk)

    	-- check for revwalk's repository
    	local owner_repo = luagit2.revwalk_repository(revwalk)

    	-- Get the repo path for that owner repository
		local owner_repo_path = luagit2.repository_path(owner_repo)
		assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/" , owner_repo_path)

		luagit2.revwalk_free(revwalk)
    end)
end)