local luagit2_lib = require("luagit2")

local luagit2_reflog = {}

-------------------------------------------------------------------------
-- {"reflog_read",lua_git_reflog_read},
-- {"reflog_entrycount",lua_git_reflog_entrycount},
-- {"reflog_free",lua_git_reflog_free},
-- {"reflog_entry_byindex",lua_git_reflog_entry_byindex},
-- {"reflog_entry_committer",lua_git_reflog_entry_committer},
-- {"reflog_entry_message",lua_git_reflog_entry_message},
-- {"reflog_entry_id_new",lua_git_reflog_entry_id_new},
-- {"reflog_entry_id_old",lua_git_reflog_entry_id_old},
-- {"reflog_delete",lua_git_reflog_delete},
-- {"reflog_drop",lua_git_reflog_drop},
-- {"reflog_append",lua_git_reflog_append},
-------------------------------------------------------------------------

local function reflog_read(...)
	return luagit2_lib.reflog_read(...)
end

local function reflog_entrycount(...)
	return luagit2_lib.reflog_entrycount(...)
end

local function reflog_free(...)
	return luagit2_lib.reflog_free(...)
end

local function reflog_entry_byindex(...)
	return luagit2_lib.reflog_entry_byindex(...)
end

local function reflog_entry_committer(...)
	return luagit2_lib.reflog_entry_committer(...)
end

local function reflog_entry_message(...)
	return luagit2_lib.reflog_entry_message(...)
end

local function reflog_entry_id_new(...)
	return luagit2_lib.reflog_entry_id_new(...)
end

local function reflog_entry_id_old(...)
	return luagit2_lib.reflog_entry_id_old(...)
end

local function reflog_delete(...)
	return luagit2_lib.reflog_delete(...)
end

local function reflog_drop(...)
	return luagit2_lib.reflog_drop(...)
end

local function reflog_append(...)
	return luagit2_lib.reflog_append(...)
end

luagit2_reflog.reflog_read = reflog_read
luagit2_reflog.reflog_entrycount = reflog_entrycount
luagit2_reflog.reflog_free = reflog_free
luagit2_reflog.reflog_entry_byindex = reflog_entry_byindex
luagit2_reflog.reflog_entry_committer = reflog_entry_committer
luagit2_reflog.reflog_entry_message = reflog_entry_message
luagit2_reflog.reflog_entry_id_new = reflog_entry_id_new
luagit2_reflog.reflog_entry_id_old = reflog_entry_id_old
luagit2_reflog.reflog_delete = reflog_delete
luagit2_reflog.reflog_drop = reflog_drop
luagit2_reflog.reflog_append = reflog_append

return luagit2_reflog
