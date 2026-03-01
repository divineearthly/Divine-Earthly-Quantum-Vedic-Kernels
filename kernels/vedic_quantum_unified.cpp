#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cmath>

namespace py = pybind11;

// Forward declarations for C kernels
extern "C" {
    void urdhva_3x3_matmul_c(const double* A, const double* B, double* res, size_t N);
    void nikhilam_base_shift_c(const double* in, double* out, double base, size_t size);
    int paravartya_3x3_inverse_c(const double* B, double* res);
}

py::array_t<double> urdhva_3x3_matmul(py::array_t<double> A, py::array_t<double> B) {
    auto bufA = A.request();
    auto bufB = B.request();
    size_t N = bufA.shape[0];
    auto result = py::array_t<double>({N, (size_t)3});
    auto bufRes = result.request();

    urdhva_3x3_matmul_c(static_cast<const double*>(bufA.ptr), 
                        static_cast<const double*>(bufB.ptr), 
                        static_cast<double*>(bufRes.ptr), N);
    return result;
}

py::array_t<double> nikhilam_base_shift(py::array_t<double> data, double base) {
    auto buf = data.request();
    auto result = py::array_t<double>(buf.size);
    auto res_buf = result.request();

    nikhilam_base_shift_c(static_cast<const double*>(buf.ptr), 
                          static_cast<double*>(res_buf.ptr), base, buf.size);
    return result;
}

py::array_t<double> paravartya_3x3_inverse(py::array_t<double> B) {
    auto bufB = B.request();
    auto result = py::array_t<double>({(size_t)3, (size_t)3});
    auto bufRes = result.request();

    paravartya_3x3_inverse_c(static_cast<const double*>(bufB.ptr), 
                             static_cast<double*>(bufRes.ptr));
    return result;
}

PYBIND11_MODULE(vedic_quantum_lib, m) {
    m.doc() = "Unified High-Performance Vedic Kernels";
    m.def("urdhva_3x3_matmul", &urdhva_3x3_matmul);
    m.def("nikhilam_base_shift", &nikhilam_base_shift);
    m.def("paravartya_3x3_inverse", &paravartya_3x3_inverse);
}
