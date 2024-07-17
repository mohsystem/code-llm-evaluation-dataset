
import subprocess

filename = input("Enter the filename: ")

try:
    result = subprocess.run(["cat", filename], capture_output=True, text=True, check=True)
    print(result.stdout)
except subprocess.CalledProcessError as e:
    print(f"An error occurred: {e}")
except FileNotFoundError:
    print(f"The file \'{filename}\' was not found.")
