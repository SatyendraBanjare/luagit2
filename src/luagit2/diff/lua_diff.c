#include "lua_diff.h"

int lua_git_diff_init_options (lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)lua_newuserdata(L, sizeof(*lua_diff_opts));

	luaL_newmetatable(L, "luagit2_diff_options");
	lua_setmetatable(L, -2);

	git_diff_options local_diff_opts;
	check_error_long(git_diff_init_options(&local_diff_opts, GIT_DIFF_OPTIONS_VERSION),
	    "Error initializing diff options", NULL);

	lua_diff_opts->diff_opts = local_diff_opts;

	return 1;
}

int lua_git_diff_get_stats (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_diff");
	}

	const luagit2_diff *lua_diff = (luagit2_diff *)luaL_checkudata(L, 1, "luagit2_diff");
	luagit2_diff_stats *lua_diff_stats = (luagit2_diff_stats *)lua_newuserdata(L, sizeof(*lua_diff_stats));
	lua_diff_stats->diff_stats  = NULL;

	luaL_newmetatable(L, "luagit2_diff_stats");
	lua_setmetatable(L, -2);

	git_diff_stats *local_diff_stats;
	check_error_long(git_diff_get_stats(&local_diff_stats, lua_diff->diff),
	    "Error getting diff stats for given luagit2_diff", NULL);

	lua_diff_stats->diff_stats = local_diff_stats;

	return 1;
}

int lua_git_diff_index_to_index (lua_State *L) {

	if (lua_gettop(L) != 4) {
		return luaL_error(L, "expecting 4 arguments : luagit2_repository,luagit2_index(old),luagit2_index(new),luagit2_diff_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_index *index_old = (luagit2_index *)luaL_checkudata(L, 2, "luagit2_index");
	const luagit2_index *index_new = (luagit2_index *)luaL_checkudata(L, 3, "luagit2_index");
	const luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)luaL_checkudata(L, 4, "luagit2_diff_options");

	luagit2_diff *lua_diff = (luagit2_diff *)lua_newuserdata(L, sizeof(*lua_diff));
	lua_diff->diff  = NULL;

	luaL_newmetatable(L, "luagit2_diff");
	lua_setmetatable(L, -2);

	git_diff *local_diff;
	check_error_long(git_diff_index_to_index(&local_diff, Repo->repo, index_old->index, index_new->index, &(lua_diff_opts->diff_opts)),
	    "Error in getting diff data for given indexes ", NULL);

	lua_diff->diff = local_diff;

	return 1;
}

int lua_git_diff_index_to_workdir (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting 3 arguments : luagit2_repository,luagit2_index,luagit2_diff_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_index *lua_index = (luagit2_index *)luaL_checkudata(L, 2, "luagit2_index");
	const luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)luaL_checkudata(L, 3, "luagit2_diff_options");

	luagit2_diff *lua_diff = (luagit2_diff *)lua_newuserdata(L, sizeof(*lua_diff));
	lua_diff->diff  = NULL;

	luaL_newmetatable(L, "luagit2_diff");
	lua_setmetatable(L, -2);

	git_diff *local_diff;
	check_error_long(git_diff_index_to_workdir(&local_diff, Repo->repo, lua_index->index, &(lua_diff_opts->diff_opts)),
	    "Error in getting diff data for index to workdir ", NULL);

	lua_diff->diff = local_diff;

	return 1;
}

int lua_git_diff_is_sorted_icase (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_diff");
	}

	const luagit2_diff *lua_diff = (luagit2_diff *)luaL_checkudata(L, 1, "luagit2_diff");
	int is_sorted = git_diff_is_sorted_icase(lua_diff->diff);
	lua_pushboolean(L, is_sorted);
	return 1;
}

int lua_git_diff_merge (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting 2 arguments : luagit2_diff(onto),luagit2_diff(from)");
	}

	const luagit2_diff *lua_diff_onto = (luagit2_diff *)luaL_checkudata(L, 1, "luagit2_diff");
	const luagit2_diff *lua_diff_from = (luagit2_diff *)luaL_checkudata(L, 2, "luagit2_diff");

	check_error_long(git_diff_merge(lua_diff_onto->diff, lua_diff_from->diff),
	    "Error merging one diff onto other ", NULL);

	return 1;
}

int lua_git_diff_num_deltas (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_diff");
	}

	const luagit2_diff *lua_diff = (luagit2_diff *)luaL_checkudata(L, 1, "luagit2_diff");
	size_t num_deltas = git_diff_num_deltas(lua_diff->diff);
	lua_pushnumber(L, num_deltas);
	return 1;
}

int lua_git_diff_stats_deletions (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_diff_stats	");
	}

	const luagit2_diff_stats *lua_diff_stats = (luagit2_diff_stats *)luaL_checkudata(L, 1, "luagit2_diff_stats");
	size_t num_deletions = git_diff_stats_deletions(lua_diff_stats->diff_stats);
	lua_pushnumber(L, num_deletions);
	return 1;
}

int lua_git_diff_stats_files_changed (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_diff_stats	");
	}

	const luagit2_diff_stats *lua_diff_stats = (luagit2_diff_stats *)luaL_checkudata(L, 1, "luagit2_diff_stats");
	size_t files_changed = git_diff_stats_files_changed(lua_diff_stats->diff_stats);
	lua_pushnumber(L, files_changed);
	return 1;
}

int lua_git_diff_stats_insertions (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_diff_stats	");
	}

	const luagit2_diff_stats *lua_diff_stats = (luagit2_diff_stats *)luaL_checkudata(L, 1, "luagit2_diff_stats");
	size_t num_insertions = git_diff_stats_insertions(lua_diff_stats->diff_stats);
	lua_pushnumber(L, num_insertions);
	return 1;
}

