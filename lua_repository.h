#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

struct opts {
	int quiet;
	int bare;
	int initial_commit;
	uint32_t shared;
	const char *template;
	const char *gitdir;
};

static uint32_t parse_shared( char *shared)
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
		return (uint32_t)val;
	}

	return 0;
}

static void create_initial_commit(git_repository *repo)
{
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;

	/** First use the config to initialize a commit signature for the user. */

	if (git_signature_default(&sig, repo) < 0)
		printf("Unable to create a commit signature. \n"
		      "Perhaps 'user.name' and 'user.email' are not set");

	/* Now let's create an empty tree for this commit */

	if (git_repository_index(&index, repo) < 0)
		printf("Could not open repository index");

	/**
	 * Outside of this example, you could call git_index_add_bypath()
	 * here to put actual files into the index.  For our purposes, we'll
	 * leave it empty for now.
	 */

	if (git_index_write_tree(&tree_id, index) < 0)
		printf("Unable to write initial tree from index");

	git_index_free(index);

	if (git_tree_lookup(&tree, repo, &tree_id) < 0)
		printf("Could not look up initial tree");

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
		printf("Could not create the initial commit");

	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
}


static int lua_git_repository_init(lua_State *L){
	
	git_repository *repo = NULL;
	char *path = luaL_checkstring(L,1);
	int is_bare = luaL_checkint(L,2);

	git_repository_init(&repo, path, is_bare),
	printf("Initialized empty Git repository in %s\n", path);

	git_repository_free(repo);

return 1;
}

static int lua_git_repository_init_ext(lua_State *L){

	struct opts options = { 0, 0, 0, GIT_REPOSITORY_INIT_SHARED_UMASK, 0, 0 };
    struct opts *o_pointer;
    o_pointer = &options;

	char *path = luaL_checkstring(L,2);



	lua_settop(L, 1); //set the table to the top
    luaL_checktype(L, 1, LUA_TTABLE);

    lua_getfield(L, 1, "quiet");                 // -6
    lua_getfield(L, 1, "shared");                 // -5
    lua_getfield(L, 1, "bare");                   // -4
    lua_getfield(L, 1, "template");               // -3
    lua_getfield(L, 1, "initial-commit");         // -2 
    lua_getfield(L, 1, "separate_git_dir");       // -1

    int is_quiet = luaL_checkint(L, -6);
    char *shared_option = luaL_checkstring(L, -5);
    int is_bare = luaL_checkint(L, -4);
    int *template_dir = luaL_checkstring(L,-3);
    int do_initial_commit = luaL_checkint(L,-2);
    char *separate_git_dir = luaL_checkstring(L,-1);

	git_repository *repo = NULL;
	
	git_repository_init_options initopts = GIT_REPOSITORY_INIT_OPTIONS_INIT;
	initopts.flags = GIT_REPOSITORY_INIT_MKPATH;

	//set conditions flags by here //////////////////////////////////////
	if(is_quiet != NULL){
    	if(is_quiet == 1){
    		o_pointer->quiet = 1;
    	}
    	if(is_quiet == 0){
    		o_pointer->quiet = 0;
    	}
    }
    if(shared_option != NULL){
    	o_pointer->shared = parse_shared(shared_option);
    }
    if(is_bare != NULL){
    	if(is_bare == 1){
    		o_pointer->bare = 1;
    	}
    	if(is_bare == 0){
    		o_pointer->bare = 0;
    	}
    }
    if (template_dir != NULL){
    	o_pointer->template = template_dir;
    }
    if(do_initial_commit != NULL){
    	if(do_initial_commit == 1){
    		o_pointer->initial_commit = 1;
    	}
    	if(do_initial_commit == 0){
    		o_pointer->initial_commit = 0;
    	}
    }
    if (separate_git_dir != NULL){
    	o_pointer->gitdir = separate_git_dir;
    }

    ///////////////////////////////////////////////////////////////////////////////////////

    if (options.bare){
			initopts.flags |= GIT_REPOSITORY_INIT_BARE;
	}

	if (options.template) {
		initopts.flags |= GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE;
		initopts.template_path = options.template;
	}

	if (options.gitdir) {
			
		initopts.workdir_path = path;
		path = options.gitdir;
	}

	if (options.shared != 0){
	    initopts.mode = options.shared;
	}
 

    ///////////////////////////////////////////////////////////////////////////////////////

	git_repository_init_ext(&repo, path , &initopts);
	printf("Initialized empty Git repository in %s\n", path);
	if(options.initial_commit){
		create_initial_commit(&repo);
		printf("Created empty initial commit\n");
	}
	git_repository_free(repo);
	
return 1;
}


/*       EXAMPLE USAGE       
libluagit2.lua_git_repository_init_ext(  {quiet=1, shared = all ,
											bare = 1 , 
											template = path-to-template ,
											initial-commit = 1 ,
											separate_git_dir = path } ,path-to-store )
*/


static int lua_git_repository_is_bare(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    int  result = git_repository_is_bare(repo);

    lua_pushinteger(L, result);
    printf("SUCCESS ");
    git_repository_free(repo);
return 1;    
}

static int lua_git_repository_is_empty(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    int result = git_repository_is_empty(repo);

    lua_pushinteger(L, result);
    printf("SUCCESS ");
    git_repository_free(repo);
return 1;    
}

static int lua_git_repository_is_shallow(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    int result = git_repository_is_shallow(repo);

    lua_pushinteger(L, result);
    printf("SUCCESS ");
    git_repository_free(repo);
return 1;    
}

static int lua_git_repository_is_worktree(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    int result = git_repository_is_worktree(repo);

    lua_pushinteger(L, result);
    printf("SUCCESS ");
    git_repository_free(repo);
return 1;    
}

static int lua_git_repository_set_bare(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    git_repository_set_bare(repo);
    printf("SUCCESS ");
    git_repository_free(repo);
	return 1;
}

static int lua_git_repository_set_head(lua_State *L){
	char *path = luaL_checkstring(L,1);
	char *refname = luaL_checkstring(L,2); // refname here points to a branch name or Tree or Blob
	git_repository *repo = NULL;

    git_repository_open(&repo , path);

    git_repository_set_head(repo , refname);
    printf("SUCCESS ");
    git_repository_free(repo);
	return 1;
}



static int lua_git_repository_set_ident(lua_State *L){
	char *path = luaL_checkstring(L,1);
	char *name = luaL_checkstring(L,2); // refname here points to a branch name or Tree or Blob
	char *email = luaL_checkstring(L,3);

	git_repository *repo = NULL;

    git_repository_open(&repo , path);

    git_repository_set_ident(repo , name , email);
    printf("SUCCESS ");
    git_repository_free(repo);
	return 1;
}

static int lua_git_repository_state(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    int result = git_repository_state(repo);

    lua_pushinteger(L, result);
    printf("SUCCESS ");
    git_repository_free(repo);
return 1;    
}

static int lua_git_repository_state_cleanup(lua_State *L){
	char *path = luaL_checkstring(L,1);
	git_repository *repo = NULL;

    git_repository_open(&repo , path);
    int result = git_repository_state_cleanup(repo);

    lua_pushinteger(L, result);
    printf("SUCCESS ");
    git_repository_free(repo);
return 1;    
}


