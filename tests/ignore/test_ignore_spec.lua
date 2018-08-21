-- Luagit2's Ignore Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Ignore Methods Tests ", function()
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

    it("Tests adding ignore rules",function()
    	-- First clear all internal ignore rules to the repo.
    	luagit2.ignore_clear_internal_rules(repo)

    	-- Check if a file is ignored or not
    	local is_ignored_prev = luagit2.ignore_path_is_ignored(repo,"abc.txt")
    	assert.is_false(is_ignored_prev)

    	-- Now add a rule to make the file ignored.
    	luagit2.ignore_add_rule(repo, "*.txt")

    	-- Check again if the file is ignored.
    	local is_ignored_later = luagit2.ignore_path_is_ignored(repo,"abc.txt")
    	assert.is_true(is_ignored_later)
    end)
end)