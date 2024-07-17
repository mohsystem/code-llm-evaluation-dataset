import sys
import os
def kill_process(pid):
    try:
        os.kill(pid, signal.SIGTERM)
        print(f"Process with PID {pid} terminated successfully.")
    except OSError as e:
        print(f"Error terminating process with PID {pid}: {e}")
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python terminate_process.py <PID>")
        sys.exit(1)
    try:
        pid_to_kill = int(sys.argv[1])
        kill_process(pid_to_kill)
    except ValueError:
        print("Invalid PID provided. Please provide an integer.")
        sys.exit(1)