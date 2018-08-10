------------------------------------------------------------------------------
--
-- luagit2's "Blame" example
-- ( equivalent to git blame [path] )
--
-- Copyright (c) 2018 Satyendra Kumar Banjare
-- 
-- shows how to do a git blame on a file in a given repository.
-- 
-- Note that the file path passed should be accessible.
-- It means the that the file is present in the current workdir.
-- Errors may arise if file passed is in a different branch and is
-- NOT in current branch.
-- 
-- pass the path of repo, path of file relative to the root of the repo
-- and the number of lines for which the blame data is to be found.
--
-- 
-- It should be noted that only one file's blame dta can be seen once at a time.
--

local luagit2 = require("luagit2")

----------------------------------------------------------
-- The necessary funation call for initializing
-- Libgit2's global state & threading
----------------------------------------------------------
luagit2.init()

----------------------------------------------------------
--
-- Get the params from comand line and get the repository
-- and file path whose blame data is to be found.
----------------------------------------------------------
local repo_path = arg[1]
local file_path = arg[2]

----------------------------------------------------------
--
-- Open the repository.
-- Get the blame for a file.
-- print data for blame line by line.
--
-- It should be noted that only latest commit is shown 
-- for changes in the files.
----------------------------------------------------------
local repo = luagit2.repository_open(repo_path)
local blame_file = luagit2.blame_file(repo, file_path)

----------------------------------------------------------
--
--
-- sample functions to handle file io.
--
-- see if the file exists
function file_exists(file)
  local f = io.open(file, "rb")
  if f then f:close() end
  return f ~= nil
end

-- get all lines from a file, returns an empty 
-- list/table if the file does not exist
function lines_from(file)
  if not file_exists(file) then return {} end
  lines = {}
  for line in io.lines(file) do 
    lines[#lines + 1] = line
  end
  return lines
end
-----------------------------------------------------------
-- Get individual lines.
-----------------------------------------------------------
local lines = lines_from(file_path)

-- print all line numbers and the their commit details line by line.
for k,v in pairs(lines) do

	local hunk_byline = luagit2.blame_get_hunk_byline(blame_file,k)
    local sign = luagit2.blame_hunk_signature(hunk_byline)
    local _name, _email = luagit2.get_signature_details(sign)
    local last_commit_oid = luagit2.blame_hunk_commit_id(hunk_byline)
    local str_val_oid = luagit2.oid_tostr(last_commit_oid) 

	print('line[' .. k .. ']', v)
	print(_name .. "  " .. _email .. "  " .. str_val_oid .. "\n")

end

---------------------------------------------------------------------
-- You should get an output as
--
--
-- line[1]	hello
-- test_user  test@example.com  108ddee361877aa5c044d89d8dd232b8fd0f8992

-- line[2]	something
-- test_user  test@example.com  764e130d42fa42e1bc7a3ecb87f94ece9a6a8248

-- line[3]	to tell
-- test_user  test@example.com  764e130d42fa42e1bc7a3ecb87f94ece9a6a8248
-- 
--
-- must free the used repository, blame data to prevent
-- memory leaks
----------------------------------------------------------
luagit2.blame_free(blame_file)
luagit2.repository_free(repo)

----------------------------------------------------------
--
-- Shutdown the libgit2's threading and global state
----------------------------------------------------------
luagit2.shutdown()
