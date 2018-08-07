-- Luagit2's Status Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Status Methods Tests ", function()
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
    
    it("Tests status list",function()
        -- Get a list of status entries
        -- for the repo.
        --
        -- This is the initial status list
        -- for the current repo index.
        local status_list_old = luagit2.status_list_new(repo)

        -- Get the entry count for the list.
        local entry_count_old = luagit2.status_list_entrycount(status_list_old)
        
        -- Initially this count should be zero
        -- Since there is nothing added or modified to 
        -- Repo's current Index.

        assert.are.equal(0,entry_count_old)

        -- Free the used list
        luagit2.status_list_free(status_list_old)     
    end)

    it("Tests status list for changed repo index",function()
        -- Now make some changes to current active index
        --
        -- Let's add a new file, and change contents 
        -- of an existing file. So we should have two
        -- entries in status list.
        --
        -- We will check accordingly.
        --
        -- make changes :
        os.execute('cd Fixtures/WORKON_REPO && echo "___something_new___" > abc.txt')
        os.execute('cd Fixtures/WORKON_REPO && touch NewFile.txt ')

        local repo_index = luagit2.repository_index(repo)

        luagit2.index_add_bypath(repo_index,"NewFile.txt")

        -- Get a list of status entries
        -- for the repo.
        local status_list = luagit2.status_list_new(repo)

        -- Get the entry count for the list.
        local entry_count = luagit2.status_list_entrycount(status_list)
        
        -- There should be two entries.
        assert.are.equal(2,entry_count)


        -- Get the entry status for the lists
        local entry_one = luagit2.status_byindex(status_list,0)
        local entry_two = luagit2.status_byindex(status_list,1)

        local entry_one_status = luagit2.status_type(entry_one)
        assert.are.equal("STATUS_WT_MODIFIED",entry_one_status)

        local entry_two_status = luagit2.status_type(entry_two)
        assert.are.equal("STATUS_INDEX_NEW",entry_two_status)

        -- Get the paths for file changed
        -- 
        -- 
        -- NOTE (IMPORTANT)
        -- The file paths for status entries can be found 
        -- only if they are changed in the worktree as well.
        --
        -- Since the index changes DO NOT produce changes in Worktree
        -- too, therefore if we try to get file paths for
        -- entry two, it gices error.
        --
        --
        -- Get file paths for entry one.
        local path_one_old, path_one_new = luagit2.status_file_paths(entry_one)
        
        assert.are.equal("abc.txt",path_one_new)
        assert.are.equal("abc.txt",path_one_old)

        -- Free the used list
        luagit2.status_list_free(status_list)  
    end)
    
end)
