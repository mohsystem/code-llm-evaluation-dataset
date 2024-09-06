import os
import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <PID>")
    sys.exit(1)

pid = int(sys.argv[1])
os.kill(pid, 9)