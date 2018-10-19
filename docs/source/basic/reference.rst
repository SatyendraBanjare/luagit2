Reference
=========

These methods help in modifying , creating and reading values of ``git references`` for a git repository.
These references  are internal to working of git and are available at ``.git/refs`` .

.. contents:: Contents
   :local:

reference_create 
-----------------------------------------

Create a new reference.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           |   luagit2_reference             |
+------------------------------+                                 +
| name (string)                |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to create a new reference.
2. ``name`` : The name for new git reference.
3. ``luagit2_oid`` : The object id pointed to by the reference.
4. ``force`` : Integer equivalent of bool to force create the git reference.
5. ``log_message`` : The message to be added to log.

* Returns Created ``luagit2_reference`` or gives an error.

reference_create_matching 
-----------------------------------------

Conditionally create new direct reference. This methods updated the git ref according to changed object.
It takes an old git reference and returns a new git reference with updated values.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           |   luagit2_reference             |
+------------------------------+                                 +
| name (string)                |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+                                 +
| luagit2_oid(current_id ref)  |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to create a new reference.
2. ``name`` : The name for new git reference.
3. ``luagit2_oid`` : The object id pointed to by the reference.
4. ``force`` : Integer equivalent of bool to force create the git reference.
5. ``luagit2_oid`` : The current oid of git reference to be updated.
6. ``log_message`` : The message to be added to log.

* Returns Created ``luagit2_reference`` or gives an error.

reference_dup 
-----------------------------------------

Get a duplicate git reference of a given git reference.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_reference            |   luagit2_reference             |
+------------------------------+---------------------------------+

1. ``luagit2_reference`` : The refernce whose duplicate is to be created.

* Returns Created ``luagit2_reference`` or gives an error.

.. note:: It is very important to note that simple giving a variable the value of an old luagit2_reference object won't help . Thus this method becomes useful if you want multiple instances for a git reference.

reference_dwim 
-----------------------------------------

Lookup a reference by DWIMing its short name.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference               +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for reference.
2. ``reference_name`` : The name of reference to look for.

* Returns Created ``luagit2_reference`` or gives an error.

reference_ensure_log 
-----------------------------------------

Ensure there is a reflog for a particular reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ has_log (boolean)               +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for reference's log.
2. ``reference_name`` : The name of reference to look for.

* Returns Boolean or gives an error.

reference_has_log 
-----------------------------------------

Check if a reflog exists for the specified reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ has_log (boolean)               +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for reference's log.
2. ``reference_name`` : The name of reference to look for.

* Returns Boolean or gives an error.

reference_is_branch 
-----------------------------------------

Check if a reference poins to a git branch.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | is_branch (boolean)             |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to check.

* Returns Boolean or gives an error.

reference_is_note 
-----------------------------------------

Check if a reference poins to a git note.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | is_note   (boolean)             |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to check.

* Returns Boolean or gives an error.

reference_is_remote 
-----------------------------------------

Check if a reference poins to a git remote.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | is_remote (boolean)             |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to check.

* Returns Boolean or gives an error.

reference_is_tag 
-----------------------------------------

Check if a reference poins to a git tag.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | is_branch (boolean)             |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to check.

* Returns Boolean or gives an error.

reference_is_valid_name 
-----------------------------------------

Check if a reference name is valid.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | is_valid_name (boolean)         |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to check.

* Returns Boolean or gives an error.

reference_iterator_glob_new 
-----------------------------------------

