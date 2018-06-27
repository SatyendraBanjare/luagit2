-- Tests For luagit2's Libgit Module Functions.

describe("Libgit2 core methods Test", function()

  local lib
  local MWINDOW_SIZE = 1234
  local MWINDOW_MAPPED_LIMIT = 1234
  local Object_Cache_Limit = 1234
  local Cache_Max_Size = 2048
  local Allowed_Cache_memory , Current_Cache_Memory
  local Template_path = "./Example/Template/path/"
  local Windows_Share_Mode = 99999
  local Enable = 1
  local Disable = 0
  local User_Agent = "Example_User_Agent"
  local SSL_Cipher = "Example_SSL_Cipher"
  local Search_Paths = {}
        Search_Paths.System_lvl = "./System_level/Search_Path/"
        Search_Paths.Global_lvl = "./Global_level/Search_Path/"
        Search_Paths.XDG_lvl = "./XDG_level/Search_Path/"
        Search_Paths.Program_data_lvl = "./Program_data_level/Search_Path/"
  local Alternate_Path = "./Some/Different/Path/"

  setup(function()
    lib = require("luagit2")
    lib.luagit2_init()
  end)

  teardown(function()
    lib.luagit2_shutdown()
  end)

  before_each(function()
    lib.luagit2_SET_MWINDOW_SIZE(MWINDOW_SIZE)
    lib.luagit2_SET_MWINDOW_MAPPED_LIMIT(MWINDOW_MAPPED_LIMIT)
    lib.luagit2_SET_SEARCH_PATH(1,Search_Paths.System_lvl)
    lib.luagit2_SET_SEARCH_PATH(2,Search_Paths.Global_lvl)
    lib.luagit2_SET_SEARCH_PATH(3,Search_Paths.XDG_lvl)
    lib.luagit2_SET_SEARCH_PATH(4,Search_Paths.Program_data_lvl)
    lib.luagit2_SET_CACHE_MAX_SIZE(Cache_Max_Size)
    lib.luagit2_SET_TEMPLATE_PATH(Template_path)
    lib.luagit2_SET_WINDOWS_SHAREMODE(Windows_Share_Mode)
  end)

  it("Prints used libgit2 version",function ()
    local version_data = lib.luagit2_version()
    assert.are.same("userdata",type(version_data))
    assert.are.same("libgit2_version_data",lib.get_userdata_name(version_data))
    print(" \n   Major Version Number is : " .. lib.luagit2_print_version_data(version_data,1))
    print("   Minor Version Number is : " .. lib.luagit2_print_version_data(version_data, 2))
    print("   Revision Version Number is : " .. lib.luagit2_print_version_data(version_data, 3) .. "\n")

  end)

  it("Tests setting and getting MWINDOW_SIZE ", function ()
    -- Tests luagit2_GET_MWINDOW_SIZE()
    local old_val_MWINDOW_SIZE  = lib.luagit2_GET_MWINDOW_SIZE()
    assert.is.equal(MWINDOW_SIZE,old_val_MWINDOW_SIZE)

    -- Tests luagit2_SET_MWINDOW_SIZE()
    lib.luagit2_SET_MWINDOW_SIZE(4321)
    local new_val_MWINDOW_SIZE = lib.luagit2_GET_MWINDOW_SIZE()
    assert.is.equal(4321,new_val_MWINDOW_SIZE)

  end)

  it("Tests setting and getting MWINDOW_MAPPED_LIMIT ", function ()
    -- Tests luagit2_GET_MWINDOW_MAPPED_LIMIT()
    local old_val_MWINDOW_MAPPED_LIMIT  = lib.luagit2_GET_MWINDOW_MAPPED_LIMIT()
    assert.is.equal(MWINDOW_MAPPED_LIMIT,old_val_MWINDOW_MAPPED_LIMIT)

    -- Tests luagit2_SET_MWINDOW_MAPPED_LIMIT()
    lib.luagit2_SET_MWINDOW_MAPPED_LIMIT(4321)
    local new_val_MWINDOW_MAPPED_LIMIT = lib.luagit2_GET_MWINDOW_MAPPED_LIMIT()
    assert.is.equal(4321,new_val_MWINDOW_MAPPED_LIMIT)

  end)

  it("Tests Setting and Getting Various Search Paths", function()
    -- Tests luagit2_GET_SEARCH_PATH
    -- for different options
    assert.are.equal(Search_Paths.System_lvl,lib.luagit2_GET_SEARCH_PATH(1))
    assert.are.equal(Search_Paths.Global_lvl,lib.luagit2_GET_SEARCH_PATH(2))
    assert.are.equal(Search_Paths.XDG_lvl,lib.luagit2_GET_SEARCH_PATH(3))
    assert.are.equal(Search_Paths.Program_data_lvl,lib.luagit2_GET_SEARCH_PATH(4))

    -- reset the search paths
    lib.luagit2_SET_SEARCH_PATH(1,Alternate_Path)
    lib.luagit2_SET_SEARCH_PATH(2,Alternate_Path)
    lib.luagit2_SET_SEARCH_PATH(3,Alternate_Path)
    lib.luagit2_SET_SEARCH_PATH(4,Alternate_Path)

    -- recheck for new paths
    -- Tests luagit2_SET_SEARCH_PATH()
    assert.are.equal(Alternate_Path,lib.luagit2_GET_SEARCH_PATH(1))
    assert.are.equal(Alternate_Path,lib.luagit2_GET_SEARCH_PATH(2))
    assert.are.equal(Alternate_Path,lib.luagit2_GET_SEARCH_PATH(3))
    assert.are.equal(Alternate_Path,lib.luagit2_GET_SEARCH_PATH(4))

  end)

  it("Tests Setting and Getting Max Cache Size", function()

    -- Check if Max Cache Size value is set correctly.
    Current_Cache_Memory = lib.luagit2_GET_CACHED_MEMORY(1)
    Allowed_Cache_memory = lib.luagit2_GET_CACHED_MEMORY(2)
    assert.is.equal(Cache_Max_Size, Allowed_Cache_memory)

    -- Since We dont know current Cache memory size,
    -- We simply assert that it is an integer value
    -- and is LESS THAN or EQUAL to Max Allowed Value
    assert.is_number(Current_Cache_Memory)
    assert(Current_Cache_Memory <= Allowed_Cache_memory)

    -- Reset the Max Cache memory Size
    -- And check again
    local Max_Size = 4096
    lib.luagit2_SET_CACHE_MAX_SIZE(Max_Size)
    assert.is.equal(Max_Size,lib.luagit2_GET_CACHED_MEMORY(2))

  end)

  it("Tests Setting and Getting Template Path", function()
    -- Tests luagit2_GET_TEMPLATE_PATH()
    assert.is.equal(Template_path , lib.luagit2_GET_TEMPLATE_PATH())

    -- Reset template path value and recheck
    lib.luagit2_SET_TEMPLATE_PATH(Alternate_Path)
    assert.is.equal(Alternate_Path,lib.luagit2_GET_TEMPLATE_PATH())
  end)

  it("Checks if Windows Share Mode is set", function()
    -- Currently the test is run on Non windows system
    -- So this share mode value may vary
    -- Lets Simply Assert that it is a number
    assert.is_number(lib.luagit2_GET_WINDOWS_SHAREMODE())
  end)

  it("Checks Enable and Disable for various options", function()
    -- We simply call the enable functions.
    -- If there will be any error, The program
    -- will shutdown itself.

     -- Enable Various possible options
    lib.luagit2_ENABLE_CACHING(Enable)
    lib.luagit2_ENABLE_STRICT_OBJECT_CREATION(Enable)
    lib.luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION(Enable)
    lib.luagit2_ENABLE_OFS_DELTA(Enable)
    lib.luagit2_ENABLE_FSYNC_GITDIR(Enable)
    lib.luagit2_ENABLE_STRICT_HASH_VERIFICATION(Enable)

    -- Disable various possible options
    lib.luagit2_ENABLE_CACHING(Disable)
    lib.luagit2_ENABLE_STRICT_OBJECT_CREATION(Disable)
    lib.luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION(Disable)
    lib.luagit2_ENABLE_OFS_DELTA(Disable)
    lib.luagit2_ENABLE_FSYNC_GITDIR(Disable)
    lib.luagit2_ENABLE_STRICT_HASH_VERIFICATION(Disable)

  end)

  it("Tests setting SSL_Cipher and User_Agent ", function()
    -- We simply call the setting functions.
    -- If there will be any error, The program
    -- will shutdown itself

    lib.luagit2_SET_USER_AGENT(User_Agent)
    lib.luagit2_SET_SSL_CIPHERS(SSL_Cipher)
  end)

  it("Tests Setting Object's Cache Limit ", function()
    -- We call the functions with possible
    -- git object types. If there will be any
    -- error the program will shut down itself.
    local type_commit_obj = lib.luagit2_object_string2type("commit")
    local type_tree_obj = lib.luagit2_object_string2type("tree")
    local type_blob_obj = lib.luagit2_object_string2type("blob")
    local type_tag_obj = lib.luagit2_object_string2type("tag")
    local type_OFS_DELTA = lib.luagit2_object_string2type("OFS_DELTA")
    local type_REF_DELTA = lib.luagit2_object_string2type("REF_DELTA")

    lib.luagit2_SET_CACHE_OBJECT_LIMIT(type_commit_obj,Object_Cache_Limit)
    lib.luagit2_SET_CACHE_OBJECT_LIMIT(type_tree_obj,Object_Cache_Limit)
    lib.luagit2_SET_CACHE_OBJECT_LIMIT(type_blob_obj,Object_Cache_Limit)
    lib.luagit2_SET_CACHE_OBJECT_LIMIT(type_tag_obj,Object_Cache_Limit)
    lib.luagit2_SET_CACHE_OBJECT_LIMIT(type_OFS_DELTA,Object_Cache_Limit)
    lib.luagit2_SET_CACHE_OBJECT_LIMIT(type_REF_DELTA,Object_Cache_Limit)
  end)

end)
