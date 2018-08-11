-- Cred Module Tests

describe(" Cred Methods Tests ", function()
	local luagit2 = require("luagit2")
	local luagit2_cred = require("cred.cred_cover")

	setup(function()
		luagit2.init()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	it("Tests Cred Username ",function()
		-- Create a git username type cred and test its validity.
		local cred_username_new = luagit2_cred.cred_username_new("UserName")
		local value = luagit2_cred.cred_username_details(cred_username_new)
		assert.are.equal("UserName",value)
		luagit2_cred.cred_free(cred_username_new)
	end)

	it("Tests Cred Userpass_Plaintext ",function()
		-- Create a git userpass type cred and test its validity.
		local cred_userpass_new = luagit2_cred.cred_userpass_plaintext_new("UserName","Password@123")
		local username , password = luagit2_cred.cred_userpass_details(cred_userpass_new)
		assert.are.equal("UserName",username)
		assert.are.equal("Password@123",password)
		luagit2_cred.cred_free(cred_userpass_new)
	end)

	it("Tests Cred SSH_key agent ",function()
		-- Create a git ssh_from_agent type cred and test its validity.
		local cred_ssh_key_agent_new = luagit2_cred.cred_ssh_key_from_agent("AGENT_NAME")
		local value = luagit2_cred.cred_ssh_key_from_agent_details(cred_ssh_key_agent_new)
		assert.are.equal("AGENT_NAME",value)
		luagit2_cred.cred_free(cred_ssh_key_agent_new)
	end)

end)