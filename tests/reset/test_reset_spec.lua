-- Luagit2's Reset Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Reset Methods Tests ", function()
    local luagit2 = require("luagit2")
    local luagit2_reset = require("reset.reset_cover")
    local repo_path = "Fixtures/WORKON_REPO"
    
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

    it("Test reset for a commit type object",function()
    	local commit_id_str = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
    	local commit_id = luagit2.oid_fromstr(commit_id_str)
    	local otype_commit = luagit2.object_string2type("commit")
    	local obj_commit = luagit2.object_lookup(repo,commit_id,otype_commit)

    	local checkout_init_opts = luagit2.checkout_init_options()

    	assert.has_no_errors(function() luagit2_reset.reset(repo,obj_commit,"soft") end)
    	assert.has_no_errors(function() luagit2_reset.reset(repo,obj_commit,"hard") end)
    	assert.has_no_errors(function() luagit2_reset.reset(repo,obj_commit,"mixed") end)
    end)
end)