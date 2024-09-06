import os
import sys

if len(sys.argv) != 2:
    print("Usage: python terminate_process.py <PID>")
    sys.exit(1)

pid = int(sys.argv[1])

try:
    os.kill(pid, 9)  # 9 represents SIGKILL signal
    print(f"Process with PID {pid} has been terminated.")
except OSError as e:
    print(f"Error: {e}")