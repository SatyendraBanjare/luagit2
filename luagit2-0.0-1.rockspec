package = "luagit2"
version = "0.0-1"
source = {
   url = "https://github.com/SatyendraBanjare/luagit2",
}
description = {
   summary = "Updated Lua-bindings to libgit library functions.",
   homepage = "https://github.com/SatyendraBanjare/luagit2",
   license = "MIT/X11"
}
dependencies = {
   "lua == 5.3",
}

build = {
   type = "builtin",
   modules = {
      luagit2 = {
         sources = { "src/luagit2/common/lua_common.c",
                     "src/luagit2/libgit2/lua_libgit2.c",
                     "src/luagit2/libgit2/lua_libgit2_help.c",
                     "src/luagit2/blame/lua_blame.c",
                     "src/luagit2/blob/lua_blob.c",
                     "src/luagit2/branch/lua_branch.c",
                     "src/luagit2/clone/lua_clone.c",
                     "src/luagit2/commit/lua_commit.c",
                     "src/luagit2/config/lua_config.c",
                     "src/luagit2/cred/lua_cred.c",
                     "src/luagit2/index/lua_index.c",
                     "src/luagit2/oid/lua_oid.c",
                     "src/luagit2/reference/lua_reference.c",
                     "src/luagit2/repository/lua_repository.c",
                     "src/luagit2/signature/lua_signature.c",
                     "src/luagit2/signature/lua_signature_help.c",
                     "src/luagit2/tree/lua_tree.c",
                     "src/main_wrapper.c" 
                   },
         libraries = {"git2" , "lua5.3" },
      }
   },
   
}