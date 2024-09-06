
import os
import shutil

def copy_file(source_path, dest_path):
    try:
        with open(source_path, 'r') as source_file:
            content = source_file.read()
        
        with open(dest_path, 'w') as dest_file:
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
    source_file = "source.txt"
    temp_dir = "temp"
    temp_file = os.path.join(temp_dir, "temp_copy.txt")

    try:
        if not os.path.exists(temp_dir):
            os.makedirs(temp_dir)
        
        copy_file(source_file, temp_file)
    except OSError as e:
        print(f"Error creating temporary directory: {str(e)}")
    finally:
        if os.path.exists(temp_file):
            try:
                os.remove(temp_file)
                print(f"Temporary file {temp_file} removed.")
            except OSError as e:
                print(f"Error removing temporary file: {str(e)}")
        
        if os.path.exists(temp_dir):
            try:
                shutil.rmtree(temp_dir)
                print(f"Temporary directory {temp_dir} removed.")
            except OSError as e:
                print(f"Error removing temporary directory: {str(e)}")
