-- Fixing and modifying the testrepos to be used 
-- for testing luagit2's functions

local fix_repo = {}

-- Temporarily changes .gitted/ to .git/
-- Requires a string argument of testrepo's name

function fix_repo.set_repo(repo_name)
	os.execute( string.format( [[mv "%s" "%s"]], "Fixtures/" .. repo_name .. "/.gitted/", "Fixtures/" .. repo_name .. "/.git/" ))
end

function fix_repo.set_back(repo_name)
	os.execute( string.format( [[mv "%s" "%s"]], "Fixtures/" .. repo_name .. "/.git/", "Fixtures/" .. repo_name .. "/.gitted/" ))
end

return fix_repo