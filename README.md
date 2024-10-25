## Introduction:
**FdF** (Fil de Fer) is a wireframe model representation program, part of the 42 curriculum. It reads a file representing a 3D map and displays it as a 2D isometric projection. This project is an introduction to graphical programming, specifically using the **MiniLibX** graphics library.
This code is built to work on linux and was only tested on Debian

# Prerequisites:

1.  clone 42 minilibx into main directory
```sh
git clone https://github.com/42Paris/minilibx-linux.git 
 ```
2.  compile minilibx
```sh
cd minilibx-linux
./configure
cd ..
```
4.  install the following packages: xorg, x11, zlib, libxext-dev, zlib1g-dev
```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
4.  compile
```sh
make && ./fdf ./test_maps/42.fdf
```
