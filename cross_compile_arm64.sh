#!/bin/bash

CXX=aarch64-linux-gnu-g++
INCLUDE_DIR="./include"
OUTPUT="build/divine_kernel_arm64"

mkdir -p build

echo "Starting Cross-Compilation for ARM64..."

$CXX -std=c++17 -O3 -march=armv8-a+simd -ffast-math -Wall \
    -I$INCLUDE_DIR \
    sovereign_inference_demo.cpp \
    memory/GarudaShredder.cpp \
    -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "[Success] ARM64 binary created at: $OUTPUT"
    file $OUTPUT
else
    echo "[Error] Cross-compilation failed. Ensure aarch64-linux-gnu-g++ is installed."
fi
