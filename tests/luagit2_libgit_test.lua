pcall(require, "luacov")
lib = require"luagit2"
print("\n successfully imported library luagit2 \n")
lunatest = require "lunatest"

lib.luagit2_init()

print("\n Starting luagit2_libgit Tests \n")

function test_luagit2_version()	
	version_data = lib.luagit2_version()
	lunatest.assert_userdata(version_data)
	print(" \n		Major Version Number is : " .. lib.luagit2_print_version_data(version_data, 1))

	print("		Minor Version Number is : " .. lib.luagit2_print_version_data(version_data, 2))

	print("		Revision Version Number is : " .. lib.luagit2_print_version_data(version_data, 3) .. "\n")

end

function test_luagit2_GIT_OPT_GET_and_SET_MWINDOW_SIZE()	
	lib.luagit2_SET_MWINDOW_SIZE(123)
	new_val = lib.luagit2_GET_MWINDOW_SIZE()

	lunatest.assert_equal(new_val,123)
end

function test_luagit2_GIT_OPT_GET_and_SET_MWINDOW_MAPPED_LIMIT()	
	lib.luagit2_SET_MWINDOW_MAPPED_LIMIT(123)
	new_val = lib.luagit2_GET_MWINDOW_MAPPED_LIMIT()

	lunatest.assert_equal(new_val,123)
end

function test_luagit2_GIT_OPT_GET_and_SET_SEARCH_PATH()	
	-- for GIT_CONFIG_LEVEL_SYSTEM ---- passing 1st parameter as 1
	lib.luagit2_SET_SEARCH_PATH(1,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(1)
	lunatest.assert_equal(new_val,"./example_path/")

	-- for GIT_CONFIG_LEVEL_GLOBAL ---- passing 1st parameter as 2
	lib.luagit2_SET_SEARCH_PATH(2,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(2)
	lunatest.assert_equal(new_val,"./example_path/")	

	-- for GIT_CONFIG_LEVEL_XDG ---- passing 1st parameter as 3
	lib.luagit2_SET_SEARCH_PATH(3,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(3)
	lunatest.assert_equal(new_val,"./example_path/")

	-- for GIT_CONFIG_LEVEL_PROGRAMDATA ---- passing 1st parameter as 4
	lib.luagit2_SET_SEARCH_PATH(4,"./example_path/")
	new_val = lib.luagit2_GET_SEARCH_PATH(4)
	lunatest.assert_equal(new_val,"./example_path/")
end

function test_luagit2_GIT_OPT_SET_CACHE_OBJECT_LIMIT()	
	lunatest.assert_true(lib.luagit2_SET_CACHE_OBJECT_LIMIT(123))
end

function test_luagit2_SET_CACHE_MAX_SIZE()	
	lunatest.assert_true(lib.luagit2_SET_CACHE_MAX_SIZE(123))
end

function test_luagit2_ENABLE_CACHING()	
	lunatest.assert_true(lib.luagit2_ENABLE_CACHING(1))
end

function test_luagit2_GET_and_SET_TEMPLATE_PATH()	
	lib.luagit2_SET_TEMPLATE_PATH("./example_template_path/")
	new_template_path = lib.luagit2_GET_TEMPLATE_PATH()
	lunatest.assert_equal(new_template_path,"./example_template_path/")
end

function test_luagit2_SET_USER_AGENT()	
	lunatest.assert_true(lib.luagit2_SET_USER_AGENT("MY_USER_AGENT"))
end

function test_luagit2_SET_WINDOWS_SHAREMODE()	
	lunatest.assert_true(lib.luagit2_SET_WINDOWS_SHAREMODE(99999))
end

function test_luagit2_ENABLE_STRICT_OBJECT_CREATION()	
	lunatest.assert_true(lib.luagit2_ENABLE_STRICT_OBJECT_CREATION(1))
end

function test_luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION()	
	lunatest.assert_true(lib.luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION(1))
end

function test_luagit2_SET_SSL_CIPHERS()	
	lunatest.assert_true(lib.luagit2_SET_SSL_CIPHERS("Example_SSL_Cipher"))
end

function test_luagit2_ENABLE_OFS_DELTA()	
	lunatest.assert_true(lib.luagit2_ENABLE_OFS_DELTA(1))
end

function test_luagit2_ENABLE_FSYNC_GITDIR()	
	lunatest.assert_true(lib.luagit2_ENABLE_FSYNC_GITDIR(1))
end

function test_luagit2_ENABLE_STRICT_HASH_VERIFICATION()	
	lunatest.assert_true(lib.luagit2_ENABLE_STRICT_HASH_VERIFICATION(1))
end

lunatest.run()
