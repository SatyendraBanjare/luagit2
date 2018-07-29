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
		local value = lib.luagit2_buf_details(buffer)
		lib.luagit2_buf_free(buffer)
		assert.are.equal("Hello",value)
	end)
	
	it("Tests Buf Free Method",function()
		local buffer = lib.luagit2_buf_set_str("Hello")
		lib.luagit2_buf_free(buffer)
	end)

end)
