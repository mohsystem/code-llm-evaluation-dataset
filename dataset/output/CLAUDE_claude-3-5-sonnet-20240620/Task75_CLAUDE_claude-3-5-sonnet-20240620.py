
import sys
import os
import signal

def terminate_process(pid):
    try:
        os.kill(pid, signal.SIGTERM)
        print(f"Process with PID {pid} terminated successfully.")
    except OSError as e:
        print(f"Failed to terminate process: {e}")
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <PID>")
        sys.exit(1)

    try:
        pid = int(sys.argv[1])
    except ValueError:
        print("Invalid PID. Please provide a valid integer.")
        sys.exit(1)

    terminate_process(pid)
