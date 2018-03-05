# Starter: WebAssembly/WebGL and Native/OpenGL 3D project

Builds with CMake. Supports [GLFW](http://www.glfw.org/).

## Details

* Requires `Make` and `CMake` installed.
* `CMake` configures `Make` to build for both environments.
* The `Makefile` in the root is only a task runner.
* [Libraries available in emscripten][emsdklib].
* Displays an empty off-white window. Nothing else.

[emsdklib]:https://github.com/kripken/emscripten/tree/incoming/system/include

## Building

### WebAssembly

* [Download or Compile the WASM Toolchain][wasm-toolchain].
* Setup the WASM toolchain
  * `cd emsdk`
  * `./emsdk install latest`
  * `./emsdk activate latest`
  * `source ./emsdk_env.sh`
* Build/Run the example
  * `cd starter-wasm-webgl-opengl`
  * `make wasm`
  * Available at: http://localhost:8080/wasm.html

[wasm-toolchain]:http://webassembly.org/getting-started/developers-guide/

### Native Linux

Tested on Ubuntu 16.04.

* Install development tools: `sudo apt install xorg-dev`
* Install GLFW
  * [Download the source, currently 3.2.1][glfw-dl]
  * Uncompress the files
  * `cd glfw-3.2.1`
  * `cmake .`
  * `sudo make install`
* Build/Run the example
  * `cd starter-wasm-webgl-opengl`
  * `make native`

[glfw-dl]:http://www.glfw.org/download.html

## Notes

I was hoping to build both in the same CMake tree, but the `CMAKE_TOOLCHAIN_FILE` change
for emscripten breaks the native build.

Thanks to:

* https://cmake.org/cmake/help/v3.0/
* http://www.glfw.org/docs/latest/quick.html
* https://github.com/HarryLovesCode/WebAssembly-WebGL-2
* https://github.com/daminetreg/emscripten-example/

## Todo

* Test/debug on a fresh Ubuntu install
* Native MacOS
* Native Windows
* More polish