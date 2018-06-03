-- @module luagit2_signature_test
local luagit2_signature_tests = {}

function luagit2_signature_tests.test_luagit2_signature_default()
	Sig_default = lib.luagit2_signature_default("./Simple-Repository/")
	lunatest.assert_not_nil(Sig_default)
	lunatest.assert_userdata(Sig_default)
end

function luagit2_signature_tests.test_luagit2_signature_dup()

	Sig_source = lib.luagit2_signature_default("./Simple-Repository/")
	Sig_duplicate = lib.luagit2_signature_dup(Sig_source)
	lunatest.assert_not_nil(Sig_source)
	lunatest.assert_not_nil(Sig_duplicate)
	lunatest.assert_userdata(Sig_source)
	lunatest.assert_userdata(Sig_duplicate)
end
-- pass 1 as 2nd parameter if you want the name and 2 is you want the email address from signature object.
-- Used lib.luagit2_print_complete_signature_details to directly print string from c.
function luagit2_signature_tests.test_luagit2_signature_from_buffer()
	Sig_from_buf = lib.luagit2_signature_from_buffer("Test User <test@test.tt> 1461698487 +0200")
	lunatest.assert_not_nil(Sig_from_buf)
	lunatest.assert_userdata(Sig_from_buf)
	lunatest.assert_equal("Test User" , lib.luagit2_get_signature_details(Sig_from_buf,1))
	lunatest.assert_equal("test@test.tt" , lib.luagit2_get_signature_details(Sig_from_buf,2))
	print("\n Complete details of Signature from buffer are : \n")
	lunatest.assert_true(lib.luagit2_print_complete_signature_details(Sig_from_buf))
	print("\n")
end

function luagit2_signature_tests.test_luagit2_signature_now()
	Sig_now = lib.luagit2_signature_now("Test User", "test@test.tt")
	lunatest.assert_not_nil(Sig_now)
	lunatest.assert_userdata(Sig_now)
	lunatest.assert_equal("Test User" , lib.luagit2_get_signature_details(Sig_now,1))
	lunatest.assert_equal("test@test.tt" , lib.luagit2_get_signature_details(Sig_now,2))
	print("\n Complete details of Signature from Now are : \n")
	lunatest.assert_true(lib.luagit2_print_complete_signature_details(Sig_now))
	print("\n")
end

return luagit2_signature_tests