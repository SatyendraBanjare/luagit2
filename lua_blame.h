#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "common.h"

static int lua_git_blame_file(lua_State *L)
{
	char *path = luaL_checkstring(L,1);
	char *filepath = luaL_checkstring(L,2);
	int line, break_on_null_hunk;
	size_t i, rawsize;
	char spec[1024] = {0};
	

	const char *rawdata;
	git_repository *repo = NULL;
	git_revspec revspec = {0};
	git_blame_options blameopts = GIT_BLAME_OPTIONS_INIT;
	git_blame *blame = NULL;
	git_blob *blob;
	git_object *obj;

	git_repository_open(&repo, path);
	
	
	git_blame_file(&blame, repo, filepath, &blameopts);

	if (git_oid_iszero(&blameopts.newest_commit))
		strcpy(spec, "HEAD");
	else
		git_oid_tostr(spec, sizeof(spec), &blameopts.newest_commit);
	strcat(spec, ":");
	strcat(spec, filepath);

	check_lg2(git_revparse_single(&obj, repo, spec), "Object lookup error", NULL);
	check_lg2(git_blob_lookup(&blob, repo, git_object_id(obj)), "Blob lookup error", NULL);
	git_object_free(obj);

	rawdata = git_blob_rawcontent(blob);
	rawsize = git_blob_rawsize(blob);

	/** Produce the output. */
	line = 1;
	i = 0;
	break_on_null_hunk = 0;
	while (i < rawsize) {
		const char *eol = memchr(rawdata + i, '\n', rawsize - i);
		char oid[10] = {0};
		const git_blame_hunk *hunk = git_blame_get_hunk_byline(blame, line);

		if (break_on_null_hunk && !hunk)
			break;

		if (hunk) {
			char sig[128] = {0};
			break_on_null_hunk = 1;
			
			git_oid_tostr(oid, 10, &hunk->final_commit_id);
			snprintf(sig, 30, "%s <%s>", hunk->final_signature->name, hunk->final_signature->email);

			printf("%s ( %-30s %3d) %.*s\n",
					oid,
					sig,
					line,
					(int)(eol - rawdata - i),
					rawdata + i);
		}

		i = (int)(eol - rawdata + 1);
		line++;
	}

	/** Cleanup. */
	git_blob_free(blob);
	git_blame_free(blame);
	git_repository_free(repo);

	return 0;
}