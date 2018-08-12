
#!/bin/sh

cd ~

git clone --depth=1 -b maint/v0.27 https://github.com/libgit2/libgit2.git
cd libgit2/

mkdir build && cd build
cmake .. -DBUILD_CLAR=OFF
sudo make install

ls -la ..











