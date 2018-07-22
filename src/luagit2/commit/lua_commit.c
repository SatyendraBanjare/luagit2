#include "lua_commit.h"

int lua_git_commit_author (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	lua_sign->sign = git_commit_author(lua_commit->commit);

	return 1;
}

int lua_git_commit_body (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	const char *body = git_commit_body(lua_commit->commit);
	lua_pushstring(L, body);
	return 1;
}

int lua_git_commit_committer (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	git_signature *Signature = git_commit_committer(lua_commit->commit);
	lua_sign->sign = Signature;
	git_signature_free(Signature);

	return 1;
}

int lua_git_commit_extract_signature (lua_State *L) {
	luagit2_repository *Repo = (luagit2_repository *)lua_touserdata(L, 1);
	luagit2_oid *Commit_id = (luagit2_oid *)lua_touserdata(L, 2);
	const char *field = luaL_checkstring(L, 3);

	luagit2_buf *lua_signature_buf;

	lua_signature_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_signature_buf));
	lua_signature_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf *local_sign_buf;
	git_buf *local_extra_buf;
	check_error_long(git_commit_extract_signature(local_sign_buf, local_extra_buf,
	        Repo->repo, &(Commit_id->oid), field), "Error extracting signature from given commit id", NULL);

	lua_signature_buf->buf  = local_sign_buf;
	git_buf_free(local_sign_buf);
	return 1;
}

int lua_git_commit_header_field (lua_State *L) {
	const luagit2_commit *Commit = (luagit2_commit *)lua_touserdata(L, 1);
	const char *field = luaL_checkstring(L, 2);

	luagit2_buf *lua_header_buf;

	lua_header_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_header_buf));
	lua_header_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf *local_out_buf;
	check_error_long(git_commit_header_field(local_out_buf, Commit->commit, field),
	    "Error getting header field for the given commit", NULL);

	lua_header_buf->buf  = local_out_buf;
	git_buf_free(local_out_buf);
	return 1;
}

int lua_git_commit_lookup (lua_State *L) {
	luagit2_repository *Repo = (luagit2_repository *)lua_touserdata(L, 1);
	const luagit2_oid *Commit_id = (luagit2_oid *)lua_touserdata(L, 2);

	luagit2_commit *lua_Commit;

	lua_Commit = (luagit2_commit *)lua_newuserdata(L, sizeof(*lua_Commit));
	lua_Commit->commit = NULL;

	luaL_newmetatable(L, "luagit2_commit");
	lua_setmetatable(L, -2);

	git_commit *local_commit;
	check_error_long(git_commit_lookup(&(local_commit), Repo->repo, &(Commit_id->oid)),
	    "Failed to look up the commit in the given repo", NULL);

	lua_Commit->commit  = local_commit;
	git_commit_free(local_commit);
	return 1;
}

int lua_git_commit_lookup_prefix (lua_State *L) {
	luagit2_repository *Repo = (luagit2_repository *)lua_touserdata(L, 1);
	const luagit2_oid *Commit_id = (luagit2_oid *)lua_touserdata(L, 2);
	size_t length = luaL_checkinteger(L, 3);

	luagit2_commit *lua_Commit;

	lua_Commit = (luagit2_commit *)lua_newuserdata(L, sizeof(*lua_Commit));
	lua_Commit->commit = NULL;

	luaL_newmetatable(L, "luagit2_commit");
	lua_setmetatable(L, -2);

	git_commit *local_commit;
	check_error_long(git_commit_lookup_prefix(&(local_commit), Repo->repo, &(Commit_id->oid), length),
	    "Failed to look up th commit in given repo using length of prefix", NULL);

	lua_Commit->commit  = local_commit;
	git_commit_free(local_commit);
	return 1;
}

int lua_git_commit_message (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	const char *message = git_commit_message(lua_commit->commit);
	lua_pushstring(L, message);
	return 1;
}

int lua_git_commit_message_encoding (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	const char *message_encoding = git_commit_message_encoding(lua_commit->commit);
	lua_pushstring(L, message_encoding);
	return 1;
}

int lua_git_commit_message_raw (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	const char *message = git_commit_message_raw(lua_commit->commit);
	lua_pushstring(L, message);
	return 1;
}

int lua_git_commit_nth_gen_ancestor (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	unsigned int Nth_ancestor_gen  = luaL_checkinteger(L, 2);

	luagit2_commit *lua_ancesstor_commit;

	lua_ancesstor_commit = (luagit2_commit *)lua_newuserdata(L, sizeof(*lua_ancesstor_commit));
	lua_ancesstor_commit->commit = NULL;

	luaL_newmetatable(L, "luagit2_commit");
	lua_setmetatable(L, -2);

	git_commit *local_commit;
	check_error_long(git_commit_nth_gen_ancestor(&(local_commit), lua_commit->commit, Nth_ancestor_gen),
	    "Failed to get the nth generation ancestor for the given commit", NULL);

	lua_ancesstor_commit->commit  = local_commit;
	git_commit_free(local_commit);
	return 1;
}

int lua_git_commit_parent (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	unsigned int position  = luaL_checkinteger(L, 2);

	luagit2_commit *lua_Commit;

	lua_Commit = (luagit2_commit *)lua_newuserdata(L, sizeof(*lua_Commit));
	lua_Commit->commit = NULL;

	luaL_newmetatable(L, "luagit2_commit");
	lua_setmetatable(L, -2);

	git_commit *local_commit;
	check_error_long(git_commit_parent(&(local_commit), lua_commit->commit, position),
	    "Failed to get the parent commit for the given commit", NULL);

	lua_Commit->commit  = local_commit;
	git_commit_free(local_commit);
	return 1;
}

int lua_git_commit_parent_id (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	luagit2_oid *parent_id;
	unsigned int position  = luaL_checkinteger(L, 2);

	parent_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*parent_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	parent_id->oid = *(git_commit_parent_id(lua_commit->commit, position));

	return 1;
}

int lua_git_commit_parentcount (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	unsigned int parent_count = git_commit_parentcount(lua_commit->commit);
	lua_pushinteger(L, parent_count);
	return 1;
}

int lua_git_commit_raw_header (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	const char *header = git_commit_raw_header(lua_commit->commit);
	lua_pushstring(L, header);
	return 1;
}

int lua_git_commit_summary (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);

	const char *summary = git_commit_summary(lua_commit->commit);
	lua_pushstring(L, summary);
	return 1;
}

int lua_git_commit_time (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	luagit2_time *commit_time;

	commit_time = (luagit2_time *)lua_newuserdata(L, sizeof(*commit_time));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	commit_time->time = git_commit_time(lua_commit->commit);

	return 1;
}

int lua_git_commit_tree (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	luagit2_tree *lua_tree;

	lua_tree = (luagit2_tree *)lua_newuserdata(L, sizeof(*lua_tree));
	lua_tree->tree = NULL;

	luaL_newmetatable(L, "luagit2_tree");
	lua_setmetatable(L, -2);

	git_tree *local_tree_obj;
	check_error_long(git_commit_tree(&local_tree_obj, lua_commit->commit),
	    "Failed to get the tree for given commit", NULL);

	lua_tree->tree  = local_tree_obj;
	git_tree_free(local_tree_obj);
	return 1;
}

int lua_git_commit_tree_id (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	luagit2_oid *tree_id;

	tree_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*tree_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	tree_id->oid = *(git_commit_tree_id(lua_commit->commit));

	return 1;
}

int lua_git_commit_free (lua_State *L) {
	const luagit2_commit *lua_commit = (luagit2_commit *)lua_touserdata(L, 1);
	git_commit_free(lua_commit->commit);

	return 1;
}
