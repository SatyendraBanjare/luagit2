-- Luagit2's Diff Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Diff Methods Tests ", function()
    local luagit2 = require("luagit2")
    local repo_path = "Fixtures/WORKON_REPO"
    local diff_options, repo_index

    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open(repo_path)
        
        -- Create changes in two files that are already
        -- in the current index.
        local file = io.open( "Fixtures/WORKON_REPO/abc.txt", "w")
        file:write("Creating some changes to test diff functions\n")
        file:close()
        
        local file_2 = io.open( "Fixtures/WORKON_REPO/new.txt", "w")
        file_2:write("Creating some changes to test diff functions\n")
        file_2:close()

        repo_index = luagit2.repository_index(repo)
        diff_options = luagit2.diff_init_options()
    end)
    
    after_each(function()
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)

    it("Tests diff index to workdir ",function()
        local diff_idx_wkdir = luagit2.diff_index_to_workdir(repo,repo_index,diff_options)
        
        -- Check for the number of diff deltas.
        assert.is_same(2,luagit2.diff_num_deltas(diff_idx_wkdir))
    end)

    it("checks for different diff format type outputs ",function()
        local diff_idx_wkdir = luagit2.diff_index_to_workdir(repo,repo_index,diff_options)

        local diff_format_options_raw = luagit2.diff_format_init("raw")
        local diff_format_options_patch = luagit2.diff_format_init("patch")
        local diff_format_options_patch_header = luagit2.diff_format_init("patch_header")
        local diff_format_options_name_only = luagit2.diff_format_init("name_only")
        local diff_format_options_name_status = luagit2.diff_format_init("name_status")

        -- get complete diff details. thus passing raw to it.
        local diff_idx_wkdir_buf_raw = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options_raw)
        local diff_data_raw = luagit2.buf_details(diff_idx_wkdir_buf_raw)

        local diff_idx_wkdir_buf_patch = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options_patch)
        local diff_data_patch = luagit2.buf_details(diff_idx_wkdir_buf_patch)

        local diff_idx_wkdir_buf_patch_header = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options_patch_header)
        local diff_data_patch_header = luagit2.buf_details(diff_idx_wkdir_buf_patch_header)

        local diff_idx_wkdir_buf_name_only = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options_name_only)
        local diff_data_name_only = luagit2.buf_details(diff_idx_wkdir_buf_name_only)

        local diff_idx_wkdir_buf_name_status = luagit2.diff_to_buf(diff_idx_wkdir,diff_format_options_name_status)
        local diff_data_name_status = luagit2.buf_details(diff_idx_wkdir_buf_name_status)

        print("diff Raw : \n\n" .. diff_data_raw .. "\n\n")
        print("diff patch: \n\n" .. diff_data_patch .. "\n\n")
        print("diff patch header: \n\n" .. diff_data_patch_header .. "\n\n")
        print("diff name only : \n\n" .. diff_data_name_only .. "\n\n")
        print("diff name status : \n\n" .. diff_data_name_status .. "\n\n")
    end)

    it("Tests diff stats related functions",function()
        local diff_idx_wkdir = luagit2.diff_index_to_workdir(repo,repo_index,diff_options)
        local diff_stats = luagit2.diff_get_stats(diff_idx_wkdir)
        local deletions = luagit2.diff_stats_deletions(diff_stats)
        local insertions = luagit2.diff_stats_insertions(diff_stats)
        local files_changed = luagit2.diff_stats_files_changed(diff_stats)

        assert.are.same(2,deletions)
        assert.are.same(2,insertions)
        assert.are.same(2,files_changed)
    end)

    it("checks for different diff_stats format type outputs",function()
        local diff_idx_wkdir = luagit2.diff_index_to_workdir(repo,repo_index,diff_options)
        local diff_stats = luagit2.diff_get_stats(diff_idx_wkdir)

        local stats_format_full = luagit2.diff_stats_format_init("full")
        local stats_format_short = luagit2.diff_stats_format_init("short")
        local stats_format_number = luagit2.diff_stats_format_init("number")
        -- the format options none & summary are not working properly.
        -- check later

        local stats_full_buf = luagit2.diff_stats_to_buf(diff_stats,stats_format_full,20)
        local data_stats_full = luagit2.buf_details(stats_full_buf)
        
        local stats_short_buf = luagit2.diff_stats_to_buf(diff_stats,stats_format_short,20)
        local data_stats_short = luagit2.buf_details(stats_short_buf)

        local stats_number_buf = luagit2.diff_stats_to_buf(diff_stats,stats_format_number,20)
        local data_stats_number = luagit2.buf_details(stats_number_buf)

        print("diff stats full: \n\n" .. data_stats_full .. "\n\n")
        print("diff stats short: \n\n" .. data_stats_short .. "\n\n")
        print("diff patch number: \n\n" .. data_stats_number .. "\n\n")
    end)

    it("tests diff index to tree",function()
        local tree_oid_string = "619f9935957e010c419cb9d15621916ddfcc0b96"
        local tree_oid = luagit2.oid_fromstr(tree_oid_string)
        local tree = luagit2.tree_lookup(repo, tree_oid)
        local diff_idx_tree = luagit2.diff_tree_to_index(repo,tree,repo_index,diff_options)

        local diff_stats = luagit2.diff_get_stats(diff_idx_tree)
        local files_changed = luagit2.diff_stats_files_changed(diff_stats)
        
        -- The tree here is Fixtures/new_test_repo/subdir
        -- to that there are total 7 file changes taking place.
        -- thus we should get 7 files changed.
        assert.is_same(7,files_changed)
    end)

    it("tests diff_tree_to_workdir_with_index ",function()
        local tree_oid_string = "619f9935957e010c419cb9d15621916ddfcc0b96"
        local tree_oid = luagit2.oid_fromstr(tree_oid_string)
        local tree = luagit2.tree_lookup(repo, tree_oid)
        local diff_tree_wkdir_with_index = luagit2.diff_tree_to_workdir_with_index(repo,tree,diff_options)

        local diff_stats = luagit2.diff_get_stats(diff_tree_wkdir_with_index)
        local files_changed = luagit2.diff_stats_files_changed(diff_stats)
        assert.is_number(files_changed)
    end)

    it("tests diff tree to tree",function()
        local tree_oid_string_a = "619f9935957e010c419cb9d15621916ddfcc0b96"
        local tree_oid_string_b = "f60079018b664e4e79329a7ef9559c8d9e0378d1"
        local tree_oid_a = luagit2.oid_fromstr(tree_oid_string_a)
        local tree_a = luagit2.tree_lookup(repo, tree_oid_a)
        local tree_oid_b = luagit2.oid_fromstr(tree_oid_string_b)
        local tree_b = luagit2.tree_lookup(repo, tree_oid_b)

        local diff_tree_tree = luagit2.diff_tree_to_tree(repo,tree_a,tree_b,diff_options)

        local diff_stats = luagit2.diff_get_stats(diff_tree_tree)
        local files_changed = luagit2.diff_stats_files_changed(diff_stats)
        assert.is_number(files_changed)
    end)
end)