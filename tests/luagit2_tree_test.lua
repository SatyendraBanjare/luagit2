-- @module luagit2_tree_test
local luagit2_tree_tests = {}

function luagit2_tree_tests.test_luagit2_tree_entry_byid()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	object_id = lib.luagit2_oid_fromstr("d041fdcd12d6aac20dd0ddf203cff81553eb7cce") -- blob git oid for README.md
	lunatest.assert_not_nil(object_id)
	tree_entry_byid = lib.luagit2_tree_entry_byid(tree,object_id)
	lunatest.assert_not_nil(tree_entry_byid)

end

function luagit2_tree_tests.test_luagit2_tree_entry_byindex()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry_byindex = lib.luagit2_tree_entry_byindex(tree,0)
	lunatest.assert_not_nil(tree_entry_byindex)

end

function luagit2_tree_tests.test_luagit2_tree_entry_byname()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry_byname = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry_byname)

end

function luagit2_tree_tests.test_luagit2_tree_entry_bypath()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry_bypath = lib.luagit2_tree_entry_bypath(tree,"./README.md")
	lunatest.assert_not_nil(tree_entry_bypath)

end

function luagit2_tree_tests.test_luagit2_tree_entry_cmp()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id_one = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id_one)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	-- newfile1 was committed before newfile2
	tree_entry_one = lib.luagit2_tree_entry_byname(tree,"newfile1")
	lunatest.assert_not_nil(tree_entry_one)

	tree_entry_two = lib.luagit2_tree_entry_byname(tree,"newfile2")
	lunatest.assert_not_nil(tree_entry_two)

	lunatest.assert_lte(0,lib.luagit2_tree_entry_cmp(tree_entry_one,tree_entry_two))
	lunatest.assert_gte(0,lib.luagit2_tree_entry_cmp(tree_entry_two,tree_entry_one))
	lunatest.assert_equal(0,lib.luagit2_tree_entry_cmp(tree_entry_one,tree_entry_one))

end

function luagit2_tree_tests.test_luagit2_tree_entry_filemode()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry)

	filemode = lib.luagit2_tree_entry_filemode(tree_entry)
	lunatest.assert_not_nil(filemode)

end

function luagit2_tree_tests.test_luagit2_tree_entry_filemode_raw()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry)

	filemode_raw = lib.luagit2_tree_entry_filemode_raw(tree_entry)
	lunatest.assert_not_nil(filemode_raw)

end

function luagit2_tree_tests.test_luagit2_tree_entry_id()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry)

	object_id = lib.luagit2_tree_entry_id(tree_entry)
	lunatest.assert_not_nil(object_id)
	lunatest.assert_match("d041fdcd12d6aac20dd0ddf203cff81553eb7cce",lib.luagit2_oid_tostr_s(object_id))

end

function luagit2_tree_tests.test_luagit2_tree_entry_name()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry)

	Name = lib.luagit2_tree_entry_name(tree_entry)
	lunatest.assert_not_nil(Name)
	lunatest.assert_match("README.md",Name)

end

function luagit2_tree_tests.test_luagit2_tree_entry_to_object()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry)

	object = lib.luagit2_tree_entry_to_object(repo,tree_entry)
	lunatest.assert_not_nil(object)

end

function luagit2_tree_tests.test_luagit2_tree_entry_type()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	tree_entry = lib.luagit2_tree_entry_byname(tree,"README.md")
	lunatest.assert_not_nil(tree_entry)

	entry_type = lib.luagit2_tree_entry_type(tree_entry)
	lunatest.assert_not_nil(entry_type)

end

function luagit2_tree_tests.test_luagit2_tree_entrycount()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	entry_count = lib.luagit2_tree_entrycount(tree)
	lunatest.assert_number(entry_count)

end

function luagit2_tree_tests.test_luagit2_tree_id()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	new_tree_id = lib.luagit2_tree_id(tree)
	lunatest.assert_not_nil(new_tree_id)
	lunatest.assert_match("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0",lib.luagit2_oid_tostr_s(new_tree_id))

end

function luagit2_tree_tests.test_luagit2_tree_lookup_prefix()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup_prefix(repo,tree_id,0)
	lunatest.assert_not_nil(tree)

end

function luagit2_tree_tests.test_luagit2_tree_owner()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this tree id was obtained using git write-tree for the repository Simple-Repository
	tree_id = lib.luagit2_oid_fromstr("0e5678c4efe744fbecb1c175edd1f1d8caccfdc0")
	lunatest.assert_not_nil(tree_id)

	tree = lib.luagit2_tree_lookup(repo,tree_id)
	lunatest.assert_not_nil(tree)

	new_repo = lib.luagit2_tree_owner(tree)
	lunatest.assert_not_nil(new_repo)
end

return luagit2_tree_tests
