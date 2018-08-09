Commit
======

These methods help in creating new ``git commits`` and 
extracting information about already created commits. 

.. contents:: Contents
   :local:

commit_author 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose author is to be known.

* Returns a ``luagit2_signature`` for commit's author or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_author

commit_body 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | body_data (string)              |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose contents are to be found out.

* Returns a string for commit's content or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_body

commit_committer 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose committer is to be known.

* Returns a ``luagit2_signature`` for commit's committer or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_committer

commit_extract_signature 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_buf (signature)         |
+---------------------------+---------------------------------+
| luagit2_oid               | luagit2_buf (extra)             |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look in for the commit's details.
2. ``luagit2_oid`` : The commit's oid to look for.

* Returns two ``luagit2_buf`` or gives an error. The first buf is for signature details and other is extra for the commit's details. Example : 
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_extract_signature

Example: 

.. code:: lua
	
	local sign_buf, extra_buf = luagit2.commit_extract_signature(repo,commit_oid)


commit_header_field 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_buf                     |
+---------------------------+                                 +
| field (string)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose header field is to be known.
2. ``field`` : the stringvalue of field to lookup for.

* returns ``luagit2_buf`` for the details or gives an error. 
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_header_field

commit_lookup 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_commit                  |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : the repository in which commit is to be looked up.
2. ``luagit2_oid`` : the oid of commit to be looked up.

* returns ``luagit2_commit`` for the commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_lookup

commit_lookup_prefix 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_commit                  |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+                                 +
| length (int)              |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : the repositpry in which commit is to be looked up.
2. ``luagit2_oid`` : the oid of commit to be looked up.
3. ``length`` : the number of first `n` characters to be used to look up for the commit in repository.

* returns ``luagit2_commit`` for the commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_lookup_prefix

commit_message 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | message_data (string)           |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose message is to be found out.

* Returns a string for commit's message or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_message

commit_message_encoding 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | message_encoding (string)       |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose message's encoding is to be found out.

* Returns a string for commit's message encoding which is used or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_message_encoding

commit_message_raw 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | raw_message_data (string)       |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose message are to be found out.

* Returns a string for commit's raw message or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_message_raw

commit_nth_gen_ancestor 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_commit                  |
+---------------------------+                                 +
| nth_generation (int)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose ancestors are to be found.
2. ``nth_generation`` : How old ancestor commit is to be found.

* returns a ``luagit2_commit`` of the ancestor or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_nth_gen_ancestor

commit_parent 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_commit                  |
+---------------------------+                                 +
| position (int)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose parents are to be found.
2. ``position`` : How old parent should be. The `0`th parent means immediate parent commit and `1` for one previous to immediate parent commit. 

* returns a ``luagit2_commit`` of the parent commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_parent

commit_parent_id 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_oid                     |
+---------------------------+                                 +
| position (int)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose parents are to be found.
2. ``position`` : How old parent should be. The `0`th parent means immediate parent commit and `1` for one previous to immediate parent commit. 

* returns a ``luagit2_oid`` of the parent commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_parent_id

commit_parentcount 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | parent_count (int)              |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose number of parents are to be found.

* returns the number of parent commits or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_parentcount

commit_raw_header 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | raw_header (string)             |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose raw header is to be found.

* returns the raw header data for the commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_raw_header

commit_summary 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | commit_summary (string)         |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose message summary is to be found.

* returns the message summary string for the commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_summary

commit_time 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | commit_time (string)            |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose commit time is to be found.

* returns the commit_time string for the commit or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_time

commit_tree 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_tree                    |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose tree is to be found.

* returns the ``luagit2_tree`` for the commit's parent tree or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_tree

commit_tree_id 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose tree's oid is to be found.

* returns the ``luagit2_oid`` for the commit's parent tree oid or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_tree_id

commit_free 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit which is to be freed.

* returns none or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_free

commit_id
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_commit            | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_commit`` : The commit whose oid is to be found out.

* returns ``luagit2_oid`` for the commit's oid or gives an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_id

commit_create_update_head 
-----------------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| message (string)             |                                 |
+------------------------------+                                 +
| luagit2_tree                 |                                 |
+------------------------------+                                 +
| luagit2_commit (immediate    |                                 |
| parent commit )              |                                 |
+------------------------------+---------------------------------+


1. ``luagit2_repository`` : The repository where to create a new commit.
2. ``luagit2_signature(author)`` : The author's signature.
3. ``luagit2_signature(committer)`` : The committer's signature.
4. ``Message`` : The string message to be created with new commit.
5. ``luagit2_tree`` : The tree in which the commit is to be made.
6. ``luagit2_commit`` : The immediate parent commit which is to be used to create the new commit.

.. note:: The parent commit should not have any child commits. Also the parent commit should also belong to that same tree.

* returns a ``luagit2_oid`` of the newly created commit or gives an error. This method updates the **HEAD** tip of git repository so if you do a git log, it will show the output of latest commit. 

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_create_v

