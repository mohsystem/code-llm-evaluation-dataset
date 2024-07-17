import os
import shutil

try:
    source_file = '/path/to/source/file'
    destination_file = '/path/to/destination/file'

    shutil.copy(source_file, destination_file)
    print("File copied successfully.")

except FileNotFoundError:
    print("The source file does not exist.")

except PermissionError:
    print("Permission denied.")

except Exception as e:
    print("An error occurred:", str(e))