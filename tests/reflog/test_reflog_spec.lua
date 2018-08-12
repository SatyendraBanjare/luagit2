-- Luagit2's Reflog Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Reflog Methods Tests ", function()
    local luagit2 = require("luagit2")
    local luagit2_reflog = require("reflog.reflog_cover")
    local repo_path = "Fixtures/WORKON_REPO"
    local head_reflog, master_reflog
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open(repo_path)
        head_reflog = luagit2_reflog.reflog_read(repo, "HEAD")
        master_reflog = luagit2_reflog.reflog_read(repo, "master")
    end)
    
    after_each(function()
        luagit2_reflog.reflog_free(head_reflog)
        luagit2_reflog.reflog_free(master_reflog)
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)
    
    --[[
        Example output of `git reflog HEAD` on Fixtures/new_test_repo
 
        git reflog HEAD
        108ddee HEAD@{0}: commit: Added File
        36060c5 HEAD@{1}: clone: from /Users/rb/src/libgit2/tests-clar/resources/../../../rugged/test/fixtures/testrepo.git
 
        Example output of `git reflog master` on Fixtures/new_test_repo
 
        git reflog master
        108ddee master@{0}: commit: Added File
        36060c5 master@{1}: clone: from /Users/rb/src/libgit2/tests-clar/resources/../../../rugged/test/fixtures/testrepo.git
    ]]--
    
    it("tests reflog entry count", function()
        local count = luagit2_reflog.reflog_entrycount(head_reflog)
        assert.are.same(2, count)
    end)
    
    it("tests reflog entry by index", function()
        -- Lets check out the receive entry
        -- by the message it contains.
        local reflog_entry = luagit2_reflog.reflog_entry_byindex(head_reflog, 0)
        local message = luagit2_reflog.reflog_entry_message(reflog_entry)
        assert.are.equal("commit: Added File", message)
    end)
    
    it("tests entry committer", function()
        local reflog_entry = luagit2_reflog.reflog_entry_byindex(head_reflog, 0)
        local committer = luagit2_reflog.reflog_entry_committer(reflog_entry)
        local name, email = luagit2.get_signature_details(committer)
        assert.are.equal("test_user", name)
        assert.are.equal("test@example.com", email)
    end)
    
    it("tests reflog id new & old", function()
        local reflog_entry = luagit2_reflog.reflog_entry_byindex(head_reflog, 0)
        
        -- old Id refers to first entry in reflog in this case, HEAD@{1}
        local id_old = luagit2_reflog.reflog_entry_id_old(reflog_entry)
        local id_str_old = luagit2.oid_tostr_s(id_old)
        assert.are.equal("36060c58702ed4c2a40832c51758d5344201d89a", id_str_old)
        
        -- new Id refers to second entry in reflog in this case, HEAD@{2}
        local id_new = luagit2_reflog.reflog_entry_id_new(reflog_entry)
        local id_str_new = luagit2.oid_tostr_s(id_new)
        assert.are.equal("108ddee361877aa5c044d89d8dd232b8fd0f8992", id_str_new)
    end)
    
    it("tests reflog entry drop", function()
        local count_old = luagit2_reflog.reflog_entrycount(head_reflog)
        assert.are.same(2, count_old)
        
        -- drop a reflog entry
        luagit2_reflog.reflog_drop(head_reflog, 0, 0) -- do not rewrite
        
        -- check if count has reduced or not
        local count_new = luagit2_reflog.reflog_entrycount(head_reflog)
        assert.are.same(1, count_new)
    end)
    
    it("tests reflog delete", function()
        assert.has_no_errors(function() luagit2_reflog.reflog_delete(repo, "HEAD@{1}") end)
    end)
    
    it("tests reflog append", function()
        -- check old reflog count
        local count_old = luagit2_reflog.reflog_entrycount(head_reflog)
        assert.are.same(2, count_old)
        
        -- add a new reflog entry
        local commit_id_str = "36060c58702ed4c2a40832c51758d5344201d89a"
        local commit_oid = luagit2.oid_fromstr(commit_id_str)
        local sign_now = luagit2.signature_now("new_user", "new_user@example.com")
        luagit2_reflog.reflog_append(head_reflog, commit_oid, sign_now, "Some message")
        
        -- again check if count has increased or not
        local count_new = luagit2_reflog.reflog_entrycount(head_reflog)
        assert.are.same(3, count_new)
    end)
end)
