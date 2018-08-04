Cred
====

These methods help to create different type of Credential objects for a git repository.

.. contents:: Contents
   :local:


cred_default_new 
---------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_cred_object             |
+---------------------------+---------------------------------+

* There are no parameters required. It finds default git credential details and returns ``luagit2_cred_object`` consisting of that data or gives an error.

cred_ssh_key_from_agent 
---------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| username(string)          | luagit2_cred_object             |
+---------------------------+---------------------------------+

1. ``username`` : The Agent username required to make a credential object.

* Returns ``luagit2_cred_object`` for the given username or gives an error.

cred_ssh_key_memory_new
---------------------------------------

	Create a new ssh key credential object reading the keys from memory.

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| username(string)             | luagit2_cred_object             |
+------------------------------+                                 +
| public_key(string)           |                                 |
+------------------------------+                                 +
| private_key(string)          |                                 |
+------------------------------+                                 +
| pass_phrase(string)          |                                 |
+------------------------------+---------------------------------+


1. ``username`` : The username to be used.
2. ``public_key`` : The public key.
3. ``private_key`` : The private key.
4. ``pass_phrase`` : The pass phrase.

* Returns corresponding ``luagit2_cred_object`` or an error.

cred_ssh_key_new 
---------------------------------------

	Create a new ssh key credential object .

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| username(string)             | luagit2_cred_object             |
+------------------------------+                                 +
| public_key(string)           |                                 |
+------------------------------+                                 +
| private_key(string)          |                                 |
+------------------------------+                                 +
| pass_phrase(string)          |                                 |
+------------------------------+---------------------------------+


1. ``username`` : The username to be used.
2. ``public_key`` : The public key.
3. ``private_key`` : The private key.
4. ``pass_phrase`` : The pass phrase.

* Returns corresponding ``luagit2_cred_object`` or an error.

cred_username_new 
---------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| username(string)          | luagit2_cred_object             |
+---------------------------+---------------------------------+

1. ``username`` : The username required to make a credential object.

* Returns ``luagit2_cred_object`` for the given username or gives an error.

cred_userpass_plaintext_new 
---------------------------------------

+------------------------------+---------------------------------+
| parameters                   | Returns                         |
+==============================+=================================+
| username(string)             | luagit2_cred_object             |
+------------------------------+                                 +
| password(string)             |                                 |
+------------------------------+---------------------------------+

1. ``username`` : The username to be used.
2. ``password`` : The password to be used.

* Returns ``luagit2_cred_object`` for these provided details or gives an error. 

cred_free 
---------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_cred_object       | none                            |
+---------------------------+---------------------------------+

1. ``luagit2_cred_object`` : The credential object to free.

* Returns none or gives an error.
