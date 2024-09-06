import sys
import os

if len(sys.argv) != 2:
    print("Usage: python delete_file.py <file_path>")
    sys.exit(1)

file_path = sys.argv[1]

try:
    os.remove(file_path)
    print("File deleted successfully")
except FileNotFoundError:
    print("File not found")
except PermissionError:
    print("Permission denied")