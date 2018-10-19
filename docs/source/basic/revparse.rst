Revparse
========

These methods help in findings refs and parsing revision strings for ``git objects``.

revparse
--------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_revspec                 |
+---------------------------+                                 +
| spec (string)             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository from where to look for and parse the given spec string.
2. ``spec`` : The spec string to parse. example : ``origin/master..HEAD`` to get refspec data between **master** and **HEAD**.

.. note:: See ``man gitrevisions`` or http://git-scm.com/docs/git-rev-parse.html#_specifying_revisions for information on the syntax of spec string accepted. 

* Returns ``luagit2_revspec`` which can be later used by helper methods : **revspec_from()** and **revspec_to()** to get the `From` &`to` objects pointed by luagit2_revspec,

revparse_single
--------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_object                  |
+---------------------------+                                 +
| spec (string)             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository from where to look for and parse the given spec string.
2. ``spec`` : The spec string to parse. This should point to only one of the objects.

* Returns corresponding ``luagit2_object`` being pointed or gives an error.

