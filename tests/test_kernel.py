import unittest
import subprocess
import json
import os

class TestVedicKernel(unittest.TestCase):
    def setUp(self):
        self.repo_path = '/content/Divine-Earthly-Quantum-Vedic-Kernels'
        self.engine_path = os.path.join(self.repo_path, 'vedic_engine')

    def run_engine(self, gate, data):
        cmd = [self.engine_path, gate, json.dumps(data)]
        result = subprocess.run(cmd, capture_output=True, text=True, cwd=self.repo_path)
        return json.loads(result.stdout)

    def test_ahimsa_rule(self):
        # Test data that should trigger the Ahimsa Principle rule
        data = {"input_sentiment": "violent", "impact_score": 0.9}
        response = self.run_engine("Ahimsa Principle: Non-Violence", data)
        self.assertEqual(response['status'], 'success')
        self.assertIn('Rule Applied', response['message'])

    def test_no_match(self):
        # Test data that doesn't match any specific rule
        data = {"unknown_field": "value"}
        response = self.run_engine("UnknownGate", data)
        self.assertEqual(response['status'], 'error')

if __name__ == '__main__':
    unittest.main()