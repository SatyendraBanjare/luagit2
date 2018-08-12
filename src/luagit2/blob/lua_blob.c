#include "lua_blob.h"

int lua_git_blob_create_fromdisk (lua_State *L) {

    if (lua_gettop(L) != 2) {
        return luaL_error(L, "expecting exactly 2 argument(s) : luagit2_repository,path(string)");
    }

    luagit2_oid *obj_id;
    const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
    const char *path = luaL_checkstring(L, 2);

    obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

    luaL_newmetatable(L, "luagit2_oid");
    lua_setmetatable(L, -2);

    git_oid local_id;
    check_error_long(git_blob_create_fromdisk(&local_id, Repo->repo, path),
        "Error creating blob from disk", NULL);
    obj_id->oid = local_id;

    return 1;
}

int lua_git_blob_create_fromworkdir (lua_State *L) {

    if (lua_gettop(L) != 2) {
        return luaL_error(L, "expecting exactly 2 argument(s) : luagit2_repository,path(string)");
    }

    luagit2_oid *obj_id;
    const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
    const char *relative_path = luaL_checkstring(L, 2);

    obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

    luaL_newmetatable(L, "luagit2_oid");
    lua_setmetatable(L, -2);

    git_oid local_id;
    check_error_long(git_blob_create_fromworkdir(&local_id, Repo->repo, relative_path),
        "Error creating blob from work dir", NULL);
    obj_id->oid = local_id;

    return 1;
}

int lua_git_blob_filtered_content (lua_State *L) {

    if (lua_gettop(L) != 3) {
        return luaL_error(L, "expecting exactly 3 argument(s) : luagit2_blob,path(string),check_for_binary_data(int)");
    }

    const luagit2_blob *lua_blob = (luagit2_blob *)luaL_checkudata(L, 1,"luagit2_blob");
    const char *as_path = luaL_checkstring(L, 2);
    int check_for_binary_data = luaL_checkinteger(L, 3);

    luagit2_buf *lua_out_buf;

    lua_out_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_out_buf));
    lua_out_buf->buf = NULL;

    luaL_newmetatable(L, "luagit2_buf");
    lua_setmetatable(L, -2);

    git_buf *local_buf;
    check_error_long(git_blob_filtered_content(local_buf, lua_blob->blob, as_path, check_for_binary_data),
        "Error getting filteres content of the blob", NULL);

    lua_out_buf->buf  = local_buf;
    return 1;
}

int lua_git_blob_id (lua_State *L) {

    if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blob");
    }

    luagit2_oid *obj_id;
    const luagit2_blob *lua_blob = (luagit2_blob *)luaL_checkudata(L, 1,"luagit2_blob");

    obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

    luaL_newmetatable(L, "luagit2_oid");
    lua_setmetatable(L, -2);

    obj_id->oid = *(git_blob_id(lua_blob->blob));

    return 1;
}

int lua_git_blob_is_binary (lua_State *L) {

    if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blob");
    }

    const luagit2_blob *lua_blob = (luagit2_blob *)luaL_checkudata(L, 1,"luagit2_blob");

    int is_binary = git_blob_is_binary(lua_blob->blob);
    lua_pushboolean(L, is_binary);
    return 1;
}

int lua_git_blob_lookup (lua_State *L) {

    if (lua_gettop(L) != 2) {
        return luaL_error(L, "expecting exactly 2 argument(s) : luagit2_repository,luagit2_oid");
    }

    luagit2_blob *lua_blob ;
    const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
    const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");

    lua_blob = (luagit2_blob *)lua_newuserdata(L, sizeof(*lua_blob));
    lua_blob->blob = NULL;

    luaL_newmetatable(L, "luagit2_blob");
    lua_setmetatable(L, -2);

    git_blob *local_blob;
    check_error_long(git_blob_lookup(&local_blob, Repo->repo, &(lua_oid->oid)),
        "Error in looking up for the blob in the given repo", NULL);

    lua_blob->blob  = local_blob;
    return 1;
}

int lua_git_blob_lookup_prefix (lua_State *L) {

    if (lua_gettop(L) != 3) {
        return luaL_error(L, "expecting exactly 3 argument(s) : luagit2_repository,luagit2_oid,length(int)");
    }

    luagit2_blob *lua_blob ;
    const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
    const luagit2_oid *lua_oid = (luagit2_oid *)luaL_checkudata(L, 2,"luagit2_oid");
    size_t len = luaL_checkinteger(L, 3);

    lua_blob = (luagit2_blob *)lua_newuserdata(L, sizeof(*lua_blob));
    lua_blob->blob = NULL;

    luaL_newmetatable(L, "luagit2_blob");
    lua_setmetatable(L, -2);

    git_blob *local_blob;
    check_error_long(git_blob_lookup_prefix(&local_blob, Repo->repo, &(lua_oid->oid), len),
        "Error in looking up for the blob in the given repo using prefix", NULL);

    lua_blob->blob  = local_blob;
    return 1;
}

int lua_git_blob_owner(lua_State *L) {

    if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blob");
    }

    luagit2_repository *lua_repo;
    const luagit2_blob *lua_blob = (luagit2_blob *)luaL_checkudata(L, 1,"luagit2_blob");

    lua_repo = (luagit2_repository *)lua_newuserdata(L, sizeof(*lua_repo));
    lua_repo->repo  = NULL;

    luaL_newmetatable(L, "luagit2_repository");
    lua_setmetatable(L, -2);

    lua_repo->repo = git_blob_owner(lua_blob->blob);

    return 1;
}

int lua_git_blob_rawsize(lua_State *L) {

    if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blob");
    }

    luagit2_off_t *lua_blob_size;
    const luagit2_blob *lua_blob = (luagit2_blob *)luaL_checkudata(L, 1,"luagit2_blob");

    lua_blob_size = (luagit2_off_t *)lua_newuserdata(L, sizeof(*lua_blob_size));

    luaL_newmetatable(L, "luagit2_off_t");
    lua_setmetatable(L, -2);

    lua_blob_size->size = git_blob_rawsize(lua_blob->blob);

    return 1;
}

int lua_git_blob_free(lua_State *L) {

    if (lua_gettop(L) != 1) {
        return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blob");
    }

    const luagit2_blob *lua_blob = (luagit2_blob *)luaL_checkudata(L, 1,"luagit2_blob");
    git_blob_free(lua_blob->blob);

    return 1;
}
