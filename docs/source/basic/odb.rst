Object Database (ODB)
=====================

These methods allow functions related to finding details about 
``git objects`` in the repository's object database. 

.. contents:: Contents
   :local:

odb_exists
----------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb               | exists (boolean)                |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_odb`` : The object data base where to check.
2. ``luagit2_oid`` : The oid of object to check.

* Returns boolean if the object exists in the given odb.

odb_free
--------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb               | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_odb`` : The object to free.

* Returns none or gives an error.

odb_hash
--------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| data (string)             | luagit2_oid                     |
+---------------------------+                                 +
|  luagit2_otype            |                                 |
+---------------------------+---------------------------------+

1. ``Data`` : The string data whose hash is to be found out.
2. ``luagit2_otype`` : The object type for the data passed.

* Returns corresponding ``luagit2_oid`` for data passed or gives an error.

odb_hashfile
------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| path (string)             | luagit2_oid                     |
+---------------------------+                                 +
|  luagit2_otype            |                                 |
+---------------------------+---------------------------------+

1. ``path`` : The file's path whose hash is to be found out.
2. ``luagit2_otype`` : The object type for the file passed.

* Returns corresponding ``luagit2_oid`` for file passed or gives an error.

odb_object_free
---------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb_object        | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_odb_object`` : The odb_object to free.

* Returns none or gives an error.

odb_object_id
-------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb_object        | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_odb_object`` : The odb_object whose oid is to be found.

* Returns corresponding ``luagit2_oid`` or gives an error.

odb_object_size
---------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb_object        | Size (number)                   |
+---------------------------+---------------------------------+

1. ``luagit2_odb_object`` : The odb_object whose size is to be found.

* Returns corresponding numerical value of size or gives an error.

odb_object_type
---------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb_object        | luagit2_otype                   |
+---------------------------+---------------------------------+

1. ``luagit2_odb_object`` : The odb_object whose object type to be found.

* Returns corresponding ``luagit2_otype`` or gives an error.

odb_open
--------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| path (string)             | luagit2_odb                     |
+---------------------------+---------------------------------+

1. ``path`` : The path to objects for the repository. example : ``repo/path/.git/objects``

* Returns corresponding ``luagit2_odb`` or gives an error.

odb_read
--------

Get a luagit2_odb_object from the object_database using it's oid.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb               | luagit2_odb_object              |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_odb`` : The odb from where to read data.
2. ``luagit2_oid`` : The oid of object to read.

* Returns ``luagit2_odb_object`` or gives an error.

odb_refresh
-----------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb               | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_odb`` : The object to refresh.

* Returns none or gives an error.

odb_write
---------

Create a luagit2_odb_object in the object_database.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_odb               | luagit2_oid                     |
+---------------------------+                                 +
|  Buffer (string)          |                                 |
+---------------------------+                                 +
| luagit2_otype             |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_odb`` : The odb from where to add new ofb object data.
2. ``Buffer`` : The string data to add to odb.
3. ``luagit2_otype`` : The type of object the data refers to.

* Returns ``luagit2_oid`` of new created object in odb or gives an error.

