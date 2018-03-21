#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "common.h"


struct opts {
	int no_options;
	int quiet;
	int bare;
	int initial_commit;
	uint32_t shared;
	const char *template;
	const char *gitdir;
	const char *dir;
};

static void create_initial_commit(git_repository *repo);
static void parse_opts(struct opts *o, int argc, char *argv[]);


static int  c_gitinit (lua_State *L) {
    git_libgit2_init();

    /* Here I have tried to make make a simple argument array as required to create an empty git repository*/
   char *argv[2]; 
   argv[0] = "--initial-commit";
   argv[1] = "./defgh" ;

    git_repository *repo = NULL;
	struct opts o = { 1, 0, 0, 0, GIT_REPOSITORY_INIT_SHARED_UMASK, 0, 0, 0 };

	git_libgit2_init();

	parse_opts(&o, 2, argv);

	
	if (o.no_options) {
		
		check_lg2(git_repository_init(&repo, o.dir, 0),
			"Could not initialize repository", NULL);
	}
	else {
		git_repository_init_options initopts = GIT_REPOSITORY_INIT_OPTIONS_INIT;
		initopts.flags = GIT_REPOSITORY_INIT_MKPATH;

		if (o.bare){
			initopts.flags |= GIT_REPOSITORY_INIT_BARE;
		}

		if (o.template) {
			initopts.flags |= GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE;
			initopts.template_path = o.template;
		}

		if (o.gitdir) {
			
			initopts.workdir_path = o.dir;
			o.dir = o.gitdir;
		}

		if (o.shared != 0)
			initopts.mode = o.shared;

		check_lg2(git_repository_init_ext(&repo, o.dir, &initopts),
				"Could not initialize repository", NULL);
	}

	if (!o.quiet) {
		if (o.bare || o.gitdir)
			o.dir = git_repository_path(repo);
		else
			o.dir = git_repository_workdir(repo);

		printf("Initialized empty Git repository in %s\n", o.dir);
	}

	
	if (o.initial_commit) {
		create_initial_commit(repo);
		printf("Created empty initial commit\n");
	}

	git_repository_free(repo);
	git_libgit2_shutdown();

    return 1;
}

static void create_initial_commit(git_repository *repo)
{
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;

	/** First use the config to initialize a commit signature for the user. */

	if (git_signature_default(&sig, repo) < 0)
		fatal("Unable to create a commit signature.",
		      "Perhaps 'user.name' and 'user.email' are not set");

	/* Now let's create an empty tree for this commit */

	if (git_repository_index(&index, repo) < 0)
		fatal("Could not open repository index", NULL);

	/**
	 * Outside of this example, you could call git_index_add_bypath()
	 * here to put actual files into the index.  For our purposes, we'll
	 * leave it empty for now.
	 */

	if (git_index_write_tree(&tree_id, index) < 0)
		fatal("Unable to write initial tree from index", NULL);

	git_index_free(index);

	if (git_tree_lookup(&tree, repo, &tree_id) < 0)
		fatal("Could not look up initial tree", NULL);

	/**
	 * Ready to create the initial commit.
	 *
	 * Normally creating a commit would involve looking up the current
	 * HEAD commit and making that be the parent of the initial commit,
	 * but here this is the first commit so there will be no parent.
	 */

	if (git_commit_create_v(
			&commit_id, repo, "HEAD", sig, sig,
			NULL, "Initial commit", tree, 0) < 0)
		fatal("Could not create the initial commit", NULL);

	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
}

static void usage(const char *error, const char *arg)
{
	fprintf(stderr, "error: %s '%s'\n", error, arg);
	fprintf(stderr,
			"usage: init [-q | --quiet] [--bare] [--template=<dir>]\n"
			"            [--shared[=perms]] [--initial-commit]\n"
			"            [--separate-git-dir] <directory>\n");
	exit(1);
}

/** Parse the tail of the --shared= argument. */
static uint32_t parse_shared(const char *shared)
{
	if (!strcmp(shared, "false") || !strcmp(shared, "umask"))
		return GIT_REPOSITORY_INIT_SHARED_UMASK;

	else if (!strcmp(shared, "true") || !strcmp(shared, "group"))
		return GIT_REPOSITORY_INIT_SHARED_GROUP;

	else if (!strcmp(shared, "all") || !strcmp(shared, "world") ||
			 !strcmp(shared, "everybody"))
		return GIT_REPOSITORY_INIT_SHARED_ALL;

	else if (shared[0] == '0') {
		long val;
		char *end = NULL;
		val = strtol(shared + 1, &end, 8);
		if (end == shared + 1 || *end != 0)
			usage("invalid octal value for --shared", shared);
		return (uint32_t)val;
	}

	else
		usage("unknown value for --shared", shared);

	return 0;
}

static void parse_opts(struct opts *o, int argc, char *argv[])
{
	struct args_info args = ARGS_INFO_INIT;
	const char *sharedarg;

	/** Process arguments. */

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		char *a = argv[args.pos];

		if (a[0] == '-')
			o->no_options = 0;

		if (a[0] != '-') {
			if (o->dir != NULL)
				usage("extra argument", a);
			o->dir = a;
		}
		else if (!strcmp(a, "-q") || !strcmp(a, "--quiet"))
			o->quiet = 1;
		else if (!strcmp(a, "--bare"))
			o->bare = 1;
		else if (!strcmp(a, "--shared"))
			o->shared = GIT_REPOSITORY_INIT_SHARED_GROUP;
		else if (!strcmp(a, "--initial-commit"))
			o->initial_commit = 1;
		else if (match_str_arg(&sharedarg, &args, "--shared"))
			o->shared = parse_shared(sharedarg);
		else if (!match_str_arg(&o->template, &args, "--template") ||
		         !match_str_arg(&o->gitdir, &args, "--separate-git-dir"))
			usage("unknown option", a);
	}

	if (!o->dir)
		usage("must specify directory to init", NULL);
}


//library to be registered
static const struct luaL_Reg mylib [] = {
      {"c_gitinit", c_gitinit},
      {NULL, NULL}  /* sentinel */
    };


int luaopen_mylib (lua_State *L){
luaL_register(L, "mylib", mylib);    
return 1;
}