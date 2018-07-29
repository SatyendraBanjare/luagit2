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
#include "luagit2/revert/lua_revert.h"
#include "luagit2/reflog/lua_reflog.h"
#include "luagit2/describe/lua_describe.h"
#include "luagit2/checkout/lua_checkout.h"
#include "luagit2/reset/lua_reset.h"
#include "luagit2/annotated/lua_annotated.h"
//----------------- Helper Methods Functions --------------------//
#include "luagit2/signature/lua_signature_help.h"
#include "luagit2/buf/lua_buf_help.h"
#include "luagit2/branch/lua_branch_help.h"
#include "luagit2/config/lua_config_help.h"
#include "luagit2/cred/lua_cred_help.h"
#include "luagit2/index/lua_index_help.h"

static const struct luaL_Reg luagit2 [] = {

      //-------------- libgit2 functions -------------------------------------------------------//
      {"init", lua_git_libgit2_init },
      {"shutdown", lua_git_libgit2_shutdown},
      {"libgit2_features", lua_git_libgit2_features},
      {"libgit2_version", lua_git_libgit2_version},
      {"get_mwindow_size", lua_GIT_OPT_GET_MWINDOW_SIZE},
      {"set_mwindow_size", lua_GIT_OPT_SET_MWINDOW_SIZE},
      {"get_mwindow_mapped_limit", lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT},
      {"set_mwindow_mapped_limit", lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT},
      {"get_search_path", lua_GIT_OPT_GET_SEARCH_PATH},
      {"set_search_path", lua_GIT_OPT_SET_SEARCH_PATH},
      {"get_cached_memory", lua_GIT_OPT_GET_CACHED_MEMORY},
      {"set_cache_object_limit", lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT},
      {"set_cache_max_size", lua_GIT_OPT_SET_CACHE_MAX_SIZE},
      {"enable_caching", lua_GIT_OPT_ENABLE_CACHING},
      {"get_template_path", lua_GIT_OPT_GET_TEMPLATE_PATH},
      {"set_template_path", lua_GIT_OPT_SET_TEMPLATE_PATH},
      {"set_user_agent", lua_GIT_OPT_SET_USER_AGENT},
      {"get_windows_sharemode", lua_GIT_OPT_GET_WINDOWS_SHAREMODE},
      {"set_windows_sharemode", lua_GIT_OPT_SET_WINDOWS_SHAREMODE},
      {"enable_strict_object_creation", lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION},
      {"enable_strict_symbolic_ref_creation", lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION},
      {"set_ssl_ciphers", lua_GIT_OPT_SET_SSL_CIPHERS},
      {"enable_ofs_delta", lua_GIT_OPT_ENABLE_OFS_DELTA},
      {"enable_fsync_gitdir", lua_GIT_OPT_ENABLE_FSYNC_GITDIR},
      {"enable_strict_hash_verification", lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION},
      //--------------------------------------------------------------------------------------------//

      //---------------------------  cred functions  ------------------------------------------------//
      {"cred_default_new", lua_git_cred_default_new},
      {"cred_ssh_key_from_agent", lua_git_cred_ssh_key_from_agent},
      {"cred_ssh_key_memory_new", lua_git_cred_ssh_key_memory_new},
      {"cred_ssh_key_new", lua_git_cred_ssh_key_new},
      {"cred_username_new", lua_git_cred_username_new},
      {"cred_userpass_plaintext_new", lua_git_cred_userpass_plaintext_new},
      {"cred_free", lua_git_cred_free},
      //---------------------------------------------------------------------------------------------//

      //----------------------------- config functions ----------------------------------------------//
      {"config_delete_entry", lua_git_config_delete_entry},
      {"config_delete_multivar", lua_git_config_delete_multivar},
      {"config_find_global", lua_git_config_find_global},
      {"config_find_programdata", lua_git_config_find_programdata},
      {"config_find_system", lua_git_config_find_system},
      {"config_find_xdg", lua_git_config_find_xdg},
      {"config_get_bool", lua_git_config_get_bool},
      {"config_get_int32", lua_git_config_get_int32},
      {"config_get_int64", lua_git_config_get_int64},
      {"config_get_path", lua_git_config_get_path},
      {"config_get_string", lua_git_config_get_string},
      {"config_get_string_buf", lua_git_config_get_string_buf},
      {"config_open_global", lua_git_config_open_global},
      {"config_open_level", lua_git_config_open_level},
      {"config_open_ondisk", lua_git_config_open_ondisk},
      {"config_open_default", lua_git_config_open_default},
      {"config_parse_bool", lua_git_config_parse_bool},
      {"config_parse_int32", lua_git_config_parse_int32},
      {"config_parse_int64", lua_git_config_parse_int64},
      {"config_parse_path", lua_git_config_parse_path},
      {"config_set_bool", lua_git_config_set_bool},
      {"config_set_int32", lua_git_config_set_int32},
      {"config_set_int64", lua_git_config_set_int64},
      {"config_set_multivar", lua_git_config_set_multivar},
      {"config_set_string", lua_git_config_set_string},
      {"config_snapshot", lua_git_config_snapshot},
      {"config_free", lua_git_config_free},
      {"config_add_file_ondisk",lua_git_config_add_file_ondisk},
      {"config_new",lua_git_config_new},
      {"config_iterator_new",lua_git_config_iterator_new},
      {"config_entry_free",lua_git_config_entry_free},
      {"config_get_entry",lua_git_config_get_entry},
      {"config_next",lua_git_config_next},
      {"config_iterator_free",lua_git_config_iterator_free},
      //----------------------------------------------------------------------------------------------//

      //---------------------------------------- Object Id (oid) functions ---------------------------//
      {"oid_fromstr", lua_git_oid_fromstr},
      {"oid_fromstrn", lua_git_oid_fromstrn},
      {"oid_cmp", lua_git_oid_cmp},
      {"oid_fmt", lua_git_oid_fmt},
      {"oid_ncmp", lua_git_oid_ncmp},
      {"oid_nfmt", lua_git_oid_nfmt},
      {"oid_pathfmt", lua_git_oid_pathfmt},
      {"oid_iszero", lua_git_oid_iszero},
      {"oid_strcmp", lua_git_oid_strcmp},
      {"oid_tostr", lua_git_oid_tostr},
      {"oid_tostr_s", lua_git_oid_tostr_s},
      //----------------------------------------------------------------------------------------------//

      //----------------------------------------- Signature functions --------------------------------//
      {"signature_default", lua_git_signature_default},
      {"signature_dup", lua_git_signature_dup},
      {"signature_from_buffer", lua_git_signature_from_buffer},
      {"signature_now", lua_git_signature_now},
      {"signature_free", lua_git_signature_free},
      //----------------------------------------------------------------------------------------------//

      //------------------------------------------- Clone functions -----------------------------------//
      {"clone_public", lua_git_clone_public},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Repository functions ------------------------------//
      {"repository_commondir", lua_git_repository_commondir},
      {"repository_config", lua_git_repository_config},
      {"repository_config_snapshot", lua_git_repository_config_snapshot},
      {"repository_detach_head", lua_git_repository_detach_head},
      {"repository_get_namespace", lua_git_repository_get_namespace},
      {"repository_head", lua_git_repository_head},
      {"repository_head_detached", lua_git_repository_head_detached},
      {"repository_head_for_worktree", lua_git_repository_head_for_worktree},
      {"repository_head_unborn", lua_git_repository_head_unborn},
      {"repository_ident", lua_git_repository_ident},
      {"repository_index", lua_git_repository_index},
      {"repository_init", lua_git_repository_init},
      {"repository_is_bare", lua_git_repository_is_bare},
      {"repository_is_empty", lua_git_repository_is_empty},
      {"repository_is_shallow", lua_git_repository_is_shallow},
      {"repository_is_worktree", lua_git_repository_is_worktree},
      {"repository_message", lua_git_repository_message},
      {"repository_message_remove", lua_git_repository_message_remove},
      {"repository_odb", lua_git_repository_odb},
      {"repository_open", lua_git_repository_open},
      {"repository_open_bare", lua_git_repository_open_bare},
      {"repository_open_from_worktree", lua_git_repository_open_from_worktree},
      {"repository_path", lua_git_repository_path},
      {"repository_refdb", lua_git_repository_refdb},
      {"repository_set_head", lua_git_repository_set_head},
      {"repository_set_head_detached", lua_git_repository_set_head_detached},
      {"repository_set_ident", lua_git_repository_set_ident},
      {"repository_set_namespace", lua_git_repository_set_namespace},
      {"repository_set_workdir", lua_git_repository_set_workdir},
      {"repository_state", lua_git_repository_state},
      {"repository_state_cleanup", lua_git_repository_state_cleanup},
      {"repository_workdir", lua_git_repository_workdir},
      {"repository_free", lua_git_repository_free},
      {"repository_submodule_cache_all",lua_git_repository_submodule_cache_all},
      {"repository_submodule_cache_clear",lua_git_repository_submodule_cache_clear},
      {"repository_set_index",lua_git_repository_set_index},
      {"repository_set_bare",lua_git_repository_set_bare},
      {"repository_set_config",lua_git_repository_set_config},
      {"repository_set_odb",lua_git_repository_set_odb},
      {"repository_cleanup",lua_git_repository__cleanup},
      //-----------------------------------------------------------------------------------------------//

      //-------------------------------------------- Tree functions -----------------------------------//
      {"tree_entry_byid", lua_git_tree_entry_byid},
      {"tree_entry_byindex", lua_git_tree_entry_byindex},
      {"tree_entry_byname", lua_git_tree_entry_byname},
      {"tree_entry_bypath", lua_git_tree_entry_bypath},
      {"tree_entry_cmp", lua_git_tree_entry_cmp},
      {"tree_entry_filemode", lua_git_tree_entry_filemode},
      {"tree_entry_filemode_raw", lua_git_tree_entry_filemode_raw},
      {"tree_entry_id", lua_git_tree_entry_id},
      {"tree_entry_name", lua_git_tree_entry_name},
      {"tree_entry_to_object", lua_git_tree_entry_to_object},
      {"tree_entry_type", lua_git_tree_entry_type},
      {"tree_entrycount", lua_git_tree_entrycount},
      {"tree_id", lua_git_tree_id},
      {"tree_lookup", lua_git_tree_lookup},
      {"tree_lookup_prefix", lua_git_tree_lookup_prefix},
      {"tree_owner", lua_git_tree_owner},
      {"tree_entry_free", lua_git_tree_entry_free},
      {"tree_free", lua_git_tree_free},
      //-----------------------------------------------------------------------------------------------//

      //--------------------------------------------- Commit functions --------------------------------//
      {"commit_author", lua_git_commit_author},
      {"commit_body", lua_git_commit_body},
      {"commit_committer", lua_git_commit_committer},
      {"commit_extract_signature", lua_git_commit_extract_signature},
      {"commit_header_field", lua_git_commit_header_field},
      {"commit_lookup", lua_git_commit_lookup},
      {"commit_lookup_prefix", lua_git_commit_lookup_prefix},
      {"commit_message", lua_git_commit_message},
      {"commit_message_encoding", lua_git_commit_message_encoding},
      {"commit_message_raw", lua_git_commit_message_raw},
      {"commit_nth_gen_ancestor", lua_git_commit_nth_gen_ancestor},
      {"commit_parent", lua_git_commit_parent},
      {"commit_parent_id", lua_git_commit_parent_id},
      {"commit_parentcount", lua_git_commit_parentcount},
      {"commit_raw_header", lua_git_commit_raw_header},
      {"commit_summary", lua_git_commit_summary},
      {"commit_time", lua_git_commit_time},
      {"commit_tree", lua_git_commit_tree},
      {"commit_tree_id", lua_git_commit_tree_id},
      {"commit_free", lua_git_commit_free},
      {"commit_id", lua_git_commit_id},
      {"commit_create_update_head", lua_git_commit_create_update_head},
      {"commit_create_update_none", lua_git_commit_create_update_none},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Index methods -------------------------------------//
      {"index_add", lua_git_index_add},
      {"index_add_bypath", lua_git_index_add_bypath},
      {"index_caps", lua_git_index_caps},
      {"index_checksum", lua_git_index_checksum},
      {"index_conflict_add", lua_git_index_conflict_add},
      {"index_conflict_cleanup", lua_git_index_conflict_cleanup},
      {"index_entry_is_conflict", lua_git_index_entry_is_conflict},
      {"index_entry_stage", lua_git_index_entry_stage},
      {"index_entrycount", lua_git_index_entrycount},
      {"index_find", lua_git_index_find},
      {"index_find_prefix", lua_git_index_find_prefix},
      {"index_get_byindex", lua_git_index_get_byindex},
      {"index_get_bypath", lua_git_index_get_bypath},
      {"index_has_conflicts", lua_git_index_has_conflicts},
      {"index_open", lua_git_index_open},
      {"index_owner", lua_git_index_owner},
      {"index_path", lua_git_index_path},
      {"index_read", lua_git_index_read},
      {"index_read_tree", lua_git_index_read_tree},
      {"index_remove", lua_git_index_remove},
      {"index_remove_bypath", lua_git_index_remove_bypath},
      {"index_remove_directory", lua_git_index_remove_directory},
      {"index_set_caps", lua_git_index_set_caps},
      {"index_set_version", lua_git_index_set_version},
      {"index_version", lua_git_index_version},
      {"index_write", lua_git_index_write},
      {"index_write_tree", lua_git_index_write_tree},
      {"index_write_tree_to", lua_git_index_write_tree_to},
      {"index_free", lua_git_index_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Reference Methods ---------------------------------//
      {"reference_create", lua_git_reference_create},
      {"reference_create_matching", lua_git_reference_create_matching},
      {"reference_dup", lua_git_reference_dup},
      {"reference_dwim", lua_git_reference_dwim},
      {"reference_ensure_log", lua_git_reference_ensure_log},
      {"reference_has_log", lua_git_reference_has_log},
      {"reference_is_branch", lua_git_reference_is_branch},
      {"reference_is_note", lua_git_reference_is_note},
      {"reference_is_remote", lua_git_reference_is_remote},
      {"reference_is_tag", lua_git_reference_is_tag},
      {"reference_is_valid_name", lua_git_reference_is_valid_name},
      {"reference_iterator_glob_new", lua_git_reference_iterator_glob_new},
      {"reference_iterator_new", lua_git_reference_iterator_new},
      {"reference_list", lua_git_reference_list},
      {"reference_lookup", lua_git_reference_lookup},
      {"reference_name", lua_git_reference_name},
      {"reference_name_to_id", lua_git_reference_name_to_id},
      {"reference_next", lua_git_reference_next},
      {"reference_next_name", lua_git_reference_next_name},
      {"reference_owner", lua_git_reference_owner},
      {"reference_peel", lua_git_reference_peel},
      {"reference_remove", lua_git_reference_remove},
      {"reference_rename", lua_git_reference_rename},
      {"reference_resolve", lua_git_reference_resolve},
      {"reference_set_target", lua_git_reference_set_target},
      {"reference_symbolic_create", lua_git_reference_symbolic_create},
      {"reference_symbolic_create_matching", lua_git_reference_symbolic_create_matching},
      {"reference_symbolic_set_target", lua_git_reference_symbolic_set_target},
      {"reference_symbolic_target", lua_git_reference_symbolic_target},
      {"reference_target", lua_git_reference_target},
      {"reference_target_peel", lua_git_reference_target_peel},
      {"reference_type", lua_git_reference_type},
      {"reference_free", lua_git_reference_free},
      {"reference_iterator_free", lua_git_reference_iterator_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Branch Methods ---------------------------------//
      {"branch_create", lua_git_branch_create},
      {"branch_create_from_annotated", lua_git_branch_create_from_annotated},
      {"branch_delete", lua_git_branch_delete},
      {"branch_is_checked_out", lua_git_branch_is_checked_out},
      {"branch_is_head", lua_git_branch_is_head},
      {"branch_iterator_new", lua_git_branch_iterator_new},
      {"branch_lookup", lua_git_branch_lookup},
      {"branch_move", lua_git_branch_move},
      {"branch_name", lua_git_branch_name},
      {"branch_next", lua_git_branch_next},
      {"branch_set_upstream", lua_git_branch_set_upstream},
      {"branch_upstream", lua_git_branch_upstream},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Blame Methods -------------------------------------//
      {"blame_buffer", lua_git_blame_buffer},
      {"blame_file", lua_git_blame_file},
      {"blame_get_hunk_byindex", lua_git_blame_get_hunk_byindex},
      {"blame_get_hunk_byline", lua_git_blame_get_hunk_byline},
      {"blame_get_hunk_count", lua_git_blame_get_hunk_count},
      {"blame_free", lua_git_blame_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------ Blob Methods ---------------------------------------//
      {"blob_create_fromdisk", lua_git_blob_create_fromdisk},
      {"blob_create_fromworkdir", lua_git_blob_create_fromworkdir},
      {"blob_filtered_content", lua_git_blob_filtered_content},
      {"blob_id", lua_git_blob_id},
      {"blob_is_binary", lua_git_blob_is_binary},
      {"blob_lookup", lua_git_blob_lookup},
      {"blob_lookup_prefix", lua_git_blob_lookup_prefix},
      {"blob_owner", lua_git_blob_owner},
      {"blob_rawsize", lua_git_blob_rawsize},
      {"blob_free", lua_git_blob_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------ Tag Methods ----------------------------------------//
      {"tag_annotation_create", lua_git_tag_annotation_create},
      {"tag_create", lua_git_tag_create},
      {"tag_create_frombuffer", lua_git_tag_create_frombuffer},
      {"tag_create_lightweight", lua_git_tag_create_lightweight},
      {"tag_delete", lua_git_tag_delete},
      {"tag_free", lua_git_tag_free},
      {"tag_id", lua_git_tag_id},
      {"tag_list", lua_git_tag_list},
      {"tag_list_match", lua_git_tag_list_match},
      {"tag_lookup", lua_git_tag_lookup},
      {"tag_owner", lua_git_tag_owner},
      {"tag_tagger", lua_git_tag_tagger},
      {"tag_target", lua_git_tag_target},
      {"tag_target_id", lua_git_tag_target_id},
      {"tag_target_type", lua_git_tag_target_type},
      {"tag_message",lua_git_tag_message},
      {"tag_name",lua_git_tag_name},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Object Methods ------------------------------------//
      {"object_size", lua_git_object__size},
      {"object_free", lua_git_object_free},
      {"object_id", lua_git_object_id},
      {"object_lookup", lua_git_object_lookup},
      {"object_lookup_bypath", lua_git_object_lookup_bypath},
      {"object_lookup_prefix", lua_git_object_lookup_prefix},
      {"object_owner", lua_git_object_owner},
      {"object_short_id", lua_git_object_short_id},
      {"object_string2type", lua_git_object_string2type},
      {"object_type", lua_git_object_type},
      {"object_type2string", lua_git_object_type2string},
      {"object_typeisloose", lua_git_object_typeisloose},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Buf Methods ---------------------------------------//
      {"buf_set_str", lua_git_buf_set_str},
      {"buf_free", lua_git_buf_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- revert methods ------------------------------------//
      {"revert",lua_git_revert},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Reflog Methods ------------------------------------//
      {"reflog_read",lua_git_reflog_read},
      {"reflog_entrycount",lua_git_reflog_entrycount},
      {"reflog_free",lua_git_reflog_free},
      {"reflog_entry_byindex",lua_git_reflog_entry_byindex},
      {"reflog_entry_committer",lua_git_reflog_entry_committer},
      {"reflog_entry_message",lua_git_reflog_entry_message},
      {"reflog_entry_id_new",lua_git_reflog_entry_id_new},
      {"reflog_entry_id_old",lua_git_reflog_entry_id_old},
      {"reflog_delete",lua_git_reflog_delete},
      {"reflog_drop",lua_git_reflog_drop},
      {"reflog_append",lua_git_reflog_append},
      //-----------------------------------------------------------------------------------------------//


      //------------------------------------------- Describe Mehthods ---------------------------------//
      {"describe_commit",lua_git_describe_commit},
      {"describe_workdir",lua_git_describe_workdir},
      {"describe_format",lua_git_describe_format},
      {"describe_result_free",lua_git_describe_result_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------ Checkout Methods------------------------------------//
      {"checkout_init_options",lua_git_checkout_init_options},
      {"checkout_head",lua_git_checkout_head},
      {"checkout_index",lua_git_checkout_index},
      {"checkout_tree",lua_git_checkout_tree},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------ Reset Methods --------------------------------------//
      {"reset",lua_git_reset},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Annotated Methods ---------------------------------//
      {"annotated_commit_from_ref",lua_git_annotated_commit_from_ref},
      {"annotated_commit_from_revspec",lua_git_annotated_commit_from_revspec},
      {"annotated_commit_lookup",lua_git_annotated_commit_lookup},
      {"annotated_commit_from_fetchhead",lua_git_annotated_commit_from_fetchhead},
      {"annotated_commit_id",lua_git_annotated_commit_id},
      {"annotated_commit_free",lua_git_annotated_commit_free},
      //-----------------------------------------------------------------------------------------------//

      //------------------------------------------- Helper Methods ------------------------------------//
      {"get_signature_details", lua_get_signature_details},
      {"print_complete_signature_details", lua_print_complete_signature_details},
      {"get_userdata_name", get_userdata_name},
      {"buf_details", lua_git_buf_details},
      {"get_type_GIT_BRANCH_LOCAL", get_type_GIT_BRANCH_LOCAL},
      {"get_type_GIT_BRANCH_REMOTE", get_type_GIT_BRANCH_REMOTE},
      {"config_level_program_data", lua_get_config_level_program_data},
      {"config_level_system", lua_get_config_level_system},
      {"config_level_global", lua_get_config_level_global},
      {"config_level_xdg", lua_get_config_level_xdg},
      {"config_level_local",lua_get_config_level_local},
      {"config_entry_name",lua_get_config_entry_name},
      {"config_entry_value",lua_get_config_entry_value},
      {"cred_username_details",lua_git_cred_username_details},
      {"cred_userpass_details",lua_git_cred_userpass_details},
      {"cred_ssh_key_from_agent_details",lua_git_cred_ssh_key_from_agent_details},
      {"index_entry_get_path",lua_git_index_entry_get_path},
      {"index_entry_get_filemode",lua_git_index_entry_get_filemode},
      {"index_entry_get_filesize",lua_git_index_entry_get_filesize},
      {"index_entry_get_stage",lua_git_index_entry_get_stage},
      {"index_entry_get_oid_str",lua_git_index_entry_get_oid_str},
      {"index_entry_get_dev_inode",lua_git_index_entry_get_dev_inode},
      {"index_entry_get_UID_GID",lua_git_index_entry_get_UID_GID},
      //-----------------------------------------------------------------------------------------------//
      {NULL, NULL}
};

int luaopen_luagit2 (lua_State *L) {
      luaL_newlib(L, luagit2);
      return 1;
};
