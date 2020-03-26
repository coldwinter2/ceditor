@echo off
mkdir build
cd build
mkdir win32
cd win32
cmake ../../ -G"Visual Studio 15 2017" -Tv141
cd ..
mkdir win64
cd win64
cmake ../../ -G"Visual Studio 15 2017 Win64" -Tv141
cd ..
cd ..

