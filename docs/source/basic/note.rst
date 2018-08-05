Note
====

These methods allow creating and reading ``git notes`` for ``git objects``. 

.. contents:: Contents
   :local:

note_author 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_note              | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_note`` : The note whose author signature is to be found.

* Returns ``luagit2_signature`` or gives an error.

note_committer 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_note              | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_note`` : The note whose committer signature is to be found.

* Returns ``luagit2_signature`` or gives an error.

note_commit_create 
-----------------------------

Create a note with a new commit for an object.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid (commit_id)         |
+------------------------------+---------------------------------+
| luagit2_commit (immediate    |  luagit2_oid (blob_id)          |
| parent commit )              |                                 |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| message (string)             |                                 |
+------------------------------+                                 +
| force(int)                   |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repos where to make a new note.
2. ``luagit2_commit`` : The parent commit using which new note' creation commit will be made.
3. ``luagit2_signature`` : The author signature.
4. ``luagit2_signature`` : The committer signature.
5. ``luagit2_oid`` :  The target object's oid.
6. ``message`` : The note message.
7. ``force`` : integer equivalent of boolean to force create note.

* Returns these values or gives an error.
	a. Commit's oid
	b. Note blob's oid. 

note_create 
-----------------------------

Create a note without a new commit for an object.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid (commit_id)         |
+------------------------------+---------------------------------+
| notes_ref (string)           |  luagit2_oid (blob_id)          |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+                                 +
| message (string)             |                                 |
+------------------------------+                                 +
| force(int)                   |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repos where to make a new note.
2. ``notes_ref`` : The note reference where new note will be created.
3. ``luagit2_signature`` : The author signature.
4. ``luagit2_signature`` : The committer signature.
5. ``luagit2_oid`` :  The target object's oid.
6. ``message`` : The note message.
7. ``force`` : integer equivalent of boolean to force create note.

* Returns these values or gives an error.
	a. Commit's oid
	b. Note blob's oid. 


note_free 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_note              | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_note`` : The note to free.

* Returns none or gives an error.

note_message 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_note              | message (string)                |
+---------------------------+---------------------------------+

1. ``luagit2_note`` : The note whose message is to be found.

* Returns message or gives an error.

note_id 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_note              | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_note`` : The note whose oid is to be found.

* Returns corresponding ``luagit2_oid`` or gives an error.

note_commit_remove 
-----------------------------

Remove an existing note with a new commit.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid (commit_id)         |
+------------------------------+---------------------------------+
| luagit2_commit (immediate    |  luagit2_oid (blob_id)          |
| parent commit )              |                                 |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repos where to make a new note.
2. ``luagit2_commit`` : The parent commit using which note deletion commit will be made.
3. ``luagit2_signature`` : The author signature.
4. ``luagit2_signature`` : The committer signature.
5. ``luagit2_oid`` :  The note oid to remove.

* Returns none or gives an error.

note_remove 
-----------------------------

Remove a commit without making a new commit.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| luagit2_repository           | luagit2_oid (commit_id)         |
+------------------------------+---------------------------------+
| notes_ref (string)           |  luagit2_oid (blob_id)          |
+------------------------------+                                 +
| luagit2_signature(author)    |                                 |
+------------------------------+                                 +
| luagit2_signature(committer) |                                 |
+------------------------------+                                 +
| luagit2_oid                  |                                 |
+------------------------------+---------------------------------+

1. ``luagit2_repository`` : The repos where to make a new note.
2. ``notes_ref`` : The ref where to look for the note to be deleted.
3. ``luagit2_signature`` : The author signature.
4. ``luagit2_signature`` : The committer signature.
5. ``luagit2_oid`` :  The note oid to remove.

* Returns none or gives an error.


note_read 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_note                    |
+---------------------------+                                 +
| notes_ref (string)        |                                 |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : Thhe repository where to look for notes.
2. ``notes_ref`` : The reference name for the notes refs.
3. ``luagit2_oid`` : The oid of note to be found.

* Returns corresponding ``luagit2_note`` or gives an error.

note_commit_read 
-----------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_note                    |
+---------------------------+                                 +
| luagit2_commit            |                                 |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : Thhe repository where to look for notes.
2. ``luagit2_commit`` : The commit corresponding to creation of note for the object.
3. ``luagit2_oid`` : The oid of note to be found.

* Returns corresponding ``luagit2_note`` or gives an error.


