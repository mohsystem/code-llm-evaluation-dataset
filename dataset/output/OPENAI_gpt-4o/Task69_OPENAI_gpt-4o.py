import os
import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)

file_path = sys.argv[1]

try:
    os.remove(file_path)
    print(f"{file_path} deleted successfully.")
except FileNotFoundError:
    print(f"{file_path} does not exist.")
except Exception as e:
    print(f"Error: {e}")