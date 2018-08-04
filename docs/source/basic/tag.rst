Tag
===

These methods help in creating and reading values of ``git tags``
for a given repository.

.. contents:: Contents
   :local:

tag_annotation_create
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| Tag_name (string)            |                                 |
+------------------------------+                                 +
| luagit2_object               |                                 |
+------------------------------+                                 +
| luagit2_signature            |                                 |
+------------------------------+                                 +
| tag_message (string)         |                                 |
+------------------------------+---------------------------------+
 
1. ``luagit2_repository`` : The repository in which the tag is to be created.
2. ``tag_name`` : The tag name of tag to be created.
3. ``luagit2_object`` :  The target object targetting to which the tag should be created.
4. ``luagit2_signature`` : The signature to be used to create tag.
5. ``tag_message`` : The tag message.

* Returns ``luagit2_oid`` for the new created annotated tag.

tag_create
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| Tag_name (string)            |                                 |
+------------------------------+                                 +
| luagit2_object               |                                 |
+------------------------------+                                 +
| luagit2_signature            |                                 |
+------------------------------+                                 +
| tag_message (string)         |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+---------------------------------+
 
1. ``luagit2_repository`` : The repository in which the tag is to be created.
2. ``tag_name`` : The tag name of tag to be created.
3. ``luagit2_object`` :  The target object targetting to which the tag should be created.
4. ``luagit2_signature`` : The signature to be used to create tag.
5. ``tag_message`` : The tag message.
6. ``force`` : integer equivalent for boolean whether to do a force creation.

* Returns ``luagit2_oid`` for the new created tag.

tag_create_frombuffer
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| data (string)                |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+---------------------------------+
 
1. ``luagit2_repository`` : The repository in which the tag is to be created.
2. ``data`` : The data to be used to create tag.
3. ``force`` :  integer equivalent for boolean whether to do a force creation.

* Returns ``luagit2_oid`` for the new created tag.

tag_create_lightweight
------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid                     |
+------------------------------+                                 +
| Tag_name (string)            |                                 |
+------------------------------+                                 +
| luagit2_object               |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+---------------------------------+
 
1. ``luagit2_repository`` : The repository in which the tag is to be created.
2. ``Tag_name`` : The tag name.
3. ``luagit2_object`` : The target object targetting to which the tag should be created.
4. ``force`` :  integer equivalent for boolean whether to do a force creation.

* Returns ``luagit2_oid`` for the new created tag.

tag_delete
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| tag_name                  |                                 |
+---------------------------+---------------------------------+

* Deletes a tag in a given repository. Returns none or gives an error.

tag_free
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag               | None                            |
+---------------------------+---------------------------------+

* Frees a tag. Returns None or gives an errors

tag_id
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag               | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : The tag whose oid is to be found.

* Returns ``luagit2_oid`` of the tag or gives an error.

tag_list 
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_strarray                |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose list of tags is to be found.

* returns ``luagit2_strarray`` as a list of created tags or gives an error.

tag_list_match 
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_strarray                |
+---------------------------+                                 +
| pattern (string)          |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose list of tags is to be found.
2. ``pattern`` : The pattern matching which tags will be listed out

* returns ``luagit2_strarray`` as a list of created tags or gives an error.

tag_lookup 
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_tag                     |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for the tag.
2. ``luagit2_oid`` : The oid of tag to lookup.

* returns ``luagit2_tag`` or gives an error.

tag_owner
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose owner repository is to be found.

* Returns owner repository ``luagit2_repository`` or gives an error.

tag_tagger 
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose tagger is to be found.

* Returns tagger's signature  ``luagit2_signature`` or gives an error.

tag_target 
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | luagit2_object                  |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose target object is to be found.

* Returns target ``luagit2_object`` or gives an error.

tag_target_id
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose target object's oid is to be found.

* Returns target ``luagit2_oid`` or gives an error.

tag_target_type 
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | luagit2_otype                   |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose target object type is to be found.

* Returns target object type ``luagit2_otype`` or gives an error.

tag_message
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | message (string)                |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose message is to be found.

* Returns tag message or gives an error.

tag_name
------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_tag	            | name (string)                   |
+---------------------------+---------------------------------+

1. ``luagit2_tag`` : tag whose name is to be found.

* Returns tag name or gives an error.

