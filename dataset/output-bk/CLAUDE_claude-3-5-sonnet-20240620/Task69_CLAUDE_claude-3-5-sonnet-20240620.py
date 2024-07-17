
import sys
import os

if len(sys.argv) != 2:
    print(f"Usage: python {sys.argv[0]} <file_path>")
    sys.exit(1)

file_path = sys.argv[1]

try:
    os.remove(file_path)
    print(f"File deleted successfully: {file_path}")
except OSError as e:
    print(f"Failed to delete the file: {file_path}")
    print(f"Error: {e}")
