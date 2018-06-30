#include "luagit2/libgit2/lua_libgit2.h"
#include "luagit2/cred/lua_cred.h"
#include "luagit2/config/lua_config.h"
#include "luagit2/oid/lua_oid.h"
#include "luagit2/signature/lua_signature.h"
#include "luagit2/clone/lua_clone.h"
#include "luagit2/repository/lua_repository.h"
#include "luagit2/tree/lua_tree.h"
#include "luagit2/commit/lua_commit.h"
#include "luagit2/index/lua_index.h"
#include "luagit2/reference/lua_reference.h"
#include "luagit2/branch/lua_branch.h"
#include "luagit2/blame/lua_blame.h"
#include "luagit2/blob/lua_blob.h"
#include "luagit2/tag/lua_tag.h"
#include "luagit2/object/lua_object.h"
#include "luagit2/buf/lua_buf.h"
//----------------- Helper Methods Functions --------------------//
#include "luagit2/libgit2/lua_libgit2_help.h"
#include "luagit2/signature/lua_signature_help.h"
#include "luagit2/buf/lua_buf_help.h"

static const struct luaL_Reg luagit2 [] = {

      //-------------- libgit2 functions -------------------------------------------------------//
      {"luagit2_init", lua_git_libgit2_init },
      {"luagit2_shutdown", lua_git_libgit2_shutdown},
      {"luagit2_features", lua_git_libgit2_features},
      {"luagit2_version", lua_git_libgit2_version},
      {"luagit2_GET_MWINDOW_SIZE", lua_GIT_OPT_GET_MWINDOW_SIZE},
      {"luagit2_SET_MWINDOW_SIZE", lua_GIT_OPT_SET_MWINDOW_SIZE},
      {"luagit2_GET_MWINDOW_MAPPED_LIMIT", lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT},
      {"luagit2_SET_MWINDOW_MAPPED_LIMIT", lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT},
      {"luagit2_GET_SEARCH_PATH", lua_GIT_OPT_GET_SEARCH_PATH},
      {"luagit2_SET_SEARCH_PATH", lua_GIT_OPT_SET_SEARCH_PATH},
      {"luagit2_GET_CACHED_MEMORY", lua_GIT_OPT_GET_CACHED_MEMORY},
      {"luagit2_SET_CACHE_OBJECT_LIMIT", lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT},
      {"luagit2_SET_CACHE_MAX_SIZE", lua_GIT_OPT_SET_CACHE_MAX_SIZE},
      {"luagit2_ENABLE_CACHING", lua_GIT_OPT_ENABLE_CACHING},
      {"luagit2_GET_TEMPLATE_PATH", lua_GIT_OPT_GET_TEMPLATE_PATH},
      {"luagit2_SET_TEMPLATE_PATH", lua_GIT_OPT_SET_TEMPLATE_PATH},
      {"luagit2_SET_USER_AGENT", lua_GIT_OPT_SET_USER_AGENT},
      {"luagit2_GET_WINDOWS_SHAREMODE", lua_GIT_OPT_GET_WINDOWS_SHAREMODE},
      {"luagit2_SET_WINDOWS_SHAREMODE", lua_GIT_OPT_SET_WINDOWS_SHAREMODE},
      {"luagit2_ENABLE_STRICT_OBJECT_CREATION", lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION},
      {"luagit2_ENABLE_STRICT_SYMBOLIC_REF_CREATION", lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION},
      {"luagit2_SET_SSL_CIPHERS", lua_GIT_OPT_SET_SSL_CIPHERS},
      {"luagit2_ENABLE_OFS_DELTA", lua_GIT_OPT_ENABLE_OFS_DELTA},
      {"luagit2_ENABLE_FSYNC_GITDIR", lua_GIT_OPT_ENABLE_FSYNC_GITDIR},
      {"luagit2_ENABLE_STRICT_HASH_VERIFICATION", lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION},
      //--------------------------------------------------------------------------------------------//

      //---------------------------  cred functions  ------------------------------------------------//
      {"luagit2_cred_default_new", lua_git_cred_default_new},
      {"luagit2_cred_ssh_key_from_agent", lua_git_cred_ssh_key_from_agent},
      {"luagit2_cred_ssh_key_memory_new", lua_git_cred_ssh_key_memory_new},
      {"luagit2_cred_ssh_key_new", lua_git_cred_ssh_key_new},
      {"luagit2_cred_username_new", lua_git_cred_username_new},
      {"luagit2_cred_userpass_plaintext_new", lua_git_cred_userpass_plaintext_new},
      {"luagit2_cred_free", lua_git_cred_free},
      //---------------------------------------------------------------------------------------------//

      //----------------------------- config functions ----------------------------------------------//
      {"luagit2_config_delete_entry", lua_git_config_delete_entry},
      {"luagit2_config_delete_multivar", lua_git_config_delete_multivar},
      {"luagit2_config_find_global", lua_git_config_find_global},
      {"luagit2_config_find_programdata", lua_git_config_find_programdata},
      {"luagit2_config_find_system", lua_git_config_find_system},
      {"luagit2_config_find_xdg", lua_git_config_find_xdg},
      {"luagit2_config_get_bool", lua_git_config_get_bool},
      {"luagit2_config_get_int32", lua_git_config_get_int32},
      {"luagit2_config_get_int64", lua_git_config_get_int64},
      {"luagit2_config_get_path", lua_git_config_get_path},
      {"luagit2_config_get_string", lua_git_config_get_string},
      {"luagit2_config_get_string_buf", lua_git_config_get_string_buf},
      {"luagit2_config_open_global", lua_git_config_open_global},
      {"luagit2_config_open_level", lua_git_config_open_level},
      {"luagit2_config_open_ondisk", lua_git_config_open_ondisk},
      {"luagit2_config_open_default", lua_git_config_open_default},
      {"luagit2_config_parse_bool", lua_git_config_parse_bool},
      {"luagit2_config_parse_int32", lua_git_config_parse_int32},
      {"luagit2_config_parse_int64", lua_git_config_parse_int64},
      {"luagit2_config_parse_path", lua_git_config_parse_path},
      {"luagit2_config_set_bool", lua_git_config_set_bool},
      {"luagit2_config_set_int32", lua_git_config_set_int32},
      {"luagit2_config_set_int64", lua_git_config_set_int64},
      {"luagit2_config_set_multivar", lua_git_config_set_multivar},
      {"luagit2_config_set_string", lua_git_config_set_string},
      {"luagit2_config_snapshot", lua_git_config_snapshot},
      {"luagit2_config_free",lua_git_config_free},
      //----------------------------------------------------------------------------------------------//

      //---------------------------------------- Object Id (oid) functions ---------------------------//
      {"luagit2_oid_fromstr", lua_git_oid_fromstr},
      {"luagit2_oid_fromstrn", lua_git_oid_fromstrn},
      {"luagit2_oid_cmp", lua_git_oid_cmp},
      {"luagit2_oid_fmt", lua_git_oid_fmt},
      {"luagit2_oid_ncmp", lua_git_oid_ncmp},
      {"luagit2_oid_nfmt", lua_git_oid_nfmt},
      {"luagit2_oid_pathfmt", lua_git_oid_pathfmt},
      {"luagit2_oid_iszero", lua_git_oid_iszero},
      {"luagit2_oid_strcmp", lua_git_oid_strcmp},
      {"luagit2_oid_tostr", lua_git_oid_tostr},
      {"luagit2_oid_tostr_s", lua_git_oid_tostr_s},
      //----------------------------------------------------------------------------------------------//

      //----------------------------------------- Signature functions --------------------------------//
      {"luagit2_signature_default", lua_git_signature_default},
      {"luagit2_signature_dup", lua_git_signature_dup},
      {"luagit2_signature_from_buffer", lua_git_signature_from_buffer},
      {"luagit2_signature_now", lua_git_signature_now},
      {"luagit2_signature_free", lua_git_signature_free},
      //----------------------------------------------------------------------------------------------//

      //------------------------------------------- Clone functions -----------------------------------//
      {"luagit2_clone_public", lua_git_clone_public},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Repository functions ------------------------------//
      {"luagit2_repository_commondir", lua_git_repository_commondir},
      {"luagit2_repository_config", lua_git_repository_config},
      {"luagit2_repository_config_snapshot", lua_git_repository_config_snapshot},
      {"luagit2_repository_detach_head", lua_git_repository_detach_head},
      {"luagit2_repository_get_namespace", lua_git_repository_get_namespace},
      {"luagit2_repository_head", lua_git_repository_head},
      {"luagit2_repository_head_detached", lua_git_repository_head_detached},
      {"luagit2_repository_head_for_worktree", lua_git_repository_head_for_worktree},
      {"luagit2_repository_head_unborn", lua_git_repository_head_unborn},
      {"luagit2_repository_ident", lua_git_repository_ident},
      {"luagit2_repository_index", lua_git_repository_index},
      {"luagit2_repository_init", lua_git_repository_init},
      {"luagit2_repository_is_bare", lua_git_repository_is_bare},
      {"luagit2_repository_is_empty", lua_git_repository_is_empty},
      {"luagit2_repository_is_shallow", lua_git_repository_is_shallow},
      {"luagit2_repository_is_worktree", lua_git_repository_is_worktree},
      {"luagit2_repository_message", lua_git_repository_message},
      {"luagit2_repository_message_remove", lua_git_repository_message_remove},
      {"luagit2_repository_odb", lua_git_repository_odb},
      {"luagit2_repository_open", lua_git_repository_open},
      {"luagit2_repository_open_bare", lua_git_repository_open_bare},
      {"luagit2_repository_open_from_worktree", lua_git_repository_open_from_worktree},
      {"luagit2_repository_path", lua_git_repository_path},
      {"luagit2_repository_refdb", lua_git_repository_refdb},
      {"luagit2_repository_set_head", lua_git_repository_set_head},
      {"luagit2_repository_set_head_detached", lua_git_repository_set_head_detached},
      {"luagit2_repository_set_ident", lua_git_repository_set_ident},
      {"luagit2_repository_set_namespace", lua_git_repository_set_namespace},
      {"luagit2_repository_set_workdir", lua_git_repository_set_workdir},
      {"luagit2_repository_state", lua_git_repository_state},
      {"luagit2_repository_state_cleanup", lua_git_repository_state_cleanup},
      {"luagit2_repository_workdir", lua_git_repository_workdir},
      {"luagit2_repository_free",lua_git_repository_free},
      //-----------------------------------------------------------------------------------------------//

      //-------------------------------------------- Tree functions -----------------------------------//
      {"luagit2_tree_entry_byid", lua_git_tree_entry_byid},
      {"luagit2_tree_entry_byindex", lua_git_tree_entry_byindex},
      {"luagit2_tree_entry_byname", lua_git_tree_entry_byname},
      {"luagit2_tree_entry_bypath", lua_git_tree_entry_bypath},
      {"luagit2_tree_entry_cmp", lua_git_tree_entry_cmp},
      {"luagit2_tree_entry_filemode", lua_git_tree_entry_filemode},
      {"luagit2_tree_entry_filemode_raw", lua_git_tree_entry_filemode_raw},
      {"luagit2_tree_entry_id", lua_git_tree_entry_id},
      {"luagit2_tree_entry_name", lua_git_tree_entry_name},
      {"luagit2_tree_entry_to_object", lua_git_tree_entry_to_object},
      {"luagit2_tree_entry_type", lua_git_tree_entry_type},
      {"luagit2_tree_entrycount", lua_git_tree_entrycount},
      {"luagit2_tree_id", lua_git_tree_id},
      {"luagit2_tree_lookup", lua_git_tree_lookup},
      {"luagit2_tree_lookup_prefix", lua_git_tree_lookup_prefix},
      {"luagit2_tree_owner", lua_git_tree_owner},
      {"luagit2_tree_entry_free", lua_git_tree_entry_free},
      {"luagit2_tree_free", lua_git_tree_free},
      //-----------------------------------------------------------------------------------------------//

      //--------------------------------------------- Commit functions --------------------------------//
      {"luagit2_commit_author", lua_git_commit_author},
      {"luagit2_commit_body", lua_git_commit_body},
      {"luagit2_commit_committer", lua_git_commit_committer},
      {"luagit2_commit_extract_signature", lua_git_commit_extract_signature},
      {"luagit2_commit_header_field", lua_git_commit_header_field},
      {"luagit2_commit_lookup", lua_git_commit_lookup},
      {"luagit2_commit_lookup_prefix", lua_git_commit_lookup_prefix},
      {"luagit2_commit_message", lua_git_commit_message},
      {"luagit2_commit_message_encoding", lua_git_commit_message_encoding},
      {"luagit2_commit_message_raw", lua_git_commit_message_raw},
      {"luagit2_commit_nth_gen_ancestor", lua_git_commit_nth_gen_ancestor},
      {"luagit2_commit_parent", lua_git_commit_parent},
      {"luagit2_commit_parent_id", lua_git_commit_parent_id},
      {"luagit2_commit_parentcount", lua_git_commit_parentcount},
      {"luagit2_commit_raw_header", lua_git_commit_raw_header},
      {"luagit2_commit_summary", lua_git_commit_summary},
      {"luagit2_commit_time", lua_git_commit_time},
      {"luagit2_commit_tree", lua_git_commit_tree},
      {"luagit2_commit_tree_id", lua_git_commit_tree_id},
      {"luagit2_commit_free", lua_git_commit_free},
      {"luagit2_commit_id",lua_git_commit_id},
      {"luagit2_commit_create_update_head",lua_git_commit_create_update_head},
      {"luagit2_commit_create_update_none",lua_git_commit_create_update_none},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Index methods -------------------------------------//
      {"luagit2_index_add", lua_git_index_add},
      {"luagit2_index_add_bypath", lua_git_index_add_bypath},
      {"luagit2_index_caps", lua_git_index_caps},
      {"luagit2_index_checksum", lua_git_index_checksum},
      {"luagit2_index_conflict_add", lua_git_index_conflict_add},
      {"luagit2_index_conflict_cleanup", lua_git_index_conflict_cleanup},
      {"luagit2_index_entry_is_conflict", lua_git_index_entry_is_conflict},
      {"luagit2_index_entry_stage", lua_git_index_entry_stage},
      {"luagit2_index_entrycount", lua_git_index_entrycount},
      {"luagit2_index_find", lua_git_index_find},
      {"luagit2_index_find_prefix", lua_git_index_find_prefix},
      {"luagit2_index_get_byindex", lua_git_index_get_byindex},
      {"luagit2_index_get_bypath", lua_git_index_get_bypath},
      {"luagit2_index_has_conflicts", lua_git_index_has_conflicts},
      {"luagit2_index_open", lua_git_index_open},
      {"luagit2_index_owner", lua_git_index_owner},
      {"luagit2_index_path", lua_git_index_path},
      {"luagit2_index_read", lua_git_index_read},
      {"luagit2_index_read_tree", lua_git_index_read_tree},
      {"luagit2_index_remove", lua_git_index_remove},
      {"luagit2_index_remove_bypath", lua_git_index_remove_bypath},
      {"luagit2_index_remove_directory", lua_git_index_remove_directory},
      {"luagit2_index_set_caps", lua_git_index_set_caps},
      {"luagit2_index_set_version", lua_git_index_set_version},
      {"luagit2_index_version", lua_git_index_version},
      {"luagit2_index_write", lua_git_index_write},
      {"luagit2_index_write_tree", lua_git_index_write_tree},
      {"luagit2_index_write_tree_to", lua_git_index_write_tree_to},
      {"luagit2_index_free",lua_git_index_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Reference Methods ---------------------------------//
      {"luagit2_reference_create", lua_git_reference_create},
      {"luagit2_reference_create_matching", lua_git_reference_create_matching},
      {"luagit2_reference_dup", lua_git_reference_dup},
      {"luagit2_reference_dwim", lua_git_reference_dwim},
      {"luagit2_reference_ensure_log", lua_git_reference_ensure_log},
      {"luagit2_reference_has_log", lua_git_reference_has_log},
      {"luagit2_reference_is_branch", lua_git_reference_is_branch},
      {"luagit2_reference_is_note", lua_git_reference_is_note},
      {"luagit2_reference_is_remote", lua_git_reference_is_remote},
      {"luagit2_reference_is_tag", lua_git_reference_is_tag},
      {"luagit2_reference_is_valid_name", lua_git_reference_is_valid_name},
      {"luagit2_reference_iterator_glob_new", lua_git_reference_iterator_glob_new},
      {"luagit2_reference_iterator_new", lua_git_reference_iterator_new},
      {"luagit2_reference_list", lua_git_reference_list},
      {"luagit2_reference_lookup", lua_git_reference_lookup},
      {"luagit2_reference_name", lua_git_reference_name},
      {"luagit2_reference_name_to_id", lua_git_reference_name_to_id},
      {"luagit2_reference_next", lua_git_reference_next},
      {"luagit2_reference_next_name", lua_git_reference_next_name},
      {"luagit2_reference_owner", lua_git_reference_owner},
      {"luagit2_reference_peel", lua_git_reference_peel},
      {"luagit2_reference_remove", lua_git_reference_remove},
      {"luagit2_reference_rename", lua_git_reference_rename},
      {"luagit2_reference_resolve", lua_git_reference_resolve},
      {"luagit2_reference_set_target", lua_git_reference_set_target},
      {"luagit2_reference_symbolic_create", lua_git_reference_symbolic_create},
      {"luagit2_reference_symbolic_create_matching", lua_git_reference_symbolic_create_matching},
      {"luagit2_reference_symbolic_set_target", lua_git_reference_symbolic_set_target},
      {"luagit2_reference_symbolic_target", lua_git_reference_symbolic_target},
      {"luagit2_reference_target", lua_git_reference_target},
      {"luagit2_reference_target_peel", lua_git_reference_target_peel},
      {"luagit2_reference_type", lua_git_reference_type},
      {"luagit2_reference_free",lua_git_reference_free},
      {"luagit2_reference_iterator_free",lua_git_reference_iterator_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Branch Methods ---------------------------------//
      {"luagit2_branch_create", lua_git_branch_create},
      {"luagit2_branch_create_from_annotated", lua_git_branch_create_from_annotated},
      {"luagit2_branch_delete", lua_git_branch_delete},
      {"luagit2_branch_is_checked_out", lua_git_branch_is_checked_out},
      {"luagit2_branch_is_head", lua_git_branch_is_head},
      {"luagit2_branch_iterator_new", lua_git_branch_iterator_new},
      {"luagit2_branch_lookup", lua_git_branch_lookup},
      {"luagit2_branch_move", lua_git_branch_move},
      {"luagit2_branch_name", lua_git_branch_name},
      {"luagit2_branch_next", lua_git_branch_next},
      {"luagit2_branch_set_upstream", lua_git_branch_set_upstream},
      {"luagit2_branch_upstream", lua_git_branch_upstream},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Blame Methods -------------------------------------//
      {"luagit2_blame_buffer", lua_git_blame_buffer},
      {"luagit2_blame_file", lua_git_blame_file},
      {"luagit2_blame_get_hunk_byindex", lua_git_blame_get_hunk_byindex},
      {"luagit2_blame_get_hunk_byline", lua_git_blame_get_hunk_byline},
      {"luagit2_blame_get_hunk_count", lua_git_blame_get_hunk_count},
      {"luagit2_blame_free", lua_git_blame_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------ Blob Methods ---------------------------------------//
      {"luagit2_blob_create_fromdisk", lua_git_blob_create_fromdisk},
      {"luagit2_blob_create_fromworkdir", lua_git_blob_create_fromworkdir},
      {"luagit2_blob_filtered_content", lua_git_blob_filtered_content},
      {"luagit2_blob_id", lua_git_blob_id},
      {"luagit2_blob_is_binary", lua_git_blob_is_binary},
      {"luagit2_blob_lookup", lua_git_blob_lookup},
      {"luagit2_blob_lookup_prefix", lua_git_blob_lookup_prefix},
      {"luagit2_blob_owner", lua_git_blob_owner},
      {"luagit2_blob_rawsize", lua_git_blob_rawsize},
      {"luagit2_blob_free", lua_git_blob_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------ Tag Methods ----------------------------------------//
      {"luagit2_tag_annotation_create",lua_git_tag_annotation_create},
      {"luagit2_tag_create",lua_git_tag_create},
      {"luagit2_tag_create_frombuffer",lua_git_tag_create_frombuffer},
      {"luagit2_tag_create_lightweight",lua_git_tag_create_lightweight},
      {"luagit2_tag_delete",lua_git_tag_delete},
      {"luagit2_tag_free",lua_git_tag_free},
      {"luagit2_tag_id",lua_git_tag_id},
      {"luagit2_tag_list",lua_git_tag_list},
      {"luagit2_tag_list_match",lua_git_tag_list_match},
      {"luagit2_tag_lookup",lua_git_tag_lookup},
      {"luagit2_tag_owner",lua_git_tag_owner},
      {"luagit2_tag_tagger",lua_git_tag_tagger},
      {"luagit2_tag_target",lua_git_tag_target},
      {"luagit2_tag_target_id",lua_git_tag_target_id},
      {"luagit2_tag_target_type",lua_git_tag_target_type},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Object Methods ------------------------------------//
      {"luagit2_object_size",lua_git_object__size},
      {"luagit2_object_free",lua_git_object_free},
      {"luagit2_object_id",lua_git_object_id},
      {"luagit2_object_lookup",lua_git_object_lookup},
      {"luagit2_object_lookup_bypath",lua_git_object_lookup_bypath},
      {"luagit2_object_lookup_prefix",lua_git_object_lookup_prefix},
      {"luagit2_object_owner",lua_git_object_owner},
      {"luagit2_object_short_id",lua_git_object_short_id},
      {"luagit2_object_string2type",lua_git_object_string2type},
      {"luagit2_object_type",lua_git_object_type},
      {"luagit2_object_type2string",lua_git_object_type2string},
      {"luagit2_object_typeisloose",lua_git_object_typeisloose},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Buf Methods ---------------------------------------//
      {"luagit2_buf_set_char",lua_git_buf_set_char},
      {"luagit2_buf_free",lua_git_buf_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Helper Methods ------------------------------------//
      {"luagit2_print_version_data", lua_git_libgit2_print_version_data},
      {"luagit2_get_signature_details", lua_get_signature_details},
      {"luagit2_print_complete_signature_details", lua_print_complete_signature_details},
      {"get_userdata_name",get_userdata_name},
      {"luagit2_buf_details",lua_git_buf_details},
      //-----------------------------------------------------------------------------------------------//
      {NULL, NULL}
};

int luaopen_luagit2 (lua_State *L) {
      luaL_newlib(L, luagit2);
      return 1;
};
