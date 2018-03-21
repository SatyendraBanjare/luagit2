#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>
#include "common.h"

typedef struct progress_data {
	git_transfer_progress fetch_progress;
	size_t completed_steps;
	size_t total_steps;
	const char *path;
} progress_data;

static void print_progress(const progress_data *pd)
{
	int network_percent = pd->fetch_progress.total_objects > 0 ?
		(100*pd->fetch_progress.received_objects) / pd->fetch_progress.total_objects :
		0;
	int index_percent = pd->fetch_progress.total_objects > 0 ?
		(100*pd->fetch_progress.indexed_objects) / pd->fetch_progress.total_objects :
		0;

	int checkout_percent = pd->total_steps > 0
		? (100 * pd->completed_steps) / pd->total_steps
		: 0;
	int kbytes = pd->fetch_progress.received_bytes / 1024;

	if (pd->fetch_progress.total_objects &&
		pd->fetch_progress.received_objects == pd->fetch_progress.total_objects) {
		printf("Resolving deltas %d/%d\r",
		       pd->fetch_progress.indexed_deltas,
		       pd->fetch_progress.total_deltas);
	} else {
		printf("net %3d%% (%4d kb, %5d/%5d)  /  idx %3d%% (%5d/%5d)  /  chk %3d%% (%4"  "/%4"  ") %s\n",
		   network_percent, kbytes,
		   pd->fetch_progress.received_objects, pd->fetch_progress.total_objects,
		   index_percent, pd->fetch_progress.indexed_objects, pd->fetch_progress.total_objects,
		   checkout_percent,
		   pd->completed_steps, pd->total_steps,
		   pd->path);
	}
}


static void checkout_progress(const char *path, size_t cur, size_t tot, void *payload)
{
	progress_data *pd = (progress_data*)payload;
	pd->completed_steps = cur;
	pd->total_steps = tot;
	pd->path = path;
	print_progress(pd);
}

static int sideband_progress(const char *str, int len, void *payload)
{
	(void)payload; // unused

	printf("remote: %.*s", len, str);
	fflush(stdout);
	return 0;
}

static int fetch_progress(const git_transfer_progress *stats, void *payload)
{
	progress_data *pd = (progress_data*)payload;
	pd->fetch_progress = *stats;
	print_progress(pd);
	return 0;
}

static int lua_git_clone(lua_State *L)
{
	progress_data pd = {{0}};
	git_repository *cloned_repo = NULL;
	git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
	git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;
	const char *url = luaL_checkstring(L,1);
	const char *path = luaL_checkstring(L,2);
	int error;

	// Set up options
	checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
	checkout_opts.progress_cb = checkout_progress;
	checkout_opts.progress_payload = &pd;
	clone_opts.checkout_opts = checkout_opts;
	clone_opts.fetch_opts.callbacks.sideband_progress = sideband_progress;
	clone_opts.fetch_opts.callbacks.transfer_progress = &fetch_progress;

	/*
	Here I have removed the credentials callback so that only public repositories can be cloned by this function. 
	As cloning a private repository Prompts and asks for user credentials.
	*/

	//clone_opts.fetch_opts.callbacks.credentials = cred_acquire_cb;                  <- this line is purposefuly commented out

	clone_opts.fetch_opts.callbacks.payload = &pd;

	// Do the clone
	error = git_clone(&cloned_repo, url, path, &clone_opts);
	printf("\n");
	if (error != 0) {
		const git_error *err = giterr_last();
		if (err) printf("ERROR %d: %s\n", err->klass, err->message);
		else printf("ERROR %d: no detailed info\n", error);
	}
	else if (cloned_repo) git_repository_free(cloned_repo);
	printf("SUCCESS ");

	/*
	need to improve error handling for output of `git_clone` function
	*/

	return 1;
}