# Python
import sys
import os
import signal

if len(sys.argv) != 2:
    print("Usage: python terminate_process.py <PID>")
    sys.exit(1)

pid = int(sys.argv[1])

if pid <= 0:
    print("Invalid PID.")
    sys.exit(1)

if pid == os.getpid():
    print("Cannot terminate the current process.")
    sys.exit(1)

try:
    os.kill(pid, signal.SIGTERM)
    print(f"Process {pid} terminated.")
except OSError as e:
    print(f"Error terminating process: {e}")
    sys.exit(1)