-- @module luagit2_cred_test
local luagit2_cred_tests = {}

function luagit2_cred_tests.test_luagit2_cred_default_new()
	default_cred = lib.luagit2_cred_default_new()
	lunatest.assert_not_nil(default_cred)
end

function luagit2_cred_tests.test_luagit2_cred_ssh_key_from_agent()
	cred_from_agent = lib.luagit2_cred_ssh_key_from_agent("Test_User")
	lunatest.assert_not_nil(cred_from_agent)
end


function luagit2_cred_tests.test_luagit2_cred_ssh_key_memory_new()
	cred_ssh_key_memory = lib.luagit2_cred_ssh_key_memory_new("Test_User","20AAB1F98B65F79FC05124309B891903EAC6545C31EACEF17CA5693597E9531E"
		,"B7E2F6E4E95B2967ADB1C8175899E03E5DB554ABFC5E49C13E250F6597CA926E","Test_Password")
	lunatest.assert_not_nil(cred_ssh_key_memory)
end

function luagit2_cred_tests.test_luagit2_cred_ssh_key_new()
	cred_ssh_key = lib.luagit2_cred_ssh_key_new("Test_User","20AAB1F98B65F79FC05124309B891903EAC6545C31EACEF17CA5693597E9531E"
		,"B7E2F6E4E95B2967ADB1C8175899E03E5DB554ABFC5E49C13E250F6597CA926E","Test_Password")
	lunatest.assert_not_nil(cred_ssh_key)
end

function luagit2_cred_tests.test_luagit2_cred_username_new()
	cred_username = lib.luagit2_cred_username_new("Test_User","20AAB1F98B65F79FC05124309B891903EAC6545C31EACEF17CA5693597E9531E"
		,"B7E2F6E4E95B2967ADB1C8175899E03E5DB554ABFC5E49C13E250F6597CA926E","Test_Password")
	lunatest.assert_not_nil(cred_username)
end

function luagit2_cred_tests.test_luagit2_cred_userpass_plaintext_new()
	cred_userpass = lib.luagit2_cred_userpass_plaintext_new("Test_User","Test_Password")
	lunatest.assert_not_nil(cred_userpass)
end

return luagit2_cred_tests
