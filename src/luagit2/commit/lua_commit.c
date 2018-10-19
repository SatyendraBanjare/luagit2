#include "lua_commit.h"

int lua_git_commit_author (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	lua_sign->sign = git_commit_author(lua_commit->commit);

	return 1;
}

int lua_git_commit_body (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *body = git_commit_body(lua_commit->commit);
	lua_pushstring(L, body);
	return 1;
}

int lua_git_commit_committer (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	git_signature *Signature = git_commit_committer(lua_commit->commit);
	lua_sign->sign = Signature;

	return 1;
}

int lua_git_commit_extract_signature (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_oid");
    }

	luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	luagit2_oid *Commit_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");

	git_buf local_sign_buf = GIT_BUF_INIT_CONST(NULL,0);
	git_buf local_extra_buf =  GIT_BUF_INIT_CONST(NULL,0);
	check_error_long(git_commit_extract_signature(&local_sign_buf, &local_extra_buf,
	        Repo->repo, &(Commit_id->oid), NULL), "Error extracting signature from given commit id", NULL);

	luagit2_buf *lua_signature_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_signature_buf));
	lua_signature_buf->buf = NULL;
	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);
	lua_signature_buf->buf  = &local_sign_buf;

	luagit2_buf *lua_extra_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_extra_buf));
	lua_extra_buf->buf = NULL;
	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);
	lua_extra_buf->buf  = &local_extra_buf;

	return 2;
}

int lua_git_commit_header_field (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_commit,field(string)");
    }

	const luagit2_commit *Commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *field = luaL_checkstring(L, 2);

	luagit2_buf *lua_header_buf;

	lua_header_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_header_buf));
	lua_header_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_out_buf = {0};
	check_error_long(git_commit_header_field(&local_out_buf, Commit->commit, field),
	    "Error getting header field for the given commit", NULL);

	lua_header_buf->buf  = &local_out_buf;

	return 1;
}

int lua_git_commit_lookup (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_oid");
    }

	luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *Commit_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");

	luagit2_commit *lua_Commit;

	lua_Commit = (luagit2_commit *)lua_newuserdata(L, sizeof(*lua_Commit));
	lua_Commit->commit = NULL;

	luaL_newmetatable(L, "luagit2_commit");
	lua_setmetatable(L, -2);

	git_commit *local_commit;
	check_error_long(git_commit_lookup(&(local_commit), Repo->repo, &(Commit_id->oid)),
	    "Failed to look up the commit in the given repo", NULL);

	lua_Commit->commit  = local_commit;

	return 1;
}

int lua_git_commit_lookup_prefix (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_repository,luagit2_oid,length(int)");
    }

	luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_oid *Commit_id = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
	size_t length = luaL_checkinteger(L, 3);

	luagit2_commit *lua_Commit;

	lua_Commit = (luagit2_commit *)lua_newuserdata(L, sizeof(*lua_Commit));
	lua_Commit->commit = NULL;

	luaL_newmetatable(L, "luagit2_commit");
	lua_setmetatable(L, -2);

	git_commit *local_commit;
	check_error_long(git_commit_lookup_prefix(&(local_commit), Repo->repo, &(Commit_id->oid), length),
	    "Failed to look up the commit in given repo using length of prefix", NULL);

	lua_Commit->commit  = local_commit;

	return 1;
}

int lua_git_commit_message (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *message = git_commit_message(lua_commit->commit);
	lua_pushstring(L, message);
	return 1;
}

int lua_git_commit_message_encoding (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *message_encoding = git_commit_message_encoding(lua_commit->commit);
	lua_pushstring(L, message_encoding);
	return 1;
}

int lua_git_commit_message_raw (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *message = git_commit_message_raw(lua_commit->commit);
	lua_pushstring(L, message);
	return 1;
}

int lua_git_commit_nth_gen_ancestor (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_commit,nth_gen(int)");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
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

	return 1;
}

int lua_git_commit_parent (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_commit,parent_number(int)");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
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

	return 1;
}

int lua_git_commit_parent_id (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_commit,position(int)");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	luagit2_oid *parent_id;
	unsigned int position  = luaL_checkinteger(L, 2);

	parent_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*parent_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	parent_id->oid = *(git_commit_parent_id(lua_commit->commit, position));

	return 1;
}

int lua_git_commit_parentcount (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	unsigned int parent_count = git_commit_parentcount(lua_commit->commit);
	lua_pushinteger(L, parent_count);
	return 1;
}

int lua_git_commit_raw_header (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *header = git_commit_raw_header(lua_commit->commit);
	lua_pushstring(L, header);
	return 1;
}

int lua_git_commit_summary (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	const char *summary = git_commit_summary(lua_commit->commit);
	lua_pushstring(L, summary);
	return 1;
}

int lua_git_commit_time (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	time_t time = git_commit_time(lua_commit->commit);
	const char *time_str = ctime(&time);
	lua_pushstring(L,time_str);
	return 1;
}

