Tree
====

These Methods allow reading values froma ``git tree`` for a given repository and
also helps in comparing them.

.. contents:: Contents
   :local:

tree_entry_byid
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | luagit2_tree_entry              |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree in which entyr is to be looked up.
2. ``luagit2_oid`` : The tree entry oid which is being looked up.

* Returns corresponding ``luagit2_tree_entry`` or gives an error.

tree_entry_byindex
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | luagit2_tree_entry              |
+---------------------------+                                 +
| index_number (integer)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree in which entyr is to be looked up.
2. ``index_number`` : The tree entry index number is being looked up in the tree .

* Returns corresponding ``luagit2_tree_entry`` or gives an error.

tree_entry_byname
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | luagit2_tree_entry              |
+---------------------------+                                 +
| file_name (string)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree in which entyr is to be looked up.
2. ``file_name`` : The file name which is being looked up in the tree .

* Returns corresponding ``luagit2_tree_entry`` or gives an error.

tree_entry_bypath
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | luagit2_tree_entry              |
+---------------------------+                                 +
| file_path (string)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree in which entyr is to be looked up.
2. ``file_path`` : The path for file which is being looked up in the tree .

* Returns corresponding ``luagit2_tree_entry`` or gives an error.

tree_entry_cmp
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree_entry        | Integer (>0, ==0 , <0)          |
+---------------------------+                                 +
| luagit2_tree_entry        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_tree_entry`` : The first tree entry to compare.
2. ``luagit2_tree_entry`` : The second tree entry to compare.

* Returns an integer value corresponding to 
	a. (>0) if entry_first > entry_second. 
	b. (=0) if entry_first = entry_second.
	c. (<0) if entry_first < entry_second.

tree_entry_filemode
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree_entry        | luagit2_filemode                |
+---------------------------+---------------------------------+

1. ``luagit2_tree_entry`` : The tree entry whose file mode is to be found.

* Returns corresponding ``luagit2_filemode`` or an error.

tree_entry_filemode_raw
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree_entry        | luagit2_filemode                |
+---------------------------+---------------------------------+

1. ``luagit2_tree_entry`` : The tree entry whose file mode is to be found.

* Returns corresponding raw ``luagit2_filemode`` or an error.

tree_entry_id
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree_entry        | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_tree_entry`` : The tree entry whose oid is to be found.

* Returns corresponding ``luagit2_oid`` or an error.

tree_entry_name 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree_entry        | name (string)                   |
+---------------------------+---------------------------------+

1. ``luagit2_tree_entry`` : The tree entry whose name is to be found.

* Returns corresponding string name or an error.

tree_entry_to_object 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_object                  |
+---------------------------+                                 +
| luagit2_tree_entry        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to lookup for tree entry.
2. ``luagit2_tree_entry`` : The tree entry which is to be converted to luagit2_object.

* Returns corresponding ``luagit2_object`` or an error.

tree_entry_type
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_otype                   |
+---------------------------+                                 +
| luagit2_tree_entry        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to lookup for tree entry.
2. ``luagit2_tree_entry`` : The tree entry whose object type is to be found.

* Returns corresponding ``luagit2_otype`` or an error.

tree_entrycount
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | entry_count(number)             |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree whose entry count is to be found.

* Returns numerical value of number of entries or an error.

tree_id
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree whose oid is to be found.

* Returns corresponding ``luagit2_oid`` or an error.

tree_lookup 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_tree                    |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to lookup for tree.
2. ``luagit2_oid`` : The oid of tree being looked up.

* Returns corresponding  ``luagit2_tree`` or an error.

tree_lookup_prefix 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_tree                    |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+                                 +
| length (int)              |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to lookup for tree.
2. ``luagit2_oid`` : The oid of tree being looked up.
3. ``length`` : The length of oid to be used for looking up the tree in repository.

* Returns corresponding  ``luagit2_tree`` or an error.

tree_owner
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree whose owner is to be found.

* Returns owner ``luagit2_repository`` or gives  an error.

tree_entry_free 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree_entry        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_tree_entry`` : The tree entry which is to be freed.

* Returns None or gives an error

tree_free 
---------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tree              | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_tree`` : The tree which is to be freed.

* Returns None or gives an error.

