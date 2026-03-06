import cmath

def vedic_complex_multiply(z1, z2):
    """
    Implements complex number multiplication using the 'Urdhva Tiryagbhyam'
    (Vertically and Crosswise) Vedic Sutra principle.

    For two complex numbers z1 = (a + bi) and z2 = (c + di):
    The product is (ac - bd) + (ad + bc)i.
    This function explicitly computes these intermediate products (ac, bd, ad, bc)
    and combines them, reflecting the structured approach of the Sutra.
    For standard floating-point numbers, this is primarily illustrative and
    not a performance optimization over native complex multiplication.
    """
    a, b = z1.real, z1.imag
    c, d = z2.real, z2.imag

    # Vertical products for real part components
    ac = a * c
    bd = b * d

    # Cross products for imaginary part components
    ad = a * d
    bc = b * c

    # Combine them to get the final real and imaginary parts
    real_part = ac - bd
    imag_part = ad + bc

    return complex(real_part, imag_part)

def vedic_matrix_vector_multiply(matrix, vector):
    """
    Performs matrix-vector multiplication using vedic_complex_multiply for
    each element-wise complex product.
    """
    num_rows = len(matrix)
    num_cols = len(matrix[0])
    if num_cols != len(vector):
        raise ValueError("Matrix columns must match vector length")

    result_vector = [complex(0, 0)] * num_rows

    for i in range(num_rows):
        current_sum = complex(0, 0)
        for j in range(num_cols):
            # Use Vedic-inspired complex multiplication
            term = vedic_complex_multiply(matrix[i][j], vector[j])
            current_sum = current_sum + term  # Standard complex addition
        result_vector[i] = current_sum
    return result_vector

def vedic_dot_product(vec1, vec2):
    """
    Calculates the dot product of two complex vectors, using vedic_complex_multiply
    for each element-wise complex product. Assumes vec1 is conjugated for <vec1|vec2>.
    """
    if len(vec1) != len(vec2):
        raise ValueError("Vectors must have the same length")

    result = complex(0, 0)
    for i in range(len(vec1)):
        # For dot product <vec1|vec2>, we use the conjugate of vec1[i]
        term = vedic_complex_multiply(vec1[i].conjugate(), vec2[i])
        result = result + term  # Standard complex addition
    return result

def simulate_2_qubit_vedic_optimization(initial_state_vector):
    """
    Simulates a basic 2-qubit quantum task, applying Vedic Math principles
    (specifically the 'Urdhva Tiryagbhyam' Sutra for complex multiplication)
    to its core arithmetic operations.

    The 'optimization' here refers to structuring complex number arithmetic
    according to Vedic Sutra principles, breaking down multiplication into
    explicit vertical and crosswise components, rather than a computational
    speedup over highly optimized native complex number operations in Python.

    The task involves:
    1.  Initializing a 2-qubit state.
    2.  Applying a CNOT gate (control Q0, target Q1).
    3.  Calculating the expectation value of the Pauli Z operator on Q0.

    Args:
        initial_state_vector (list or numpy.ndarray): A list or array of 4 complex
                                                      numbers representing the
                                                      amplitudes of the 2-qubit state
                                                      in the computational basis
                                                      (|00>, |01>, |10>, |11>).
                                                      The state should be normalized.

    Returns:
        float: The real part of the expectation value of the Pauli Z operator on Q0.
               Returns a float as expectation values for Hermitian observables are real.
    """

    # Ensure the input is a list of complex numbers
    state = [complex(x) for x in initial_state_vector]

    # Normalize the initial state if not already (safeguard, though caller should ensure)
    # Using vedic_complex_multiply to calculate magnitude squared for normalization
    norm_sq = sum([vedic_complex_multiply(amp.conjugate(), amp).real for amp in state])
    norm = cmath.sqrt(norm_sq)
    state = [amp / norm for amp in state]

    # Define the CNOT gate (control Q0, target Q1) as a 4x4 unitary matrix
    # Basis order: |00>, |01>, |10>, |11>
    cnot_gate = [
        [complex(1, 0), complex(0, 0), complex(0, 0), complex(0, 0)],
        [complex(0, 0), complex(1, 0), complex(0, 0), complex(0, 0)],
        [complex(0, 0), complex(0, 0), complex(0, 0), complex(1, 0)],
        [complex(0, 0), complex(0, 0), complex(1, 0), complex(0, 0)]
    ]

    # Apply the CNOT gate to the state vector using Vedic-inspired matrix-vector multiplication
    state_after_cnot = vedic_matrix_vector_multiply(cnot_gate, state)

    # Define the observable: Pauli Z on Q0 (tensor product with Identity on Q1)
    # Z_0 = Z_q0 @ I_q1 = [[1, 0], [0, -1]] @ [[1, 0], [0, 1]]
    # In the |00>, |01>, |10>, |11> basis:
    observable_z0 = [
        [complex(1, 0), complex(0, 0), complex(0, 0), complex(0, 0)],
        [complex(0, 0), complex(1, 0), complex(0, 0), complex(0, 0)],
        [complex(0, 0), complex(0, 0), complex(-1, 0), complex(0, 0)],
        [complex(0, 0), complex(0, 0), complex(0, 0), complex(-1, 0)]
    ]

    # Calculate O|psi'> using Vedic-inspired matrix-vector multiplication
    observable_applied_state = vedic_matrix_vector_multiply(observable_z0, state_after_cnot)

    # Calculate the expectation value <psi'|O|psi'> using Vedic-inspired dot product
    expectation_value = vedic_dot_product(state_after_cnot, observable_applied_state)

    # Expectation values for Hermitian observables are always real
    return expectation_value.real