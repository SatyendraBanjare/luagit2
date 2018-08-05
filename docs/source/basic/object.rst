Object
======

These methods allow finding details for ``git objects``.

.. contents:: Contents
   :local:

object__size
------------------------------

Get the object size for different **object types**.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_otype             | (Number) size                   |
+---------------------------+---------------------------------+

1. ``luagit2_otype`` : The object type whose size is to be found.

* returns numerical value of size for that object type.

object_free
------------------------------

Free the object.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_object            | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_object`` : The object to free.

* returns none or gives an error.

object_id
------------------------------

Get the oid of given luagit2_object.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_object            | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_object`` : The object whose oid is to be found.

* returns corresponding ``luagit2_oid`` or gives an error.

object_lookup
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_object                  |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| luagit2_otype                |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for object.
2. ``luagit2_oid`` : The oid of requested object.
3. ``luagit2_otype`` : The object type of requested object.

* Returns corresponding ``luagit2_object`` or gives an error.

object_lookup_bypath
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_object                  |
+------------------------------+                                 +
| path                         |                                 |
+------------------------------+                                 +
| luagit2_otype                |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for object.
2. ``path`` : The path where to find objects. example : ``repo_path/.git/objects``
3. ``luagit2_otype`` : The object type of requested object.

* Returns corresponding ``luagit2_object`` or gives an error.

object_lookup_prefix
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_object                  |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| length (int)                 |                                 |
+------------------------------+                                 +
| luagit2_otype                |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for object.
2. ``luagit2_oid`` : The oid of requested object.
3. ``length`` : The length of oid to use look to the object in repository.
4. ``luagit2_otype`` : The object type of requested object.

* Returns corresponding ``luagit2_object`` or gives an error.

object_owner
------------------------------

Get the owner repository of a luagit2_object.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_object            | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_object`` : The object whose owner repository is to be found.

* Returns ``luagit2_repository`` or gives an error.

object_short_id 
------------------------------

Get the short oid for object.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_object            | luagit2_buf                     |
+---------------------------+---------------------------------+

1. ``luagit2_object`` : The object whose short oid is to be found.

* Returns ``luagit2_buf`` that contians the shortened oid or gives an error.

object_string2type
------------------------------

Get a luagit2_otype from string type_name .

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| type_name (string)        | luagit2_otype                   |
+---------------------------+---------------------------------+

1. ``type_name`` : The name of type to get a luagit2_otype for. can be any of **commit**, **blob** , **tag**, **tree** etc.

* Returns corresponding ``luagit2_otype`` or gives an error.

object_type
------------------------------

Get object's type.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_object            | luagit2_otype                   |
+---------------------------+---------------------------------+

1. ``luagit2_object`` : The object whose object type is to be found.

* Returns ``luagit2_otype`` for the object's type or gives an error.

object_type2string
------------------------------

Get the string name of object_type.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_otype             |  type_name(string)              |
+---------------------------+---------------------------------+

1. ``luagit2_otype`` : The object type whose string type name is to be found.

* Returns string value of ``type_name`` for the object's type or gives an error.

object_typeisloose
------------------------------

Check if the object type is a valid loose object type.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_otype             | is_loose (boolean)              |
+---------------------------+---------------------------------+

1. ``luagit2_otype`` : The object type to check.

* Returns boolean if the object is a valid loose object type.

