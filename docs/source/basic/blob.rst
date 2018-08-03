Blob
====

.. contents:: Contents
   :local:


blob_create_fromdisk
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_oid                     +
| path_to_blob(string)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the given blob.
2. ``path_to_blob`` : the path to the blob in repository .

.. note:: The path should be relative to current path, which may or may not inside the directory.

* Creates a ``luagit2_oid`` from blob's path.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_create_fromdisk

blob_create_fromworkdir
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_oid                     +
| path_to_blob(string)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the given blob.
2. ``path_to_blob`` : the path to the blob in repository.

.. note:: The path should be relative to root directory of repository. Prefer this method over **blob_create_fromdisk** while creating blob using its path and not oid.

* Creates a ``luagit2_oid`` from blob's path.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_create_fromdisk


blob_filtered_content
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blob              |                                 |
+---------------------------+ luagit2_buf                     +
| path_to_blob(string)      |                                 |
+---------------------------+                                 +
| check_for_binary_data(int)|                                 |
+---------------------------+---------------------------------+


1. ``luagit2_blob`` : The luagit2_blob whose content to look for .
2. ``path_to_blob`` : the path to the blob in repository.
3. ``check_for_binary_data`` : integer value of bool whether to check or not for filtered content.

.. note:: The path should be relative to root directory of repository.

* Creates a ``luagit2_buf`` from blob's Content, can be read using **buf_details()**.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_filtered_content

blob_id
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blob              | luagit2_oid                     |
+---------------------------+---------------------------------+


1. ``luagit2_blob`` : The blob whose oid is to be found.

.. note:: The path should be relative to root directory of repository.

* Creates a ``luagit2_oid`` for given blob.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_id

blob_is_binary
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blob              | boolean                         |
+---------------------------+---------------------------------+

1. ``luagit2_blob`` : The blob which is to be checked.

* returns boolean if blob is binary or not.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_is_binary

blob_lookup
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_blob                    +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the given blob.
2. ``luagit2_oid`` : the oid of the blob to look for.

* returns ``luagit2_blob`` for given oid or an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_lookup

blob_lookup_prefix
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_blob                    +
| luagit2_oid               |                                 |
+---------------------------+                                 +
| length (int)              |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the given blob.
2. ``luagit2_oid`` : the oid of the blob to look for.
3. ``length`` : length of oid to use for looking up.

* returns ``luagit2_blob`` for given oid or an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_lookup_prefix

blob_owner
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blob              | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_blob`` : The blob whose owner repo is to be found.

* returns ``luagit2_repository`` or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_owner

blob_rawsize
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blob              | size(number)                    |
+---------------------------+---------------------------------+

1. ``luagit2_blob`` : The blob whose content size is to be found.

* returns a numerical value of the blob's size or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_rawsize

blob_free
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blob              | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_blob`` : The blob which is to be freed.

* returns None or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/blob/git_blob_free 