commit_create_update_none 
-----------------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| message (string)             |                                 |
+------------------------------+                                 +
| luagit2_tree                 |                                 |
+------------------------------+                                 +
| luagit2_commit (immediate    |                                 |
| parent commit )              |                                 |
+------------------------------+---------------------------------+


1. ``luagit2_repository`` : The repository where to create a new commit.
2. ``luagit2_signature(author)`` : The author's signature.
3. ``luagit2_signature(committer)`` : The committer's signature.
4. ``Message`` : The string message to be created with new commit.
5. ``luagit2_tree`` : The tree in which the commit is to be made.
6. ``luagit2_commit`` : The immediate parent commit which is to be used to create the new commit.

.. note:: The parent commit should not have any child commits. Also the parent commit should also belong to that same tree.

* returns a ``luagit2_oid`` of the newly created commit or gives an error. This method **does not** update the **HEAD** tip of git repository so if you do a git log, it **will not** show the output of latest commit. 

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_create_v

commit_create_with_signature 
-----------------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| commit_content(string)       |                                 |
+------------------------------+                                 +
| commit_sign(string)          |                                 |
+------------------------------+---------------------------------+


1. ``luagit2_repository`` : The repository where to create a new commit.
2. ``commit_content`` : The content to be used to make a commit. It should contain details of parent, tree, author, committer and commit message.
3. ``commit_sign`` : The committer's **pgp** signature.

* returns a ``luagit2_oid`` for the new created commit or gives an error.This method updates the **HEAD** tip of git repository so if you do a git log, it will show the output of latest commit. 
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_create_with_signature

.. note:: The data used for creating commit should be all valid. the parent commit should be immediate and of same tree.

Example :

.. code:: lua
	
	local gpgsig = "-----BEGIN PGP SIGNATURE-----\n\
	Version: GnuPG v1.4.12 (Darwin)\n\
	\n\
	iQIcBAABAgAGBQJQ+FMIAAoJEH+LfPdZDSs1e3EQAJMjhqjWF+WkGLHju7pTw2al\n\
	o6IoMAhv0Z/LHlWhzBd9e7JeCnanRt12bAU7yvYp9+Z+z+dbwqLwDoFp8LVuigl8\n\
	JGLcnwiUW3rSvhjdCp9irdb4+bhKUnKUzSdsR2CK4/hC0N2i/HOvMYX+BRsvqweq\n\
	AsAkA6dAWh+gAfedrBUkCTGhlNYoetjdakWqlGL1TiKAefEZrtA1TpPkGn92vbLq\n\
	SphFRUY9hVn1ZBWrT3hEpvAIcZag3rTOiRVT1X1flj8B2vGCEr3RrcwOIZikpdaW\n\
	who/X3xh/DGbI2RbuxmmJpxxP/8dsVchRJJzBwG+yhwU/iN3MlV2c5D69tls/Dok\n\
	6VbyU4lm/ae0y3yR83D9dUlkycOnmmlBAHKIZ9qUts9X7mWJf0+yy2QxJVpjaTGG\n\
	cmnQKKPeNIhGJk2ENnnnzjEve7L7YJQF6itbx5VCOcsGh3Ocb3YR7DMdWjt7f8pu\n\
	c6j+q1rP7EpE2afUN/geSlp5i3x8aXZPDj67jImbVCE/Q1X9voCtyzGJH7MXR0N9\n\
	ZpRF8yzveRfMH8bwAJjSOGAFF5XkcR/RNY95o+J+QcgBLdX48h+ZdNmUf6jqlu3J\n\
	7KmTXXQcOVpN6dD3CmRFsbjq+x6RHwa8u1iGn+oIkX908r97ckfB/kHKH7ZdXIJc\n\
	cpxtDQQMGYFpXK/71stq\n\
	=ozeK\n\
	-----END PGP SIGNATURE-----";

	local commit_data =  "tree 1b49a09ae5e707b8ed48e6048aa1901138838944\n\
	parent 108ddee361877aa5c044d89d8dd232b8fd0f8992\n\
	author Test_user <test@example.com> 1358451456 -0800\n\
	committer Test_user <test@example.com> 1358451456 -0800\n\
	\n\
	new commit which works\n";

	local new_commit_id = luagit2.commit_create_with_signature(repo,data,gpgsig)


commit_create_initial 
-----------------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| message (string)             |                                 |
+------------------------------+                                 +
| luagit2_tree                 |                                 |
+------------------------------+---------------------------------+


1. ``luagit2_repository`` : The repository where to create a new commit.
2. ``luagit2_signature(author)`` : The author's signature.
3. ``luagit2_signature(committer)`` : The committer's signature.
4. ``Message`` : The string message to be created with new commit.
5. ``luagit2_tree`` : The tree in which the initial commit is to be made.

.. note:: This is the first commit to be made in the repository. Take care that there is no previous commit present. The tree for this initial commit, pass value from **index_write_tree()** .

* returns a ``luagit2_oid`` of the newly created commit or gives an error. This method updates the **HEAD** tip of git repository so if you do a git log, it will show the output of latest commit. 

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#v0.27.0/group/commit/git_commit_create_v