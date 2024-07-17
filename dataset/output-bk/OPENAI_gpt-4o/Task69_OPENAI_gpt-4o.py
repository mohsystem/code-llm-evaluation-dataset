import os
import sys

def main():
    if len(sys.argv) < 2:
        print("Please provide the file path as an argument.")
        return
    file_path = sys.argv[1]
    try:
        os.remove(file_path)
        print("File deleted successfully.")
    except OSError as e:
        print(f"Error: {e.strerror}")

if __name__ == "__main__":
    main()