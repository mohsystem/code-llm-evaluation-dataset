import sys
import os

if len(sys.argv) != 2:
    print("Usage: python script.py <PID>")
    sys.exit(1)

pid = int(sys.argv[1])
try:
    os.kill(pid, 15)
except OSError as e:
    print("Error:", e.strerror)
    sys.exit(1)