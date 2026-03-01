import unittest
import numpy as np
import vedic_quantum_lib # Changed from vedic_cpu

class TestVedicKernel(unittest.TestCase):
    def setUp(self):
        """Initialize standard test data for Vedic Kernel tests."""
        np.random.seed(42)
        self.test_matrix_A = np.random.rand(10, 3).astype(np.float64)

    def test_identity_transformation(self):
        """Verify that multiplying by an identity matrix returns the original matrix."""
        identity_matrix = np.eye(3).astype(np.float64)
        result = vedic_quantum_lib.urdhva_3x3_matmul(self.test_matrix_A, identity_matrix) # Changed to vedic_quantum_lib
        np.testing.assert_allclose(result, self.test_matrix_A, rtol=1e-7, atol=1e-8)

    def test_zero_matrix(self):
        """Verify that multiplying by a zero matrix returns all zeros."""
        zero_matrix = np.zeros((3, 3)).astype(np.float64)
        result = vedic_quantum_lib.urdhva_3x3_matmul(self.test_matrix_A, zero_matrix) # Changed to vedic_quantum_lib
        expected = np.zeros((10, 3))
        np.testing.assert_allclose(result, expected, atol=1e-8)

    def test_scaling_matrix(self):
        """Verify that multiplying by a scaling matrix correctly scales the input."""
        scalar = 2.5
        scaling_matrix = (np.eye(3) * scalar).astype(np.float64)
        result = vedic_quantum_lib.urdhva_3x3_matmul(self.test_matrix_A, scaling_matrix) # Changed to vedic_quantum_lib
        expected = self.test_matrix_A * scalar
        np.testing.assert_allclose(result, expected, rtol=1e-7, atol=1e-8)

    def test_stress_large_random(self):
        """Verify numerical precision against NumPy using a large random dataset."""
        N = 100000
        large_A = np.random.rand(N, 3).astype(np.float64)
        rand_B = np.random.rand(3, 3).astype(np.float64)

        # Compute results
        result_cpp = vedic_quantum_lib.urdhva_3x3_matmul(large_A, rand_B) # Changed to vedic_quantum_lib
        result_np = np.matmul(large_A, rand_B)

        # Assert strict precision match
        np.testing.assert_allclose(result_cpp, result_np, rtol=1e-12, atol=1e-14)

if __name__ == '__main__':
    unittest.main(argv=['first-arg-is-ignored'], exit=False)
