Reset
=====

This method allows to do a ``git reset`` for the passed commit in the given repository.

reset
------

Sets the current head to the specified commit oid and resets the index and working tree to match.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| luagit2_commit            |                                 |
+---------------------------+                                 +
| option (string)           |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to reset the changes.
2. ``luagit2_commit`` : The commit till where changes are to be reset.
3. ``option`` : Specify the type of reset to be performed. This option can be any of **soft**, **mixed** or **hard** . 

* Returns None or gives an error.

