local luagit2_lib = require("luagit2")

local luagit2_revaparse = {}

-------------------------------------------------------------------
-- {"revparse",lua_git_revparse},
-- {"revparse_single",lua_git_revparse_single},
-------------------------------------------------------------------

local function revparse(...)
	return luagit2_lib.revparse(...)
end

local function revparse_single(...)
	return luagit2_lib.revparse_single(...)
end

luagit2_revaparse.revparse = revparse
luagit2_revaparse.revparse_single = revparse_single

return luagit2_revaparse
