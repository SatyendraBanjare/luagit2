# Luagit2

<p>(for Lua >= 5.1 and < 5.4 )</p>

Updated Lua bindings to libgit2 written using [LuaC-API](https://www.lua.org/pil/24.html) and 
tests written using [Lunatest](https://luarocks.org/modules/luarocks/lunatest/0.9.5-1)
and coverage using [luacov](https://luarocks.org/modules/mpeterv/luacov/0.13.0-1). 

Though the project is still under development, you can try, install and test the project using: 

## Installation 

- First, install [libgit2](https://github.com/libgit2/libgit2), according to the instructions on their documentation.

- Since this project depends on LuaC-Api , it is required to install `liblua5.1-dev`, `liblua5.2-dev` , `liblua5.3-dev` 
as :

```
sudo apt-get install liblua5.1-dev
sudo apt-get install liblua5.2-dev
sudo apt-get install liblua5.3-dev
```

### install using cmake/make

```
git clone https://github.com/SatyendraBanjare/luagit2.git
cd luagit2
mkdir build && cd build
cmake ..
make 
make install
```

### install using luarocks

```
cd luagit2 
sudo luarocks make
```

## Runnig tests

Make sure you have lunatest and luacov installed (refer link above).

```
cd tests/
lua <filename>.lua -lluacov
```

To get the coverage result,
```
cd tests/
luacov
```

It generates text file luacov.report.out our final coverage report. 
