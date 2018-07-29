-- Fixing and modifying the testrepos to be used 
-- for testing luagit2's functions

local fix_repo = {}

-- Temporarily changes .gitted/ to .git/
-- Requires a string argument of testrepo's name

function fix_repo.set_repo(repo_name)
	os.execute("cd ../ && mv .git/ .gitted/")
	os.execute(string.format( [[cp -r "%s" "%s"]], "Fixtures/" .. repo_name , "Fixtures/WORKON_REPO" ))
	os.execute("mv Fixtures/WORKON_REPO/.gitted/ Fixtures/WORKON_REPO/.git/ ")
	os.execute("cd Fixtures/WORKON_REPO/ && git config user.name \"TEST_USER\"")
	os.execute("cd Fixtures/WORKON_REPO/ && git config user.email \"testusernoreply@github.com\"")
end

function fix_repo.set_back()
	os.execute("rm -rf Fixtures/WORKON_REPO/")
	os.execute("cd ../ && mv .gitted/ .git/")
end

return fix_repo