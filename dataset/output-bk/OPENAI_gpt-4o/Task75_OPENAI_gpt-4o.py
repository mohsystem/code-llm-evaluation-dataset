import os
import sys
import signal

if len(sys.argv) != 2:
    print("Usage: python script.py <pid>")
    sys.exit(1)

pid = int(sys.argv[1])

try:
    os.kill(pid, signal.SIGKILL)
    print(f"Process {pid} terminated.")
except ProcessLookupError:
    print(f"Failed to terminate process {pid}.")
except PermissionError:
    print(f"No permission to terminate process {pid}.")