.. LuaGit2 documentation master file, created by
   sphinx-quickstart on Fri May 11 15:09:58 2018.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to LuaGit2's documentation!
===================================

 `Luagit2`_ is a tool to do cool git things on lua. It depends on `Libgit2`_ ``Version 0.27.0`` and
 consists of updated Lua bindings to the same. 

 It is currently compatible to be used only for ``lua 5.3``. 

 It is built using `Lua_C_Api`_ and has its tests written using `Busted`_ . It can be easily
 installed using luarocks and Cmake/Make.

*************
Compatibility
*************

   * Libgit2 - **0.27.0**
   * Lua- **5.3**

   * Operating systems :
      1. Linux
      2. MacOs

.. _Libgit2: https://github.com/libgit2/libgit2
.. _Luagit2: https://github.com/SatyendraBanjare/luagit2
.. _Lua_C_Api: https://www.lua.org/pil/24.html
.. _Busted: https://github.com/Olivine-Labs/busted

.. toctree::
   :maxdepth: 2
   :caption: Installation
   
   install/index

.. toctree::
   :maxdepth: 2
   :caption: API Documentation
   
   basic/index
   examples/index


