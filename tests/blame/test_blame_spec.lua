-- Luagit2's Blame Module Tests

local fixer = require("Fixtures.fix_repo")
local lfs = require("lfs")

describe(" Blame Methods Tests ", function()
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
    
    it("Tests getting blame data for a file ",function()

        local blame_file = luagit2.blame_file(repo,"abc.txt")

        -- Get the hunk count for this blame.
        local hunk_count = luagit2.blame_get_hunk_count(blame_file)

        -- Get the hunk by index
        local hunk_byindex = luagit2.blame_get_hunk_byindex(blame_file,0)
        
        -- Get signature details for this hunk.
        local sign = luagit2.blame_hunk_signature(hunk_byindex)

        local name, email = luagit2.get_signature_details(sign)
        
        assert.are.equal("test_user",name)
        assert.are.equal("test@example.com",email)

        -- Get hunk from line number
        local hunk_byline = luagit2.blame_get_hunk_byline(blame_file,1)

        local sign_byline = luagit2.blame_hunk_signature(hunk_byline)

        local _name, _email = luagit2.get_signature_details(sign_byline)
        
        assert.are.equal("test_user",_name)
        assert.are.equal("test@example.com",_email)

        luagit2.blame_free(blame_file)
    end)
    
end)
