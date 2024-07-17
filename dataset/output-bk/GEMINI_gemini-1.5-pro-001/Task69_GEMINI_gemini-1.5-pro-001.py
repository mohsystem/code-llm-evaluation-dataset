import sys
import os

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Error: File path not provided.")
        sys.exit(1)

    file_path = sys.argv[1]

    if os.path.exists(file_path):
        os.remove(file_path)
        print("File deleted successfully.")
    else:
        print("File not found.")