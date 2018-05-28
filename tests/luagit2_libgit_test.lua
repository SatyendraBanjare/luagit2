pcall(require, "luacov")
lib = require"luagit2"
print("successfully imported library luagit2")
local lunatest = require "lunatest"
local assert_true, assert_false = lunatest.assert_true, lunatest.assert_false
local assert_diffvars = lunatest.assert_diffvars
local assert_boolean, assert_not_boolean = lunatest.assert_boolean, lunatest.assert_not_boolean
local assert_len, assert_not_len = lunatest.assert_len, lunatest.assert_not_len
local assert_match, assert_not_match = lunatest.assert_match, lunatest.assert_not_match
local assert_error = lunatest.assert_error
local assert_lt, assert_lte = lunatest.assert_lt, lunatest.assert_lte
local assert_gt, assert_gte = lunatest.assert_gt, lunatest.assert_gte
local assert_nil, assert_not_nil = lunatest.assert_nil, lunatest.assert_not_nil
local assert_equal, assert_not_equal = lunatest.assert_equal, lunatest.assert_not_equal
local assert_string, assert_not_string = lunatest.assert_string, lunatest.assert_not_string
local assert_metatable, assert_not_metatable = lunatest.assert_metatable, lunatest.assert_not_metatable
local assert_userdata, assert_not_userdata = lunatest.assert_userdata, lunatest.assert_not_userdata
local assert_thread, assert_not_thread = lunatest.assert_thread, lunatest.assert_not_thread
local assert_function, assert_not_function = lunatest.assert_function, lunatest.assert_not_function
local assert_table, assert_not_table = lunatest.assert_table, lunatest.assert_not_table
local assert_number, assert_not_number = lunatest.assert_number, lunatest.assert_not_number
local skip, fail = lunatest.skip, lunatest.fail

lib.luagit2_init()

print("\n -------- Starting luagit2_libgit Tests --------\n")

function test_luagit2_version()	
	version_data = lib.luagit2_version()
	assert_userdata(version_data)
	print(" \nMajor Version Number is : " .. lib.luagit2_print_version_data(version_data, 1))

	print("Minor Version Number is : " .. lib.luagit2_print_version_data(version_data, 2))

	print("Revision Version Number is : " .. lib.luagit2_print_version_data(version_data, 3))

end

function test_luagit2_GIT_OPT_GET_and_SET_MWINDOW_SIZE()	
	lib.luagit2_SET_MWINDOW_SIZE(123)
	new_val = lib.luagit2_GET_MWINDOW_SIZE()

	assert_equal(new_val,123)
end

function test_luagit2_GIT_OPT_GET_and_SET_MWINDOW_MAPPED_LIMIT()	
	lib.luagit2_SET_MWINDOW_MAPPED_LIMIT(123)
	new_val = lib.luagit2_GET_MWINDOW_MAPPED_LIMIT()

	assert_equal(new_val,123)
end

function test_luagit2_GIT_OPT_GET_and_SET_SEARCH_PATH()	
	-- for GIT_CONFIG_LEVEL_SYSTEM ---- passing 1st parameter as 1
	lib.luagit2_SET_SEARCH_PATH(1,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(1)
	assert_equal(new_val,"./example_path/")

	-- for GIT_CONFIG_LEVEL_GLOBAL ---- passing 1st parameter as 2
	lib.luagit2_SET_SEARCH_PATH(2,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(2)
	assert_equal(new_val,"./example_path/")	

	-- for GIT_CONFIG_LEVEL_XDG ---- passing 1st parameter as 3
	lib.luagit2_SET_SEARCH_PATH(3,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(3)
	assert_equal(new_val,"./example_path/")

	-- for GIT_CONFIG_LEVEL_PROGRAMDATA ---- passing 1st parameter as 4
	lib.luagit2_SET_SEARCH_PATH(4,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(4)
	assert_equal(new_val,"./example_path/")
end

function test_luagit2_GIT_OPT_SET_CACHE_OBJECT_LIMIT()	
	assert_true(lib.luagit2_SET_CACHE_OBJECT_LIMIT(123))
end

function test_luagit2_SET_CACHE_MAX_SIZE()	
	assert_true(lib.luagit2_SET_CACHE_MAX_SIZE(123))
end

function test_luagit2_ENABLE_CACHING()	
	assert_true(lib.luagit2_ENABLE_CACHING(1))
end

function test_luagit2_GET_and_SET_TEMPLATE_PATH()	
	lib.luagit2_SET_TEMPLATE_PATH("./example_template_path/")
	new_template_path = lib.luagit2_GET_TEMPLATE_PATH()
	assert_equal(new_template_path,"./example_template_path/")
end

function test_luagit2_SET_USER_AGENT()	
	assert_true(lib.luagit2_SET_USER_AGENT("MY_USER_AGENT"))
end

function test_luagit2_SET_WINDOWS_SHAREMODE()	
	assert_true(lib.luagit2_SET_WINDOWS_SHAREMODE(99999))
end

function test_luagit2_ENABLE_STRICT_OBJECT_CREATION()	
	assert_true(lib.luagit2_ENABLE_STRICT_OBJECT_CREATION(1))
end

function test_luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION()	
	assert_true(lib.luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION(1))
end

function test_luagit2_SET_SSL_CIPHERS()	
	assert_true(lib.luagit2_SET_SSL_CIPHERS("Example_SSL_Cipher"))
end

function test_luagit2_ENABLE_OFS_DELTA()	
	assert_true(lib.luagit2_ENABLE_OFS_DELTA(1))
end

function test_luagit2_ENABLE_FSYNC_GITDIR()	
	assert_true(lib.luagit2_ENABLE_FSYNC_GITDIR(1))
end

function test_luagit2_ENABLE_STRICT_HASH_VERIFICATION()	
	assert_true(lib.luagit2_ENABLE_STRICT_HASH_VERIFICATION(1))
end

lunatest.run()
