-- Luagit2's Signature Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Signature Methods Tests ", function()
	local lib = require("luagit2")

	setup(function()
		lib.luagit2_init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = lib.luagit2_repository_open("Fixtures/WORKON_REPO/.git")
	end)

	after_each(function()
		lib.luagit2_repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		lib.luagit2_shutdown()
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

	it("Tests signature_default method",function()
		-- Get the Default signature for repository
		local sign_default = lib.luagit2_signature_default(repo)
		assert.are.equal("TEST_USER", lib.luagit2_get_signature_details(sign_default,1))
		assert.are.equal("testusernoreply@github.com", lib.luagit2_get_signature_details(sign_default,2))
		lib.luagit2_signature_free(sign_default)
	end)

	it("Tests signature from string method",function()
		-- Create a sign from a complete signature string
		-- as you see in a commit.
		local sign_string = "Testing_user <something@example.com> 1461698487 +0200"
		local sign_from_string_buffer = lib.luagit2_signature_from_buffer(sign_string)

		assert.are.equal("Testing_user", lib.luagit2_get_signature_details(sign_from_string_buffer,1))
		assert.are.equal("something@example.com", lib.luagit2_get_signature_details(sign_from_string_buffer,2))
		-- free the signature
		lib.luagit2_signature_free(sign_from_string_buffer)
	end)

	it("Tests signature now method",function()
		local sign_now = lib.luagit2_signature_now("new_user","new_user@example.com")

		assert.are.equal("new_user", lib.luagit2_get_signature_details(sign_now,1))
		assert.are.equal("new_user@example.com", lib.luagit2_get_signature_details(sign_now,2))
		-- free the signature
		lib.luagit2_signature_free(sign_now)
	end)

	it("Tests signature dup method",function()
		local sign_now = lib.luagit2_signature_now("new_user","new_user@example.com")
		local sign_dup = lib.luagit2_signature_dup(sign_now)

		assert.are.equal("new_user", lib.luagit2_get_signature_details(sign_dup,1))
		assert.are.equal("new_user@example.com", lib.luagit2_get_signature_details(sign_dup,2))
		-- free the signatures
		lib.luagit2_signature_free(sign_now)
		lib.luagit2_signature_free(sign_dup)
	end)
end)
