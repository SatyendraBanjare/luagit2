Revwalk
=======

These methods allows to do rewalk the repository's refs.

.. contents:: Contents
   :local:

revwalk_new
-----------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_revwalk                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository those references are to be read.

* Returns ``luagit2_revwalk`` for the correspondings references of given repository or gives an error.

revwalk_next
------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_revwalk           | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_revwalk`` : The revwalk which is to be iterated over for its entries.

* Returns ``luagit2_oid`` for the next reference of given revwalk of repository or gives an error.

revwalk_push
------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to push new refs.
2. ``luagit2_oid`` : The refernce's oid to push.

* Returns none or gives an error.

revwalk_push_ref
----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| ref_name(string)          |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to push new refs.
2. ``ref_name`` : The refernce's name which is to be added.

* Returns none or gives an error.

revwalk_free
------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_revwalk           | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_revwalk`` : The revwalk which is to be freed.

* Returns None or gives an error.

revwalk_reset
-------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_revwalk           | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_revwalk`` : The revwalk which is to be reset.

* Returns None or gives an error.

revwalk_push_head
-----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_revwalk           | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_revwalk`` : The revwalk where to add **HEAD** of the git repository.

* Returns None or gives an error.

revwalk_repository
------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_revwalk           | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_revwalk`` : The revwalk whose owner repository is to be found.

* Returns owner ``luagit2_repository`` or gives an error.
