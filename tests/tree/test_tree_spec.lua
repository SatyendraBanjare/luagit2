-- Luagit2's Tree Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Tree Methods Tests ", function()
    local luagit2 = require("luagit2")
    local repo_path = "Fixtures/WORKON_REPO"
    local tree_oid_string = "619f9935957e010c419cb9d15621916ddfcc0b96"
    local readme_oid_string = "1385f264afb75a56a5bec74243be9b367ba4ca08"
    local tree_oid, tree, readme_oid
    local current_directory_path = lfs.currentdir()
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open(repo_path)
        tree_oid = luagit2.oid_fromstr(tree_oid_string)
        readme_oid = luagit2.oid_fromstr(readme_oid_string)
        tree = luagit2.tree_lookup(repo, tree_oid)
    end)
    
    after_each(function()
        luagit2.tree_free(tree)
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
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
    
    it("Tests Tree id", function()
        -- It tests that id of tree generated
        -- acually matches one used for creation
        
        local tree_id_check = luagit2.tree_id(tree)
        local tree_id_str_check = luagit2.oid_tostr_s(tree_id_check)
        assert.are.equal(tree_oid_string, tree_id_str_check)
        
    end)
    
    it("Tests Tree owner repository", function()
        local owner_repo = luagit2.tree_owner(tree)
        local owner_repo_path = luagit2.repository_path(owner_repo)
        
        -- Check with absolute path
        assert.are.equal(current_directory_path .. "/Fixtures/WORKON_REPO/.git/", owner_repo_path)
    end)
    
    it("Tests tree lookup by prefix", function()
        -- Lookup using first 5 chars of oid
        local tree_by_prefix = luagit2.tree_lookup_prefix(repo, tree_oid, 5)
        
        -- Check for returned oid value
        -- Must match with original value
        local tree_id_check = luagit2.tree_id(tree_by_prefix)
        local tree_id_str_check = luagit2.oid_tostr_s(tree_id_check)
        assert.are.equal(tree_oid_string, tree_id_str_check)
    end)
    
    it("Tests Tree entry count", function()
        --
        -- Get th entries count
        -- It should be equal to '3'
        -- As seen in the output of git ls-tree
        --
        local count = luagit2.tree_entrycount(tree)
        assert.are.equal(3, count)
    end)
    
    it("Tests getting Tree entries ", function()
        --
        -- Here we retrieve trww entries by different
        -- available methods. Then we check for their
        -- Values.
        --
        -- By oid of README
        local readme_entry_by_id = luagit2.tree_entry_byid(tree, readme_oid)
        
        -- Since README is the first in tree, its index value is 0
        local readme_entry_byindex = luagit2.tree_entry_byindex(tree, 0)
        
        -- Make sure this object does exist in tree by
        -- given name.
        local readme_entry_byname = luagit2.tree_entry_byname(tree, "README")
        
        -- README is in the current path pointed
        -- by tree object. Hence simply passing the name
        -- would work.
        local readme_entry_bypath = luagit2.tree_entry_bypath(tree, "README")
        
        -- Get ids for each tree entry
        local entry_oid_byid = luagit2.tree_entry_id(readme_entry_by_id)
        local entry_oid_byindex = luagit2.tree_entry_id(readme_entry_byindex)
        local entry_oid_byname = luagit2.tree_entry_id(readme_entry_byname)
        local entry_oid_bypath = luagit2.tree_entry_id(readme_entry_bypath)
        
        -- Get the names for different Entries
        local entry_name_byid = luagit2.tree_entry_name(readme_entry_by_id)
        local entry_name_byindex = luagit2.tree_entry_name(readme_entry_by_id)
        local entry_name_byname = luagit2.tree_entry_name(readme_entry_by_id)
        local entry_name_bypath = luagit2.tree_entry_name(readme_entry_by_id)
        
        -- Check for the values of oids
        -- They all must be consistent with readme's oid string value
        assert.are.equal(readme_oid_string, luagit2.oid_tostr_s(entry_oid_byid))
        assert.are.equal(readme_oid_string, luagit2.oid_tostr_s(entry_oid_byindex))
        assert.are.equal(readme_oid_string, luagit2.oid_tostr_s(entry_oid_byname))
        assert.are.equal(readme_oid_string, luagit2.oid_tostr_s(entry_oid_bypath))
        
        -- Check for the values of entry names
        -- They all must be README .
        assert.are.equal("README", entry_name_byid)
        assert.are.equal("README", entry_name_byindex)
        assert.are.equal("README", entry_name_byname)
        assert.are.equal("README", entry_name_bypath) 
    end)
    
    it("Tests tree entry's object type", function()
        local readme_entry_by_id = luagit2.tree_entry_byid(tree, readme_oid)
        local entry_type = luagit2.tree_entry_type(readme_entry_by_id)
        
        local type_value = luagit2.object_type2string(entry_type)
        assert.are.equal("blob", type_value)
    end)
    
end)
