import re
import subprocess

def is_valid_command(command):
    pattern = r'^[a-zA-Z0-9\s-_/.]+$'
    return re.match(pattern, command) is not None

def main():
    command = input("Enter shell command: ")
    
    if is_valid_command(command):
        try:
            result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            print(result.stdout.decode())
        except subprocess.CalledProcessError as e:
            print(f"Failed to run command: {e.stderr.decode()}")
    else:
        print("Invalid command.")

if __name__ == "__main__":
    main()