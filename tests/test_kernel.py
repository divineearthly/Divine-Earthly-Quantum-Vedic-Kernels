import unittest
import subprocess
import json
import os

class TestVedicKernel(unittest.TestCase):
    def setUp(self):
        self.repo_path = '/content/Divine-Earthly-Quantum-Vedic-Kernels'
        self.vedic_engine_path = os.path.join(self.repo_path, 'vedic_engine')
        self.rules_json_path = os.path.join(self.repo_path, 'configs', 'rules.json')

        # Ensure the engine is compiled (if not already)
        # In a real scenario, this might be handled by a build pipeline
        # For this test, we assume it's compiled or attempt to compile if needed.
        if not os.path.exists(self.vedic_engine_path):
            print("Vedic engine not found, attempting to compile...")
            try:
                subprocess.run(['make', 'clean', '&&', 'make', '-j$(nproc)'], cwd=self.repo_path, check=True, shell=True)
                print("Vedic engine compiled successfully.")
            except subprocess.CalledProcessError as e:
                self.fail(f"Failed to compile vedic_engine: {e}")

        # Ensure rules.json exists (created in previous steps)
        if not os.path.exists(self.rules_json_path):
            self.fail(f"rules.json not found at {self.rules_json_path}")

    def _run_kernel(self, gate_name, json_input_str):
        command = [self.vedic_engine_path, gate_name, json_input_str]
        result = subprocess.run(command, capture_output=True, text=True, cwd=self.repo_path)
        return result.stdout.strip(), result.stderr.strip(), result.returncode

    def test_unknown_gate(self):
        gate_name = "unknown_gate"
        json_input = "{}"
        stdout, stderr, returncode = self._run_kernel(gate_name, json_input)
        self.assertIn("Unknown Cognitive Gate", stdout)
        self.assertEqual(returncode, 0) # Assuming it exits gracefully with error message in stdout

    def test_dummy_gate_with_empty_json(self):
        gate_name = "dummy_gate"
        json_input = "{}"
        stdout, stderr, returncode = self._run_kernel(gate_name, json_input)
        self.assertIn("Unknown Cognitive Gate: dummy_gate", stdout)
        self.assertEqual(returncode, 0)

    def test_rule_loading_and_processing_placeholder(self):
        # This test will primarily check if the C++ kernel starts and loads rules
        # without crashing, and eventually if it indicates rule processing.
        # Actual rule evaluation logic would require more detailed C++ implementation
        # and corresponding output.
        gate_name = "Ahimsa Principle: Non-Violence"
        json_input = json.dumps({
            "input_sentiment": "violent",
            "impact_score": 0.9,
            "action_type": "aggressive"
        })
        stdout, stderr, returncode = self._run_kernel(gate_name, json_input)
        self.assertEqual(returncode, 0)
        # The output currently indicates 'Unknown Cognitive Gate' because the C++ part
        # doesn't yet have specific handlers for the dynamically loaded rules' names.
        # This test verifies it doesn't crash and the rule loading print is present.
        self.assertIn("Successfully loaded", stdout)
        self.assertIn("Unknown Cognitive Gate: Ahimsa Principle: Non-Violence", stdout) # Expected until gate handlers are implemented

    def test_another_rule_with_data(self):
        gate_name = "Ecological Balance: Resource Optimization"
        json_input = json.dumps({
            "resource_consumption": 0.8,
            "environmental_impact": "high",
            "area": "Barak River"
        })
        stdout, stderr, returncode = self._run_kernel(gate_name, json_input)
        self.assertEqual(returncode, 0)
        self.assertIn("Successfully loaded", stdout)
        self.assertIn("Unknown Cognitive Gate: Ecological Balance: Resource Optimization", stdout)

if __name__ == '__main__':
    unittest.main(argv=['first-arg-is-ignored'], exit=False)
