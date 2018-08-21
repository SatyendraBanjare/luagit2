-- Luagit2's Graph Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Graph Methods Tests ", function()
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

    it("Tests git graph ahead-behind",function()
    	-- Lets Pick two commmits differing by one commit in between.
    	local commit_id_str_ahead = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
		local commit_id_str_behind = "5b5b025afb0b4c913b4c338a42934a3863bf3644"

		local commit_id_ahead = luagit2.oid_fromstr(commit_id_str_ahead)
		local commit_id_behind = luagit2.oid_fromstr(commit_id_str_behind)

		local ahead_by , behind_by = luagit2.graph_ahead_behind(repo,commit_id_ahead,commit_id_behind)
		
		-- The newer commit is ahead of old commit by 2.
		-- thus these values should match.
		assert.are.same(2,ahead_by)
		assert.are.same(0,behind_by)
    end)

    it("Tests git graph is_decendent ",function()
    	-- Lets Pick two commmits differing by one commit in between.
    	-- therefore one commit is true ancestor of other.
    	local commit_id_str = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
		local commit_id_str_ancestor = "5b5b025afb0b4c913b4c338a42934a3863bf3644"

		local commit_id = luagit2.oid_fromstr(commit_id_str)
		local commit_id_ancestor = luagit2.oid_fromstr(commit_id_str_ancestor)

		local is_decendent = luagit2.graph_descendant_of(repo,commit_id,commit_id_ancestor)
		-- Check
		assert.is_true(is_decendent)
    end)
end)
