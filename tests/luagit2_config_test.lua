-- @module luagit2_config_test
local luagit2_config_tests = {}

function luagit2_config_tests.test_luagit2_config_find_global()
	cfg_global = lib.luagit2_config_find_global()
	lunatest.assert_not_nil(cfg_global)
	lunatest.assert_userdata(cfg_global)
end

function luagit2_config_tests.test_luagit2_config_find_programdata()
	cfg_programdata = lib.luagit2_config_find_programdata()
	lunatest.assert_not_nil(cfg_programdata)
	lunatest.assert_userdata(cfg_programdata)
end

function luagit2_config_tests.test_luagit2_config_find_system()
	cfg_system = lib.luagit2_config_find_system()
	lunatest.assert_not_nil(cfg_system)
	lunatest.assert_userdata(cfg_system)
end

function luagit2_config_tests.test_luagit2_config_find_xdg()
	cfg_xdg = lib.luagit2_config_find_xdg()
	lunatest.assert_not_nil(cfg_xdg)
	lunatest.assert_userdata(cfg_xdg)
end

function luagit2_config_tests.test_luagit2_config_get_int32()
	cfg_xdg = lib.luagit2_config_find_xdg()
	lunatest.assert_not_nil(cfg_xdg)
	lunatest.assert_userdata(cfg_xdg)
	num = lib.luagit2_config_get_int32(cfg_xdg,"temp")
	lunatest.assert_not_nil(num)
	lunatest.assert_number(num)
end

function luagit2_config_tests.test_luagit2_config_get_int64()
	cfg_xdg = lib.luagit2_config_find_xdg()
	lunatest.assert_not_nil(cfg_xdg)
	lunatest.assert_userdata(cfg_xdg)
	num = lib.luagit2_config_get_int64(cfg_xdg,"temp")
	lunatest.assert_not_nil(num)
	lunatest.assert_number(num)
end

function luagit2_config_tests.test_luagit2_config_get_bool()
	cfg_xdg = lib.luagit2_config_find_xdg()
	lunatest.assert_not_nil(cfg_xdg)
	lunatest.assert_userdata(cfg_xdg)
	num = lib.luagit2_config_get_bool(cfg_xdg,"temp")
	lunatest.assert_not_nil(num)
	lunatest.assert_number(num)
end

function luagit2_config_tests.test_luagit2_config_get_path()
	cfg_xdg = lib.luagit2_config_find_xdg()
	lunatest.assert_not_nil(cfg_xdg)
	lunatest.assert_userdata(cfg_xdg)
	path = lib.luagit2_config_get_path(cfg_xdg,"temp")
	lunatest.assert_not_nil(num)
end

function luagit2_config_tests.test_luagit2_config_get_string_buf()
	cfg_xdg = lib.luagit2_config_find_xdg()
	lunatest.assert_not_nil(cfg_xdg)
	lunatest.assert_userdata(cfg_xdg)
	string_buf = lib.luagit2_config_get_string_buf(cfg_xdg,"temp")
	lunatest.assert_not_nil(string_buf)
end

function luagit2_config_tests.test_luagit2_config_open_default()
	cfg_def = lib.luagit2_config_open_default()
	lunatest.assert_not_nil(cfg_def)
	lunatest.assert_userdata(cfg_def)
end

function luagit2_config_tests.test_luagit2_config_open_ondisk()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
end

function luagit2_config_tests.test_luagit2_config_parse_bool()
	cfg_bool = lib.luagit2_config_parse_bool("true")
	lunatest.assert_not_nil(cfg_bool)
	lunatest.assert_number(cfg_bool)
end

function luagit2_config_tests.test_luagit2_config_parse_int32()
	cfg_parsed_int32 = lib.luagit2_config_parse_int32("test")
	lunatest.assert_not_nil(cfg_parsed_int32)
	lunatest.assert_number(cfg_parsed_int32)
end

function luagit2_config_tests.test_luagit2_config_parse_int64()
	cfg_parsed_int64 = lib.luagit2_config_parse_int64("test")
	lunatest.assert_not_nil(cfg_parsed_int64)
	lunatest.assert_number(cfg_parsed_int64)
end

function luagit2_config_tests.test_luagit2_config_parse_path()
	cfg_parsed_path = lib.luagit2_config_parse_path("path")
	lunatest.assert_not_nil(cfg_parsed_path)
	lunatest.assert_userdata(cfg_parsed_path)
end

function luagit2_config_tests.test_luagit2_config_set_int32()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
	lunatest.assert_true(lib.luagit2_config_set_int32(cfg_ondisk,"example_int_32_value",10))
end

function luagit2_config_tests.test_luagit2_config_set_int64()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
	lunatest.assert_true(lib.luagit2_config_set_int64(cfg_ondisk,"example_int_64_value",10))
end


function luagit2_config_tests.test_luagit2_config_set_string()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
	lunatest.assert_true(lib.luagit2_config_set_string(cfg_ondisk,"example_string_value","test_string"))
end

function luagit2_config_tests.test_luagit2_config_set_multivar()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
	lunatest.assert_true(lib.luagit2_config_set_multivar(cfg_ondisk,"example_multivar_value",
		"^([a-zA-Z0-9_\-\.])","test_string"))
end

function luagit2_config_tests.test_luagit2_config_snapshot()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
	cfg_snap = lib.luagit2_config_snapshot(cfg_ondisk)
	lunatest.assert_not_nil(cfg_snap)
	lunatest.assert_userdata(cfg_snap)
end

function luagit2_config_tests.test_luagit2_config_delete_entry()
	cfg_ondisk = lib.luagit2_config_open_ondisk("./Simple-Repository/config")
	lunatest.assert_not_nil(cfg_ondisk)
	lunatest.assert_userdata(cfg_ondisk)
	lunatest.assert_true(lib.luagit2_config_set_string(cfg_ondisk,"example_string_value","test_string"))
	lib.luagit2_config_delete_entry(cfg_ondisk,"example_string_value")
end
return luagit2_config_tests
