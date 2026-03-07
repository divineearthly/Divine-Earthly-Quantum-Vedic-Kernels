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
        # The binary might print 'Successfully loaded rules' to stdout. 
        # We need the last line which contains the actual JSON response.
        output_lines = result.stdout.strip().split('\n')
        json_str = output_lines[-1]
        return json.loads(json_str)

    def test_ahimsa_rule(self):
        # Test data that triggers 'rule_001' (Ahimsa Principle)
        data = {"input_sentiment": "violent", "impact_score": 0.9}
        response = self.run_engine("Ahimsa Principle: Non-Violence", data)
        self.assertEqual(response['status'], 'success')
        self.assertIn('Rule Applied', response['message'])
        self.assertIn('Ahimsa', response['message'])

    def test_no_intervention(self):
        # Test data that doesn't trigger any rules (e.g., non-violent sentiment)
        data = {"input_sentiment": "peaceful", "impact_score": 0.1}
        response = self.run_engine("Ahimsa Principle: Non-Violence", data)
        # Updated behavior: should return success with 'No intervention required'
        self.assertEqual(response['status'], 'success')
        self.assertEqual(response['message'], 'No intervention required')

if __name__ == '__main__':
    unittest.main()
