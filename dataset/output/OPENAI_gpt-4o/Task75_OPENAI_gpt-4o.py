import os
import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <PID>")
    else:
        pid = int(sys.argv[1])
        try:
            os.kill(pid, 9)
            print(f"Process {pid} terminated.")
        except OSError as e:
            print(f"Error: {e}")