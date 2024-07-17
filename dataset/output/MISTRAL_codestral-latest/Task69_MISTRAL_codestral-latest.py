# Python
import sys
import os

if len(sys.argv) > 1:
    file_path = sys.argv[1]
    if os.path.exists(file_path):
        os.remove(file_path)
        print("File deleted successfully")
    else:
        print("File does not exist")
else:
    print("Please provide a file path as an argument")