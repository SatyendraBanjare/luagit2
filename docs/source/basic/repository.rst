Repository
==========

.. contents:: Contents
   :local:


repository_commondir
---------------------------------------------

Get the path of the shared common directory for this repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | common_dir_path (string)        |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose path is to be found.

* Returns common dir path of given repository.

repository_config 
---------------------------------------------

Get the repository's config.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_config                  |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose config is to be found.

* Returns corresponding ``luagit2_config`` or gives an error.

repository_config_snapshot 
---------------------------------------------

Get the repository's config snapshot.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_config                  |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose config is to be found.

* Returns corresponding snapshot type of ``luagit2_config`` or gives an error.

repository_detach_head 
---------------------------------------------

Detach the repository's HEAD so that HEAD now points to nothing.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose HEAD is to be detached.

* Returns None or gives an error.

repository_get_namespace
---------------------------------------------

Get the namespace value for a given repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | namespace (string)              |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose namespace is to be found.

* Returns corresponding namespace or gives an error.

repository_head 
---------------------------------------------

Get the Reference being pointed by the repository's HEAD.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_reference               |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose reference being pointed by HEAD is to be found.

* Returns corresponding ``luagit2_reference`` or gives an error.

repository_head_detached 
---------------------------------------------

Check if repository's HEAD is detached or not.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_detached (boolean)           |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be checked.

* Returns Boolean equivalent for if the HEAD is detached or not. 

repository_head_for_worktree 
---------------------------------------------

