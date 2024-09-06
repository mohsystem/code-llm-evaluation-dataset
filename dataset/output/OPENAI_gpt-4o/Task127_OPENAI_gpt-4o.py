import shutil
import os

source_path = '/path/to/source/file.txt'
dest_path = '/path/to/dest/tmp_file.txt'

try:
    shutil.copy(source_path, dest_path)
    print("File copied successfully.")
except FileNotFoundError:
    print(f"Error: The file at {source_path} does not exist.")
except PermissionError:
    print("Error: Permission denied.")
except Exception as e:
    print(f"An unexpected error occurred: {e}")