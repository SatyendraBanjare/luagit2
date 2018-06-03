pcall(require, "luacov")
lib = require"luagit2"
print("\n successfully imported library luagit2 \n")
lunatest = require "lunatest"

lib.luagit2_init()

-- First clone an example repository to check the functions
os.execute("git clone https://github.com/SatyendraBanjare/Simple-Repository.git")

lunatest.suite("luagit2_libgit_test")
lunatest.suite("luagit2_oid_test")
lunatest.suite("luagit2_signature_test")
lunatest.suite("luagit2_tree_test")
lunatest.suite("luagit2_commit_test")
lunatest.suite("luagit2_cred_test")
lunatest.suite("luagit2_config_test")

lunatest.run()
os.execute("rm -rf ./Simple-Repository/")