local luagit2_lib = require("luagit2")

local luagit2_object = {}

--------------------------------------------------------------------
-- {"object_size", lua_git_object__size},
-- {"object_free", lua_git_object_free},
-- {"object_id", lua_git_object_id},
-- {"object_lookup", lua_git_object_lookup},
-- {"object_lookup_bypath", lua_git_object_lookup_bypath},
-- {"object_lookup_prefix", lua_git_object_lookup_prefix},
-- {"object_owner", lua_git_object_owner},
-- {"object_short_id", lua_git_object_short_id},
-- {"object_string2type", lua_git_object_string2type},
-- {"object_type", lua_git_object_type},
-- {"object_type2string", lua_git_object_type2string},
-- {"object_typeisloose", lua_git_object_typeisloose},
--------------------------------------------------------------------

local function object_size(...)
	return luagit2_lib.object_size(...)
end

local function object_free(...)
	return luagit2_lib.object_free(...)
end

local function object_id(...)
	return luagit2_lib.object_id(...)
end

local function object_lookup(...)
	return luagit2_lib.object_lookup(...)
end

local function object_lookup_bypath(...)
	return luagit2_lib.object_lookup_bypath(...)
end

local function object_lookup_prefix(...)
	return luagit2_lib.object_lookup_prefix(...)
end

local function object_owner(...)
	return luagit2_lib.object_owner(...)
end

local function object_short_id(...)
	return luagit2_lib.object_short_id(...)
end

local function object_string2type(...)
	return luagit2_lib.object_string2type(...)
end

local function object_type(...)
	return luagit2_lib.object_type(...)
end

local function object_type2string(...)
	return luagit2_lib.object_type2string(...)
end

local function object_typeisloose(...)
	return luagit2_lib.object_typeisloose(...)
end

luagit2_object.object_size = object_size
luagit2_object.object_free = object_free
luagit2_object.object_id = object_id
luagit2_object.object_lookup = object_lookup
luagit2_object.object_lookup_bypath = object_lookup_bypath
luagit2_object.object_lookup_prefix = object_lookup_prefix
luagit2_object.object_owner = object_owner
luagit2_object.object_short_id = object_short_id
luagit2_object.object_string2type = object_string2type
luagit2_object.object_type = object_type
luagit2_object.object_type2string = object_type2string
luagit2_object.object_typeisloose = object_typeisloose

return luagit2_object
