############
Installation
############

This section is about how to successfully install ``luagit2`` from the source.


Requirements :
--------------
- Lua 5.3 (ONLY)
- Libgit2 - 0.27.0
- liblua5.3-dev


First make sure ``Libgit2`` is succesfully installed on your system.
There are some important libraries on which Libgit2 depends.

Here is a quick handy guide to install them

.. code-block:: sh

   $ sudo apt-get install libhttp-parser-dev
   $ sudo apt install libssh2-1-dev
   $ sudo apt install libcurl4-openssl-dev


Finally install Libgit2 using :

.. code-block:: sh

   $ wget https://github.com/libgit2/libgit2/archive/v0.27.0.tar.gz
   $ tar xzf v0.27.0.tar.gz
   $ cd libgit2-0.27.0/
   $ cmake .
   $ make
   $ sudo make install


Install liblua5.3-dev using :

.. code-block:: sh

   $ sudo apt-get install liblua5.3-dev

At this point you should be all ready for installation of luagit2.

Do a quick git clone of luagit2 using :

.. code-block:: sh

   $ git clone https://github.com/SatyendraBanjare/luagit2.git

The user may now proceed with installation using any of these two methods.

Cmake/Make
----------

In the root directory of luagit2.

.. code-block:: sh

   $ mkdir build && cd build
   $ cmake ..
   $ make
   $ sudo make install

Luarocks
--------

In the root directory of luagit2.

.. code-block:: sh

   $ sudo luarocks make luagit2-0.0-1.rockspec

If you also have busted installed on your system, you may proceed to tests.
