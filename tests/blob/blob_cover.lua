local luagit2_lib = require("luagit2")

local luagit2_blob = {}

----------------------------------------------------------------
--
-- Complete Set of blob functions to test coverage for.
--
--
-- {"blob_create_fromdisk", lua_git_blob_create_fromdisk},
-- {"blob_create_fromworkdir", lua_git_blob_create_fromworkdir},
-- {"blob_filtered_content", lua_git_blob_filtered_content},
-- {"blob_id", lua_git_blob_id},
-- {"blob_is_binary", lua_git_blob_is_binary},
-- {"blob_lookup", lua_git_blob_lookup},
-- {"blob_lookup_prefix", lua_git_blob_lookup_prefix},
-- {"blob_owner", lua_git_blob_owner},
-- {"blob_rawsize", lua_git_blob_rawsize},
-- {"blob_free", lua_git_blob_free},
--
----------------------------------------------------------------


local function blob_create_fromdisk(...)
      return luagit2_lib.blob_create_fromdisk(...)
end

local function blob_create_fromworkdir(...)
      return luagit2_lib.blob_create_fromworkdir(...)
end

local function blob_filtered_content(...)
      return luagit2_lib.blob_filtered_content(...)
end

local function blob_id(...)
      return luagit2_lib.blob_id(...)
end

local function blob_is_binary(...)
      return luagit2_lib.blob_is_binary(...)
end

local function blob_lookup(...)
      return luagit2_lib.blob_lookup(...)
end

local function blob_lookup_prefix(...)
      return luagit2_lib.blob_lookup_prefix(...)
end

local function blob_owner(...)
      return luagit2_lib.blob_owner(...)
end

local function blob_rawsize(...)
      return luagit2_lib.blob_rawsize(...)
end

local function blob_free(...)
      return luagit2_lib.blob_free(...)
end

luagit2_blob.blob_create_fromdisk = blob_create_fromdisk
luagit2_blob.blob_create_fromworkdir = blob_create_fromworkdir
luagit2_blob.blob_filtered_content = blob_filtered_content
luagit2_blob.blob_id = blob_id
luagit2_blob.blob_is_binary = blob_is_binary
luagit2_blob.blob_lookup = blob_lookup
luagit2_blob.blob_lookup_prefix = blob_lookup_prefix
luagit2_blob.blob_owner = blob_owner
luagit2_blob.blob_rawsize = blob_rawsize
luagit2_blob.blob_free = blob_free

return luagit2_blob
