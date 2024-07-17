
import os

file_name = "script.sh"

try:
    with open(file_name, \'w\') as file:
        pass
    print(f"File created: {file_name}")

    os.chmod(file_name, 0o755)
    print("File permissions set to executable.")
except IOError as e:
    print(f"An error occurred: {e}")