Get a reference iterator for references that mathc the given glob.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference_iterator      +
| glob_name     (string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look in the references.
2. ``glob_name`` : The name of glob to be used.

* Returns corresponding ``luagit2_reference_iterator`` or gives an error.

reference_iterator_new 
-----------------------------------------

Get a reference iterator for the whole repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_reference_iterator      |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look in the references.

* Returns corresponding ``luagit2_reference_iterator`` or gives an error.

reference_list 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_strarray                |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look in the references.

* Returns ``luagit2_strarray`` as a list of string values for git refernces or gives an error.

reference_lookup 
-----------------------------------------

Get a luagit2_reference from a ref name in repository.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_reference               +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look in the references.
2. ``reference_name`` : The name of reference to look for.

* Returns ``luagit2_reference`` or gives an error.

reference_name 
-----------------------------------------

Get the name of a git reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | ref_name (string)               |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference whose name is to be found.

* Returns reference's name or gives an error.

reference_name_to_id 
-----------------------------------------

Get the oid for reference by simply using it's name.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ luagit2_oid                     +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository to look in the references.
2. ``reference_name`` : The name of reference to look for.

* Returns corresponding ``luagit2_oid`` or gives an error.

reference_next 
-----------------------------------------

Get the next entry in reference iterator.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference_iterator| luagit2_reference               |
+---------------------------+---------------------------------+

1. ``luagit2_reference_iterator`` : The reference iterator to look for next reference value in.

* Returns next ``luagit2_reference`` or gives an error.

reference_next_name 
-----------------------------------------

Get the next entry's name in reference iterator.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference_iterator| ref_name (string)               |
+---------------------------+---------------------------------+

1. ``luagit2_reference_iterator`` : The reference iterator to look for next reference value in.

* Returns next reference's name or gives an error.

reference_owner 
-----------------------------------------

Get the owner repository for a reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | luagit2_repository              |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference whose owner repository is to be found.

* Returns corresponding owner ``luagit2_repository`` or gives an error.

reference_peel 
-----------------------------------------

Peel a reference till an object for given otype is found.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |                                 |
+---------------------------+ luagit2_object                  +
| luagit2_otype             |                                 |
+---------------------------+---------------------------------+


1. ``luagit2_reference`` : The reference to look for values in.
2. ``luagit2_otype`` : The object type to be found.

* Returns the first luagit2_object found in the reference that has requested otype.

reference_remove 
-----------------------------------------

Remove the reference from repository. 

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| reference_name(string)    |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for reference.
2. ``reference_name`` : The name of reference to be deleted.

* returns none or gives an 	error.

reference_rename 
-----------------------------------------

Rename a given reference. Get a new reference with changed name but same other values.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_reference            |   luagit2_reference             |
+------------------------------+                                 +
| new_name (string)            |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference whose name is to be changed.
2. ``new_name`` : The new name of reference.
3. ``force`` : Integer equivalent of boolean to force create a reference.
4. ``log_message`` : The message to be entered to reflog.

* Returns new reference with changed name  or gives an error.

reference_resolve 
-----------------------------------------

Resolves values for a given git reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         | luagit2_reference               |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference whose values need to be Resolved.

* Returns a new ``luagit2_reference`` or gives an error.

reference_set_target 
-----------------------------------------

Set the target for a given git reference.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_reference            |   luagit2_reference             |
+------------------------------+                                 +
| luagit2_oid (target)         |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference whose oid needs to be set.
2. ``luagit2_oid`` : The oid of target object.
3. ``log_message`` : The log message to be added to reflog.

* Returns a new ``luagit2_reference`` with new target or gives an error.

reference_symbolic_create 
-----------------------------------------

Create a new symbolic reference.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           |   luagit2_reference             |
+------------------------------+                                 +
| name (string)                |                                 |
+------------------------------+                                 +
| target_name (string)         |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to create a new reference.
2. ``name`` : The name for new git reference.
3. ``target_name`` : The name of target to be pointed to by the reference.
4. ``force`` : Integer equivalent of bool to force create the git reference.
5. ``log_message`` : The message to be added to log.

* Returns Created ``luagit2_reference`` or gives an error.

reference_symbolic_create_matching 
-----------------------------------------

Conditionally create new direct reference. This methods updated the git ref according to changed object.
It takes an old git reference and returns a new git reference with updated values.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           |   luagit2_reference             |
+------------------------------+                                 +
| name (string)                |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| force (integer)              |                                 |
+------------------------------+                                 +
| luagit2_oid(current_id ref)  |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to create a new reference.
2. ``name`` : The name for new git reference.
3. ``target_name`` : The name of target to be pointed to by the reference.
4. ``force`` : Integer equivalent of bool to force create the git reference.
5. ``current`` : The old value of the reference when updating .
6. ``log_message`` : The message to be added to log.

* Returns Created ``luagit2_reference`` or gives an error.

reference_symbolic_set_target 
-----------------------------------------

Set the target for a given symbolic git reference.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_reference            |   luagit2_reference             |
+------------------------------+                                 +
| target_name (string)         |                                 |
+------------------------------+                                 +
| log_message (string)         |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference whose oid needs to be set.
2. ``target_name`` : The name of target object.
3. ``log_message`` : The log message to be added to reflog.

* Returns a new ``luagit2_reference`` with new target or gives an error.

reference_symbolic_target 
-----------------------------------------

Get the target's name of a given symbolic reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  target_name                    |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to look for target in.

* Returns the target_name in the symbolic reference or gives an error.

reference_target 
-----------------------------------------

Get the target's oid of a given reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  luagit2_oid                    |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to look for target in.

* Returns the luagit2_oid in the reference or gives an error.

reference_target_peel 
-----------------------------------------

Return the peeled OID target of this reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  luagit2_oid                    |
+---------------------------+---------------------------------+

1. ``luagit2_reference`` : The reference to look for values in.

* Returns the luagit2_oid in the reference or gives an error.

reference_type 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  luagit2_ref_type               |
+---------------------------+---------------------------------+

* Returns corresponding ``luagit2_ref_type`` or gives an error.

reference_free 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference         |  None                           |
+---------------------------+---------------------------------+

* Frees a given ``luagit2_reference``. Returns none or gives an error.


reference_iterator_free 
-----------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reference_iterator|  None                           |
+---------------------------+---------------------------------+

* Frees a given ``luagit2_reference_iterator``. Returns none or gives an error.
