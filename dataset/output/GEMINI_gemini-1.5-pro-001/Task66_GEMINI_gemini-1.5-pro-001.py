import subprocess

command = input("Enter a bash command: ")

try:
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    print(result.stdout)
    print(result.stderr)
except Exception as e:
    print(f"Error executing command: {e}")