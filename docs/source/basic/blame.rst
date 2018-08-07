Blame
=====

These methods help get the blame data for the files.

Get the blame data as the last commit that introduced that
change of line in a file.

.. contents:: Contents
   :local:

blame_file
----------

Get the blame data for a file.

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_blame                   +
| File_path (string)        |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look into for the file.
2. ``File_path`` : the file path whose blame data is to be found.

* Creates ``luagit2_blame`` or gives an error.

blame_get_hunk_byindex
----------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_blame             |                                 |
+---------------------------+ luagit2_blame_hunk              +
| index_number (integer)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_blame`` :  the blame data using which blame hunk will be calculated.
2. ``index_number`` :  The index number of entry to be used.

* Returns corresponding ``luagit2_blame_hunk`` or gives an error.

.. note:: After Getting Blame_Hunk , One may use helper methods **blame_hunk_commit_id** & **blame_hunk_signature** to find the last commit's oid and committer. 


blame_get_hunk_byline
----------------------

+---------------------------+---------------------------------+
| Parameters                | Returns                         |
+===========================+=================================+
| luagit2_blame             |                                 |
+---------------------------+ luagit2_blame_hunk              +
|  line_number (integer)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_blame`` :  the blame data using which blame hunk will be calculated.
2. ``line_number`` :  The line number in the file for which blame is to be found.

* Returns corresponding ``luagit2_blame_hunk`` or gives an error.

.. note:: After Getting Blame_Hunk , One may use helper methods **blame_hunk_commit_id** & **blame_hunk_signature** to find the last commit's oid and committer. 


blame_get_hunk_count
--------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blame             | count_num (integer)             |
+---------------------------+---------------------------------+

1. ``luagit2_blame`` : The blame data for which blame hunk is to be found.

* Returns corresponding count of blame hunks in that blame data.

blame_free
----------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_blame             | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_blame`` : The blame data which is to be freed.

