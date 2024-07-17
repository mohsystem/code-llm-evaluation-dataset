import subprocess

command = input("Enter a shell command:
")

try:
    output = subprocess.check_output(command, shell=True, text=True)
    print(output)
except subprocess.CalledProcessError as e:
    print(f"Error executing command: {e}")