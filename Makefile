# Make as a task manager to run cmake to run make.
.PHONY: all clean

all: build/Demo

build/Demo:
	mkdir -p build
	cd build && cmake ..
	cd build && make

run: build/Demo
	build/Demo

clean:
	cd build && make clean