local luagit2_lib = require("luagit2")

local luagit2_revert = {}

--------------------------------------
-- {"revert",lua_git_revert},
--------------------------------------


local function revert(...)
	return luagit2_lib.revert(...)
end

luagit2_revert.revert = revert

return luagit2_revert
