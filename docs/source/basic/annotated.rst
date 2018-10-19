Annotated
=========

These are the luagit2 methods that help to produce
annotation commit for the tracked files in a given git 
repository.

These annotation commits can then be used while doing
merge, rebase or creating a branch from an annotated commit.
Refer to this https://libgit2.org/libgit2/#v0.27.0/type/git_annotated_commit. 

.. contents:: Contents
   :local:

annotated_commit_from_ref 
-------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_annotated_commit        +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the reference
2. ``reference_name`` : the reference_name string value using which the annotated commit will be created.

* Creates a ``luagit2_annotated_commit`` from given reference which should be free using `annotated_commit_free`.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/annotated/git_annotated_commit_from_ref

annotated_commit_from_revspec 
-----------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_annotated_commit        +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the given oid.
2. ``luagit2_oid`` : the oid to look for and to be used to create annotated commit.

* Creates a ``luagit2_annotated_commit`` from given revspec which should be free using `annotated_commit_free`.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/annotated/git_annotated_commit_from_revspec


annotated_commit_lookup 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_annotated_commit        +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the annotated commit's oid.
2. ``luagit2_oid`` : the annotated commit's oid to lookup for.

* Creates a ``luagit2_annotated_commit`` from given annotated commit's oid which should be free using `annotated_commit_free`.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/annotated/git_annotated_commit_lookup


annotated_commit_from_fetchhead 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+                                 +
| branch_name (string)      |                                 |
+---------------------------+                                 +
| remote_url_name (string)  |                                 |
+---------------------------+ luagit2_annotated_commit        +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for provided values.
2. ``branch_name`` : The branch name of whose remote url is to be used.
3. ``remote_url_name`` : Name of remote url name.
4. ``luagit2_oid`` : the commit oid (preferably latest) of provided remote branch.

* Creates a ``luagit2_annotated_commit`` from given fetchhead data which should be free using `annotated_commit_free`.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/annotated/git_annotated_commit_from_fetchhead


annotated_commit_id 
-------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_annotated_commit  | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_annotated_commit`` : The annotated commit whose oid is to be found.

* Creates a ``luagit2_oid`` from given annotated_commit.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/annotated/git_annotated_commit_id


annotated_commit_free 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_annotated_commit  | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_annotated_commit`` : The annotated commit which is to be freed.

* Frees a ``luagit2_annotated_commit`` .

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/annotated/git_annotated_commit_free

