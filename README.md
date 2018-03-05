# Native and WebAssembly builds of GLFW OpenGL/WebGL with CMake


## Use

### Native Linux

Tested on Ubuntu 16.04

* Install development tools: `sudo apt install xorg-dev`
* Install GLFW
  * [Download the source, currently 3.2.1](http://www.glfw.org/download.html)
  * Uncompress the files
  * `cd glfw-3.2.1`
  * `cmake .`
  * `sudo make install`
* Build the example
  * `cd native-wasm-glfw`
  * `make`
* Run the example
  * `make run`
