#include "lua_branch.h"

int lua_git_branch_create (lua_State *L) {

	if (lua_gettop(L) != 4) {
        return luaL_error(L, "expecting 4 argument(s) : luagit2_repository,branch_name(string),luagit2_commit,force(int)");
    }

	luagit2_reference *lua_ref;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *branch_name = luaL_checkstring(L, 2);
	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 3,"luagit2_commit");
	const int force = luaL_checkinteger(L, 4);

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_branch_create(&local_ref, lua_repo->repo, branch_name, lua_commit->commit, force),
	    "Error creating new branch for target commit", NULL);
	lua_ref->reference  = local_ref;

	return 1;
}

int lua_git_branch_create_from_annotated (lua_State *L) {

	if (lua_gettop(L) != 4) {
        return luaL_error(L, "expecting 4 argument(s) : luagit2_repository,branch_name(string),luagit2_annotated_commit,force(int)");
    }

	luagit2_reference *lua_ref;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *branch_name = luaL_checkstring(L, 2);
	const luagit2_annotated_commit *lua_annotated_commit = (luagit2_annotated_commit *)luaL_checkudata(L, 3,"luagit2_annotated_commit");
	const int force = luaL_checkinteger(L, 4);

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_branch_create_from_annotated(&local_ref, lua_repo->repo, branch_name,
	        lua_annotated_commit->annotated_commit, force), "Error creating new branch for target annotated commit", NULL);
	lua_ref->reference  = local_ref;

	return 1;
}

int lua_git_branch_delete (lua_State *L) {

	if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_reference");
    }

	const luagit2_reference *lua_ref_branch = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");
	check_error_long(git_branch_delete(lua_ref_branch->reference), "Error deleting the branch", NULL);
	return 1;
}

int lua_git_branch_is_checked_out (lua_State *L) {

	if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_reference");
    }

	const luagit2_reference *lua_ref_branch = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");
	int is_checked_out = git_branch_is_checked_out(lua_ref_branch->reference);
	lua_pushboolean(L, is_checked_out);
	return 1;
}

int lua_git_branch_is_head (lua_State *L) {

	if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_reference");
    }

	const luagit2_reference *lua_ref_branch = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");
	int is_head = git_branch_is_head(lua_ref_branch->reference);
	lua_pushboolean(L, is_head);
	return 1;
}

int lua_git_branch_iterator_new (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_repository,luagit2_branch_type");
    }

	luagit2_branch_iterator *lua_branch_iterator;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_branch_type *list_flags = (luagit2_branch_type *)luaL_checkudata(L, 2,"luagit2_branch_type");

	lua_branch_iterator = (luagit2_branch_iterator *)lua_newuserdata(L, sizeof(*lua_branch_iterator));
	lua_branch_iterator->branch_iterator  = NULL;

	luaL_newmetatable(L, "luagit2_branch_iterator");

	lua_setmetatable(L, -2);

	git_branch_iterator *local_branch_iter;
	check_error_long(git_branch_iterator_new(&local_branch_iter, lua_repo->repo, list_flags->branch_type),
	    "Error getting branch iterator ", NULL);
	lua_branch_iterator->branch_iterator  = local_branch_iter;
	return 1;
}

int lua_git_branch_lookup (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_repository,branch_name(string)luagit2_branch_type");
    }

	luagit2_reference *lua_ref;
	const luagit2_repository *lua_repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *branch_name = luaL_checkstring(L, 2);
	const luagit2_branch_type *lua_branch_type = (luagit2_branch_type *)luaL_checkudata(L, 3,"luagit2_branch_type");

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_branch_lookup(&local_ref, lua_repo->repo, branch_name, lua_branch_type->branch_type),
	    "Failed to find the branch in the given repository", NULL);
	lua_ref->reference  = local_ref;

	return 1;
}

int lua_git_branch_move (lua_State *L) {

	if (lua_gettop(L) != 3 ) {
        return luaL_error(L, "expecting 3 argument(s) : luagit2_reference,new_branch_name(string),force(int)");
    }

	luagit2_reference *lua_ref;
	const luagit2_reference *lua_branch_from = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");
	const char *new_branch_name = luaL_checkstring(L, 2);
	const int force = luaL_checkinteger(L, 3);

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_branch_move(&local_ref, lua_branch_from->reference, new_branch_name, force),
	    "Failed to rename/move the branch", NULL);
	lua_ref->reference  = local_ref;

	return 1;
}

int lua_git_branch_name (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_reference");
    }

	const luagit2_reference *lua_branch_from = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");
	const char *branch_name = NULL;
	check_error_long(git_branch_name(&branch_name, lua_branch_from->reference), "Failed to get the branch name", NULL);
	lua_pushstring(L, branch_name);
	return 1;
}

int lua_git_branch_next (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_branch_type,luagit2_branch_iterator");
    }

	luagit2_reference *lua_ref;
	luagit2_branch_type *lua_branch_t = (luagit2_branch_type *)luaL_checkudata(L, 1,"luagit2_branch_type");
	luagit2_branch_iterator *lua_branch_iterator = (luagit2_branch_iterator *)luaL_checkudata(L, 2,"luagit2_branch_iterator");

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_branch_next(&local_ref, &(lua_branch_t->branch_type), lua_branch_iterator->branch_iterator),
	    "Failed to get next branch name", NULL);
	lua_ref->reference  = local_ref;

	return 1;
}

int lua_git_branch_set_upstream (lua_State *L) {

	if (lua_gettop(L) != 2 ) {
        return luaL_error(L, "expecting 2 argument(s) : luagit2_reference,upstream_name(string)");
    }

	const luagit2_reference *lua_branch_from = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");
	const char *upstream_name = luaL_checkstring(L, 2);
	check_error_long(git_branch_set_upstream(lua_branch_from->reference, upstream_name),
	    "Failed to set upstream for given branch", NULL);
	return 1;
}

int lua_git_branch_upstream (lua_State *L) {

	if (lua_gettop(L) != 1 ) {
        return luaL_error(L, "expecting 1 argument(s) : luagit2_reference");
    }

	luagit2_reference *lua_ref;
	const luagit2_reference *lua_branch_base = (luagit2_reference *)luaL_checkudata(L, 1,"luagit2_reference");

	lua_ref = (luagit2_reference *)lua_newuserdata(L, sizeof(*lua_ref));
	lua_ref->reference  = NULL;

	luaL_newmetatable(L, "luagit2_reference");

	lua_setmetatable(L, -2);

	git_reference *local_ref;
	check_error_long(git_branch_upstream(&local_ref, lua_branch_base->reference),
		"Error in getting branch upstream",NULL);
	lua_ref->reference  = local_ref;

	return 1;
}
