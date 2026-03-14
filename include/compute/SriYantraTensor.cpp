#include "include/compute/SriYantraTensor.h"

namespace DivineEarthlyKernels {
namespace Compute {

template<typename T>
SriYantraTensor::Tensor<T>::Tensor(const std::vector<size_t>& s) : shape(s) {
    size_t total_size = std::accumulate(s.begin(), s.end(), 1, std::multiplies<size_t>());
    data.resize(total_size);
}

template<typename T>
T& SriYantraTensor::Tensor<T>::operator()(size_t d0, size_t d1, size_t d2) {
    // Simplified 3D access
    return data[d0 * shape[1] * shape[2] + d1 * shape[2] + d2];
}

template<typename T>
const T& SriYantraTensor::Tensor<T>::operator()(size_t d0, size_t d1, size_t d2) const {
    return data[d0 * shape[1] * shape[2] + d1 * shape[2] + d2];
}

template<typename T>
void SriYantraTensor::projectTensor(Tensor<T>& tensor, const std::string& projection_type) {
    std::cout << "[SriYantra] Projecting tensor with shape (" << tensor.shape[0] << "," << tensor.shape[1] << "," << tensor.shape[2] << ") using " << projection_type << " projection.\n";
    // In a real scenario, this would involve complex mathematical transformations.
    // Here, we just conceptually acknowledge the operation.
}

template<typename T>
SriYantraTensor::Tensor<T> SriYantraTensor::performTensorOperation(const Tensor<T>& tensor1, const Tensor<T>& tensor2, const std::string& operation_name) {
    if (tensor1.shape != tensor2.shape) {
        throw std::runtime_error("Tensor shapes must match for this operation");
    }

    Tensor<T> result(tensor1.shape);
    std::cout << "[SriYantra] Performing operation: " << operation_name << std::endl;

    if (operation_name == "add") {
        for (size_t i = 0; i < tensor1.data.size(); ++i) {
            result.data[i] = tensor1.data[i] + tensor2.data[i];
        }
    }
    // Add more operations as needed (e.g., multiply, dot product)

    return result;
}

void SriYantraTensor::demonstrate() {
    std::cout << "\n--- Sri Yantra Tensor Demonstration ---\n";
    Tensor<float> t1({2, 2, 2});
    Tensor<float> t2({2, 2, 2});

    // Initialize tensors
    std::iota(t1.data.begin(), t1.data.end(), 1.0f);
    std::iota(t2.data.begin(), t2.data.end(), 1.0f);

    std::cout << "Tensor 1 initialized with sequential values.\n";
    std::cout << "Tensor 2 initialized with sequential values.\n";

    auto t3 = performTensorOperation(t1, t2, "add");

    std::cout << "Result of t1 + t2 (first element): " << t3(0,0,0) << std::endl;
    
    projectTensor(t3, "PCA-like");
    std::cout << "--- End Sri Yantra Demonstration ---\n";
}

// Explicit template instantiation
template struct SriYantraTensor::Tensor<float>;
template void SriYantraTensor::projectTensor<float>(Tensor<float>&, const std::string&);
template SriYantraTensor::Tensor<float> SriYantraTensor::performTensorOperation<float>(const Tensor<float>&, const Tensor<float>&, const std::string&);

} // namespace Compute
} // namespace DivineEarthlyKernels
