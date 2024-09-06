import sys
import os

if len(sys.argv) != 2:
    print("Usage: python terminate_process.py <PID>")
    sys.exit(1)

pid = int(sys.argv[1])
try:
    os.kill(pid, 9)
except OSError as e:
    print(f"Error: {e}")