Checkout
========

These methods help doing a ``git checkout`` to either a repository's **HEAD**
or `Index` or `Tree`.

.. contents:: Contents
   :local:

checkout_init_options
-----------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| None                      | luagit2_checkout_options        |
+---------------------------+---------------------------------+

* Creates a ``luagit2_checkout_options`` to be used in other functions or gives an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/checkout/git_checkout_init_options

checkout_head
-----------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| luagit2_checkout_options  |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository in which checkout is to be performed.
2. ``luagit2_checkout_options`` :  The checkout options to be used while checkout is performed.

* returns none or an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/checkout/git_checkout_head

checkout_index
-----------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| luagit2_index             |                                 |
+---------------------------+                                 +
| luagit2_checkout_options  |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository in which checkout is to be performed.
2. ``luagit2_index`` : The index to which checkout is to be performed.
3. ``luagit2_checkout_options`` :  The checkout options to be used while checkout is performed.

* returns none or an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/checkout/git_checkout_index

checkout_tree
----------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        |                                 |
+---------------------------+ None                            +
| luagit2_tree              |                                 |
+---------------------------+                                 +
| luagit2_checkout_options  |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository in which checkout is to be performed.
2. ``luagit2_tree`` : The tree to which checkout is to be performed.
3. ``luagit2_checkout_options`` :  The checkout options to be used while checkout is performed.

* returns none or an error.
* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/checkout/git_checkout_tree
