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
        # The binary prints initialization logs followed by the JSON response on the last line
        output_lines = [line for line in result.stdout.strip().split('\n') if line.strip()]
        if not output_lines:
            raise ValueError(f"No output from engine. Stderr: {result.stderr}")
        json_str = output_lines[-1]
        return json.loads(json_str)

    def test_ahimsa_rule_trigger(self):
        # Test data that triggers 'rule_001' (Ahimsa Principle)
        data = {"input_sentiment": "violent", "impact_score": 0.9}
        response = self.run_engine("Ahimsa Principle: Non-Violence", data)
        self.assertEqual(response['status'], 'success')
        self.assertIn('Rule Applied', response['message'])

    def test_no_intervention_fallback(self):
        # Test data that should not trigger rules
        data = {"input_sentiment": "peaceful", "impact_score": 0.1}
        response = self.run_engine("Ahimsa Principle: Non-Violence", data)
        self.assertEqual(response['status'], 'success')
        self.assertEqual(response['message'], 'No intervention required')

if __name__ == '__main__':
    unittest.main()
