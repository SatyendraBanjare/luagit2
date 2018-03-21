package = "luagit2"
version = "0.0-1"
source = {
   url = "https://github.com/SatyendraBanjare/luagit2",
}
description = {
   summary = "Prototype Lua-bindings model on Updated libgit library functions.",
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
         sources = {"binding_main.c" , "common.c"},
         libraries = {"git2" , "lua5.1"},
      }
   },
   
}