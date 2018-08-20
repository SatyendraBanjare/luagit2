local luagit2_lib = require("luagit2")

local luagit2_tag = {}

-----------------------------------------------------------------
-- {"tag_annotation_create", lua_git_tag_annotation_create},
-- {"tag_create", lua_git_tag_create},
-- {"tag_create_frombuffer", lua_git_tag_create_frombuffer},
-- {"tag_create_lightweight", lua_git_tag_create_lightweight},
-- {"tag_delete", lua_git_tag_delete},
-- {"tag_free", lua_git_tag_free},
-- {"tag_id", lua_git_tag_id},
-- {"tag_list", lua_git_tag_list},
-- {"tag_list_match", lua_git_tag_list_match},
-- {"tag_lookup", lua_git_tag_lookup},
-- {"tag_owner", lua_git_tag_owner},
-- {"tag_tagger", lua_git_tag_tagger},
-- {"tag_target", lua_git_tag_target},
-- {"tag_target_id", lua_git_tag_target_id},
-- {"tag_target_type", lua_git_tag_target_type},
-- {"tag_message",lua_git_tag_message},
-- {"tag_name",lua_git_tag_name},
-----------------------------------------------------------------

local function tag_annotation_create(...)
	return luagit2_lib.tag_annotation_create(...)
end

local function tag_create(...)
	return luagit2_lib.tag_create(...)
end

local function tag_create_frombuffer(...)
	return luagit2_lib.tag_create_frombuffer(...)
end

local function tag_create_lightweight(...)
	return luagit2_lib.tag_create_lightweight(...)
end

local function tag_delete(...)
	return luagit2_lib.tag_delete(...)
end

local function tag_free(...)
	return luagit2_lib.tag_free(...)
end

local function tag_id(...)
	return luagit2_lib.tag_id(...)
end

local function tag_list(...)
	return luagit2_lib.tag_list(...)
end

local function tag_list_match(...)
	return luagit2_lib.tag_list_match(...)
end

local function tag_lookup(...)
	return luagit2_lib.tag_lookup(...)
end

local function tag_owner(...)
	return luagit2_lib.tag_owner(...)
end

local function tag_tagger(...)
	return luagit2_lib.tag_tagger(...)
end

local function tag_target(...)
	return luagit2_lib.tag_target(...)
end

local function tag_target_id(...)
	return luagit2_lib.tag_target_id(...)
end

local function tag_target_type(...)
	return luagit2_lib.tag_target_type(...)
end

local function tag_message(...)
	return luagit2_lib.tag_message(...)
end

local function tag_name(...)
	return luagit2_lib.tag_name(...)
end

luagit2_tag.tag_annotation_create = tag_annotation_create
luagit2_tag.tag_create = tag_create
luagit2_tag.tag_create_frombuffer = tag_create_frombuffer
luagit2_tag.tag_create_lightweight = tag_create_lightweight
luagit2_tag.tag_delete = tag_delete
luagit2_tag.tag_free = tag_free
luagit2_tag.tag_id = tag_id
luagit2_tag.tag_list = tag_list
luagit2_tag.tag_list_match = tag_list_match
luagit2_tag.tag_lookup = tag_lookup
luagit2_tag.tag_owner = tag_owner
luagit2_tag.tag_tagger = tag_tagger
luagit2_tag.tag_target = tag_target
luagit2_tag.tag_target_id = tag_target_id
luagit2_tag.tag_target_type = tag_target_type
luagit2_tag.tag_message = tag_message
luagit2_tag.tag_name = tag_name

return luagit2_tag
