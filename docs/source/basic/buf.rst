Buf
===

buf_set_str 
-------------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| data (string)             | luagit2_buf                     |
+---------------------------+---------------------------------+

1. ``data`` : The string data to put in the luagit2_buf.

* returns ``luagit2_buf`` or an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/buf/git_buf_set

buf_free 
-------------------------------------

.. note:: The **buf_free** is being worked upon. It is advised not to use that for now.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| data (string)             | none                            |
+---------------------------+---------------------------------+

1. ``luagit2_buf`` : The luagit2_buf to free.

* returns none or an error.

* :guilabel:`libgit2 equivalent` : https://libgit2.org/libgit2/#HEAD/group/buf/git_buf_free

