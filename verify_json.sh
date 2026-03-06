#!/bin/bash
    make clean && make
    echo "--- TESTING 32-SUTRA KERNEL INTEGRITY ---"
    if [ -f ./vedic_engine ]; then
        ./vedic_engine | python3 -m json.tool > /dev/null
            if [ $? -eq 0 ]; then
                    echo "✅ SUCCESS: 32-SUTRA VCF KERNEL PRODUCES VALID JSON"
                        else
                                echo "❌ ERROR: INVALID JSON OUTPUT"
                                    fi
                                    else
                                        echo "❌ ERROR: BUILD FAILED"
                                        fi
                                        