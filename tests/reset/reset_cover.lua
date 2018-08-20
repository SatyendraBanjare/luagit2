local luagit2_lib = require("luagit2")

local luagit2_reset = {}

--------------------------------------
-- {"reset",lua_git_reset},
--------------------------------------

local function reset(...)
	return luagit2_lib.reset(...)
end

luagit2_reset.reset = reset

return luagit2_reset
