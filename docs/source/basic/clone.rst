Clone
=====

These methods help in cloning a valid git repository.

clone_public
------------

.. note:: Only **Public** repositories can be cloned using this function.

+----------------------------+---------------------------------+
| parameters                 | Returns                         |
+============================+=================================+
| path_where_to_save(string) |                                 |
+----------------------------+ None                            +
| url_to_clone (string)      |                                 |
+----------------------------+                                 +
| print_progress (int)       |                                 |
+----------------------------+---------------------------------+

1. ``path_where_to_save`` : The path where to clone the repository. The `git` folder will be saved at provided path. example: If you want to clone a repo at **example_folder** then pass this value as **example_folder/.git** so this example_folder will be top level directory for the cloned repository.
2. ``url_to_clone`` : The url value of git repo to clone
3. ``print_progress`` :  The integer equivalent of whether or not to print progress.

* returns none or an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/clone/git_clone

