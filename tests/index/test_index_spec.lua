-- Tests for lugit2's Index module functions

local fixer = require("Fixtures.fix_repo")
local lfs = require("lfs")

describe(" Index Methods Tests ", function()
    local luagit2 = require("luagit2")
    local luagit2_index = require("index.index_cover")
    local repo
    local repo_index
    local current_directory_path = lfs.currentdir()

    setup(function()
        luagit2.init()
    end)

    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
        repo_index = luagit2.repository_index(repo)
    end)

    after_each(function()
        luagit2_index.index_free(repo_index)
        luagit2.repository_free(repo)
        fixer.set_back()
    end)

    teardown(function()
        luagit2.shutdown()
    end)

    it("Tests Index path", function()
        local path = luagit2_index.index_path(repo_index)
        assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/index", path)
    end)

    it("Tests index entrycount", function()
        local entrycount = luagit2_index.index_entrycount(repo_index)
        assert(entrycount >= 0)
    end)

    it("Tests open index using the path", function()
        local index_open_by_path = luagit2_index.index_open("/Fixtures/WORKON_REPO/.git/index")
        luagit2_index.index_free(index_open_by_path)
    end)

    it("Tests index version methods", function()
        local index_version = luagit2_index.index_version(repo_index)
        assert.is.number(index_version)

        luagit2_index.index_set_version(repo_index, 4)

        local index_version_new = luagit2_index.index_version(repo_index)
        assert.are.equal(4, index_version_new)
    end)

    it("Tests git index find", function()
        -- Given a file's path name from the top directory
        -- of git repository, The index positions are set alphabetically.
        --
        -- Since in repository new_test_repo , abc.txt is in the top
        -- level directory as well as alphabetically, its index position must be 0
        local index_entry_position = luagit2_index.index_find(repo_index, "abc.txt")
        assert.are.equal(0, index_entry_position)

        -- Similarily Lets check for another file `new.txt`
        -- its index position must be 1.
        local index_entry_position_2 = luagit2_index.index_find(repo_index, "new.txt")
        assert.are.equal(1, index_entry_position_2)

        --alternatively we can also check by the path value
        -- with original path relative to toplevel

        local index_entry = luagit2_index.index_get_byindex(repo_index, index_entry_position)
        local entry_path = luagit2_index.index_entry_get_path(index_entry)
        assert.are.equal("abc.txt", entry_path)

        local index_entry_2 = luagit2_index.index_get_byindex(repo_index, index_entry_position_2)
        local entry_path_2 = luagit2_index.index_entry_get_path(index_entry_2)
        assert.are.equal("new.txt", entry_path_2)
    end)

    it("Tests index checksum", function()
        -- Calculates checksum for the index
        local index_oid = luagit2_index.index_checksum(repo_index)
        local index_oid_str = luagit2.oid_tostr_s(index_oid)
        assert.is_string(index_oid_str)
    end)

    it("Tests index caps related methods", function()
        local index_caps = luagit2_index.index_caps(repo_index)
        assert.are.equal(1, index_caps)

        -- set the caps value and check again
        luagit2_index.index_set_caps(repo_index, 0)
        local index_caps_new = luagit2_index.index_caps(repo_index)
        assert.are.equal(0, index_caps_new)
    end)

    it("Tests index add related methods", function()
        -- Create a new file and add it to repo's
        -- index
        --
        os.execute('cd Fixtures/WORKON_REPO/ && echo "Hello" > something.txt')
        -- Added a new file at the root directory level
        --
        -- Add to index
        luagit2_index.index_add_bypath(repo_index, "something.txt")

        -- Next lets try to find the recently added file in repo.
        local index_entry_position = luagit2_index.index_find(repo_index, "something.txt")

        -- Check for the path of added file.
        local index_entry = luagit2_index.index_get_byindex(repo_index, index_entry_position)
        local entry_path = luagit2_index.index_entry_get_path(index_entry)
        assert.are.equal("something.txt", entry_path)
    end)

    it("Tests Conflict related functions", function()
        -- Check if currently the index has conflicts or not
        -- It should not have any conflicts as we have not crearted
        -- any merge-conflict.
        local has_conflicts = luagit2_index.index_has_conflicts(repo_index)
        assert.are.equal(false, has_conflicts)

        pending("Create a merge conflict and test index conflict add cleanup", function()
            -- TO DO
        end)
    end)

    it("Tests Removing files and directory from index", function()
        -- Lets remove a file
        luagit2_index.index_remove_bypath(repo_index, "new.txt")

        -- Try to get the file from index
        local index_val = luagit2_index.index_find(repo_index, "new.txt")

        local index_entry = luagit2_index.index_get_byindex(repo_index, index_val)

        -- The output of error NULL_ERROR shows that internally
        -- the index_entry has been set to NULL
        -- or the index entry does not have deleted entry as
        -- Expected
        assert.has_error(function() luagit2_index.index_entry_get_path(index_entry) end)

        -- Lets try removing a directory from index
        -- The files in that directory can therefore be not
        -- called upon.
        --
        -- setting required variables
        index_val = luagit2_index.index_find(repo_index, "subdir/new.txt")
        index_entry = luagit2_index.index_get_byindex(repo_index, index_val)
        local stage_val = luagit2_index.index_entry_stage(index_entry)

        -- Remove the directory
        luagit2_index.index_remove_directory(repo_index, "subdir", stage_val)

        -- Try to get the file from index
        index_val = luagit2_index.index_find(repo_index, "subdir/new.txt")

        index_entry = luagit2_index.index_get_byindex(repo_index, index_val)

        -- The output of error NULL_ERROR shows that internally
        -- the index_entry has been set to NULL
        -- or the index entry does not have deleted entry as
        -- Expected
        assert.has_error(function() luagit2_index.index_entry_get_path(index_entry) end)
    end)

    it("Tests index write", function()
        luagit2_index.index_write(repo_index)
    end)

    it("Tests index write tree", function()
        -- get the tree oid for the used index
        local oid = luagit2_index.index_write_tree(repo_index)

        -- lookup for the tree in repo
        -- if this works successfully, it means
        -- tree truly exists in the repo.
        local tree = luagit2.tree_lookup(repo, oid)
        luagit2.tree_free(tree)
    end)

    it("Tests index write tree to repo", function()
        -- get the tree oid for the used index
        local oid = luagit2_index.index_write_tree_to(repo_index, repo)

        -- lookup for the tree in repo
        -- if this works successfully, it means
        -- tree truly exists in the repo.
        local tree = luagit2.tree_lookup(repo, oid)
        luagit2.tree_free(tree)
    end)
end)
