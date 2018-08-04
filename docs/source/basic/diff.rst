Diff
====

These Methods allow generating ``git diff`` for added files to current index, 
between files of two trees and trees 

.. contents:: Contents
   :local:

diff_init_options 
---------------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_diff_options            |
+---------------------------+---------------------------------+

* There are no parameters required. This is an important function to initialize a init_options to be used in other functions of this module.

diff_get_stats 
---------------------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff              | luagit2_diff_stats              |
+---------------------------+---------------------------------+

1. ``luagit2_diff`` : The diff whose stats are to be found.

* Returns ``luagit2_diff_stats`` or gives an error.

diff_index_to_index 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_diff                    |
+---------------------------+                                 +
| luagit2_index(old)        |                                 |
+---------------------------+                                 +
| luagit2_index(new)        |                                 |
+---------------------------+                                 +
| luagit2_diff_options      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for the files.
2. ``luagit2_index`` : The old index.
3. ``luagit2_index`` : The new index to compare.
4. ``luagit2_diff_options`` :The diff options.

* Returns ``luagit2_diff`` or gives an error. 

diff_index_to_workdir 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_diff                    |
+---------------------------+                                 +
| luagit2_index(old)        |                                 |
+---------------------------+                                 +
| luagit2_diff_options      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for the files.
2. ``luagit2_index`` : The index to compare.
3. ``luagit2_diff_options`` :The diff options.

* Returns ``luagit2_diff`` or gives an error. 

diff_is_sorted_icase 
---------------------------------
diff_merge 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff (onto)       | None                            |
+---------------------------+                                 +
| luagit2_diff (from)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_diff`` : The diff on which to merge other diff results.
2. ``luagit2_diff`` : The diff to merge. 

* Returns None or gives an error. 

diff_num_deltas 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff              | number_of_deltas(integer)       |
+---------------------------+---------------------------------+

1. ``luagit2_diff`` : The diff whose number of deltas is to be found. 

* Returns numerical value of number of deltas or gives an error. 

diff_stats_deletions 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff_stats        | number_of_deletion (integer)    |
+---------------------------+---------------------------------+

1. ``luagit2_diff_stats`` : The diff stats whose number of line deletions is to be found. 

* Returns numerical value of number of line deletions in a given diff or gives an error. 

diff_stats_files_changed 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff_stats        | number_of_changes(integer)      |
+---------------------------+---------------------------------+

1. ``luagit2_diff_stats`` : The diff stats whose number of file changes is to be found. 

* Returns numerical value of number of file changed in a given diff or gives an error. 

diff_stats_insertions 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff_stats        | number_of_insertions (integer)  |
+---------------------------+---------------------------------+

1. ``luagit2_diff_stats`` : The diff stats whose number of line insertions is to be found. 

* Returns numerical value of number of line insertions in a given diff or gives an error. 

diff_stats_to_buf 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff_stats        | luagit2_buf                     |
+---------------------------+                                 +
| luagit2_diff_stats_format |                                 |
+---------------------------+                                 +
| width (integer)           |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_diff_stats`` : The diff stats which is to be formatted into a lua buf.
2. ``luagit2_diff_stats_format`` : The format in which the diff stats is to be formatted. This can be a value returned by any of these possible options in this helper method : ``diff_stats_format_init()``. The options are **none** ,**full** , **short** , **number** , **summary**.

* Returns ``luagit2_buf`` for the formatted diff stats or gives an error. 

diff_to_buf
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_diff_stats        | luagit2_buf                     |
+---------------------------+                                 +
| luagit2_diff_format       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_diff_stats`` : The diff stats which is to be formatted into a lua buf.
2. ``luagit2_diff_format`` : The format in which the diff stats is to be formatted. This can be a value returned by any of these possible options in this helper method : ``diff_format_init()``. The options are **patch** ,**patch_header**,**raw**,**name_only**,**name_status** .

* Returns ``luagit2_buf`` fir the formatted diff  or gives an error. 

diff_tree_to_index 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_diff                    |
+---------------------------+                                 +
| luagit2_tree              |                                 |
+---------------------------+                                 +
| luagit2_index(new)        |                                 |
+---------------------------+                                 +
| luagit2_diff_options      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look files into.
2. ``luagit2_tree`` : The tree to compare with.
3. ``luagit2_index`` : The index to compare.
4. ``luagit2_diff_options`` : THe necessary diff options.

* Returns a ``luagit2_diff`` or gives an error.

diff_tree_to_tree 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_diff                    |
+---------------------------+                                 +
| luagit2_tree(old)         |                                 |
+---------------------------+                                 +
| luagit2_tree (new)        |                                 |
+---------------------------+                                 +
| luagit2_diff_options      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look files into.
2. ``luagit2_tree`` : The old tree to compare with.
3. ``luagit2_tree`` : The new tree to compare.
4. ``luagit2_diff_options`` : THe necessary diff options.

* Returns a ``luagit2_diff`` or gives an error.

diff_tree_to_workdir 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_diff                    |
+---------------------------+                                 +
| luagit2_tree              |                                 |
+---------------------------+                                 +
| luagit2_diff_options      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look files into.
2. ``luagit2_tree`` : The old tree to compare current workdir files with.
3. ``luagit2_diff_options`` : THe necessary diff options.

* Returns a ``luagit2_diff`` or gives an error.

diff_tree_to_workdir_with_index 
---------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_diff                    |
+---------------------------+                                 +
| luagit2_tree              |                                 |
+---------------------------+                                 +
| luagit2_diff_options      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look files into.
2. ``luagit2_tree`` : The old tree to compare files with that are present in current workdir **and also in current index too**.
3. ``luagit2_diff_options`` : THe necessary diff options.

* Returns a ``luagit2_diff`` or gives an error.