int lua_git_commit_tree (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	luagit2_tree *lua_tree;

	lua_tree = (luagit2_tree *)lua_newuserdata(L, sizeof(*lua_tree));
	lua_tree->tree = NULL;

	luaL_newmetatable(L, "luagit2_tree");
	lua_setmetatable(L, -2);

	git_tree *local_tree_obj;
	check_error_long(git_commit_tree(&local_tree_obj, lua_commit->commit),
	    "Failed to get the tree for given commit", NULL);

	lua_tree->tree  = local_tree_obj;

	return 1;
}

int lua_git_commit_tree_id (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	luagit2_oid *tree_id;

	tree_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*tree_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	tree_id->oid = *(git_commit_tree_id(lua_commit->commit));

	return 1;
}

int lua_git_commit_free (lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	git_commit_free(lua_commit->commit);

	return 1;
}

int lua_git_commit_create_update_head (lua_State *L) {

	if (lua_gettop(L) != 6 ) {
        return luaL_error(L, "expecting 6 argument(s) : luagit2_repository,luagit2_signature(author),luagit2_signature(committer)\
        	commit_message,luagit2_tree,luagit2_commit");
    }

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 2,"luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 3,"luagit2_signature");
	const char *commit_message = luaL_checkstring(L, 4);
	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 5,"luagit2_tree");
	const luagit2_commit *Parent_Commit = (luagit2_commit *)luaL_checkudata(L,6,"luagit2_commit");

	luagit2_oid *new_commit_id;

	new_commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*new_commit_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_oid;
	check_error_long(git_commit_create_v(&local_oid,
	        Repo->repo,
	        "HEAD",
	        Author_sign->sign,
	        Commiter_sign->sign,
	        NULL,
	        commit_message,
	        Tree->tree,
	        1,
	        Parent_Commit->commit)
	    , "Unable to create commit & update ", NULL);

	new_commit_id->oid = local_oid;
	return 1;
}

int lua_git_commit_create_update_none (lua_State *L) {

	if (lua_gettop(L) != 6 ) {
        return luaL_error(L, "expecting 6 argument(s) : luagit2_repository,luagit2_signature(author),luagit2_signature(committer)\
        	commit_message,luagit2_tree,luagit2_commit");
    }

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 2,"luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 3,"luagit2_signature");
	const char *commit_message = luaL_checkstring(L, 4);
	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 5,"luagit2_tree");
	const luagit2_commit *Parent_Commit = (luagit2_commit *)luaL_checkudata(L,6,"luagit2_commit");

	luagit2_oid *new_commit_id;

	new_commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*new_commit_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_oid;
	check_error_long(git_commit_create_v(&local_oid,
	        Repo->repo,
	        NULL,
	        Author_sign->sign,
	        Commiter_sign->sign,
	        NULL,
	        commit_message,
	        Tree->tree,
	        1,
	        Parent_Commit->commit)
	    , "Unable to create commit", NULL);

	new_commit_id->oid = local_oid;
	return 1;
}

int lua_git_commit_id(lua_State *L) {
	
	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_commit");
    }

	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 1,"luagit2_commit");
	luagit2_oid *commit_id;
	commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*commit_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	commit_id->oid = *(git_commit_id(lua_commit->commit));
	return 1;
}

int lua_git_commit_create_with_signature (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_repository,commit_content(string),commit_sign(string)");
    }

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *commit_content = luaL_checkstring(L,2);
	const char *commit_sign = luaL_checkstring(L,3);

	luagit2_oid *new_commit_id;

	new_commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*new_commit_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_oid;
	check_error_long(git_commit_create_with_signature(&local_oid, Repo->repo, commit_content, commit_sign,
		NULL) //passing NULL for default value gpgsig.
	, "Unable to create commit", NULL);
	new_commit_id->oid = local_oid;

	return 1;
}

int lua_git_commit_create_initial (lua_State *L) {

	if (lua_gettop(L) != 5 ) {
        return luaL_error(L, "expecting 5 argument(s) : luagit2_repository,luagit2_signature(author),luagit2_signature(committer)\
        	commit_message,luagit2_tree");
    }

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 2,"luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 3,"luagit2_signature");
	const char *commit_message = luaL_checkstring(L, 4);
	const luagit2_tree *Tree = (luagit2_tree *)luaL_checkudata(L, 5,"luagit2_tree");

	luagit2_oid *new_commit_id;

	new_commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*new_commit_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	git_oid local_oid;
	check_error_long(git_commit_create_v(&local_oid,
	        Repo->repo,
	        "HEAD",
	        Author_sign->sign,
	        Commiter_sign->sign,
	        NULL,
	        commit_message,
	        Tree->tree,
	        0)
	    , "Unable to create initial commit ", NULL);

	new_commit_id->oid = local_oid;
	return 1;
}
