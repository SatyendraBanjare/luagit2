Graph
=====

.. contents:: Contents
   :local:


graph_ahead_behind
-----------------------

	This Method help in comparing and finding number of commits in between 2 commits.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | numbers_ahead (number)          |
+---------------------------+---------------------------------+
| luagit2_oid (current)     | numbers_behind(number)          |
+---------------------------+                                 +
| luagit2_oid(upstream)     |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose commits are to be compared.
2. ``luagit2_oid`` : The current commit.
3. ``luagit2_oid`` : The other upstream commit with which to compare.

* Returns two numbers in order: 
	a. number of commits current commit is ahead of upstream commit.
	b. number of commits current commit is behind upstream commit.

.. note:: The upstream commit must be one of commits in the same tree as the other commit.

graph_descendant_of
-----------------------

	Helps in checking if one commit is parent commit of other.

+---------------------------+---------------------------------+
| parameters                | Returns                         |
+===========================+=================================+
| luagit2_repository        | is_decendent (Boolean)          |
+---------------------------+                                 +
| luagit2_oid (current)     |                                 |
+---------------------------+                                 +
| luagit2_oid(upstream)     |                                 |
+---------------------------+---------------------------------+

1. ``luagit2_repository`` : The repository whose commits are to be compared.
2. ``luagit2_oid`` : The current commit to check.
3. ``luagit2_oid`` : The ancestor commit with which to compare.

* Returns a boolean value for whether current commit is a child commit of other or gives an error.
