-- Tests For luagit2's Libgit Module Functions.

describe("Libgit2 core methods Test", function()
    
    local luagit2 = require("luagit2")
    local mwindow_size = 1234
    local mwindow_mapped_limit = 1234
    local cache_max_size = 2048
    local template_path = "./Example/Template/path/"
    local windows_share_mode = 99999
    local enable = 1
    local disable = 0
    local search_paths = {
        system_lvl = "./System_level/Search_Path/",
        global_lvl = "./Global_level/Search_Path/",
        xdg_lvl = "./XDG_level/Search_Path/",
        program_data_lvl = "./Program_data_level/Search_Path/",
    }
    local alternate_path = "./Some/Different/Path/"
    
    setup(function()
        -- initialize libgit2's global state and threading
        luagit2.init()
        
        -- setup different variables
        luagit2.set_mwindow_size(mwindow_size)
        luagit2.set_mwindow_mapped_limit(mwindow_mapped_limit)
        luagit2.set_search_path("system", search_paths.system_lvl)
        luagit2.set_search_path("global", search_paths.global_lvl)
        luagit2.set_search_path("xdg", search_paths.xdg_lvl)
        luagit2.set_search_path("programdata", search_paths.program_data_lvl)
        luagit2.set_cache_max_size(cache_max_size)
        luagit2.set_template_path(template_path)
        luagit2.set_windows_sharemode(windows_share_mode)
    end)
    
    teardown(function()
        -- close threading and global state.
        luagit2.shutdown()
    end)
    
    it("Prints used libgit2 version", function ()
        local major, minor, rev = luagit2.libgit2_version()
        print("Used libgit2 version is : " .. major .. "." .. minor .. "." .. rev)
    end)
    
    it("Tests setting and getting mwindow_size ", function ()
        -- Tests luagit2's get_mwindow_size()
        local old_val_mwindow_size = luagit2.get_mwindow_size()
        assert.is.equal(mwindow_size, old_val_mwindow_size)
        
        -- tests luagit2's set_mwindow_size()
        luagit2.set_mwindow_size(4321)
        local new_val_mwindow_size = luagit2.get_mwindow_size()
        assert.is.equal(4321, new_val_mwindow_size)
        
    end)
    
    it("Tests setting and getting mwindow_mapped_limit ", function ()
        -- Tests luagit2's get_mwindow_mapped_limit()
        local old_val_mwindow_mapped_limit = luagit2.get_mwindow_mapped_limit()
        assert.is.equal(mwindow_mapped_limit, old_val_mwindow_mapped_limit)
        
        -- Tests luagit2's set_mwindow_mapped_limit()
        luagit2.set_mwindow_mapped_limit(4321)
        local new_val_mwindow_mapped_limit = luagit2.get_mwindow_mapped_limit()
        assert.is.equal(4321, new_val_mwindow_mapped_limit)
        
    end)
    
    it("Tests Setting and Getting Various Search Paths", function()
        -- tests luagit2's get_search_path
        -- for different options
        assert.are.equal(search_paths.system_lvl, luagit2.get_search_path("system"))
        assert.are.equal(search_paths.global_lvl, luagit2.get_search_path("global"))
        assert.are.equal(search_paths.xdg_lvl, luagit2.get_search_path("xdg"))
        assert.are.equal(search_paths.program_data_lvl, luagit2.get_search_path("programdata"))
        
        -- reset the search paths
        luagit2.set_search_path("system", alternate_path)
        luagit2.set_search_path("global", alternate_path)
        luagit2.set_search_path("xdg", alternate_path)
        luagit2.set_search_path("programdata", alternate_path)
        
        -- recheck for new paths
        -- tests luagit2_set_search_path()
        assert.are.equal(alternate_path, luagit2.get_search_path("system"))
        assert.are.equal(alternate_path, luagit2.get_search_path("global"))
        assert.are.equal(alternate_path, luagit2.get_search_path("xdg"))
        assert.are.equal(alternate_path, luagit2.get_search_path("programdata"))
        
    end)
    
    it("Tests Setting and Getting Max Cache Size", function()
        
        -- check if max cache size value is set correctly.
        local current_cache_memory, allowed_cache_memory = luagit2.get_cached_memory()
        assert.is.equal(cache_max_size, allowed_cache_memory)
        
        -- since we don't know current cache memory size,
        -- we simply assert that it is an integer value
        -- and is less than or equal to max allowed value
        assert.is_number(current_cache_memory)
        assert(current_cache_memory <= allowed_cache_memory)
        
        -- reset the max cache memory size
        -- and check again
        local max_size = 4096
        luagit2.set_cache_max_size(max_size)
        local _, new_allowed_cache_memory = luagit2.get_cached_memory()
        assert.is.equal(max_size, new_allowed_cache_memory)
    end)
    
    it("Tests Setting and Getting Template Path", function()
        -- tests luagit2_get_template_path()
        assert.is.equal(template_path, luagit2.get_template_path())
        
        -- reset template path value and recheck
        luagit2.set_template_path(alternate_path)
        assert.is.equal(alternate_path, luagit2.get_template_path())
    end)
    
    it("Checks if Windows Share Mode is set", function()
        -- Currently the test is run on Non windows system
        -- So this share mode value may vary
        -- Lets Simply Assert that it is a number
        assert.is_number(luagit2.get_windows_sharemode())
    end)
    
    it("Checks Enable and Disable for various options", function()
        -- we simply call the enable functions.
        -- if there will be any error, the program
        -- will shutdown itself.
        
        -- enable various possible options
        luagit2.enable_caching(enable)
        luagit2.enable_strict_object_creation(enable)
        luagit2.enable_strict_symbolic_ref_creation(enable)
        luagit2.enable_ofs_delta(enable)
        luagit2.enable_fsync_gitdir(enable)
        luagit2.enable_strict_hash_verification(enable)
        
        -- disable various possible options
        luagit2.enable_caching(disable)
        luagit2.enable_strict_object_creation(disable)
        luagit2.enable_strict_symbolic_ref_creation(disable)
        luagit2.enable_ofs_delta(disable)
        luagit2.enable_fsync_gitdir(disable)
        luagit2.enable_strict_hash_verification(disable)
    end)
    
    it("Tests setting SSL_Cipher and User_Agent ", function()
        -- we simply call the setting functions.
        -- if there will be any error, the program
        -- will shutdown itself
        local user_agent = "Example_User_Agent"
        local ssl_cipher = "Example_SSL_Cipher"
        
        luagit2.set_user_agent(user_agent)
        luagit2.set_ssl_ciphers(ssl_cipher)
    end)
    
    it("Tests Setting Object's Cache Limit ", function()
        -- we call the functions with possible
        -- git object types. if there will be any
        -- error the program will shut down itself.
        local object_cache_limit = 1234
        
        local type_commit_obj = luagit2.object_string2type("commit")
        local type_tree_obj = luagit2.object_string2type("tree")
        local type_blob_obj = luagit2.object_string2type("blob")
        local type_tag_obj = luagit2.object_string2type("tag")
        
        luagit2.set_cache_object_limit(type_commit_obj, object_cache_limit)
        luagit2.set_cache_object_limit(type_tree_obj, object_cache_limit)
        luagit2.set_cache_object_limit(type_blob_obj, object_cache_limit)
        luagit2.set_cache_object_limit(type_tag_obj, object_cache_limit)
    end)
    
end)
