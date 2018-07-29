-- Annotated module test

local fixer = require("Fixtures.fix_repo")

describe(" Annotated Methods Tests ", function()
    local luagit2 = require("luagit2")
    local repo_path = "Fixtures/WORKON_REPO"
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("testrepo")
        repo = luagit2.repository_open(repo_path)
    end)
    
    after_each(function()
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)
    
    --[[ An example output of git show-ref on testrepo
		
		a4a7dce85cf63874e984719f4fdd239f5145052f refs/heads/br2
		144344043ba4d4a405da03de3844aa829ae8be0e refs/heads/dir
		f9ed4af42472941da45a3ce44458455ed227a6be refs/heads/executable
		6fd5c7dd2ab27b48c493023f794be09861e9045f refs/heads/ident
		6b377958d8c6a4906e8573b53672a1a23a4e8ce6 refs/heads/long-file-name
		099fabac3a9ea935598528c27f866e34089c2eff refs/heads/master
		a38d028f71eaa590febb7d716b1ca32350cf70da refs/heads/merge-conflict
		41bc8c69075bbdb46c5c6f0566cc8cc5b46e8bd9 refs/heads/packed
		4a202b346bb0fb0db7eff3cffeb3c70babbd2045 refs/heads/packed-test
		763d71aadf09a7951596c9746c024e7eece7c7af refs/heads/subtrees
		e90810b8df3e80c413d903f631643c716887138d refs/heads/test
		099fabac3a9ea935598528c27f866e34089c2eff refs/heads/testrepo-worktree
		7b4384978d2493e851f9cca7858815fac9b10980 refs/tags/e90810b
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/foo/bar
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/foo/foo/bar
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/packed-tag
		1385f264afb75a56a5bec74243be9b367ba4ca08 refs/tags/point_to_blob
		b25fa35b38051e4ae45d4222e795f9df2e43f1d1 refs/tags/test

		----------------------------------------------------------------------
		example output of git log of git log on test branch of test repo

		commit e90810b8df3e80c413d903f631643c716887138d
		Author: Vicent Marti <tanoku@gmail.com>
		Date:   Thu Aug 5 18:42:20 2010 +0200

		    Test commit 2

		commit 6dcf9bf7541ee10456529833502442f385010c3d
		Author: Vicent Marti <tanoku@gmail.com>
		Date:   Thu Aug 5 18:41:33 2010 +0200

		    Test commit 1

	]]--
    
    it("Tests creating annotated commit from given reference", function()
        local ref_dir_str = "144344043ba4d4a405da03de3844aa829ae8be0e"
        local ref_dir = luagit2.reference_lookup(repo, "refs/heads/dir")
        
        local annotated_from_ref = luagit2.annotated_commit_from_ref(repo, ref_dir)
        local annotated_commit_id = luagit2.annotated_commit_id(annotated_from_ref)
        local id_string = luagit2.oid_tostr(annotated_commit_id)
        assert.are.equal(ref_dir_str, id_string)
        luagit2.annotated_commit_free(annotated_from_ref)
    end)
    
    it("Tests creating annotated commit from given reference", function()
        local ref_dir_str = "144344043ba4d4a405da03de3844aa829ae8be0e"
        local annotated_from_revspec = luagit2.annotated_commit_from_revspec(repo, "refs/heads/dir")
        
        local annotated_commit_id = luagit2.annotated_commit_id(annotated_from_revspec)
        local id_string = luagit2.oid_tostr(annotated_commit_id)
        assert.are.equal(ref_dir_str, id_string)
        luagit2.annotated_commit_free(annotated_from_revspec)
    end)
    
    it("Tests creating annotated commit from fetchhead", function()
        local commit_id_str = "e90810b8df3e80c413d903f631643c716887138d"
        local commit_oid = luagit2.oid_fromstr(commit_id_str)
        local annotated_from_fetchhead = luagit2.annotated_commit_from_fetchhead(repo, "test", "git://github.com/libgit2/libgit2", commit_oid)
        
        local annotated_commit_id = luagit2.annotated_commit_id(annotated_from_fetchhead)
        local id_string = luagit2.oid_tostr(annotated_commit_id)
        assert.are.equal(commit_id_str, id_string)
        luagit2.annotated_commit_free(annotated_from_fetchhead)
    end)
    
end)
