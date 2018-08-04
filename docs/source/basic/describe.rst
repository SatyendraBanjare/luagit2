Describe
========

.. contents:: Contents
   :local:

describe_commit
-------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_object            | luagit2_describe_result         |
+---------------------------+---------------------------------+

1. ``luagit2_object`` : The commit object which is to be described.

* Returns ``luagit2_describe_result`` or gives and error.

describe_workdir
-------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | luagit2_describe_result         |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository which is to be described.

* Returns ``luagit2_describe_result`` or gives and error.

describe_format
-------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_describe_result   | luagit2_buf                     |
+---------------------------+---------------------------------+

1. ``luagit2_describe_result`` : The describe result which is to be formatted into a ``luagit2_buf``.

* Returns ``luagit2_buf`` or gives an error.

describe_result_free
-------------------------------

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_describe_result   | None                            |
+---------------------------+---------------------------------+

1. ``luagit2_describe_result`` : The describe result which is to be freed.

* Returns None or gives an error.
