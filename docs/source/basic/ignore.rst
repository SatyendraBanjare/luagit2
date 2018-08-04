Ignore
======

.. contents:: Contents
   :local:


ignore_add_rule
---------------------

	Adds ignore rules for a given repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| Rule (string)             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to add ignore rules.
2. ``Rule`` : The string value of rule to add.

* Returns None or gives an error.

ignore_clear_internal_rules
-----------------------------

	Clears all ignore rules of a given repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose rules are to be cleared.

* Returns none or gives an error

ignore_path_is_ignored
--------------------------

	Checks if a file is ignored in a given repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_ignored (Boolean)            |
+---------------------------+                                 +
| Path (string)             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to check for the provided file.
2. ``Path`` : The path to the file which is to be checked.

* Returns Boolean value or gives an error.
