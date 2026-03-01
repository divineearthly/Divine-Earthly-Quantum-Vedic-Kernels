# Divine Earthly: Universal Harmony & Quantum-Vedic Integration

Autonomous Vedic-Quantum Kernels designed for high-performance High Energy Physics (HEP) reconstruction and coordinate transformations.

## 🌌 Project Overview

This project integrates ancient Vedic mathematical principles with modern Quantum computing and high-performance C++ kernels to optimize particle track reconstruction. The core focus is on the **Urdhva Tiryakbhyam** (Vertical and Crosswise) algorithm applied to $3 \times 3$ transformation matrices.

## 🚀 Key Features

- **Vedic-Quantum Kernels**: Hybrid models mapping Vedic constants (1.08, 1.618) to Quantum rotation gates (Rx, Ry, Rz).
- **Optimized C++ Extension**: A `pybind11`-based module for $N \times 3$ matrix multiplications, providing significant speedups over standard Python/NumPy implementations.
- **HEP Integration**: Specifically tuned for particle track transformations and detector layer calibrations.

## 📊 Performance Benchmark

| Implementation | Time ($10^6$ runs) | Speedup |
| :--- | :--- | :--- |
| NumPy Baseline | 0.0813s | 1.00x |
| **Vedic C++ Kernel** | **0.0482s** | **1.69x** |

*Benchmarks were performed on coordinate matrices of size $10^6 \times 3$.*

## 🛠️ Installation & Usage

### Prerequisites
- Python 3.12+
- `pybind11`
- `g++` compiler

### Compiling the Kernel
```bash
g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) vedic_kernel.cpp -o vedic_cpu$(python3-config --extension-suffix)
```

### Python Usage
```python
import vedic_cpu
import numpy as np

A = np.random.rand(100, 3)
B = np.eye(3) * 1.618
result = vedic_cpu.urdhva_3x3_matmul(A, B)
```

## 📜 Documentation
Full Sphinx documentation can be found in the `docs/` directory.

## ✍️ Author
**Joydeep Das (Arjuna)**
