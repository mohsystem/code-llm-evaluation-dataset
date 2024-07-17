import os
import sys

if len(sys.argv) != 2:
    print("Usage: python delete_file.py <file_path>")
    sys.exit(1)

try:
    os.remove(sys.argv[1])
    print("File deleted successfully")
except OSError as e:
    print("Failed to delete the file:", e.strerror)