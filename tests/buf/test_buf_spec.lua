-- Luagit2's Buf Module Tests

describe(" Buf Module Tests ", function()
	local lib = require("luagit2")

	setup(function()
		lib.luagit2_init()
	end)

	teardown(function()
		lib.luagit2_shutdown()
	end)

	it("test Buf Setting and Getting a string value",function()
		-- Set A string value to create a buf
		local buffer = lib.luagit2_buf_set_str("Hello")
		local abc = lib.luagit2_buf_details(buffer)
	end)
	--
	--
	-- Thing to note here is that
	-- When you buf details method is called
	-- The git_buf object Buf's (Buf.ptr) is cleared to NULL
	-- Hence For now, It causes error on using buf_free
	-- This Also means You cannot cal luagit2_buf_details()
	-- Again and Again on same luagit2_buffer Object
	--
	--
	it("Tests Buf Free Method",function()
		local buffer = lib.luagit2_buf_set_str("Hello")
		lib.luagit2_buf_free(buffer)
	end)

end)
