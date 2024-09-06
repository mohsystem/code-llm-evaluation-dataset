
import os
import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file_path>")
    sys.exit(1)

file_path = sys.argv[1]

try:
    os.remove(file_path)
    print(f"File '{file_path}' has been deleted successfully.")
except FileNotFoundError:
    print(f"File '{file_path}' not found.")
except PermissionError:
    print(f"Permission denied. Unable to delete '{file_path}'.")
except Exception as e:
    print(f"An error occurred: {e}")
