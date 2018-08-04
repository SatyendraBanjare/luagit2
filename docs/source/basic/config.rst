Config
======

These methods help to read and  modify configuration details for a git repository.

.. contents:: Contents
   :local:

config_delete_entry  
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entry is to be deleted.
2. ``entry_name`` : The entry name to delete.

* returns none or gives an error.

config_delete_multivar 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+                                 +
| regex_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entry is to be deleted.
2. ``entry_name`` : The entry name to delete.
3. ``regex_name`` : The regex using which to search.

* returns none or gives an error.

config_find_global 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_buf                     |
+---------------------------+---------------------------------+

* There are no parameters required. It finds global git configuration details and returns ``luagit2_buf`` consisting of that data or gives an error.

config_find_programdata 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_buf                     |
+---------------------------+---------------------------------+

* There are no parameters required. It finds programdata git configuration details and returns ``luagit2_buf`` consisting of that data or gives an error.

.. note:: This method should be used on windows system only.

config_find_system 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_buf                     |
+---------------------------+---------------------------------+

* There are no parameters required. It finds system git configuration details and returns ``luagit2_buf`` consisting of that data or gives an error.

config_find_xdg 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_buf                     |
+---------------------------+---------------------------------+

* There are no parameters required. It finds XDG git configuration details and returns ``luagit2_buf`` consisting of that data or gives an error.

.. note:: This method should be used on windows system only.

config_get_int32 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

* Get the value of an ``32bit integer`` config variable or en error.

config_get_int64 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

* Get the value of an ``64bit integer`` config variable or an error.

config_get_bool 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | boolean                         |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

* Get the boolean value of an config variable or an error.

config_get_path 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | luagit2_buf                     |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

* returns a ``luagit2_buf`` for path value of an config variable or an error.

config_get_string 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | luagit2_buf                     |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

* returns a string for value of an config variable or an error.

config_get_string_buf 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | luagit2_buf                     |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

* returns a ``luagit2_buf`` for string value of an config variable or an error.

config_open_default 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_config                  |
+---------------------------+---------------------------------+

* There are no parameters required. It finds default git configuration details and returns ``luagit2_config`` consisting of that data or gives an error.

config_open_global 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config (parent)   | luagit2_config                  |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose global git config details are to be found.

* returns ``luagit2_config`` for  given's config global values or an error.

config_open_level 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config (parent)   | luagit2_config                  |
+---------------------------+                                 +
| luagit2_config_level_t    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The parent config used to find values.
2. ``luagit2_config_level_t`` : The config level to open. This can be obtained by any of these helper methods ``config_level_program_data()`` , ``config_level_system()`` , ``config_level_xdg()`` , ``config_level_global()`` or ``config_level_local()``.

.. note:: The xdg and programdata config level should be used on;y in windows type system.

* Returns corresponding ``luagit2_config`` or gives an error.

config_open_ondisk 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| path (string)             | luagit2_config                  |
+---------------------------+---------------------------------+

1. ``path`` : The path of config file in the repository to look for. Onw may also open global config file by passing appropriate path value.

.. note:: One may also first create a config file using **config_add_file_ondisk()** and then use it.

* returns corresponding  ``luagit2_config`` or an error.

config_parse_bool 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| value(string)             | boolean                         |
+---------------------------+---------------------------------+

1. ``value`` : string value to parse.

* returns a boolen value for the passed string. The value true is returned for `true` , `yes` , `on` or `1` or any other number other than zero and false for `false`, `no`, `off` and `0`. 

config_parse_int32 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| value(string)             | number                          |
+---------------------------+---------------------------------+

1. ``value`` : string value to parse.

* returns ``32 bit int`` type number value of passed string.

config_parse_int64 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| value(string)             | number                          |
+---------------------------+---------------------------------+

1. ``value`` : string value to parse.

* returns ``64 bit int`` type number value of passed string.

config_parse_path 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| value(string)             | luagit2_buf                     |
+---------------------------+---------------------------------+

1. ``value`` : string value to parse.

* returns ``luagit2_buf`` for passed path string value.

config_set_bool 
------------------------------------------
 
	Use this to set boolean values to entries in a git config.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+                                 +
| value (boolean)           |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be set.
2. ``entry_name`` : The entry name to set.
3. ``value`` : boolean value to be set.

* Returns none or gives an error.

config_set_int32 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+                                 +
| value (number)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be set.
2. ``entry_name`` : The entry name to set.
3. ``value`` : ``32 bit integer`` type value to be set.

* Returns none or gives an error.

config_set_int64 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+                                 +
| value (number)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be set.
2. ``entry_name`` : The entry name to set.
3. ``value`` : ``64 bit integer`` type value to be set.

* Returns none or gives an error.

config_set_multivar 
------------------------------------------

	Can be used to set string values in a git config.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+                                 +
| regex (string)            |                                 |
+---------------------------+                                 +
| value (string)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be set.
2. ``entry_name`` : The entry name to set.
3. ``regex`` :  The regular expression to be used while setting variable values.
4. ``value`` : string value to be set.

* Returns none or gives an error.

config_set_string 
------------------------------------------

	Can be used to set string values in a git config.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+                                 +
| value (string)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be set.
2. ``entry_name`` : The entry name to set.
3. ``value`` : string value to be set.

* Returns none or gives an error.

config_snapshot 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config (parent)   | luagit2_config                  |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The parent config whose snapshot is to be created.

* returns snapshot ``luagit2_config`` for  given config or an error.

.. note:: This method only creates a snapshot. Only snapshot config as returned by this function is to be used while reading values. Setting values can not be performed on config snapshot.

config_free 
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config to free.

* returns none or an error.

config_add_file_ondisk 
------------------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_config               | None                            |
+------------------------------+                                 +
| path (string)                |                                 |
+------------------------------+                                 +
| luagit2_config_level_t       |                                 |
+------------------------------+                                 +
| luagit2_repository           |                                 |
+------------------------------+                                 +
| force (int)                  |                                 |
+------------------------------+---------------------------------+


1. ``luagit2_config`` : The config to add on disk.
2. ``path`` : The path where to save.
3. ``luagit2_config_level_t`` : The config level used to save the file.
4. ``luagit2_repository`` : The repository to save.
5. ``force`` : integer value fo boolean to force create a config.

* Returns None or an error.

config_new
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_config                  |
+---------------------------+---------------------------------+

* No parameters required. returns an empty luagit2_config or an error.

config_iterator_new
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | luagit2_config_iterator         |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config for which an iterator is to be created.

* returns ``luagit2_config_iterator`` for the given config or an error.

config_entry_free
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config_entry      | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_config_entry`` : The config_entry to free.

* returns none or an error.

config_get_entry
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config            | luagit2_config_entry            |
+---------------------------+                                 +
| entry_name (string)       |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_config`` : The config whose entries are to be looked up.
2. ``entry_name`` :  The entry whose value is to be found.

..note:: The config entry values can be read using helper methods **config_entry_name()** and **config_entry_value()**.

* Returns ``luagit2_config_entry`` for that or gives an error.

config_next
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config_iterator   | luagit2_config_entry            |
+---------------------------+---------------------------------+

1. ``luagit2_config_iterator`` : The config_iterator to lookup values in.

* returns next ``luagit2_config_entry`` or an error.


..note:: The config entry values can be read using helper methods **config_entry_name()** and **config_entry_value()**.

config_iterator_free
------------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_config_iterator   | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_config_iterator`` : The config_iterator to free.

* returns none or an error.
