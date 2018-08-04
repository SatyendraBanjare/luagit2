Signature
=========

These methods allow us to create ``git signatures`` to be used 
while creating commits or tags.

.. contents:: Contents
   :local:

signature_default
-----------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` :  The repository's whose default signature is to be found.

* Returns corresponding ``luagit2_signature`` or gives an error.

signature_dup
-------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_signature         | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``luagit2_signature`` :  The old signature whose duplicate is to be made.

* Returns corresponding duplicate ``luagit2_signature`` or gives an error.

signature_from_buffer
---------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| sign_data (string)        | luagit2_signature               |
+---------------------------+---------------------------------+

1. ``sign_data`` :  The signature data used to make a luagit2_signature .

* Returns corresponding ``luagit2_signature`` or gives an error.

signature_now
-------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| username (string)         | luagit2_signature               |
+---------------------------+                                 +
| password (string)         |                                 |
+---------------------------+---------------------------------+

1. ``username`` : The username of signature.
2. ``password`` : The password of signature.

* returns ``luagit2_signature``  or gives an error.

signature_free
--------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_signature         | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_signature`` :  The signature to be freed.

* Returns None or gives an error.

