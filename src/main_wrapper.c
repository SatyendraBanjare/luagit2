#include "./header_files/lua_libgit2.h"
#include "./header_files/lua_cred.h"
#include "./header_files/lua_config.h"
#include "./header_files/lua_oid.h"

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
      {"luagit2_cred_ssh_key_from_agent",lua_git_cred_ssh_key_from_agent},
      {"luagit2_cred_ssh_key_memory_new",lua_git_cred_ssh_key_memory_new},
      {"luagit2_cred_ssh_key_new",lua_git_cred_ssh_key_new},
      {"luagit2_cred_username_new",lua_git_cred_username_new},
      {"luagit2_cred_userpass_plaintext_new",lua_git_cred_userpass_plaintext_new},
      //---------------------------------------------------------------------------------------------//

      //----------------------------- config functions ----------------------------------------------//
      {"luagit2_config_delete_entry",lua_git_config_delete_entry},
      {"luagit2_config_delete_multivar",lua_git_config_delete_multivar},
      {"luagit2_config_find_global",lua_git_config_find_global},
      {"luagit2_config_find_programdata",lua_git_config_find_programdata},
      {"luagit2_config_find_system",lua_git_config_find_system},
      {"luagit2_config_find_xdg",lua_git_config_find_xdg},
      {"luagit2_config_get_bool",lua_git_config_get_bool},
      {"luagit2_config_get_int32",lua_git_config_get_int32},
      {"luagit2_config_get_int64",lua_git_config_get_int64},
      {"luagit2_config_get_path",lua_git_config_get_path},
      {"luagit2_config_get_string",lua_git_config_get_string},
      {"luagit2_config_get_string_buf",lua_git_config_get_string_buf},
      {"luagit2_config_open_global",lua_git_config_open_global},
      {"luagit2_config_open_level",lua_git_config_open_level},
      {"luagit2_config_open_ondisk",lua_git_config_open_ondisk},
      {"luagit2_config_open_default",lua_git_config_open_default},
      {"luagit2_config_parse_bool",lua_git_config_parse_bool},
      {"luagit2_config_parse_int32",lua_git_config_parse_int32},
      {"luagit2_config_parse_int64",lua_git_config_parse_int64},
      {"luagit2_config_parse_path",lua_git_config_parse_path},
      {"luagit2_config_set_bool",lua_git_config_set_bool},
      {"luagit2_config_set_int32",lua_git_config_set_int32},
      {"luagit2_config_set_int64",lua_git_config_set_int64},
      {"luagit2_config_set_multivar",lua_git_config_set_multivar},
      {"luagit2_config_set_string",lua_git_config_set_string},
      {"luagit2_config_snapshot",lua_git_config_snapshot},
      //----------------------------------------------------------------------------------------------//

      //---------------------------------------- Object Id (oid) functions ---------------------------//
      {"luagit2_oid_fromstr",lua_git_oid_fromstr},
      {"luagit2_oid_fromstrn",lua_git_oid_fromstrn},
      {"luagit2_oid_cmp",lua_git_oid_cmp},
      {"luagit2_oid_ncmp",lua_git_oid_ncmp},
      {"luagit2_oid_nfmt",lua_git_oid_nfmt},
      {"luagit2_oid_pathfmt",lua_git_oid_pathfmt},
      {"luagit2_oid_iszero",lua_git_oid_iszero},
      {"luagit2_oid_strcmp",lua_git_oid_strcmp},
      //----------------------------------------------------------------------------------------------//
      {NULL, NULL}  
    };

int luaopen_luagit2 (lua_State *L){
luaL_register(L, "luagit2", luagit2);    
return 1;
}; 