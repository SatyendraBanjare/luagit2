Status
======

These Methods help in getting ``git status`` 

.. contents:: Contents
   :local:


status_list_new
---------------

Get a list of status list entries for the repository. It should be freed using **status_list_free**.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_status_list             |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repo whose status list is to be found.

* Creates a corresponding  ``luagit2_status_list`` or gives an error.

status_list_free
----------------

It frees the used **luagit2_status_list**. 

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_status_list       | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_status_list`` : The status list to free.

* Returns none or gives an error.

status_list_entrycount
----------------------

It frees the used **luagit2_status_list**. 

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_status_list       | num_count (ineger)              |
+---------------------------+---------------------------------+

1. ``luagit2_status_list`` : The status list whose entry count is to be found.

* Returns number of entries in the status list or gives an error.

status_byindex
--------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_status_list       | luagit2_status_entry            |
+---------------------------+                                 +
| index_number (integer)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_status_list`` : The status list where to find entry.
2. ``index_number`` : The index number of entry. Must be less than entry count. since the indexing starts from `0`.

* Returns corresponding ``luagit2_status_entry`` in the status list or gives an error.

.. note:: Having received the status entry, one may use helper method **status_type** to find what type of entry is it. Also One may use helper method **status_file_path** to find the changed file paths for that status entry.

