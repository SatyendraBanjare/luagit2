-- Tests for luagit2's Checkout module functions

local fixer = require("Fixtures.fix_repo")

describe(" Checkout Methods Tests ", function()
    local luagit2 = require("luagit2")
    local luagit2_checkout = require("checkout.checkout_cover")
    local repo_path = "Fixtures/WORKON_REPO"
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open(repo_path)
    end)
    
    after_each(function()
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)
    
    it("Tests checkout master ", function ()
        local checkout_init_opts = luagit2_checkout.checkout_init_options()
        -- checkout head
        luagit2_checkout.checkout_head(repo, checkout_init_opts)
        local repo_HEAD_ref = luagit2.repository_head(repo)
        local ref_name = luagit2.reference_name(repo_HEAD_ref)
        assert.are.equal("refs/heads/master", ref_name)
    end)
    
    it("Tests checkout index ", function ()
        local checkout_init_opts = luagit2_checkout.checkout_init_options()
        -- checkout current index (by default it is master)
        local index_open_by_path = luagit2.index_open("/Fixtures/WORKON_REPO/.git/index")
        luagit2_checkout.checkout_index(repo, index_open_by_path, checkout_init_opts)
        local repo_HEAD_ref = luagit2.repository_head(repo)
        local ref_name = luagit2.reference_name(repo_HEAD_ref)
        assert.are.equal("refs/heads/master", ref_name)
        luagit2.index_free(index_open_by_path)
    end)
	
	--[[ A simple output of `git cat-file -p HEAD^{tree}`
		on Fixtures/new_test_repo
		 
		100644 blob 1385f264afb75a56a5bec74243be9b367ba4ca08README
		100644 blob ce013625030ba8dba906f756967f9e9ca394464aabc.txt
		100644 blob fa49b077972391ad58037050f2a75f74e3671e92new.txt
		040000 tree 619f9935957e010c419cb9d15621916ddfcc0b96subdir <--------|
																			|
		---------------------------------------------------------------     |
																			|
		An output of                                                        | 
		-$ git ls-tree 619f9935957e010c419cb9d15621916ddfc  <---------------|
		 
		100644 blob 1385f264afb75a56a5bec74243be9b367ba4ca08README
		100644 blob fa49b077972391ad58037050f2a75f74e3671e92new.txt
		040000 tree f60079018b664e4e79329a7ef9559c8d9e0378d1subdir2
	
	]]--    

    it("Tests checkout tree ", function ()
        -- Setup the variables
        local checkout_init_opts = luagit2_checkout.checkout_init_options()
        local tree_oid_string = "619f9935957e010c419cb9d15621916ddfcc0b96"
        local tree_oid = luagit2.oid_fromstr(tree_oid_string)
        local otype_tree = luagit2.object_string2type("tree")
        local obj_tree = luagit2.object_lookup(repo, tree_oid, otype_tree)
        
        -- Checkout the branch whose tree is this.
        luagit2_checkout.checkout_tree(repo, obj_tree, checkout_init_opts)
        local repo_HEAD_ref = luagit2.repository_head(repo)
        local ref_name = luagit2.reference_name(repo_HEAD_ref)
        -- In this case the tree belogs to master branch. Thus this assertion
        -- is valid.
        assert.are.equal("refs/heads/master", ref_name)
    end)
    
end)
