import os
import shutil

try:
    src = input("Enter source file path: ")
    dst = input("Enter destination file path: ")
    shutil.copy(src, dst)
except FileNotFoundError:
    print("The source file does not exist.")
except PermissionError:
    print("Permission denied.")
except Exception as e:
    print(f"An error occurred: {e}")