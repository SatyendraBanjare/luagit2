#include "lua_libgit2.h"
#include "lua_clone.h"
#include "lua_repository.h"
#include "lua_blame.h"
#include "initialize.h"

static const struct luaL_Reg luagit2 [] = {
      // libgit2 Functions
      {"lua_git_libgit2_init", lua_git_libgit2_init }, 
      {"lua_git_libgit2_shutdown" , lua_git_libgit2_shutdown},

      // repository Functions
      {"lua_git_repository_init",lua_git_repository_init},
      
      //{"lua_git_repository_init_ext",lua_git_repository_init_ext},         <- removing this as of now because this is having some errors.
      
      {"lua_git_repository_is_bare",lua_git_repository_is_bare},
      {"lua_git_repository_is_empty",lua_git_repository_is_empty},
      {"lua_git_repository_is_worktree",lua_git_repository_is_worktree},
      {"lua_git_repository_is_shallow",lua_git_repository_is_shallow},
      {"lua_git_repository_set_bare",lua_git_repository_set_bare},
      {"lua_git_repository_set_head",lua_git_repository_set_head},
      {"lua_git_repository_set_ident",lua_git_repository_set_ident},
      {"lua_git_repository_state",lua_git_repository_state},
      {"lua_git_repository_state_cleanup",lua_git_repository_state_cleanup},
     
      // blame Functions
      {"lua_git_blame_file" , lua_git_blame_file},	

      // clone Functions 
      {"lua_git_clone",lua_git_clone},

      // Initialzer function to one time initialize things.	
      {"lua_initialize",lua_initialize},
      {"lua_get_initial_repo_path",lua_get_initial_repo_path},
      {NULL, NULL}  
    };



int luaopen_luagit2 (lua_State *L){
luaL_register(L, "luagit2", luagit2);    
return 1;
}; 

