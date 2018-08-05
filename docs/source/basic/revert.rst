Revert
======

This method allows to do a ``git revert`` for the passed commit in the given repository.

revert
------

Reverts the given commit, producing changes in the index and working directory.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| luagit2_commit            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to revert the changes.
2. ``luagit2_commit`` : The commit whose introduced changes are to be reverted.

* Returns None or gives an error.

