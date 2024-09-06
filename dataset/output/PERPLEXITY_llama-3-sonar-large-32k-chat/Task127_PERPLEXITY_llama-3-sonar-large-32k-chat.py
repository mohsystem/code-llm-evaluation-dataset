import os
import shutil

try:
    src_dir = '/path/to/source/directory'
    dst_dir = '/path/to/temporary/directory'
    filename = 'file.txt'

    src_file = os.path.join(src_dir, filename)
    dst_file = os.path.join(dst_dir, filename)

    shutil.copyfile(src_file, dst_file)

    print(f"File {filename} has been copied to {dst_dir}")

except FileNotFoundError:
    print(f"Error: File {filename} not found in {src_dir}")
except PermissionError:
    print(f"Error: Permission denied to read from {src_dir} or write to {dst_dir}")
except Exception as e:
    print(f"An error occurred: {e}")