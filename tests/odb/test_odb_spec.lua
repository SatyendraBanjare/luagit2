-- Luagit2's Odb Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Odb Methods Tests ", function()
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

    it("Tests odb and odb objects related functions",function()
        local odb = luagit2.odb_open(repo_path .. "/.git/objects")
       
        local tag_id_str = "0c37a5391bbff43c37f0d0371823a5509eed5b1d"
        local commit_id_str = "108ddee361877aa5c044d89d8dd232b8fd0f8992"

        local tag_id = luagit2.oid_fromstr(tag_id_str)
        local commit_id = luagit2.oid_fromstr(commit_id_str)

        -- Checkif these objects exist
        -- in the Object database. We wil then read them.
        local tag_exists = luagit2.odb_exists(odb,tag_id)
        local commit_exists = luagit2.odb_exists(odb,commit_id)

        assert.is_true(tag_exists)
        assert.is_true(commit_exists)

        -- read objects
        local tag_odb_obj = luagit2.odb_read(odb,tag_id)
        local commit_odb_obj = luagit2.odb_read(odb,commit_id)
        -- get the objects' type
        local type_tag = luagit2.odb_object_type(tag_odb_obj)
        local type_commit = luagit2.odb_object_type(commit_odb_obj)

        local type_tag_name = luagit2.object_type2string(type_tag)
        local type_commit_name = luagit2.object_type2string(type_commit)

        assert.are.same("tag",type_tag_name)
        assert.are.same("commit",type_commit_name)

        -- Check for the Id of returned odb objects
        local odb_tag_id = luagit2.odb_object_id(tag_odb_obj)
        local odb_commit_id = luagit2.odb_object_id(commit_odb_obj)

        -- A return value of zero means both oid are equal.
        assert.are.equal(0,(luagit2.oid_cmp(tag_id, odb_tag_id)))
        assert.are.equal(0,(luagit2.oid_cmp(commit_id, odb_commit_id)))

        -- Check for the object sizes
        local tag_size = luagit2.odb_object_size(tag_odb_obj)
        local commit_size = luagit2.odb_object_size(commit_odb_obj)
        assert.is_number(tag_size)
        assert.is_number(commit_size)

        -- Free used odb and odb objects
        luagit2.odb_object_free(tag_odb_obj)
        luagit2.odb_object_free(commit_odb_obj)
        luagit2.odb_free(odb)
    end)

    it("tests odb write and refresh functions", function()
        local odb = luagit2.odb_open(repo_path .. "/.git/objects")

        -- create a new commit type object.
        local otype_commit = luagit2.object_string2type("commit")
        luagit2.odb_write(odb,"hello world commit",otype_commit)

        -- Check for refreshing the odb.
        assert.has_no_errors(function() luagit2.odb_refresh(odb) end )

        luagit2.odb_free(odb)
    end)

    it("tests odb-hash related funcitons",function()
        local otype_commit = luagit2.object_string2type("commit")
        local hash_from_buf = luagit2.odb_hash("hello world commit",otype_commit)
        -- git the hash string value
        local hash_str = luagit2.oid_tostr_s(hash_from_buf)
        assert.is_string(hash_str)
    end)
end)