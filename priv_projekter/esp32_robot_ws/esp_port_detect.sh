#!/bin/bash

# Find all potential serial ports
PORTS=$(ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null)

if [ -z "$PORTS" ]; then
    echo "No serial ports found (USB0/ACM0)."
    exit 1
fi

echo "Searching for ESP device..."

for PORT in $PORTS; do
    echo "Testing $PORT..."
    OUTPUT=$(esptool.py --port $PORT chip_id 2>&1)

    if echo "$OUTPUT" | grep -q "Detecting chip type"; then
        
        # Extract chip type (ESP32, ESP32-S3, ESP32-C6, …)
        CHIP=$(echo "$OUTPUT" | grep "Chip is" | sed -E 's/.*Chip is ([A-Za-z0-9\-]+).*/\1/')

        if [ -n "$CHIP" ]; then
            echo "ESP detected:"
            echo "   • Port: $PORT"
            echo "   • Chip type: $CHIP"
            exit 0
        fi
    fi
done

echo "No ESP devices responded."
exit 1
