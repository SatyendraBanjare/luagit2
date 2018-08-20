local luagit2_lib = require("luagit2")

local luagit2_describe = {}

---------------------------------------------------------
-- {"describe_commit",lua_git_describe_commit},
-- {"describe_workdir",lua_git_describe_workdir},
-- {"describe_format",lua_git_describe_format},
-- {"describe_result_free",lua_git_describe_result_free},
---------------------------------------------------------

local function describe_commit(...)
	return luagit2_lib.describe_commit(...)
end

local function describe_workdir(...)
	return luagit2_lib.describe_workdir(...)
end

local function describe_format(...)
	return luagit2_lib.describe_format(...)
end

local function describe_result_free(...)
	return luagit2_lib.describe_result_free(...)
end

luagit2_describe.describe_commit = describe_commit
luagit2_describe.describe_workdir = describe_workdir
luagit2_describe.describe_format = describe_format
luagit2_describe.describe_result_free = describe_result_free

return luagit2_describe
