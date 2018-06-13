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
   "lua >= 5.1, < 5.4",
}

build = {
   type = "builtin",
   modules = {
      luagit2 = {
         sources = {"src/main_wrapper.c" },
         libraries = {"git2" , "lua5.1" , "lua5.2" , "lua5.3" },
      }
   },
   
}