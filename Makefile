# Make as a task manager to run cmake to run make.
SRC=src/demo.cpp
WASM=build/wasm.html
NATIVE=build-native/native

.PHONY: all
all: $(WASM) $(NATIVE)

# Build WebAssembly and load in Python Webserver
.PHONY: wasm
wasm: $(WASM)
	cd build && python -m SimpleHTTPServer 8080	

# Build Native and execute
.PHONY: native
native: $(NATIVE)
	$(NATIVE)

$(WASM): $(SRC)
	mkdir -p build
	cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake
	cd build && make

$(NATIVE): $(SRC)
	mkdir -p build-native
	cd build-native && cmake ../native
	cd build-native && make

.PHONY: clean
clean:
	cd build && make clean
	cd build-native && make clean