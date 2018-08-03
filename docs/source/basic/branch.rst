Branch
======

These methods allows user to work with ``git branches`` of a given repository.

These help to create, delete, iterate over list of branches
and setting upstreams for a branch.

.. contents:: Contents
   :local:

branch_create 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference               +
| branch_name (string)      |                                 |
+---------------------------+                                 +
| luagit2_commit            |                                 |
+---------------------------+                                 +
| force (int)               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to create a new branch in.
2. ``branch_name`` : the name of new branch to create .
3. ``luagit2_commit`` : the last commit using which the branch will be created.
4. ``force`` : integer equivalent of boolean whether or not force create a new branch.

* Creates a ``luagit2_reference`` for the new created branch.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_create

branch_create_from_annotated 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference               +
| branch_name (string)      |                                 |
+---------------------------+                                 +
| luagit2_annotated_commit  |                                 |
+---------------------------+                                 +
| force (int)               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to create a new branch in.
2. ``branch_name`` : the name of new branch to create .
3. ``luagit2_annotated_commit`` : the annptated commit using which the branch will be created.
4. ``force`` : integer equivalent of boolean whether or not force create a new branch.

* Creates a ``luagit2_reference`` for the new created branch.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_create_from_annotated

branch_delete 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  None                           |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch which is to be deleted.

* returns none or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_delete

branch_is_checked_out 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  Boolean                        |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch which to check.

* returns boolean for whether branch is currently checked out or not.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_is_checked_out

branch_is_head 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  Boolean                        |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch which to check.

* returns boolean for whether branch is being pointed by ``HEAD`` or not.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_is_head

branch_iterator_new 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_branch_iterator         +
| luagit2_branch_type       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look for the list of branches.
2. ``luagit2_branch_type`` : the type of branches to look .It can be either LOCAL or REMOTE. It can be created using luagit2's branch helper methods ``get_type_GIT_BRANCH_LOCAL`` & ``get_type_GIT_BRANCH_REMOTE`` .

* Creates a ``luagit2_branch_iterator`` for list of branches. The list index starts with 0. 

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_iterator_new

branch_lookup 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference               +
| branch_name (string)      |                                 |
+---------------------------+                                 +
| luagit2_branch_type       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the given branch.
2. ``branch_name`` : the path to the blob in repository .
3. ``luagit2_branch_type`` : the type of branches to look . It can be either LOCAL or REMOTE. It can be created using luagit2's branch helper methods ``get_type_GIT_BRANCH_LOCAL`` & ``get_type_GIT_BRANCH_REMOTE`` .



* Creates a ``luagit2_reference`` from looked up branch or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_lookup

branch_move 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |                                 |
+---------------------------+ luagit2_reference               +
| new_branch_name (string)  |                                 |
+---------------------------+                                 +
| force (int)               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch which is to be moved to a new name.
2. ``new_branch_name`` : The new branch name.
3. ``force`` : integer equivalent of bool to force branch moving.


* Creates a ``luagit2_reference`` for new branch or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_move

branch_name 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  String (name)                  |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch whose name is to be found.

* returns name of branch or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_name

branch_next 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_branch_type       |                                 |
+---------------------------+   luagit2_reference             +
| luagit2_branch_iterator   |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_branch_type`` : The type of branches to look .It can be either LOCAL or REMOTE. It can be created using luagit2's branch helper methods ``get_type_GIT_BRANCH_LOCAL`` & ``get_type_GIT_BRANCH_REMOTE`` .
2. ``luagit2_branch_iterator`` : The branch iterator that contains list of all branches .

* Creates a ``luagit2_reference`` for next branch.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_next

branch_set_upstream 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |                                 |
+---------------------------+ None                            +
| upstream_name(string)     |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch.
2. ``upstream_name`` : The upstream's name.

* returns none or an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_set_upstream

branch_upstream 
--------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  luagit2_reference              |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference for the branch whose upstream branch is to be found.

* Creates a ``luagit2_reference`` of upstream branch or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/branch/git_branch_upstream