Get The HEAD for the worktree.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference               +
| worktree_name (string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for worktree.
2. ``worktree_name`` : The name of worktree to look for.

* Returns corresponding ``luagit2_reference`` or gives an error.

repository_head_unborn 
---------------------------------------------

Check if HEAD for the repository is unborn, it is not at all created.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_unborn   (boolean)           |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be checked.

* Returns Boolean equivalent for if the HEAD is unborn or not.

repository_ident 
---------------------------------------------

Get the repository's identity details.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | name (string)                   |
+---------------------------+---------------------------------+
|                           | email (string)                  |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose identity details are to be found.

* Returns two values as name and email for set repo's variables.

repository_index
---------------------------------------------

Get the repository's currently active Index.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_index                   |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose index is to be found.

*  Returns corresponding ``luagit2_index`` or gives an error .

repository_init 
---------------------------------------------

Initialize an empty repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| path_to_repo (string)     |                                 |
+---------------------------+ luagit2_repository              +
| is_bare (integer)         |                                 |
+---------------------------+---------------------------------+

1. ``path_to_repo`` : The path where new repository is to be initialized. 
2. ``is_bare`` : integer equlavalent of boolean for if the new repository should be bare or not.

* Returns a new ``luagit2_repository`` or gives an error.

repository_is_bare 
---------------------------------------------

Check if a repository is bare.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_bare     (boolean)           |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be checked.

* Returns Boolean equivalent for repository it is bare or not.

repository_is_empty 
---------------------------------------------

Check if a repository is empty.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_empty    (boolean)           |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be checked.

* Returns Boolean equivalent for if repository is empty or not.

repository_is_shallow 
---------------------------------------------

Check if a repository is shallow.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_shallow  (boolean)           |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be checked.

* Returns Boolean equivalent for if repository is shallow or not.

repository_is_worktree 
---------------------------------------------

Check if the repository is also worktree. The answer may be different for a submodule repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_worktree (boolean)           |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be checked.

* Returns Boolean equivalent for if repository  is worktree or not.

repository_message 
---------------------------------------------

Get the repository's message.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_buf                     |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose message is to be found.

* Returns message in a ``luagit2_buf`` or gives an error.

repository_message_remove 
---------------------------------------------

Remove message for the repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose message is to be removed.

* Returns none or gives an error.

repository_odb 
---------------------------------------------

Get a repo's odb (object database).

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_odb                     |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose odb is to be removed.

* Returns corresponding ``luagit2_odb`` or gives an error.

repository_open
---------------------------------------------

Open a repository at a given path.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| path_to_repo (string)     | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``path_to_repo`` : The path to repository to be opened.

* Returns corresponding ``luagit2_repository`` or gives an error.

repository_open_bare
---------------------------------------------

Open a repository as bare repository at a given path.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| path_to_repo (string)     | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``path_to_repo`` : The path to repository to be opened.

* Returns corresponding ``luagit2_repository`` or gives an error.

repository_open_from_worktree 
---------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_worktree          | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_worktree`` : The worktree using which repository is to be opened.

* Returns corresponding ``luagit2_repository`` or gives an error.

repository_path 
---------------------------------------------

Get the repository's path.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | path (string)                   |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose path is to be found.

* Returns corresponding repository's path or gives an error.

repository_refdb 
---------------------------------------------

Get the repository's reference database.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_refdb                   |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose reference database is to be found .

* Returns corresponding repository's ``luagit2_refdb`` or gives an error.

repository_set_head 
---------------------------------------------

set the HEAD of the repository to point to a given ref name.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| ref_name (string)         |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose HEAD is to be set.
2. ``ref_name`` : The reference name where the repository should point at.

* Returns None or gives an error.

repository_set_head_detached 
---------------------------------------------

Set the detached HEAD to point to a commit. It will not make HEAD point to a reference.
HEAD simply points to a given commit id.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose HEAD is to be set in a detached manner.
2. ``luagit2_oid`` : Object id of the Commit the HEAD should point to.

* Returns None or gives error.

repository_set_ident 
---------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| name (string)             |                                 |
+---------------------------+                                 +
| email(string)             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose identity variables are to be set.
2. ``name`` : The name to be set.
3. ``email`` : The email variable to be set.

* Returns none or gives an error.

repository_set_namespace 
---------------------------------------------

Set the namespace of the repository .

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| namespace(string)         |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose namespace is to be set.
2. ``namespace`` : The namespace to be used.

* Returns None or gives an error.

repository_set_workdir 
---------------------------------------------

Set the work directory of the repository .

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| workdir(string)           |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose workdir is to be set.
2. ``workdir`` : The path of work directory to be used.

* Returns None or gives an error.

repository_state 
---------------------------------------------

Get the integer value of a repository's state values.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | state(integer)                  |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : the repository whose state values are to be found.

* Returns an integer value for state values flag set.

repository_state_cleanup 
---------------------------------------------

Cleanup the state values for a repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose state values are to be cleaned.

* Returns none or gives error.

repository_workdir 
---------------------------------------------

Get the repository's work directory.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | work_dir (string)               |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose workdir is to be found.

* Returns the workdir path for the repository or gives an error.

repository_free 
---------------------------------------------

Frees a used luagit2_repository object.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository object to be freed.

* Returns None or gives error.

repository_submodule_cache_all 
---------------------------------------------

Cache all the objects of a repository's submodules.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose objects are to cached.

* Returns none.

repository_submodule_cache_clear 
---------------------------------------------

Clear all the cache objects of a repository's submodules.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose caches are to be cleared.

* Returns none.

repository_set_index 
---------------------------------------------

Set the repository's current index.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ NOne                            +
| luagit2_index             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose index is to be set.
2. ``luagit2_index`` : The index to be set.

* Returns None or gives error.

repository_set_bare 
---------------------------------------------

Set the repo to be bare.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to be set bare.

* Returns none.

repository_set_config 
---------------------------------------------

Set the repository's current config values.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ NOne                            +
| luagit2_config            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose config is to be set.
2. ``luagit2_config`` : The config to be set.

* Returns None or gives error.

repository_set_odb 
---------------------------------------------

Set the repository's current odb.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ NOne                            +
| luagit2_odb               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose Odb is to be set.
2. ``luagit2_odb`` : The Odb to be set.

* Returns None or gives error.

repository__cleanup
---------------------------------------------

Cleans up the repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to be cleaned.

* Returns none.


