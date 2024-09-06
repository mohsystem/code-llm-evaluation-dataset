import os
import sys

# Check if the file path is provided as a command line argument
if len(sys.argv) > 1:
    file_path = sys.argv[1]

    # Check if the file exists
    if os.path.exists(file_path):
        # Delete the file
        os.remove(file_path)
        print(f"File {file_path} has been deleted.")
    else:
        print(f"File {file_path} does not exist.")
else:
    print("Please provide the file path as a command line argument.")