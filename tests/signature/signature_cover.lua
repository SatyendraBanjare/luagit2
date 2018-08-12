local luagit2_lib = require("luagit2")

local luagit2_signature = {}

-----------------------------------------------------------------
-- {"signature_default", lua_git_signature_default},
-- {"signature_dup", lua_git_signature_dup},
-- {"signature_from_buffer", lua_git_signature_from_buffer},
-- {"signature_now", lua_git_signature_now},
-- {"signature_free", lua_git_signature_free},
-----------------------------------------------------------------

local function signature_default(...)
	return luagit2_lib.signature_default(...)
end

local function signature_dup(...)
	return luagit2_lib.signature_dup(...)
end

local function signature_from_buffer(...)
	return luagit2_lib.signature_from_buffer(...)
end

local function signature_now(...)
	return luagit2_lib.signature_now(...)
end

local function signature_free(...)
	return luagit2_lib.signature_free(...)
end

luagit2_signature.signature_default = signature_default
luagit2_signature.signature_dup = signature_dup
luagit2_signature.signature_from_buffer = signature_from_buffer
luagit2_signature.signature_now = signature_now
luagit2_signature.signature_free = signature_free

return luagit2_signature
