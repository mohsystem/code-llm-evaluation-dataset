import os
import shutil

def copy_file(src_dir, src_file, dst_dir):
    try:
        src_path = os.path.join(src_dir, src_file)
        dst_path = os.path.join(dst_dir, src_file)
        shutil.copyfile(src_path, dst_path)
        print(f"File {src_file} copied successfully to {dst_dir}")
    except FileNotFoundError:
        print(f"Error: File {src_file} not found in {src_dir}")
    except PermissionError:
        print(f"Error: Permission denied to read file {src_file} in {src_dir} or write to {dst_dir}")
    except Exception as e:
        print(f"An error occurred: {e}")

src_dir = "/path/to/source/directory"
src_file = "file.txt"
dst_dir = "/path/to/temporary/directory"
copy_file(src_dir, src_file, dst_dir)