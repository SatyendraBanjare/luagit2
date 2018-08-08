Index
=====

These Methods allow us to read, modify, create, delete working index for a given
``git repository``.

.. contents:: Contents
   :local:

index_add
--------------------------

Add an index entry to a present index in a git repo.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| luagit2_index_entry       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to add a new index entry.
2. ``luagit2_index_entry`` : The Index entry to be added.

* returns None or gives an error. 

index_add_bypath
--------------------------

Add a file to a present index in a git repo.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| file_path (string)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to add a new index entry.
2. ``file_path`` : The path of file to be added.

* returns None or gives an error. 

index_caps
--------------------------

Get index capabilities flags value for a present index in a git repo.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | Caps_val (integer)              |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to add a new index entry.

* returns an integer or gives an error. 

index_checksum
--------------------------

Get the checksum of the index. A luagit2_oid is returned whose str value is equal to index's checksum.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index whose checksum to find.

* returns corresponding ``luagit2_oid`` or gives an error.

index_conflict_add
--------------------------

Add or update index entries to represent a conflict. Any staged entries that exist at the given paths will be removed.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_index                | None                            |
+------------------------------+                                 +
| luagit2_index_entry(ancestor)|                                 |
+------------------------------+                                 +
| luagit2_index_entry(ours)    |                                 |
+------------------------------+                                 +
| luagit2_index_entry(theirs)  |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to add.
2. ``luagit2_index_entry`` : The entry data for the ancestor of the conflict.
3. ``luagit2_index_entry`` : The entry data for our side of the merge conflict.
4. ``luagit2_index_entry`` : The entry data for their side of the merge conflict.

* Returns None or gives an error.

index_conflict_cleanup
--------------------------

Remove all conflicts in the index

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index whose conflicts are to be cleaned up.

* returns None or gives an error.

index_entry_is_conflict
--------------------------

Return whether the given index entry is a conflict.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index_entry       | is_confict (Boolean)            |
+---------------------------+---------------------------------+

1. ``luagit2_index_entry`` : The index entry to check. 

* returns Boolean for accordingly as if the enrty is a conflict or not or gives an error.

index_entry_stage
--------------------------

Get the staged index value for the index entry.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index_entry       | stage_index (integer)           |
+---------------------------+---------------------------------+

1. ``luagit2_index_entry`` : The index entry for which the stage index value is to be found. 

* returns stage index value of index entry or gives an error.

index_entrycount
--------------------------

Get the number of entries in a luagit2_index.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | entry_count (integer)           |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index whose entry count is to be found.

* Returns integer value of entry count or gives an error.

index_find
--------------------------

Find the first position of any entries which point to given path in the Git index.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | idx_pos (integer)               |
+---------------------------+                                 +
| file_path (string)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to search in.
2. ``file_path`` : The file path to search for.

* Returns an integer value for the index position or gives an error

index_find_prefix
--------------------------

Find the first position of any entries which point to given prefix name in the Git index.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | idx_pos (integer)               |
+---------------------------+                                 +
| prefix_name (string)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to search in.
2. ``prefix_name`` : The prefix name to search for.

* Returns an integer value for the index position or gives an error.

index_get_byindex
--------------------------

Get an Index entry by its index number in a given git index.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | luagit2_index_entry             |
+---------------------------+                                 +
| idx_num (integer)         |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to look for entry.
2. ``idx_pos`` : The index position of entry in the luagit2_index.

* Returns corresponding ``luagit2_index_entry`` or gives an error.

index_get_bypath
--------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | luagit2_index_entry             |
+---------------------------+                                 +
| file_path (string)        |                                 |
+---------------------------+                                 +
| stage_val  (integer)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to search in.
2. ``file_path`` : The file path to search for.
3. ``stage_val`` : The stage value for the indexentry .

*  Returns corresponding ``luagit2_index_entry`` or gives an error.

index_has_conflicts
--------------------------

Check if a luagit2_index has conflicting entries.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | has_conflicts (Boolean)         |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index which is to be checked.

* Returns Boolean value if index has conflicts or gives an error.

index_open
--------------------------

Open a git index from its path.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| index_path (string)       | luagit2_index                   |
+---------------------------+---------------------------------+

* Returns ``luagit2_index`` or gives an error.

index_owner 
--------------------------

Get the owner repo for a given git index

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | luagit2_reposiotory             |
+---------------------------+---------------------------------+

* Returns corresponding owner ``luagit2_reposiotory`` or gives an error.

index_path
--------------------------

Get the file path of a given git index.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | path (string)                   |
+---------------------------+---------------------------------+

* Returns corresponding path or gives an error.

index_read
--------------------------

Update the index by reading values from disk. (actual values in the repo)

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| force (integer)           |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index to be updated.
2. ``force`` : integer equivalent of bool to force reading values from disk.

* Returns none but updated values in the luagit2_index.

index_read_tree
--------------------------

Read values from a given tree into the git index.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| luagit2_tree              |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index to read values into.
2. ``luagit2_tree`` : The tree where to read values from.

* Returns none but updated values in the luagit2_index.

index_remove
--------------------------

Remove an entry from index. This should remove the staged index entry.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| file_path (string)        |                                 |
+---------------------------+                                 +
| stage_val  (integer)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to search in.
2. ``file_path`` : The file path to search for.
3. ``stage_val`` : The stage value for the index entry .

* Returns None or gives an error.

index_remove_bypath
--------------------------

Remove an entry from index using only file path. This should remove the index entry completely.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| file_path (string)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to search in.
2. ``file_path`` : The file path to search for.

* Returns None or gives an error.

index_remove_directory
--------------------------

Remove an Directory from index. This should remove the staged index entry.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| directory_path (string)   |                                 |
+---------------------------+                                 +
| stage_val  (integer)      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index where to search in.
2. ``directory_path`` : The directory path to search for.
3. ``stage_val`` : The stage value for the index entry .

* Returns None or gives an error.

index_set_caps
--------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| caps_val (integer)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index value whose capabilities flags are to be set.
2. ``caps_val`` : The integer value for the flags value of capabilities for index.

* Returns None or gives an error.

index_set_version
--------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+                                 +
| version_number (integer)  |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index value whose capabilities flags are to be set.
2. ``version_number`` : The integer value of version for index.

* Returns None or gives an error.

index_version
--------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | version_number (integer)        |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index whose version is to be found.

* returns None or gives an error.

index_write
--------------------------

Write the index to disk.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index to be written to disk.

* returns None or gives an error.

index_write_tree
--------------------------

Write index to a tree.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index to be written to tree.

* returns ``luagit2_oid`` of the tree or gives an error.

index_write_tree_to
--------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | luagit2_oid                     |
+---------------------------+                                 +
| luagit2_reposiotory       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index to be written to tree.
2. ``luagit2_reposiotory`` : The repository to write to.

* returns ``luagit2_oid`` of the tree or gives an error.

index_free
--------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_index             | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_index`` : The index to be freed.

* returns None or gives an error.
