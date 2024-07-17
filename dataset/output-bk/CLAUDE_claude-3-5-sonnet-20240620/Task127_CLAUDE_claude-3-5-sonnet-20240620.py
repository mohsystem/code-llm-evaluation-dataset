
import os
import shutil

def copy_file(source_path, dest_path):
    try:
        with open(source_path, \'r\') as source_file:
            content = source_file.read()
        
        with open(dest_path, \'w\') as dest_file:
            dest_file.write(content)
        
        print(f"File copied successfully from {source_path} to {dest_path}")
    except FileNotFoundError:
        print(f"Error: Source file {source_path} not found.")
    except PermissionError:
        print("Error: Permission denied. Check file permissions.")
    except IOError as e:
        print(f"I/O error occurred: {str(e)}")
    except Exception as e:
        print(f"An unexpected error occurred: {str(e)}")

if __name__ == "__main__":
    source_path = "path/to/source/file.txt"
    dest_path = "/tmp/copied_file.txt"
    copy_file(source_path, dest_path)
