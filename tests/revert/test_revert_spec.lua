-- Luagit2's Revert Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Revert Methods Tests ", function()
    local luagit2 = require("luagit2")
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
    
    it("tests git revert", function()
        local commit_id_string = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
        commit_id = luagit2.oid_fromstr(commit_id_string)
        commit = luagit2.commit_lookup(repo, commit_id)
        
        assert.has_no_errors(function () luagit2.revert(repo, commit) end)
        
    end)
    
end)
