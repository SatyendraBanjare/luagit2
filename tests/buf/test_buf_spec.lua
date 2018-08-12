-- Luagit2's Buf Module Tests

describe(" Buf Module Tests ", function()
	local luagit2 = require("luagit2")

	setup(function()
		luagit2.init()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	it("test Buf Setting and Getting a string value",function()
		-- Set A string value to create a buf
		local buffer = luagit2.buf_set_str("Hello")
		local value = luagit2.buf_details(buffer)
		assert.are.equal("Hello",value)
	end)

	-- luagit2' buf_free method giving errors.
	-- need to lookup this.
end)