int lua_git_diff_stats_to_buf (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting 3 arguments : luagit2_diff_stats,(luagit2_stats)format_option,(number)size");
	}

	const luagit2_diff_stats *lua_diff_stats = (luagit2_diff_stats *)luaL_checkudata(L, 1, "luagit2_diff_stats");
	const luagit2_diff_stats_format *lua_stats_format = (luagit2_diff_stats_format *)luaL_checkudata(L, 2, "luagit2_diff_stats_format");
	const size_t width = luaL_checknumber(L, 3);

	luagit2_buf *lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);

	check_error_long(git_diff_stats_to_buf(&local_buf, lua_diff_stats->diff_stats, lua_stats_format->stats_format, width),
	    "Error converting diff stats to buff ", NULL);

	lua_buf->buf  = &local_buf;

	return 1;
}

int lua_git_diff_to_buf(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting 2 arguments : luagit2_diff,luagit2_diff_format_option");
	}

	const luagit2_diff *lua_diff = (luagit2_diff *)luaL_checkudata(L, 1, "luagit2_diff");
	const luagit2_diff_format *lua_diff_format = (luagit2_diff_format *)luaL_checkudata(L, 2, "luagit2_diff_format");

	luagit2_buf *lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);

	check_error_long(git_diff_to_buf(&local_buf, lua_diff->diff, lua_diff_format->diff_format),
	    "Error converting diff to buff ", NULL);

	lua_buf->buf  = &local_buf;

	return 1;
}

int lua_git_diff_tree_to_index (lua_State *L) {

	if (lua_gettop(L) != 4) {
		return luaL_error(L, "expecting 4 arguments : luagit2_repository,luagit2_tree,luagit2_index,luagit2_diff_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_tree *lua_tree = (luagit2_tree *)luaL_checkudata(L, 2, "luagit2_tree");
	const luagit2_index *lua_index = (luagit2_index *)luaL_checkudata(L, 3, "luagit2_index");
	const luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)luaL_checkudata(L, 4, "luagit2_diff_options");

	luagit2_diff *lua_diff = (luagit2_diff *)lua_newuserdata(L, sizeof(*lua_diff));
	lua_diff->diff  = NULL;

	luaL_newmetatable(L, "luagit2_diff");
	lua_setmetatable(L, -2);

	git_diff *local_diff;
	check_error_long(git_diff_tree_to_index(&local_diff, Repo->repo, lua_tree->tree, lua_index->index, &(lua_diff_opts->diff_opts)),
	    "Error in getting diff data for tree to index ", NULL);

	lua_diff->diff = local_diff;

	return 1;
}

int lua_git_diff_tree_to_tree (lua_State *L) {

	if (lua_gettop(L) != 4) {
		return luaL_error(L, "expecting 4 arguments : luagit2_repository,luagit2_index(old),luagit2_index(new),luagit2_diff_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_tree *tree_old = (luagit2_tree *)luaL_checkudata(L, 2, "luagit2_tree");
	const luagit2_tree *tree_new = (luagit2_tree *)luaL_checkudata(L, 3, "luagit2_tree");
	const luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)luaL_checkudata(L, 4, "luagit2_diff_options");

	luagit2_diff *lua_diff = (luagit2_diff *)lua_newuserdata(L, sizeof(*lua_diff));
	lua_diff->diff  = NULL;

	luaL_newmetatable(L, "luagit2_diff");
	lua_setmetatable(L, -2);

	git_diff *local_diff;
	check_error_long(git_diff_tree_to_tree(&local_diff, Repo->repo, tree_old->tree, tree_new->tree, &(lua_diff_opts->diff_opts)),
	    "Error in getting diff data for given trees ", NULL);

	lua_diff->diff = local_diff;

	return 1;
}

int lua_git_diff_tree_to_workdir (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting 3 arguments : luagit2_repository,luagit2_tree,luagit2_diff_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_tree *lua_tree = (luagit2_tree *)luaL_checkudata(L, 2, "luagit2_tree");
	const luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)luaL_checkudata(L, 3, "luagit2_diff_options");

	luagit2_diff *lua_diff = (luagit2_diff *)lua_newuserdata(L, sizeof(*lua_diff));
	lua_diff->diff  = NULL;

	luaL_newmetatable(L, "luagit2_diff");
	lua_setmetatable(L, -2);

	git_diff *local_diff;
	check_error_long(git_diff_tree_to_workdir(&local_diff, Repo->repo, lua_tree->tree, &(lua_diff_opts->diff_opts)),
	    "Error in getting diff data for tree to workdir ", NULL);

	lua_diff->diff = local_diff;

	return 1;
}

int lua_git_diff_tree_to_workdir_with_index (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting 3 arguments : luagit2_repository,luagit2_tree,luagit2_diff_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_tree *lua_tree = (luagit2_tree *)luaL_checkudata(L, 2, "luagit2_tree");
	const luagit2_diff_options *lua_diff_opts = (luagit2_diff_options *)luaL_checkudata(L, 3, "luagit2_diff_options");

	luagit2_diff *lua_diff = (luagit2_diff *)lua_newuserdata(L, sizeof(*lua_diff));
	lua_diff->diff  = NULL;

	luaL_newmetatable(L, "luagit2_diff");
	lua_setmetatable(L, -2);

	git_diff *local_diff;
	check_error_long(git_diff_tree_to_workdir_with_index(&local_diff, Repo->repo, lua_tree->tree, &(lua_diff_opts->diff_opts)),
	    "Error in getting diff data for tree to workdir using the index data", NULL);

	lua_diff->diff = local_diff;

	return 1;
}
