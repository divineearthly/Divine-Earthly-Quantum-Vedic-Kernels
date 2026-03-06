#!/bin/bash
# 32-Sutra Kernel Integrity Test
make clean && make
echo "--- TESTING VEDIC KERNEL OUTPUT ---"
if [ -f ./vedic_engine ]; then
    ./vedic_engine | python3 -m json.tool > /dev/null
        if [ $? -eq 0 ]; then
                echo "✅ SUCCESS: 32-SUTRA VCF KERNEL PRODUCES VALID JSON"
                    else
                            echo "❌ ERROR: INVALID JSON OUTPUT DETECTED"
                                fi
                                else
                                    echo "❌ ERROR: BUILD FAILED. CHECK MAKEFILE LOGS."
                                    fi
                                    