import os
import shutil
import tempfile

def process_file(source_file_path):
    try:
        with open(source_file_path, 'rb') as source_file:
            with tempfile.NamedTemporaryFile(delete=False) as temp_file:
                shutil.copyfileobj(source_file, temp_file)
                print(f"File copied successfully to: {temp_file.name}")
    except FileNotFoundError:
        print(f"Error: File not found at {source_file_path}")
    except IOError as e:
        print(f"Error: Could not read or write file: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    source_file_path = "/path/to/your/source/file"
    process_file(source_file_path)