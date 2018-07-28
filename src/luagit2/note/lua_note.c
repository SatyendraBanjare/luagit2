#include "lua_note.h"

int lua_git_note_author (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_note");
	}

	const luagit2_note *lua_note = (luagit2_note *)luaL_checkudata(L, 1,"luagit2_note");

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	git_signature *Signature = git_note_author(lua_note->note);
	lua_sign->sign = Signature;

	return 1;
}

int lua_git_note_committer (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_note");
	}

	const luagit2_note *lua_note = (luagit2_note *)luaL_checkudata(L, 1,"luagit2_note");

	luagit2_signature *lua_sign;
	lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
	lua_sign->sign = NULL;

	luaL_newmetatable(L, "luagit2_signature");
	lua_setmetatable(L, -2);

	git_signature *Signature = git_note_committer(lua_note->note);
	lua_sign->sign = Signature;

	return 1;
}

int lua_git_note_commit_create (lua_State *L) {

	if (lua_gettop(L) != 7) {
		return luaL_error(L, "expecting exactly 7 arguments : luagit2_repository,(parent)luagit2_commit,\
			luagit2_signature(author),luagit2_signature(committer),luagit2_oid(object's ID),string(message),(int)force");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_commit *lua_commit_parent = (luagit2_commit *)luaL_checkudata(L, 2, "luagit2_commit");
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 3, "luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 4, "luagit2_signature");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 5, "luagit2_oid");
	const char* note_message = luaL_checkstring(L,6);
	const int force = luaL_checkinteger(L,7);

	git_oid notes_commit_out;
	git_oid notes_blob_out;

	check_error_long(git_note_commit_create(&notes_commit_out, &notes_blob_out, Repo->repo, lua_commit_parent->commit,
		Author_sign->sign,Commiter_sign->sign,&(obj_id->oid),note_message,force),"Unable to create a commit note", NULL);

	luagit2_oid *notes_commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*notes_commit_id));
	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);
	notes_commit_id->oid = notes_commit_out;

	luagit2_oid *notes_blob_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*notes_blob_id));
	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);
	notes_blob_id->oid = notes_blob_out;

	return 2;
}

int lua_git_note_create (lua_State *L) {

	if (lua_gettop(L) != 7) {
		return luaL_error(L, "expecting exactly 7 arguments : luagit2_repository,(string)notes_ref,\
			luagit2_signature(author),luagit2_signature(committer),luagit2_oid(object's ID),string(message),(int)force");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *notes_ref = luaL_checkstring(L,2);
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 3, "luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 4, "luagit2_signature");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 5, "luagit2_oid");
	const char* note_message = luaL_checkstring(L,6);
	const int force = luaL_checkinteger(L,7);

	git_oid notes_commit_out;

	check_error_long(git_note_create(&notes_commit_out, Repo->repo, notes_ref,
		Author_sign->sign,Commiter_sign->sign,&(obj_id->oid),note_message,force),"Unable to create a note", NULL);

	luagit2_oid *notes_commit_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*notes_commit_id));
	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);
	notes_commit_id->oid = notes_commit_out;

	return 1;
}

int lua_git_note_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 arguments : luagit2_note");
	}

	const luagit2_note *lua_note = (luagit2_note *)luaL_checkudata(L, 1,"luagit2_note");
	git_note_free(lua_note->note);

	return 0;
}

int lua_git_note_message (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 arguments : luagit2_note");
	}

	const luagit2_note *lua_note = (luagit2_note *)luaL_checkudata(L, 1,"luagit2_note");
	const char *message = git_note_message(lua_note->note);

	lua_pushstring(L,message);

	return 1;
}

int lua_git_note_id (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 arguments : luagit2_note");
	}

	luagit2_oid *note_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*note_id));

	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);

	const luagit2_note *lua_note = (luagit2_note *)luaL_checkudata(L, 1,"luagit2_note");
	note_id->oid = *(git_note_id(lua_note->note));

	return 1;
}

int lua_git_note_commit_remove (lua_State *L) {

	if (lua_gettop(L) != 5) {
		return luaL_error(L, "expecting exactly 5 arguments : luagit2_repository,(parent)luagit2_commit,\
			luagit2_signature(author),luagit2_signature(committer),luagit2_oid(object's ID)");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_commit *lua_note_commit = (luagit2_commit *)luaL_checkudata(L, 2, "luagit2_commit");
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 3, "luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 4, "luagit2_signature");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 5, "luagit2_oid");

	git_oid local_notes_remove_commit_out;

	check_error_long(git_note_commit_remove(&local_notes_remove_commit_out, Repo->repo, lua_note_commit->commit,
		Author_sign->sign,Commiter_sign->sign,&(obj_id->oid)),"Unable to do remove commit note", NULL);

	luagit2_oid *notes_remove_commit_out = (luagit2_oid *)lua_newuserdata(L, sizeof(*notes_remove_commit_out));
	luaL_newmetatable(L, "luagit2_oid");
	lua_setmetatable(L, -2);
	notes_remove_commit_out->oid = local_notes_remove_commit_out;

	return 0;
}

int lua_git_note_remove (lua_State *L) {

	if (lua_gettop(L) != 5) {
		return luaL_error(L, "expecting exactly 5 arguments : luagit2_repository,(string)notes_ref,\
			luagit2_signature(author),luagit2_signature(committer),luagit2_oid(object's ID)");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *notes_ref = luaL_checkstring(L,2);
	const luagit2_signature *Author_sign = (luagit2_signature *)luaL_checkudata(L, 3, "luagit2_signature");
	const luagit2_signature *Commiter_sign = (luagit2_signature *)luaL_checkudata(L, 4, "luagit2_signature");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 5, "luagit2_oid");


	check_error_long(git_note_remove(Repo->repo, notes_ref,Author_sign->sign,
		Commiter_sign->sign,&(obj_id->oid)),"Unable to remove note", NULL);

	return 0;
}

int lua_git_note_read (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,(string)notes_ref,luagit2_oid(object's ID)");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *notes_ref = luaL_checkstring(L,2);
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 3, "luagit2_oid");

	git_note *local_note;

	check_error_long(git_note_read(&local_note, Repo->repo, notes_ref,
		&(obj_id->oid)),"Unable to read a note", NULL);

	luagit2_note *lua_note = (luagit2_note *)lua_newuserdata(L, sizeof(*lua_note));
	luaL_newmetatable(L, "luagit2_note");
	lua_setmetatable(L, -2);
	lua_note->note = local_note;

	return 1;
}

int lua_git_note_commit_read (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,luagit2_commit(notes_commit),luagit2_oid(object's ID)");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 2, "luagit2_commit");
	const luagit2_oid *obj_id = (luagit2_oid *)luaL_checkudata(L, 3, "luagit2_oid");

	git_note *local_note;

	check_error_long(git_note_commit_read(&local_note, Repo->repo, lua_commit->commit,
		&(obj_id->oid)),"Unable to read a commit note", NULL);

	luagit2_note *lua_note = (luagit2_note *)lua_newuserdata(L, sizeof(*lua_note));
	luaL_newmetatable(L, "luagit2_note");
	lua_setmetatable(L, -2);
	lua_note->note = local_note;

	return 1;
}