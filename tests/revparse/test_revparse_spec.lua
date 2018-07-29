-- Luagit2's Revparse Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Revparse Methods Tests ", function()
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
    
    it("tests revparse", function()
        -- Get the complete revparse for given revision
        -- string.
        local revparse_complete = luagit2.revparse(repo, "origin/master..HEAD")
        local from_obj = luagit2.revspec_from(revparse_complete)
        local to_obj = luagit2.revspec_from(revparse_complete)
        
        -- get the from string obj_id.
        local from_obj_id = luagit2.object_id(from_obj)
        local from_obj_id_str = luagit2.oid_tostr_s(from_obj_id)
        assert.is_string(from_obj_id_str)
        
        -- get the to string obj_id.
        local to_obj_id = luagit2.object_id(to_obj)
        local to_obj_id_str = luagit2.oid_tostr_s(to_obj_id)
        assert.is_string(to_obj_id_str)
    end)
    
    it("tests revparse single", function()
        -- Get the revparse for given revision string.
        local revparse_single = luagit2.revparse_single(repo, "origin/master")
        
        -- get the from string obj_id.
        local from_obj_id = luagit2.object_id(revparse_single)
        local from_obj_id_str = luagit2.oid_tostr_s(from_obj_id)
        assert.is_string(from_obj_id_str)
        
        -- get the to string obj_id.
        local to_obj_id = luagit2.object_id(revparse_single)
        local to_obj_id_str = luagit2.oid_tostr_s(to_obj_id)
        assert.is_string(to_obj_id_str)
    end)
end)
