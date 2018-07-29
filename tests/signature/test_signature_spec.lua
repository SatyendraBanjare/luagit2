-- Luagit2's Signature Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Signature Methods Tests ", function()
    local luagit2 = require("luagit2")
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
    end)
    
    after_each(function()
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)
    
    --[[
 
		A simple output of `git config -l` on Fixtures/new_test_repo
		After th repo has been fixed for testing , that is user.email
		and user.name have been set (see fixer.set_repo())
		 
		user.email=YOUR_DEFAULT_GIT_USER_EMAIL
		user.name=YOUR_DEFAULT_GIT_USER_NAME
		core.repositoryformatversion=0
		core.filemode=true
		core.bare=false
		core.logallrefupdates=true
		core.ignorecase=true
		core.precomposeunicode=false
		remote.origin.url=https://github.com/libgit2/false.git
		remote.origin.fetch=+refs/heads/*:refs/remotes/origin/*
		remote.insteadof-test.url=http://example.com/libgit2/libgit2
		remote.insteadof-test.pushurl=http://github.com/libgit2/libgit2
		remote.insteadof-test.fetch=+refs/heads/*:refs/remotes/test/*
		branch.master.remote=origin
		branch.master.merge=refs/heads/master
		branch.master.rebase=true
		url.longer-non-prefix-match.insteadof=ttp://example.com/li
		url.shorter-prefix.insteadof=http://example.co
		url.http://github.com.insteadof=http://example.com
		url.git@github.com:.pushinsteadof=http://github.com/
		user.name=TEST_USER
		user.email=testusernoreply@github.com
 
	]]--
    
    it("Tests signature_default method", function()
        -- Get the Default signature for repository
        local sign_default = luagit2.signature_default(repo)
        local name, email = luagit2.get_signature_details(sign_default)
        
        assert.are.equal("TEST_USER", name)
        assert.are.equal("testusernoreply@github.com", email)
        luagit2.signature_free(sign_default)
    end)
    
    it("Tests signature from string method", function()
        -- Create a sign from a complete signature string
        -- as you see in a commit.
        local sign_string = "Testing_user <something@example.com> 1461698487 +0200"
        local sign_from_string_buffer = luagit2.signature_from_buffer(sign_string)
        
        local name, email = luagit2.get_signature_details(sign_from_string_buffer)
        
        assert.are.equal("Testing_user", name)
        assert.are.equal("something@example.com", email)
        -- free the signature
        luagit2.signature_free(sign_from_string_buffer)
    end)
    
    it("Tests signature now method", function()
        local sign_now = luagit2.signature_now("new_user", "new_user@example.com")
        local name, email = luagit2.get_signature_details(sign_now)
        
        assert.are.equal("new_user", name)
        assert.are.equal("new_user@example.com", email)
        -- free the signature
        luagit2.signature_free(sign_now)
    end)
    
    it("Tests signature dup method", function()
        local sign_now = luagit2.signature_now("new_user", "new_user@example.com")
        local sign_dup = luagit2.signature_dup(sign_now)
        local name, email = luagit2.get_signature_details(sign_dup)
        
        assert.are.equal("new_user", name)
        assert.are.equal("new_user@example.com", email)
        -- free the signatures
        luagit2.signature_free(sign_now)
        luagit2.signature_free(sign_dup)
    end)
end)
