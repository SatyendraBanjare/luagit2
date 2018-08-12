local luagit2_lib = require("luagit2")

local luagit2_oid = {}

--------------------------------------------------------------------
-- {"oid_fromstr", lua_git_oid_fromstr},
-- {"oid_fromstrn", lua_git_oid_fromstrn},
-- {"oid_cmp", lua_git_oid_cmp},
-- {"oid_fmt", lua_git_oid_fmt},
-- {"oid_ncmp", lua_git_oid_ncmp},
-- {"oid_nfmt", lua_git_oid_nfmt},
-- {"oid_pathfmt", lua_git_oid_pathfmt},
-- {"oid_iszero", lua_git_oid_iszero},
-- {"oid_strcmp", lua_git_oid_strcmp},
-- {"oid_tostr", lua_git_oid_tostr},
-- {"oid_tostr_s", lua_git_oid_tostr_s},
--------------------------------------------------------------------

local function oid_fromstr(...)
	return luagit2_lib.oid_fromstr(...)
end

local function oid_fromstrn(...)
	return luagit2_lib.oid_fromstrn(...)
end

local function oid_cmp(...)
	return luagit2_lib.oid_cmp(...)
end

local function oid_fmt(...)
	return luagit2_lib.oid_fmt(...)
end

local function oid_ncmp(...)
	return luagit2_lib.oid_ncmp(...)
end

local function oid_nfmt(...)
	return luagit2_lib.oid_nfmt(...)
end

local function oid_pathfmt(...)
	return luagit2_lib.oid_pathfmt(...)
end

local function oid_iszero(...)
	return luagit2_lib.oid_iszero(...)
end

local function oid_strcmp(...)
	return luagit2_lib.oid_strcmp(...)
end

local function oid_tostr(...)
	return luagit2_lib.oid_tostr(...)
end

local function oid_tostr_s(...)
	return luagit2_lib.oid_tostr_s(...)
end

luagit2_oid.oid_fromstr = oid_fromstr
luagit2_oid.oid_fromstrn = oid_fromstrn
luagit2_oid.oid_cmp = oid_cmp
luagit2_oid.oid_fmt = oid_fmt
luagit2_oid.oid_ncmp = oid_ncmp
luagit2_oid.oid_nfmt = oid_nfmt
luagit2_oid.oid_pathfmt = oid_pathfmt
luagit2_oid.oid_iszero = oid_iszero
luagit2_oid.oid_strcmp = oid_strcmp
luagit2_oid.oid_tostr = oid_tostr
luagit2_oid.oid_tostr_s = oid_tostr_s

return luagit2_oid

