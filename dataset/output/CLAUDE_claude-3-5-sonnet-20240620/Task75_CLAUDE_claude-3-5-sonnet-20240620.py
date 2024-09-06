
import os
import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <PID>")
    sys.exit(1)

try:
    pid = int(sys.argv[1])
    os.kill(pid, 9)
    print(f"Process with PID {pid} has been terminated.")
except ValueError:
    print("Invalid PID. Please provide a valid integer.")
except ProcessLookupError:
    print(f"No process with PID {pid} found.")
except PermissionError:
    print(f"Permission denied to terminate process with PID {pid}.")
except Exception as e:
    print(f"An error occurred: {e}")
