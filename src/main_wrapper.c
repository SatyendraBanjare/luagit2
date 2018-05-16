#include "./header_files/lua_libgit2.h"
#include "./header_files/lua_cred.h"

static const struct luaL_Reg luagit2 [] = {

      //-------------- libgit2 functions -------------------------------------------------------// 
      {"luagit2_init", lua_git_libgit2_init }, 
      {"luagit2_shutdown" , lua_git_libgit2_shutdown},
      {"luagit2_features",lua_git_libgit2_features},
      {"luagit2_version",lua_git_libgit2_version},
      {"luagit2_GET_MWINDOW_SIZE",lua_GIT_OPT_GET_MWINDOW_SIZE},
      {"luagit2_SET_MWINDOW_SIZE",lua_GIT_OPT_SET_MWINDOW_SIZE},
      {"luagit2_GET_MWINDOW_MAPPED_LIMIT",lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT},
      {"luagit2_SET_MWINDOW_MAPPED_LIMIT",lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT},
      {"luagit2_GET_SEARCH_PATH",lua_GIT_OPT_GET_SEARCH_PATH},
      {"luagit2_SET_SEARCH_PATH",lua_GIT_OPT_SET_SEARCH_PATH},
      {"luagit2_GET_CACHED_MEMORY",lua_GIT_OPT_GET_CACHED_MEMORY},
      {"luagit2_SET_CACHE_OBJECT_LIMIT",lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT},
      {"luagit2_SET_CACHE_MAX_SIZE",lua_GIT_OPT_SET_CACHE_MAX_SIZE},
      {"luagit2_ENABLE_CACHING",lua_GIT_OPT_ENABLE_CACHING},
      {"luagit2_GET_TEMPLATE_PATH",lua_GIT_OPT_GET_TEMPLATE_PATH},
      {"luagit2_SET_TEMPLATE_PATH",lua_GIT_OPT_SET_TEMPLATE_PATH},
      {"luagit2_SET_USER_AGENT",lua_GIT_OPT_SET_USER_AGENT},
      {"luagit2_GET_WINDOWS_SHAREMODE",lua_GIT_OPT_GET_WINDOWS_SHAREMODE},
      {"luagit2_SET_WINDOWS_SHAREMODE",lua_GIT_OPT_SET_WINDOWS_SHAREMODE},
      {"luagit2_ENABLE_STRICT_OBJECT_CREATION",lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION},
      {"luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION",lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION},
      {"luagit2_SET_SSL_CIPHERS",lua_GIT_OPT_SET_SSL_CIPHERS},
      {"luagit2_ENABLE_OFS_DELTA",lua_GIT_OPT_ENABLE_OFS_DELTA},
      {"luagit2_ENABLE_FSYNC_GITDIR",lua_GIT_OPT_ENABLE_FSYNC_GITDIR},
      {"luagit2_ENABLE_STRICT_HASH_VERIFICATION",lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION},
      //--------------------------------------------------------------------------------------------//

      //---------------------------  cred functions  ------------------------------------------------//
      {"luagit2_cred_default_new",lua_git_cred_default_new},

      {NULL, NULL}  
    };

int luaopen_luagit2 (lua_State *L){
luaL_register(L, "luagit2", luagit2);    
return 1;
}; 