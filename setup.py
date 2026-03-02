
from setuptools import setup, Extension
import sysconfig
import pybind11
import os
import glob
import sys

# Get pybind11 include paths
pybind11_include_dirs = [
    pybind11.get_include(),
    pybind11.get_include(user=True)
]

# Define the extension module
water_kernels_module = Extension(
    'water_kernels',
    sources=['water_kernel.cpp'],
    include_dirs=pybind11_include_dirs,
    extra_compile_args=['-std=c++17', '-O3', '-Wall'],
    # Removed extra_link_args, as setuptools/pybind11 typically handle Python linking
    language='c++', 
)

setup(
    name='water_kernels_pybind11',
    version='0.0.1',
    author='Divine Earthly',
    author_email='divineearthly@gmail.com',
    description='A small example package for water system analysis with pybind11',
    ext_modules=[water_kernels_module],
    install_requires=['pybind11>=2.6.0'],
    zip_safe=False,
)
