-- Luagit2's Describe Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Describe Methods Tests ", function()
    local luagit2 = require("luagit2")
    local luagit2_describe = require("describe.describe_cover")
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
    
    --[[ output of gitdescribe on a commit in Fixtures/new_test_repo.
 
        git describe 108ddee361877aa5c044d89d8dd232b8fd0f8992
        v1.0-2-g108ddee
    
    ]]--
    
    it("tests describe commit", function()
        local commit_id_str = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
        local commit_id = luagit2.oid_fromstr(commit_id_str)
        local otype_commit = luagit2.object_string2type("commit")
        obj_commit = luagit2.object_lookup(repo, commit_id, otype_commit)
        
        local describe_result = luagit2_describe.describe_commit(obj_commit)
        local buf_output = luagit2_describe.describe_format(describe_result)
        local commit_describe = luagit2.buf_details(buf_output)
        assert.are.equal("v1.0-2-g108ddee", commit_describe)
        luagit2_describe.describe_result_free(describe_result)
    end)
    
    --[[output of `git describe` on Fixtures/new_test_repo
 
        git describe 
        v1.0-2-g108ddee
    
    ]]--

    it("tests describe workdir", function()
        local describe_result = luagit2_describe.describe_workdir(repo)
        local buf_output = luagit2_describe.describe_format(describe_result)
        local wkdir_describe = luagit2.buf_details(buf_output)
        assert.are.equal("v1.0-2-g108ddee", wkdir_describe)
        luagit2_describe.describe_result_free(describe_result)
    end)  
end)
