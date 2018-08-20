local luagit2_lib = require("luagit2")

local luagit2_cred = {}

------------------------------------------------------------------------------
-- {"cred_default_new", lua_git_cred_default_new},
-- {"cred_ssh_key_from_agent", lua_git_cred_ssh_key_from_agent},
-- {"cred_ssh_key_memory_new", lua_git_cred_ssh_key_memory_new},
-- {"cred_ssh_key_new", lua_git_cred_ssh_key_new},
-- {"cred_username_new", lua_git_cred_username_new},
-- {"cred_userpass_plaintext_new", lua_git_cred_userpass_plaintext_new},
-- {"cred_free", lua_git_cred_free},

-- {"cred_username_details",lua_git_cred_username_details},
-- {"cred_userpass_details",lua_git_cred_userpass_details},
-- {"cred_ssh_key_from_agent_details",lua_git_cred_ssh_key_from_agent_details},
-------------------------------------------------------------------------------


local function cred_default_new(...)
	return luagit2_lib.cred_default_new(...)
end

local function cred_ssh_key_from_agent(...)
	return luagit2_lib.cred_ssh_key_from_agent(...)
end

local function cred_ssh_key_memory_new(...)
	return luagit2_lib.cred_ssh_key_memory_new(...)
end

local function cred_ssh_key_new(...)
	return luagit2_lib.cred_ssh_key_new(...)
end

local function cred_username_new(...)
	return luagit2_lib.cred_username_new(...)
end

local function cred_userpass_plaintext_new(...)
	return luagit2_lib.cred_userpass_plaintext_new(...)
end

local function cred_free(...)
	return luagit2_lib.cred_free(...)
end

local function cred_userpass_details(...)
	return luagit2_lib.cred_userpass_details(...)
end

local function cred_username_details(...)
	return luagit2_lib.cred_username_details(...)
end

local function cred_ssh_key_from_agent_details(...)
	return luagit2_lib.cred_ssh_key_from_agent_details(...)
end

luagit2_cred.cred_default_new = cred_default_new
luagit2_cred.cred_ssh_key_from_agent = cred_ssh_key_from_agent
luagit2_cred.cred_ssh_key_memory_new = cred_ssh_key_memory_new
luagit2_cred.cred_ssh_key_new = cred_ssh_key_new
luagit2_cred.cred_username_new = cred_username_new
luagit2_cred.cred_userpass_plaintext_new = cred_userpass_plaintext_new
luagit2_cred.cred_free = cred_free
luagit2_cred.cred_userpass_details = cred_userpass_details
luagit2_cred.cred_username_details = cred_username_details
luagit2_cred.cred_ssh_key_from_agent_details = cred_ssh_key_from_agent_details

return luagit2_cred
