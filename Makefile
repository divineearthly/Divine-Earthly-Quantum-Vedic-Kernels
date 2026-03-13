CXX = g++
CXXFLAGS = -std=c++17 -O3 -march=native -ffast-math -Wall -Iinclude

all: build_dir divine_kernel sovereign_demo

build_dir:
	mkdir -p build

divine_kernel:
	$(CXX) $(CXXFLAGS) main.cpp memory/GarudaShredder.cpp compute/YogaAttention.cpp memory/AkashicRecords.cpp -o build/divine_kernel

sovereign_demo:
	$(CXX) $(CXXFLAGS) sovereign_inference_demo.cpp memory/GarudaShredder.cpp -o build/sovereign_demo

clean:
	@echo "Executing Moksha Protocol (Cleaning build)..."
	rm -rf build/*

run_demo:
	./build/sovereign_demo
