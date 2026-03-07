#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

REPO_DIR="/content/Divine-Earthly-Quantum-Vedic-Kernels"
cd "$REPO_DIR"

echo "--- STARTING AUTOMATED UPGRADE ---"

echo "1. Cleaning and Recompiling Kernel..."
make clean
make -j$(nproc)

echo "2. Running Integration Tests..."
if python3 tests/test_kernel.py; then
    echo "Tests Passed! Proceeding with Git Workflow..."
    
    echo "3. Staging and Committing Changes..."
    git add .
    # Use || true to avoid script exit if there are no changes to commit
    git commit -m "Upgrade: Hybrid AI + symbolic kernel architecture" || echo "No changes to commit"
    
    echo "4. Attempting Push to Main..."
    # This requires GITHUB_USERNAME and GITHUB_PAT to be configured in the git remote URL
    git push origin main
    
    echo "--- UPGRADE SUCCESSFUL ---"
else
    echo "❌ ERROR: Tests Failed. Aborting Push."
    exit 1
fi
