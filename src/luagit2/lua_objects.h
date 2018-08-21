#ifndef _lua_objects_h
#define _lua_objects_h

#include <git2.h>

typedef struct {
	git_cred *git_cred_object;
} luagit2_cred_object;

typedef struct {
	git_buf *buf;
} luagit2_buf;

typedef struct {
	git_config *cfg;
} luagit2_config;

typedef struct {
	git_oid oid;
} luagit2_oid;

typedef struct {
	git_commit *commit;
} luagit2_commit;

typedef struct {
	git_signature *sign;
} luagit2_signature;

typedef struct {
	git_tree *tree;
} luagit2_tree;

typedef struct {
	git_repository *repo;
} luagit2_repository;

typedef struct {
	git_index *index;
} luagit2_index;

typedef struct {
	git_tree_entry *tree_entry;
} luagit2_tree_entry;

typedef struct {
	git_tree_update *tree_update;
} luagit2_tree_update;

typedef struct {
	git_object *object;
} luagit2_object;

typedef struct {
	git_otype otype;
} luagit2_otype;

typedef struct {
	git_filemode_t filemode;
} luagit2_filemode;

typedef struct {
	git_reference *reference;
} luagit2_reference;

typedef struct {
	git_odb *odb;
} luagit2_odb;

typedef struct {
	git_worktree *worktree;
} luagit2_worktree;

typedef struct {
	git_refdb *refdb;
} luagit2_refdb;

typedef struct {
	git_reference_iterator *iterator;
} luagit2_reference_iterator;

typedef struct {
	git_strarray array;
} luagit2_strarray;

typedef struct {
	git_ref_t ref_type;
} luagit2_ref_type;

typedef struct {
	git_annotated_commit *annotated_commit;
} luagit2_annotated_commit;

typedef struct {
	git_branch_t branch_type;
} luagit2_branch_type;

typedef struct {
	git_branch_iterator *branch_iterator;
} luagit2_branch_iterator;

typedef struct {
	git_blame *blame;
} luagit2_blame;

typedef struct {
	git_blame_hunk *blame_hunk;
} luagit2_blame_hunk;

typedef struct {
	git_blob *blob;
} luagit2_blob;

typedef struct {
	git_off_t size;
} luagit2_off_t;

typedef struct {
	git_index_entry *index_entry;
} luagit2_index_entry;

typedef struct {
	git_index_conflict_iterator *index_conflict_iterator;
} luagit2_index_conflict_iterator;

typedef struct {
	git_config_level_t level;
} luagit2_config_level_t;

typedef struct {
	git_tag *tag;
} luagit2_tag;

typedef struct {
	git_config_entry *config_entry;
} luagit2_config_entry;

typedef struct {
	git_config_iterator *config_iterator;
} luagit2_config_iterator;

typedef struct {
	git_revspec *revspec;
} luagit2_revspec;

typedef struct {
	git_reflog *reflog;
}luagit2_reflog;

typedef struct {
	git_reflog_entry *reflog_entry;
}luagit2_reflog_entry;

typedef struct {
	git_describe_result *describe_result;
}luagit2_describe_result;

typedef struct {
	git_checkout_options checkout_opts;
}luagit2_checkout_options;

typedef struct {
	git_diff *diff;
} luagit2_diff;

typedef struct {
	git_diff_options diff_opts;
} luagit2_diff_options;

typedef struct {
	git_diff_stats *diff_stats;
} luagit2_diff_stats;

typedef struct {
	git_diff_stats_format_t stats_format;
} luagit2_diff_stats_format;

typedef struct {
	git_diff_format_t diff_format;
} luagit2_diff_format;

typedef struct {
	git_revwalk *revwalk;
} luagit2_revwalk;

typedef struct {
	git_odb_object *odb_object;
} luagit2_odb_object;

typedef struct {
	git_status_list *status_list;
} luagit2_status_list;

typedef struct {
	git_status_entry *status_entry;
} luagit2_status_entry;

typedef struct {
	git_status_t status_type;
} luagit2_status_type;

typedef struct {
	git_note *note;
} luagit2_note;

#endif
