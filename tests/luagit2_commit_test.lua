-- @module luagit2_commit_test
local luagit2_commit_tests = {}

function luagit2_commit_tests.test_luagit2_commit_author()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	author_signature = lib.luagit2_commit_author(commit)
	lunatest.assert_not_nil(author_signature)
	lunatest.assert_equal("Satyendra_Kumar_Banjare" , lib.luagit2_get_signature_details(author_signature,1))
	lunatest.assert_equal("satyendrabanjare99@gmail.com" , lib.luagit2_get_signature_details(author_signature,2))
end

function luagit2_commit_tests.test_luagit2_commit_body()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id_nil_body = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id_nil_body)

	commit_with_nil_body = lib.luagit2_commit_lookup(repo,commit_id_nil_body)
	lunatest.assert_not_nil(commit_with_nil_body)

	commit_body_is_nil = lib.luagit2_commit_body(commit_with_nil_body)
	lunatest.assert_nil(commit_body_is_nil)

	commit_id_non_nil_body = lib.luagit2_oid_fromstr("15a746e5e897349f7fd9a3e7308eb0c7c7e0c010")
	lunatest.assert_not_nil(commit_id_non_nil_body)

	commit_with_non_nil_body = lib.luagit2_commit_lookup(repo,commit_id_non_nil_body)
	lunatest.assert_not_nil(commit_with_non_nil_body)

	commit_body_is_not_nil = lib.luagit2_commit_body(commit_with_non_nil_body)
	lunatest.assert_not_nil(commit_body_is_not_nil)
	lunatest.assert_string(commit_body_is_not_nil)

end

function luagit2_commit_tests.test_luagit2_commit_committer()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	committer_signature = lib.luagit2_commit_committer(commit)
	lunatest.assert_not_nil(committer_signature)
	lunatest.assert_equal("Satyendra_Kumar_Banjare" , lib.luagit2_get_signature_details(committer_signature,1))
	lunatest.assert_equal("satyendrabanjare99@gmail.com" , lib.luagit2_get_signature_details(committer_signature,2))
end

function luagit2_commit_tests.test_luagit2_commit_message()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	commit_message = lib.luagit2_commit_message(commit)
	lunatest.assert_not_nil(commit_message)
	lunatest.assert_string(commit_message)
end

function luagit2_commit_tests.test_luagit2_commit_message_encoding()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	commit_message_enc = lib.luagit2_commit_message_encoding(commit)
	lunatest.assert_nil(commit_message_enc) -- there is no encoding to the message so it should be nil.
end

function luagit2_commit_tests.test_luagit2_commit_message_raw()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	commit_message_raw = lib.luagit2_commit_message_raw(commit)
	lunatest.assert_not_nil(commit_message_raw)
	lunatest.assert_string(commit_message_raw)
end

function luagit2_commit_tests.test_luagit2_commit_nth_gen_ancestor()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	ancestor_commit = lib.luagit2_commit_nth_gen_ancestor(commit,1)
	lunatest.assert_not_nil(ancestor_commit)
end

function luagit2_commit_tests.test_luagit2_commit_parent()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	parent_commit = lib.luagit2_commit_parent(commit,0)
	lunatest.assert_not_nil(parent_commit)
end

function luagit2_commit_tests.test_luagit2_commit_parent_id()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	parent_commit_id = lib.luagit2_commit_parent_id(commit,0)
	lunatest.assert_not_nil(parent_commit_id)
end

function luagit2_commit_tests.test_luagit2_commit_parentcount()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	parent_count = lib.luagit2_commit_parentcount(commit)
	lunatest.assert_not_nil(parent_count)
	lunatest.assert_number(parent_count)
end

function luagit2_commit_tests.test_luagit2_commit_raw_header()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	header = lib.luagit2_commit_raw_header(commit)
	lunatest.assert_not_nil(header)
	lunatest.assert_string(header)
end

function luagit2_commit_tests.test_luagit2_commit_summary()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	summary = lib.luagit2_commit_summary(commit)
	lunatest.assert_not_nil(summary)
	lunatest.assert_string(summary)
end

function luagit2_commit_tests.test_luagit2_commit_time()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	commit_time = lib.luagit2_commit_time(commit)
	lunatest.assert_not_nil(commit_time)
end

function luagit2_commit_tests.test_luagit2_commit_tree()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	commit_tree = lib.luagit2_commit_tree(commit)
	lunatest.assert_not_nil(commit_tree)
end

function luagit2_commit_tests.test_luagit2_commit_tree_id()
	repo = lib.luagit2_repository_open("./Simple-Repository")
	lunatest.assert_not_nil(repo)
	-- this is an example commit id for a commit in the repository Simple-Repository
	commit_id = lib.luagit2_oid_fromstr("bb300684ed4da2e11104a98ff4d825d81787ad3a")
	lunatest.assert_not_nil(commit_id)

	commit = lib.luagit2_commit_lookup(repo,commit_id)
	lunatest.assert_not_nil(commit)

	commit_tree_id = lib.luagit2_commit_tree_id(commit)
	lunatest.assert_not_nil(commit_tree_id)
end

return luagit2_commit_tests
