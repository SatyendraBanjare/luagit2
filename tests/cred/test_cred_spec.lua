-- Cred Module Tests

describe(" Cred Methods Tests ", function()
	local lib = require("luagit2")

	setup(function()
		lib.luagit2_init()
	end)

	teardown(function()
		lib.luagit2_shutdown()
	end)

	it("Tests Cred Username ",function()
		-- Create a git username type cred and test its validity.
		local cred_username_new = lib.luagit2_cred_username_new("UserName")
		local value = lib.luagit2_cred_username_details(cred_username_new)
		assert.are.equal("UserName",value)
		lib.luagit2_cred_free(cred_username_new)
	end)

	it("Tests Cred Userpass_Plaintext ",function()
		-- Create a git userpass type cred and test its validity.
		local cred_userpass_new = lib.luagit2_cred_userpass_plaintext_new("UserName","Password@123")
		local username , password = lib.luagit2_cred_userpass_details(cred_userpass_new)
		assert.are.equal("UserName",username)
		assert.are.equal("Password@123",password)
		lib.luagit2_cred_free(cred_userpass_new)
	end)

	it("Tests Cred SSH_key agent ",function()
		-- Create a git ssh_from_agent type cred and test its validity.
		local cred_ssh_key_agent_new = lib.luagit2_cred_ssh_key_from_agent("AGENT_NAME")
		local value = lib.luagit2_cred_ssh_key_from_agent_details(cred_ssh_key_agent_new)
		assert.are.equal("AGENT_NAME",value)
		lib.luagit2_cred_free(cred_ssh_key_agent_new)
	end)

end)