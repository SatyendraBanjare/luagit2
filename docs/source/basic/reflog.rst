Reflog
======

These methods help in reading reflogs for given reference.

.. contents:: Contents
   :local:


reflog_read
-----------

Read reflog for given reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_reflog                  |
+---------------------------+                                 +
| name                      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to look for reflogs.
2. ``name`` :  The name for which to look for reflog. example : ``HEAD`` or ``master``.

* Returns ``luagit2_reflog`` accordingly or gives an error.

reflog_entrycount
-----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog            | count (number)                  |
+---------------------------+---------------------------------+

1. ``luagit2_reflog`` : The reflog whose details to find.

* Returns count of number of entries accordingly or gives an error.

reflog_free
-----------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog            | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_reflog`` : The reflog to free.

* Returns None or gives an error.

reflog_entry_byindex
--------------------

Get a reflog entry from luagit2_reflog.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog            | luagit2_reflog_entry            |
+---------------------------+                                 +
| index_number(integer)     |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_reflog`` : The reflog where to look for entries.
2. ``index_number`` :  The index number of entry in reflog which is being looked up.

* Returns ``luagit2_reflog_entry`` accordingly or gives an error.

reflog_entry_committer
----------------------

Find reflog entry committer sign.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog_entry      | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_reflog_entry`` : The reflog entry whose committer is to be found.

* Returns committer's ``luagit2_signature`` accordingly or gives an error.

reflog_entry_message
--------------------

Find reflog entry message.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog_entry      | message(string)                 |
+---------------------------+---------------------------------+

1. ``luagit2_reflog_entry`` : The reflog entry whose message is to be found.

* Returns message or gives an error.

reflog_entry_id_new
-------------------

Get the reflog entry's new id.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog_entry      | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_reflog_entry`` : The reflog entry whose oid is to be found.

* Returns ``luagit2_oid`` or gives an error.

reflog_entry_id_old
-------------------

Get the reflog entry's old id.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog_entry      | luagit2_oid                     |
+---------------------------+---------------------------------+

1. ``luagit2_reflog_entry`` : The reflog entry whose oid is to be found.

* Returns ``luagit2_oid`` or gives an error.

reflog_delete
--------------

Delete reflog for given reference.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| name                      |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to delete the reflogs.
2. ``name`` :  The reflog which to delete. example : ``HEAD`` or ``master``.

* Returns None or gives an error.

reflog_drop
-----------

Drop a reflog_enrty in a reflog.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | None                            |
+---------------------------+                                 +
| index_number              |                                 |
+---------------------------+                                 +
|rewrite_previous_entry(int)|                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository where to drop the reflogs.
2. ``index_number`` :  The entry's index number which to drop.
3. ``rewrite_previous_entry`` : the integer equivalent of boolean whether to rewrite reflog or not. o ensure there's no gap in the log history, set rewrite_previous_entry param value to 1. When deleting entry n, member old_oid of entry n-1 (if any) will be updated with the value of member new_oid of entry n+1.


* Returns None or gives an error.

reflog_append
-------------

append a new entry to an existing reflog.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_reflog            | None                            |
+---------------------------+                                 +
| luagit2_oid               |                                 |
+---------------------------+                                 +
|luagit2_signature          |                                 |
+---------------------------+                                 +
|Message(string)            |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_reflog`` :The reflog where to append new entry.
2. ``luagit2_oid`` : The OID the reference is now pointing to.
3. ``luagit2_signature`` : The committer's signature.
4. ``message`` : the reflog entry message.

* Returns none or gives an error.
