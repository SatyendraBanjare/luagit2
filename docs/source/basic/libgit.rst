Libgit
======

These are the most important set of functions that allow setting
and reading global values for all of the libgit and thus luagit2 too.

.. contents:: Contents
   :local:


init
----

Sets up the global state and threading values for the libgit2.

* There are no params required, none are returned.

.. note:: This is the First function to be called before doing anything or calling other functions of luagit2. This may be called any number of times.

shutdown
--------

Clean up the global state and threading context after calling it as many times as **init()** was called.

* There are no params required, none are returned.

libgit2_features
----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | integer_value                   |
+---------------------------+---------------------------------+

* returns a Integer value for Query compile time options for libgit2. 

get_mwindow_size
----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | integer_value                   |
+---------------------------+---------------------------------+

* returns an Integer valued maximum mmap window size.

set_mwindow_size
----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

* Sets the maximum mmap window size for libgit2.

get_mwindow_mapped_limit
------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | integer_value                   |
+---------------------------+---------------------------------+

* returns an Integer value of the maximum memory that will be mapped in total by the library.

set_mwindow_mapped_limit
------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

* Sets the the maximum memory that will be mapped in total by the library.
 
get_search_path
---------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| (string) search_path_lvl  | (string) path                   |
+---------------------------+---------------------------------+

1. ``search_path_lvl`` : The search path level. can be any of **system**, **global**, **xdg**, **programdata** .

* returns String value of search path for a selected level for a config data.

set_search_path
---------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| (string) search_path_lvl  |  None                           |
+---------------------------+                                 +
| (string) path             |                                 |
+---------------------------+---------------------------------+

1. ``search_path_lvl`` : The search path level. can be any of **system**, **global**, **xdg**, **programdata** .
2. ``path`` : The string value of path to set.

* Sets String value of search path for a selected level for a config data.

get_cached_memory
-----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | (integer_value) current         |
+                           +---------------------------------+
|                           | (integer_value) allowed         |
+---------------------------+---------------------------------+

* returns cache byte values.
	a. current size.
	b. max allowed size.

set_cache_object_limit
----------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_otype             |  None                           |
+---------------------------+                                 +
| (integer) limit           |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_otype`` : the object type whose cache size is to be set.
2. ``limit`` : The numerical value of cache size to be allowed for that object type.

* Returns none or gives an error.

set_cache_max_size
------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

* Set the max value of cache size for any of the object.

enable_caching
--------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

integer_value : 
	a. `1` -> enable caching.
	b. `0` -> disable caching.

get_template_path
------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      |  luagit2_buf                    |
+---------------------------+---------------------------------+

* there are no params required. ``luagit2_buf`` for used template path is returned.

set_template_path
------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| (String) path             |  None                           |
+---------------------------+---------------------------------+

* Set the default template path.

set_user_agent
--------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| (String) user_agent       |  None                           |
+---------------------------+---------------------------------+

* Sets the user agent using it's name. 

get_windows_sharemode
----------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | integer_value                   |
+---------------------------+---------------------------------+

* Get the numerical value of file share mode in windows systems.

.. note:: This methods should be used in windows systems only. Otherwise it may give errors or wrong results.

set_windows_sharemode
----------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| (Integer) share_mode      |  None                           |
+---------------------------+---------------------------------+

* Set the file share mode to be used by libgit in windows system.

.. note:: This methods should be used in windows systems only. Otherwise it may give errors or wrong results.

enable_strict_object_creation
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

integer_value : 
	a. `1` -> enable Strict_object_creatioN.
	b. `0` -> disable Strict_object_creatioN.

* Returns none.

enable_strict_symbolic_ref_creation
------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

integer_value : 
	a. `1` -> enable strict_symbolic_ref_creation.
	b. `0` -> disable strict_symbolic_ref_creation.

* Returns none.

enable_ofs_delta
----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

integer_value : 
	a. `1` -> enable ofs_delta.
	b. `0` -> disable ofs_delta.

* Returns none.

set_ssl_ciphers
---------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| (string) ciphers          |  None                           |
+---------------------------+---------------------------------+

1. ``Ciphers`` : The string value of ciphers to set.

* returns None.

enable_fsync_gitdir
-------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

integer_value : 
	a. `1` -> Enable synchronized writing of files in the gitdir using `fsync`.
	b. `0` -> disable synchronized writing of files in the gitdir using `fsync`.

* Returns none.

enable_strict_hash_verification
--------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| integer_value             |  None                           |
+---------------------------+---------------------------------+

integer_value : 
	a. `1` -> enable strict_hash_verification.
	b. `0` -> disable strict_hash_verification.

* Returns none.

